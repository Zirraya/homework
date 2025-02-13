using System;

namespace Lab4_2__var6_Nikitenko
{

    // Базовый класс
    public class Credit
    {
        public DateTime IssueDate { get; set; } // Дата выдачи
        public decimal Amount { get; set; } // Сумма
        public int Term { get; set; } // Срок в месяцах
        public decimal InterestRate { get; set; } // Процентная ставка

        public Credit(DateTime issueDate, decimal amount, int term, decimal interestRate)
        {
            IssueDate = issueDate;
            Amount = amount;
            Term = term;
            InterestRate = interestRate;
        }

        // Виртуальный метод для определения суммы возврата
        public virtual decimal CalculateRepaymentAmount()
        {
            
            return Amount + (Amount * InterestRate / 100 * Term / 12);
        }
        //

        // 
        public override string ToString()
        {
            return $"Кредит: Дата выдачи: {IssueDate}, Сумма: {Amount}, Срок: {Term} месяцев, Процент: {InterestRate}%";
        }
        //

        // 
        public override bool Equals(object obj)
        {
            if (obj is Credit other)
            {
                return IssueDate == other.IssueDate &&
                       Amount == other.Amount &&
                       Term == other.Term &&
                       InterestRate == other.InterestRate;
            }
            return false;
        }
        //

        //
        public override int GetHashCode()
        {
            return HashCode.Combine(IssueDate, Amount, Term, InterestRate);
        }
        //
    }
    //

    // Проивзольный класс
    public class SecuredCredit : Credit
    {
        public decimal CollateralValue { get; set; } // Стоимость имущества

        public SecuredCredit(DateTime issueDate, decimal amount, int term, decimal interestRate, decimal collateralValue)
            : base(issueDate, amount, term, interestRate)
        {
            CollateralValue = collateralValue;
        }

        // Переопределение метода для определения суммы возврата
        public override decimal CalculateRepaymentAmount()
        {
           
            return base.CalculateRepaymentAmount(); // Расчет
        }

        // Переопределение метода ToString
        public override string ToString()
        {
            return base.ToString() + $", Залог: {CollateralValue}";
        }

        //  Переопределение метода Equals
        public override bool Equals(object obj)
        {
            if (obj is SecuredCredit other)
            {
                return base.Equals(other) && CollateralValue == other.CollateralValue;
            }
            return false;
        }
        //

        // Переопределение метода GetHashCode
        public override int GetHashCode()
        {
            return HashCode.Combine(base.GetHashCode(), CollateralValue);
        }
    }
    //
    internal class Program
    {
        static void Main(string[] args)
        {
            Credit credit = new Credit(DateTime.Now, 10000m, 24, 3);
            Console.WriteLine(credit);
            Console.WriteLine($"Сумма возврата: {credit.CalculateRepaymentAmount()}");

            Credit credit1 = credit;
            Console.WriteLine(credit1);
            Console.WriteLine($"Сумма возврата: {credit1.CalculateRepaymentAmount()}");

            
            Console.WriteLine(credit.Equals(credit1));



            SecuredCredit securedCredit = new SecuredCredit(DateTime.Now, 15000m, 36, 11, 20000m);
            Console.WriteLine(securedCredit);
            Console.WriteLine($"Сумма возврата: {securedCredit.CalculateRepaymentAmount()}");

        }
    }
}
