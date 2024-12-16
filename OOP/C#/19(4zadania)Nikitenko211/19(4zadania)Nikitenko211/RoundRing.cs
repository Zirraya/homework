using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _19_4zadania_Nikitenko211
{
    public class RoundRing : FlatFigure // inner radius внутренний радиус
    {
        protected double InnerRadius;

        // Конструктор по умолчанию 
        public RoundRing() : base()
        {
            InnerRadius = 1;
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
                if (value <= base.radius)
                    throw new Exception("Радиус не может быть отрицательным!");
                base.radius = value;
            }
        }
        //



    }
}
