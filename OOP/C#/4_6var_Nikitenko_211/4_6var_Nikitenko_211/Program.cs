using System;
using System.Reflection;
using System.IO;
using Librarysincos;
using System.Linq;

namespace _4_6var_Nikitenko_211 // Задание 4 из 4 лабы
{
    internal class Program
    {
        static void Main(string[] args)
        {

            Assembly aa = Assembly.LoadFrom("Librarysincos.dll");
            object o = aa.CreateInstance("Librarysincos.Metod");
            if (o == null)
            {
                Console.WriteLine("NULL");
                return;
            }
            else
            {
                Console.WriteLine("Класс: ОК");
            }

            Type t = o.GetType();

                                        

            MethodInfo mi = t.GetMethod("Calculate", new Type[] { typeof(double) });
            if (mi == null)
            {
                Console.WriteLine("Метод отсутсвует");
                return;
            }
            double num1 = 0;

            object[] objArray = new object[1];
            objArray[0] = num1;


            object result = mi.Invoke(o, objArray);
            Console.WriteLine(result);


            MethodInfo mi2 = t.GetMethod("Calculate", new Type[] { typeof(double), typeof(double), typeof(double) });
            if (mi2 == null)
            {
                Console.WriteLine("NULL");
                return;
            }

            num1 = 0;
            double num2 = 1;
            double num3 = 0.5;

            // Создаем массив из трех объектов типа double
            object[] objArray2 = new object[3];
            objArray2[0] = num1;
            objArray2[1] = num2;
            objArray2[2] = num3;

            // Вызываем метод Calculate
            result = mi2.Invoke(o, objArray2);
            Console.WriteLine(result);

            // Динамическое подключение
            //// Загружаем сборку
            //Assembly loaddill = Assembly.LoadFrom("Librarysincos");

            //    object o = loaddill.CreateInstance("Librarysincos.Metod"); // Создание экземпляра класса Metod

            //    if (o == null)
            //    {
            //        Console.WriteLine("Экземпляр не создан");
            //        return;
            //    }

            //    // Получаем тип класса Metod
            //    Type t = o.GetType();


            //    // Вычисляем значения в точках a, b, c
            //    // Задаем точки a, b и c
            //    double aValue = 0.5;
            //    double bValue = 1.0;
            //    double cValue = 1.5;

            //    MethodInfo mi = t.GetMethod("Calculate", new Type[] { typeof(double), typeof(double), typeof(double) }); // Указываем тип параметра
            //    if (mi == null)
            //    {
            //        Console.WriteLine("Вызывание метода не вышло");
            //        return;
            //    }


            //    Object[] parametersA = new Object[] { aValue };
            //    Object[] parametersB = new Object[] { bValue };
            //    Object[] parametersC = new Object[] { cValue };

            //    double resultA = (double)mi.Invoke(o, parametersA);
            //    double resultB = (double)mi.Invoke(o, parametersB);
            //    double resultC = (double)mi.Invoke(o, parametersC);

            //    // Определяем минимальное значение
            //    double minValueDin = Math.Min(resultA, Math.Min(resultB, resultC));
            //    string minPointDin = "";

            //    if (minValueDin == resultA)
            //        minPointDin = "a";
            //    else if (minValueDin == resultB)
            //        minPointDin = "b";
            //    else if (minValueDin == resultC)
            //        minPointDin = "c";

            //    // Выводим результаты
            //    Console.WriteLine($"Значение в точке a: {resultA}");
            //    Console.WriteLine($"Значение в точке b: {resultB}");
            //    Console.WriteLine($"Значение в точке c: {resultC}");
            //    Console.WriteLine($"Минимальное значение: {minValueDin} в точке {minPointDin}");



            //----------------------------------------------------------------------------------------------

            // Не динамическое подключение
            Metod mathFunctions = new Metod();

            // Задаем точки a, b, c
            double a = 0.5;
            double b = 1.0;
            double c = 1.5;

            // Вычисление в точках
            double valueA = mathFunctions.Calculate(a);
            double valueB = mathFunctions.Calculate(b);
            double valueC = mathFunctions.Calculate(c);
            //

            // Определение минимального значения
            double minValue = Math.Min(valueA, Math.Min(valueB, valueC));
            string minPoint = "";

            if (minValue == valueA)
                minPoint = "a";
            else if (minValue == valueB)
                minPoint = "b";
            else if (minValue == valueC)
                minPoint = "c";
            //

            // Вывод результататов
            Console.WriteLine($"Значение в точке a: {valueA}");
            Console.WriteLine($"Значение в точке b: {valueB}");
            Console.WriteLine($"Значение в точке c: {valueC}");
            Console.WriteLine($"Минимальное значение: {minValue} в точке {minPoint}");
            //


        }
    }
}


