namespace n2_peregruzka_operaz_
{
    class Celcius
    {
        public double Gradus { get; set; }

        public static implicit operator Fahrenheit(Celcius celcius)               // не явное преобразование
        {
            return new Fahrenheit { Gradus = 9.0 / 5 * celcius.Gradus + 32 };
        }
        public static implicit operator Celcius(Fahrenheit fahrenheit)            // не явное преобразование
        {
            return new Celcius { Gradus = 5.0 / 9 * (fahrenheit.Gradus - 32) };
        }
    }
    class Fahrenheit
    {
        public double Gradus { get; set; } 
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8;

            Console.Write("Введите температуру(по Цельсию): ");
            double T=Convert.ToDouble(Console.ReadLine());  
            
            Console.WriteLine(" ");

            Celcius celcius= new Celcius();
            celcius.Gradus = T;
            Fahrenheit fahrenheit = celcius;

            Console.Write($"По Цельсию: {celcius.Gradus}");

            Console.WriteLine(" ");

            celcius = fahrenheit;
            Console.Write($"По Фаренгейту: {fahrenheit.Gradus}");
        }
    }
}

//class Celcius
//{
//    public double Gradus { get; set; }

//    public static implicit operator Celcius(double x)
//    {
//        return new Celcius { Gradus = 5 / 9 * (x - 32) };
//    }
//    public static explicit operator double(Celcius celcius)
//    {
//        return celcius.Gradus;
//    }
//}
//class Fahrenheit                                                        ПЕРВОНАЧАЛЬНЫЙ ВАРИАНТ
//{
//    public double Gradus { get; set; }

//    public static implicit operator Fahrenheit(double x)
//    {
//        return new Fahrenheit { Gradus = 9 / 5 * x + 32 };
//    }
//    public static explicit operator double(Fahrenheit fahrenheit)
//    {
//        return fahrenheit.Gradus;
//    }
//}