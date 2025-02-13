using System;

namespace Librarysincos
{
    public class Metod
    {
        public Metod()
        {
        }
        // Метод для вычисления sin(x) + cos(2 * x) с параметрами по умолчанию
        public double Calculate(double x = 0)
        {
            return Math.Sin(x) + Math.Cos(2 * x);
        }
        //

        // Перегрузка метода с одним параметром
        public double Calculate(double x, double y)
        {
            return Calculate(x) + Calculate(y);
        }
        //

        // Перегрузка метода с тремя параметрами
        public double Calculate(double x, double y, double z)
        {
            return Calculate(x) + Calculate(y) + Calculate(z);
        }
        //
    }
}

