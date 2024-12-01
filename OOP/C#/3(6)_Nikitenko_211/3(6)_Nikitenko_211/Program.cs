using System;

namespace _3_6__Nikitenko_211
{
    public class Matrix
    {
        // Поля для матрицы
        private long[,] elements; // элементы
        private int rows; // строки
        private int columns; // столбцы
        //

        // Конструктор по умолчанию
        public Matrix(int rows = 1, int columns = 1)
        {
            this.rows = rows;
            this.columns = columns;
            elements = new long[rows, columns];
        }
        //

        // Конструктор копирования с добавлением значения
        public Matrix(Matrix other, long increment)
        {
            this.rows = other.rows;
            this.columns = other.columns;
            elements = new long[rows, columns];

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    elements[i, j] = other.elements[i, j] + increment;
                }
            }
        }
        //

        // Деструктор 
        ~Matrix()
        {
            // Освобождение ресурсов, если нужно, конечно
            System.Diagnostics.Trace.WriteLine(this.GetHashCode() + " уничтожен"); // Уничтожение хеша (простите я  ничего лучше не придумала, все осталвьное не подходит)
        }
        //

        // Преобразование из переменной типа long в матрицу
        public static implicit operator Matrix(long value)
        {
            Matrix matrix = new Matrix(1, 1);
            matrix.elements[0, 0] = value;
            return matrix;
        }
        //

        // Преобразование из матрицы в переменную типа double (среднее арифметическое)
        public static explicit operator double(Matrix matrix)
        {
            long sum = 0;
            int count = matrix.rows * matrix.columns;

            for (int i = 0; i < matrix.rows; i++)
            {
                for (int j = 0; j < matrix.columns; j++)
                {
                    sum += matrix.elements[i, j];
                }
            }

            return (double)sum / count;
        }
        //

        // Метод заполнения матрицы 
        public void Fill(long[,] values)
        {
            if (values.GetLength(0) != rows || values.GetLength(1) != columns)
            {
                throw new ArgumentException("Размеры массива не совпадают с размером матрицы.");
            }

            elements = values;
        }
        //

        // Метод вывода матрицы
        public void Display()
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    Console.Write(elements[i, j] + " ");
                }
                Console.WriteLine();
            }
        }
    }
    //

    class Program
    {

        static void Main()
        {

            Console.WriteLine("Введите размерность матрицы");
            Console.Write(" n= ");
            int n = int.Parse(Console.ReadLine());

            Console.Write(" m= ");
            int m = int.Parse(Console.ReadLine());

            
            Matrix matrix1 = new Matrix(n, m); // Создание матрицы 

            // Ввод элементов матрицы с клавиатуры
            long[,] values = new long[n, m];
            Console.WriteLine("Введите элементы матрицы:");

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    Console.Write($"Элемент [{i + 1}, {j + 1}]= ");
                    values[i, j] = long.Parse(Console.ReadLine());
                }
            }

            matrix1.Fill(values);
            //
            Console.WriteLine("Матрица №1:");
            matrix1.Display();
            

            Console.WriteLine("Введите число на каоторое вы бы хотели увеличить матрицу: ");
            Console.Write("el= ");
            int el = int.Parse(Console.ReadLine());
         
            Matrix matrix2 = new Matrix(matrix1, el); // Создание новой матрицы с увеличением каждого элемента на n

            Console.WriteLine($"Матрица №2 (Матрица №1 увеличена на {el})"); 
            matrix2.Display();

            
            Matrix singleValueMatrix = (Matrix)10; // Преобразование long в матрицу

            Console.WriteLine("Матрица из единственного числа:");
            singleValueMatrix.Display();

           
            double average = (double)matrix1; // Преобразование матрицы в double (среднее арифметическое)
            Console.WriteLine($"Среднеее арифметическое Матрицы №1: {average}");
        }


    }
    
}
