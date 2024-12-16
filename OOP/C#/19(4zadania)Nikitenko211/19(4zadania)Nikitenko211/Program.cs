using System;

namespace _19_4zadania_Nikitenko211 // Вариант 18, а не 19
{
    // Абстрактный класс
    public abstract class FlatFigure
    {

        protected static int CountFigure = 0; // Количество плоских фигур
        protected double Perimeter; // Перемитер
        protected double SurfaceArea; // Площадь повехрности фигур
        

        // Конструктор по умалочанию
        public FlatFigure() {Perimeter = 1000; SurfaceArea = 1000; CountFigure++;}
        //

        // Конструктор с параматрами
        public FlatFigure(double per, double surf) { Perimeter = per; SurfaceArea = surf; CountFigure++; }
        //

        // Возвращает чилсо плоских фигур
        public static int countfigure
        {
            get { return CountFigure; }
        }

        // Вовзращает или устанавливает перемитер
        public double perimeter
        {
            get { return Perimeter; }
            set
            {
                if (value <= 0) throw new Exception("Перемитер не может быть отрицательным!");
                Perimeter = value;
            }
        }
        //

        // Вовзращает или устанавливает плащадь плоской фигуры
        public double surfacearea
        {
            get { return SurfaceArea; }
            set
            {
                if (value <= 0) throw new Exception("Перемитер не может быть отрицательным!");
                SurfaceArea = value;
            }
        }
        //

    }
    //

    internal class Program
    {
        static void Main()
        {
            






        }
    }
}
