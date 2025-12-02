using Graf1;
using Graph1;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// Тут интерфейс
namespace Graph1
{
    class Program
    {
        private static Graph graph;

        // Меню
        static void Main(string[] args)
        {
            Console.WriteLine("=== РАБОТА С ГРАФАМИ ===");
            InitializeGraph();

            bool running = true;
            while (running)
            {
                ShowMenu();
                string choice = Console.ReadLine();

                switch (choice)
                {
                    case "1": AddVertex(); break;
                    case "2": AddEdge(); break;
                    case "3": RemoveVertex(); break;
                    case "4": RemoveEdge(); break;
                    case "5": ShowAdjacencyList(); break;
                    case "6": SaveToFile(); break;
                    case "7": LoadFromFile(); break;
                    case "8": ShowEdgeList(); break;
                    case "9": ShowGraphInfo(); break;

                    case "10": CalculateDegrees(); break; // Задание 2 Вариант 2
                    case "11": FindPendantVertices(); break; // Задание 3 Вариант 6

                    case "0": running = false; break;
                    default: Console.WriteLine("Неверный выбор!"); break;
                }

                if (running)
                {
                    Console.WriteLine("\nНажмите любую клавишу для продолжения...");
                    Console.ReadKey();
                }
            }
        }
        //

        //
        static void InitializeGraph()
        {
            Console.WriteLine("0 - Если у вас есть файл txt с графом, вы можете загрузить его из файла");
            Console.WriteLine("Выберите тип графа:");
            Console.WriteLine("1 - Неориентированный невзвешенный");
            Console.WriteLine("2 - Ориентированный невзвешенный");
            Console.WriteLine("3 - Неориентированный взвешенный");
            Console.WriteLine("4 - Ориентированный взвешенный");
            string choice = Console.ReadLine();
            switch (choice)
            {
                case "0":
                    Console.Write("Введите имя файла: ");
                    string filename = Console.ReadLine();
                    try
                    {
                        graph = new Graph(filename);
                        Console.WriteLine($"Граф загружен из файла {filename}");
                        return; // Выходим, так как граф уже создан
                    }
                    catch (Exception ex)
                    {
                        Console.WriteLine($"Ошибка загрузки из файла: {ex.Message}");
                        Console.WriteLine("Будет создан граф по умолчанию (неориентированный невзвешенный)");
                        graph = new Graph(false, false);
                    }
                    break;
                case "1": graph = new Graph(false, false); break;
                case "2": graph = new Graph(true, false); break;
                case "3": graph = new Graph(false, true); break;
                case "4": graph = new Graph(true, true); break;
                //case "5": LoadFromFile(); break;
                default:
                    Console.WriteLine("Создан граф по умолчанию (неориентированный невзвешенный)");
                    graph = new Graph(false, false);
                    break;
            }

            Console.WriteLine("Граф создан успешно!");
        }
        //

        //
        static void ShowMenu()
        {
           
            Console.WriteLine(graph==null);
            Console.WriteLine("=== МЕНЮ УПРАВЛЕНИЯ ГРАФОМ ===");
           
            Console.WriteLine($"Тип графа: {(graph.IsDirected ? "Ориентированный" : "Неориентированный")}, " +
                            $"{(graph.IsWeighted ? "Взвешенный" : "Невзвешенный")}");
            Console.WriteLine($"Вершин: {graph.VertexCount}, Рёбер: {graph.EdgeCount}");
            Console.WriteLine();
            Console.WriteLine("1. Добавить вершину");
            Console.WriteLine("2. Добавить ребро/дугу");
            Console.WriteLine("3. Удалить вершину");
            Console.WriteLine("4. Удалить ребро/дугу");
            Console.WriteLine("5. Показать список смежности");
            Console.WriteLine("6. Сохранить в файл");
            Console.WriteLine("7. Загрузить из файла");
            Console.WriteLine("8. Показать список рёбер");
            Console.WriteLine("9. Информация о графе");

            Console.WriteLine("10. Вывести степени вершин");
            Console.WriteLine("11. Найти весячие вершины (степени 1)");





            Console.WriteLine("0. Выход");
            Console.Write("Выберите действие: ");
        }
        //

        //
        static void AddVertex()
        {
            Console.Write("Введите номер вершины: ");
            if (int.TryParse(Console.ReadLine(), out int vertex))
            {
                try
                {
                    graph.AddVertex(vertex);
                    Console.WriteLine($"Вершина {vertex} добавлена успешно!");
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"Ошибка: {ex.Message}");
                }
            }
            else
            {
                Console.WriteLine("Неверный формат числа!");
            }
        }
        //

