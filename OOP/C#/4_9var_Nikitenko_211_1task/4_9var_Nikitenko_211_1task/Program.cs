using System;

namespace _4_9var_Nikitenko_211_1task
{

    // Класс для работы с датой
    public class CustomDate
    {
        private DateTime _date; //

        //
        public CustomDate(DateTime date) 
        { 
        _date = date;
        }
        //

        // Индексатор для доступа к i-тому дню
        public DateTime this[int index]
        {
            get
            {
                return _date.AddDays(index);
            }
        }

        // Перегрузка операции !
        public static bool operator !(CustomDate customDate)
        {
            return customDate._date.Day != DateTime.DaysInMonth(customDate._date.Year, customDate._date.Month);
        }
        //

        // Перегрузка констант true и false
        public static implicit operator bool(CustomDate customDate)
        {
            return customDate._date.Day == 1 && customDate._date.Month == 1;
        }
        //

        // Перегрузка операции &
        public static bool operator &(CustomDate left, CustomDate right)
        {
            return left._date == right._date;
        }
        //

        // Преобразование в строку
        public override string ToString()
        {
            return _date.ToString("yyyy-MM-dd");
        }
        //

        // Преобразование из строки
        public static CustomDate FromString(string dateString)
        {
            if (DateTime.TryParse(dateString, out DateTime date))
            {
                return new CustomDate(date);
            }
            throw new FormatException(" Неверный формат даты ");
        }
        //

        public DateTime Date => _date; // Свойство для получения установленной даты

    }

    //

    internal class Program
    {
        static void Main()
        {
            // Дата собсвтенно говоря
            CustomDate customDate = new CustomDate(new DateTime(2024, 12, 31));
            Console.WriteLine(" Дата: " + customDate.ToString());
            //

            Console.Write("Введите число: \n");
            int days = Convert.ToInt32(Console.ReadLine());


            // Использование индексатора
            Console.WriteLine($" Дата через {days} дней: {customDate[days]} "); // дата после установленной
            Console.WriteLine($" Дата за {days} дней: {customDate[-days]} "); // дата до установленной
            //

            // Использование оператора !
            Console.WriteLine($" Не последний день месяца: {!customDate} "); // False
            //

            // Использование констант true и false
            Console.WriteLine($" Является началом года: {(bool)customDate} " ); // False/True
            //


            // Еще одна дата, это мой день рождение кстати :)
            CustomDate anotherDate = new CustomDate(new DateTime(2024, 12, 06));

            // Сравнение дат
            Console.WriteLine($" Даты равны: {customDate & anotherDate} "); // True/False
            //

            // Преобразование в строку
            Console.WriteLine($" Преобразование даты из даты (кек) в строку: {customDate} "); // То же самое но в формате строки. Мде
            //

            // Преобразование из строки
            CustomDate parsedDate = CustomDate.FromString("2024-12-06");
            Console.WriteLine($" Преобразование даты из строки: {parsedDate} "); // Теперь дата снова дата, а не строка. ЛОЛ
            //
        }

    }
}
