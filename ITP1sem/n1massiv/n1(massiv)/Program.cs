using System.Security.Authentication;

namespace n1_massiv_
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[,,] mas = { { { 1, 2 },{ 3, 4 } },
                { { 4, 5 }, { 6, 7 } },
                { { 7, 8 }, { 9, 10 } },
                { { 10, 11 }, { 12, 13 } }
              };
            Console.Write("{{");
            for ( int i=0;i<mas.GetLength(0);i++)
            {
                for(int k=0;k<mas.GetLength(1);k++)
                {
                    for(int j=0;j<mas.GetLength(2);j++) 
                    {

                        if (j == 0)
                        {
                            Console.Write("{");
                        }
                        Console.Write(mas[i,k,j]);
                        if(mas.GetLength(2)>j+1)
                        {
                            Console.Write(","); 
                        }
                    Console.Write("");
                    }
                    Console.Write("}}");
                }
            }
            Console.Write("}");

        }
    }
}