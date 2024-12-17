using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace _19_4zadania_Nikitenko211
{
    // Представляет круг, плоскую фигуру
    public class Circle : FlatFigure
    {
        protected double Radius; // Радиус

        // Конструктор по умолчанию 
        public Circle() : base() { 
        Radius= 1;
        }
        //

        // Конструктор с параметрами
        public Circle(double per, double surf, double rad) : base(per,surf) 
        { 
            Radius= rad;
        }
        //

        // Вирутальный метод для установки радиуса
        public virtual double radius
        {
            get { return Radius; }
            set
            {
                if (value <= 0)
                    throw new Exception("Радиус не может быть отрицательным или равным нулю!");
                Radius = value;
            }
        }
        //

        // Характиристика круга
        public override string ToString()
        {
            return " Характиристика круга:\n" + " радиус " + radius ;   

        }
        //

        // Возвращает периметер круга
        public override double GetPerimeter()
        {
            return (Math.PI * radius * 2);
        }
        //

        // Возвращает площадь круга
        public override double GetSurfaceArea()
        {
            return(Math.PI * Math.Pow(radius,2));

        }
        //
    }
}
