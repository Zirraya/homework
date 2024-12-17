using System;

namespace _19_4zadania_Nikitenko211 // Вариант 18, а не 19 второе зданаие из 4 лабы
{
    // Абстрактный класс
    public abstract class FlatFigure
    {

        protected static int CountFigure = 0; // Количество плоских фигур
        protected double Perimeter; // Перемитер
        protected double SurfaceArea; // Площадь повехрности фигур
        

        // Конструктор по умалочанию
        public FlatFigure() 
        {
            Perimeter = 1000; SurfaceArea = 1000; CountFigure++;
        }
        //

        // Конструктор с параматрами
        public FlatFigure(double per, double surf) 
        { 
            Perimeter = per; SurfaceArea = surf; CountFigure++; 
        }
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

        // 
        public abstract double GetPerimeter();
        //

        //
        public abstract double GetSurfaceArea();

        //

    }
    //

    internal class Program
    {
        static void Main()
        {
            Console.Title = " Пример работы полиморфных классов";
            Console.WriteLine("          Плоские фигуры       ");

            Circle cs1= new Circle();
            Console.WriteLine(cs1.ToString());

            string s = "  периметер {0} \n" +
                        " площадь плоскости {1} \n";

            Console.WriteLine(s, cs1.GetPerimeter(), cs1.GetSurfaceArea());

            Circle cs2= new Circle(2, 3.5, 7);
            Console.WriteLine(cs2.ToString());
            Console.WriteLine(s, cs2.GetPerimeter(), cs2.GetSurfaceArea());

            RoundRing rr1=new RoundRing();
            Console.WriteLine(rr1.ToString());
            Console.WriteLine(s, rr1.GetPerimeter(), rr1.GetSurfaceArea());

            RoundRing rr2=new RoundRing(2,5,9,7);
            Console.WriteLine(rr2.ToString());
            Console.WriteLine(s, rr2.GetPerimeter(), rr2.GetSurfaceArea());

            Console.WriteLine(" Всего плоских фигур: {0} шт\n ", FlatFigure.countfigure);

            // Масив кругов
            Circle[] circles = new Circle[4];
            circles[0] = cs1;
            circles[1] = cs2;
            circles[2] = rr1;
            circles[3] = rr2;

            foreach(Circle c in circles)
            {
                Console.WriteLine(" Вычисление характиристик плоских фигур:\n" + s, c.GetPerimeter(), c.GetSurfaceArea() );
            }
            Console.Read();

            //
        }
    }
}
