using Graph1;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Graf1
{
    public class PendantVertices
    {
        private Graph graph;

        public PendantVertices(Graph graph)
        {
            this.graph = graph ?? throw new ArgumentNullException(nameof(graph));
        }

        // Основной метод: найти и вывести все висячие вершины
        public void FindAndPrintPendantVertices()
        {
            Console.WriteLine("=== ПОИСК ВИСЯЧИХ ВЕРШИН (СТЕПЕНИ 1) ===");

            if (graph == null || graph.VertexCount == 0)
            {
                Console.WriteLine("Граф пуст или не создан.");
                return;
            }

            // Получаем список всех висячих вершин
            List<int> pendantVertices = GetPendantVertices();

            // Выводим результат
            if (pendantVertices.Count == 0)
            {
                Console.WriteLine("В графе нет висячих вершин (степени 1).");
            }
            else
            {
                Console.WriteLine($"Найдено {pendantVertices.Count} висячих вершин:");
                foreach (int vertex in pendantVertices)
                {
                    PrintVertexInfo(vertex);
                }
            }

            // Дополнительная статистика
            PrintStatistics(pendantVertices);
        }

        // Метод для получения списка висячих вершин
        public List<int> GetPendantVertices()
        {
            List<int> pendantVertices = new List<int>();

            // Получаем все вершины графа
            List<int> allVertices = graph.GetVertices();

            foreach (int vertex in allVertices)
            {
                if (IsPendantVertex(vertex))
                {
                    pendantVertices.Add(vertex);
                }
            }

            return pendantVertices.OrderBy(v => v).ToList();
        }

        // Проверка, является ли вершина висячей (степени 1)
        public bool IsPendantVertex(int vertex)
        {
            if (!graph.ContainsVertex(vertex))
                return false;

            if (!graph.IsDirected)
            {
                // Для неориентированного графа: просто считаем количество смежных вершин
                return graph.GetAdjacentVertices(vertex).Count == 1;
            }
            else
            {
                // Для ориентированного графа: сумма входящих и исходящих рёбер = 1
                int totalDegree = GetTotalDegree(vertex);
                return totalDegree == 1;
            }
        }

        // Получить общую степень вершины (для ориентированного графа)
        private int GetTotalDegree(int vertex)
        {
            if (!graph.ContainsVertex(vertex))
                return 0;

            if (!graph.IsDirected)
            {
                // Для неориентированного графа - просто количество смежных вершин
                return graph.GetAdjacentVertices(vertex).Count;
            }
            else
            {
                // Для ориентированного графа: сумма входящих и исходящих рёбер
                int outDegree = graph.GetAdjacentVertices(vertex).Count; // исходящие рёбра
                int inDegree = GetInDegree(vertex); // входящие рёбра
                return outDegree + inDegree;
            }
        }

        // Получить количество входящих рёбер (для ориентированного графа)
        private int GetInDegree(int vertex)
        {
            if (!graph.ContainsVertex(vertex))
                return 0;

            int inDegree = 0;

            // Проверяем все вершины графа
            foreach (int otherVertex in graph.GetVertices())
            {
                // Если есть ребро из otherVertex в vertex
                if (graph.ContainsEdge(otherVertex, vertex))
                {
                    inDegree++;
                }
            }

            return inDegree;
        }

        // Вывод информации о вершине
        private void PrintVertexInfo(int vertex)
        {
            if (!graph.ContainsVertex(vertex))
                return;

            if (!graph.IsDirected)
            {
                // Для неориентированного графа
                var adjacent = graph.GetAdjacentVertices(vertex);
                if (adjacent.Count == 1)
                {
                    Console.WriteLine($"Вершина {vertex}: смежна с вершиной {adjacent[0].Target}");
                }
            }
            else
            {
                // Для ориентированного графа
                int outDegree = graph.GetAdjacentVertices(vertex).Count;
                int inDegree = GetInDegree(vertex);

                if (outDegree == 1 && inDegree == 0)
                {
                    var adjacent = graph.GetAdjacentVertices(vertex);
                    Console.WriteLine($"Вершина {vertex}: имеет одно исходящее ребро в вершину {adjacent[0].Target}");
                }
                else if (inDegree == 1 && outDegree == 0)
                {
                    // Найдем, откуда идет ребро в эту вершину
                    int source = FindSourceVertex(vertex);
                    Console.WriteLine($"Вершина {vertex}: имеет одно входящее ребро из вершины {source}");
                }
                else if (outDegree + inDegree == 1)
                {
                    Console.WriteLine($"Вершина {vertex}: общая степень = 1");
                }
            }
        }

        // Найти вершину, из которой идет ребро в заданную вершину
        private int FindSourceVertex(int targetVertex)
        {
            foreach (int vertex in graph.GetVertices())
            {
                if (graph.ContainsEdge(vertex, targetVertex))
                {
                    return vertex;
                }
            }
            return -1;
        }

        // Вывод статистики
        private void PrintStatistics(List<int> pendantVertices)
        {
            int totalVertices = graph.VertexCount;

            if (totalVertices > 0)
            {
                Console.WriteLine("\n=== СТАТИСТИКА ===");
                Console.WriteLine($"Всего вершин в графе: {totalVertices}");
                Console.WriteLine($"Висячих вершин: {pendantVertices.Count}");
                Console.WriteLine($"Процент висячих вершин: {(double)pendantVertices.Count / totalVertices * 100:F1}%");

                if (pendantVertices.Count > 0)
                {
                    Console.WriteLine($"Список всех висячих вершин: {string.Join(", ", pendantVertices)}");
                }
            }
        }

        // Примеры графов для тестирования
        public static void TestExamples()
        {
            Console.WriteLine("\n=== ПРИМЕРЫ ГРАФОВ ===");

            // Пример 1: Простой путь (1-2-3-4)
            Console.WriteLine("\nПример 1: Путь из 4 вершин (1-2-3-4)");
            var edges1 = new List<Tuple<int, int>>
            {
                Tuple.Create(1, 2),
                Tuple.Create(2, 3),
                Tuple.Create(3, 4)
            };
            Graph graph1 = new Graph(edges1, false, false);
            PendantVertices pv1 = new PendantVertices(graph1);
            pv1.FindAndPrintPendantVertices();

            // Пример 2: Звезда
            Console.WriteLine("\nПример 2: Звезда с центром 1");
            var edges2 = new List<Tuple<int, int>>
            {
                Tuple.Create(1, 2),
                Tuple.Create(1, 3),
                Tuple.Create(1, 4),
                Tuple.Create(1, 5)
            };
            Graph graph2 = new Graph(edges2, false, false);
            PendantVertices pv2 = new PendantVertices(graph2);
            pv2.FindAndPrintPendantVertices();

            // Пример 3: Ориентированный граф
            Console.WriteLine("\nПример 3: Ориентированный граф");
            var edges3 = new List<Tuple<int, int>>
            {
                Tuple.Create(1, 2),
                Tuple.Create(2, 3),
                Tuple.Create(3, 1)
            };
            Graph graph3 = new Graph(edges3, true, false);
            PendantVertices pv3 = new PendantVertices(graph3);
            pv3.FindAndPrintPendantVertices();
        }

        // Статический метод для быстрого вызова
        public static void FindPendantVertices(Graph graph)
        {
            PendantVertices finder = new PendantVertices(graph);
            finder.FindAndPrintPendantVertices();
        }
    }
}
