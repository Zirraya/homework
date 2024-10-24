using System;

namespace _6_massiv__Nikitenko_211
{
    class Class
    {
        //
        static int[][] Input()
        {
            Console.WriteLine("Введите размерность массива");
            Console.Write("n = ");
            int n = int.Parse(Console.ReadLine());
            int[][] a = new int[n][];
            for (int i = 0; i < n; ++i)
            {
                a[i] = new int[n];
                for (int j = 0; j < n; ++j)
                {
                    Console.Write($"a[{i},{j}]= ");
                    a[i][j] = int.Parse(Console.ReadLine());
                }
            }
            return a;
        }
        //

        // Вывод
        static void Print1(int[] a)
        {
            for (int i = 0; i < a.Length; ++i)
                Console.Write("{0,5} ", a[i]);
            Console.WriteLine();
        }
        //

        // Вывод
        static void Print2(int[][] a)
        {
            for (int i = 0; i < a.Length; ++i, Console.WriteLine())
                for (int j = 0; j < a[i].Length; ++j)
                    Console.Write("{0,5} ", a[i][j]);
        }
        //

        // Подсчет отрицательных элементов массива по столбцам
        static int SumNegative(int[][] a, int column)
        {
            int sum = 0;
            for (int i = 0; i < a.Length; ++i)
            {
                if (a[i][column] < 0)
                {
                    sum += a[i][column];
                }
            }
            return sum;
        }
        //

        static void Main()
        {
            int[][] myArray = Input();
            Console.WriteLine("Исходный массив:");
            Print2(myArray);

            // Тут хранятся суммы отрицательных элементов по стобцам
            int[] negativeSums = new int[myArray[0].Length]; 

            for (int j = 0; j < myArray[0].Length; ++j)
            {
                negativeSums[j] = SumNegative(myArray, j);
            }
            //

            Console.WriteLine("Суммы отрицательных элементов по столбцам:");
            Print1(negativeSums);
        }
    }
}