        //
        static void AddEdge()
        {
            Console.Write("Введите начальную вершину: ");
            if (!int.TryParse(Console.ReadLine(), out int from))
            {
                Console.WriteLine("Неверный формат числа!");
                return;
            }

            Console.Write("Введите конечную вершину: ");
            if (!int.TryParse(Console.ReadLine(), out int to))
            {
                Console.WriteLine("Неверный формат числа!");
                return;
            }

            double weight = 1.0;
            if (graph.IsWeighted)
            {
                Console.Write("Введите вес ребра: ");
                if (!double.TryParse(Console.ReadLine(), out weight))
                {
                    Console.WriteLine("Неверный формат веса! Используется вес по умолчанию 1.0");
                    weight = 1.0;
                }
            }

            try
            {
                graph.AddEdge(from, to, weight);
                Console.WriteLine($"Ребро из {from} в {to} добавлено успешно!");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка: {ex.Message}");
            }
        }
        //

        //
        static void RemoveVertex()
        {
            Console.Write("Введите номер вершины для удаления: ");
            if (int.TryParse(Console.ReadLine(), out int vertex))
            {
                try
                {
                    graph.RemoveVertex(vertex);
                    Console.WriteLine($"Вершина {vertex} удалена успешно!");
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"Ошибка: {ex.Message}");
                }
            }
            else
            {
                Console.WriteLine("Неверный формат числа!");
            }
        }
        //

        //
        static void RemoveEdge()
        {
            Console.Write("Введите начальную вершину: ");
            if (!int.TryParse(Console.ReadLine(), out int from))
            {
                Console.WriteLine("Неверный формат числа!");
                return;
            }

            Console.Write("Введите конечную вершину: ");
            if (!int.TryParse(Console.ReadLine(), out int to))
            {
                Console.WriteLine("Неверный формат числа!");
                return;
            }

            try
            {
                graph.RemoveEdge(from, to);
                Console.WriteLine($"Ребро из {from} в {to} удалено успешно!");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка: {ex.Message}");
            }
        }
        //

        //
        static void ShowAdjacencyList()
        {
            Console.WriteLine("Список смежности:");
            Console.WriteLine(graph.GetAdjacencyListString());
        }
        //
        
        //
        static void SaveToFile()
        {
            Console.Write("Введите имя файла: ");
            string filename = Console.ReadLine();

            try
            {
                graph.SaveToFile(filename);
                Console.WriteLine($"Граф сохранён в файл {filename}");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка: {ex.Message}");
            }
        }
        //

        //
        static void LoadFromFile()
        {
            Console.Write("Введите имя файла: ");
            string filename = Console.ReadLine();

            try
            {
                graph = new Graph(filename);
                Console.WriteLine($"Граф загружен из файла {filename}");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка: {ex.Message}");
            }
        }
        //

        //
        static void ShowEdgeList()
        {
            var edges = graph.GetEdgeList();
            Console.WriteLine("Список рёбер:");
            foreach (var edge in edges)
            {
                if (graph.IsWeighted)
                    Console.WriteLine($"{edge.Item1} -> {edge.Item2} (вес: {edge.Item3})");
                else
                    Console.WriteLine($"{edge.Item1} -> {edge.Item2}");
            }
        }
        //

        // Задание 2 Вариант 3
        static void CalculateDegrees()
        {
            if (graph == null)
            {
                Console.WriteLine("Граф не создан!");
                return;
            }

            DegreeCalculator.CalculateDegrees(graph);
        }
        //


        // Задание 3 Вариант 6
        static void FindPendantVertices()
        {
            if (graph == null)
            {
                Console.WriteLine("Граф не создан!");
                return;
            }

            PendantVertices.FindPendantVertices(graph);
        }
        //


        //
        static void ShowGraphInfo()
        {
            Console.WriteLine("=== ИНФОРМАЦИЯ О ГРАФЕ ===");
            Console.WriteLine($"Тип: {(graph.IsDirected ? "Ориентированный" : "Неориентированный")}");
            Console.WriteLine($"Взвешенный: {(graph.IsWeighted ? "Да" : "Нет")}");
            Console.WriteLine($"Количество вершин: {graph.VertexCount}");
            Console.WriteLine($"Количество рёбер: {graph.EdgeCount}");

            var vertices = graph.GetVertices();
            Console.WriteLine($"Вершины: {string.Join(", ", vertices)}");

            // Проверка на изолированные вершины
            var isolated = vertices.Where(v => graph.GetAdjacentVertices(v).Count == 0).ToList();
            if (isolated.Count > 0)
                Console.WriteLine($"Изолированные вершины: {string.Join(", ", isolated)}");
        }
        //
    }
}
