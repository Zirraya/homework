using n1_index_;
using System;

namespace n1_index_
{

    class Player
    {
        public string Name { get; set; } // имя
        public int Number { get; set; } // номер

    }

    class Soccer_Team
    {
        Player[] players = new Player[11]; // Создание массива
        public Player this[int index]
        {
            get { return players[index]; } 
            set { players[index] = value; }

        }
    }
        internal class Program
        {
            static void Main(string[] args)
            {
            Console.OutputEncoding = System.Text.Encoding.UTF8; // Для включения русского языка в консоле. По умолчанию его почему то нет и мне лень разбираться...

                Soccer_Team inter=new Soccer_Team();

                inter[0] = new Player { Name = "Tom", Number= 1 };
                inter[1] = new Player { Name = "Jack", Number = 2 };
                inter[2] = new Player { Name = "Alex", Number = 3 };
                inter[3] = new Player { Name = "John", Number = 4 };
                inter[4] = new Player { Name = "Donald", Number= 5 };
                inter[5] = new Player {Name= "Alexendar", Number=6 };
                inter[6] = new Player {Name= "Petr", Number=7 };
                inter[7] = new Player {Name= "James", Number=8 };
                inter[8] = new Player {Name= "Jerry", Number=9 };
                inter[9] = new Player {Name= "Bil", Number=10 };
                inter[10] = new Player {Name= "Pol", Number=11 };
                
                Console.WriteLine("Примечание: индексы игроков Tom 0, Jack 1, Alex 2, John 3, Donlad 4, Alexender 5,");
                Console.WriteLine("                            Petr 6, James 7, Jerry 8, Bil 9, Pol 10");
                Console.Write("Введите индекс игрока, который вам нужен: ");

                int i=Convert.ToInt32(Console.ReadLine());
                Console.WriteLine(inter[i]?.Name);  // Вывод игрока по индексу
            }
        }
    
}

//string lions = new Soccer_Team(new[]
//          {
//         new Player("Tom"), new Player("Bob"), new Player("Sam"), new Player("Alice")
//           });
//Player firstplayer = lions[0];