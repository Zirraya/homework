using System;
using System.Collections.Generic;
using System.Linq;
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
        public Circle(double per, double surf, double rad) : base(per,surf) { Radius= rad;}
        //

        // Вирутальный метод для установки радиуса
        public virtual double radius
        {
            get { return Radius; }
            set
            {
                if (value <= 0)
                    throw new Exception("Радиус не может быть отрицательным!");
                Radius = value;
            }
        }
        //

    }
}
