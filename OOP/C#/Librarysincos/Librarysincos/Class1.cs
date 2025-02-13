using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Librarysincos
{
    public class Metod
    {

        // Метод для вычисления значения функции sin(x) + cos(2 * x)
        public double CalculateFunction(double x)
        {
            return Math.Sin(x) + Math.Cos(2 * x);
        }

        // Метод для определения минимального значения в заданных точках
        public (double minValue, string point) FindMinValue(double a = 0.0, double b = Math.PI / 4, double c = Math.PI / 2)
        {
            double valueA = CalculateFunction(a);
            double valueB = CalculateFunction(b);
            double valueC = CalculateFunction(c);

            double minValue = valueA;
            string minPoint = "a";

            if (valueB < minValue)
            {
                minValue = valueB;
                minPoint = "b";
            }

            if (valueC < minValue)
            {
                minValue = valueC;
                minPoint = "c";
            }

            return (minValue, minPoint);
        }
    }
}

