using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _19_4zadania_Nikitenko211
{
    public class RoundRing : Circle // inner radius внутренний радиус
    {
        protected double InnerRadius;

        // Конструктор по умолчанию 
        public RoundRing() : base()
        {
            InnerRadius = Math.PI*((Radius*2)-(InnerRadius*2));
        }
        //

        // Конструктор с параметрами
        public RoundRing(double per, double surf, double rad, double inrad) : base (per, surf, rad) { InnerRadius = inrad; }
        //

        // Вирутальный метод для установки радиуса
        public override double radius
        {
            get { return base.radius; }
            set
            {
                if (value > base.radius) // Проверка на отрицательное значение
                    throw new Exception(" Внутренний радиус не может быть больше чем внешний радиус!");
                base.radius = value; // Установка нового значения радиуса
            }
        }
        //

        //  Возвращает или устанавливает внутренний радиус
        public double innerradius
        {
            get { return InnerRadius; }
            set
            {
                if (value <= 0)
                    throw new Exception(" Внутренний радиус не может быть отрицательным или равным нуля!");
                InnerRadius = value;
            }
        }
        //


        // Характиристика круга
        public override string ToString()
        {
            return "\n - внутренний радиус кольца: " + InnerRadius;

        }
        //

        // Возвращает периметер кольца
        public override double GetPerimeter()
        {
            return (Math.PI * radius * 2);
        }
        //

        // Возвращает площадь кольца
        public override double GetSurfaceArea()
        {
            return (Math.PI * Math.Pow(radius, 2));

        }
        //



    }
}
