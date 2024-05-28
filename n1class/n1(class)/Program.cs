using System;
using System.Security.Cryptography.X509Certificates;

namespace n1_class_
{

    
    class State
    {
        public decimal Population { get; set; } // население
        public decimal Area { get; set; }       // территория



        public static State operator +(State c,State b) 
        {
            return new State
            {
                Population = c.Population + b.Population,
                Area = c.Area + b.Area
            };
        }
        public static State operator -(State c, State b)
        {
            return new State
            {
                Population = c.Population - b.Population,
                Area = c.Area - b.Area
            };
        }


        public static bool operator >(State c, State b)
        {
            return c.Population > b.Population;
        }

        public static bool operator <(State c, State b)
        {
            return c.Population < b.Population;
        }
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8;

            State canada = new State();
            canada.Population = 250; canada.Area = 500;

            Console.WriteLine("Канада");   
            Console.WriteLine($"Населения {canada.Population}"); Console.WriteLine($"Территория {canada.Area}");

            Console.WriteLine("---------------");

            Console.WriteLine("Бразилия");
            State brazil= new State();
            brazil.Population = 200; brazil.Area = 350;
            Console.WriteLine($"Население {brazil.Population}"); Console.WriteLine($"Территория {brazil.Area}");
            Console.WriteLine("------------");

            

            State russia = canada + brazil;

            Console.Write("Население России: ");
            Console.Write(russia.Population);
            Console.Write(" Территория России: ");
            Console.Write(russia.Area);


            Console.WriteLine("");
            Console.WriteLine("---------");


            State french= canada - brazil;

            Console.Write("Население Франции: ");
            Console.Write(french.Population);
            Console.Write(" Территория Франции: ");
            Console.Write(french.Area);

            Console.WriteLine("");
            Console.WriteLine("-------");

            if (canada > brazil)
            {
               ;
                Console.WriteLine("Канада больше Бразилии");
            }
            else
            {
                
                Console.WriteLine("Канада меньше Бразилии");
            }
        }
    }
}