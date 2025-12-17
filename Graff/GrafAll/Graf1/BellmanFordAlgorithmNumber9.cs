using Graph1;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Graf1
{

    public static class BellmanFordAlgorithm
    { 
  
        /// Находит кратчайшие пути от начальной вершины до всех остальных с помощью алгоритма Беллмана-Форда
        /// <param name="graph">Граф</param>
        /// <param name="startVertex">Начальная вершина</param>
        /// <returns>Результат с расстояниями и путями, или null если найден цикл отрицательного веса</returns>
        public static BellmanFordResult FindShortestPaths(Graph graph, int startVertex)
        {
            if (graph == null)
                throw new ArgumentNullException(nameof(graph));

            if (!graph.ContainsVertex(startVertex))
                throw new ArgumentException($"Вершина {startVertex} не существует в графе");

            if (!graph.IsWeighted)
                throw new ArgumentException("Алгоритм Беллмана-Форда требует взвешенный граф");

            var vertices = graph.GetVertices();
            int n = vertices.Count;

            // Инициализация расстояний
            var distances = new Dictionary<int, double>();
            var predecessors = new Dictionary<int, int?>();

            foreach (int vertex in vertices)
            {
                distances[vertex] = double.PositiveInfinity;
                predecessors[vertex] = null;
            }
            distances[startVertex] = 0;

            // Получаем список всех рёбер
            var edges = GetAllEdges(graph);

            // Основная часть алгоритма: релаксация рёбер (n-1) раз
            for (int i = 0; i < n - 1; i++)
            {
                bool anyDistanceChanged = false;

                foreach (var edge in edges)
                {
                    int u = edge.From;
                    int v = edge.To;
                    double weight = edge.Weight;

                    if (distances[u] + weight < distances[v])
                    {
                        distances[v] = distances[u] + weight;
                        predecessors[v] = u;
                        anyDistanceChanged = true;
                    }

                    // Для неориентированных графов проверяем также обратное направление
                    if (!graph.IsDirected)
                    {
                        if (distances[v] + weight < distances[u])
                        {
                            distances[u] = distances[v] + weight;
                            predecessors[u] = v;
                            anyDistanceChanged = true;
                        }
                    }
                }

                // Если на данной итерации не изменилось ни одно расстояние, можно остановиться
                if (!anyDistanceChanged)
                    break;
            }

            // Проверка на наличие циклов отрицательного веса
            bool hasNegativeCycle = CheckNegativeCycle(graph, edges, distances);

            if (hasNegativeCycle)
            {
                return null; // Цикл отрицательного веса обнаружен
            }

            return new BellmanFordResult(startVertex, distances, predecessors);
        }

        /// Получить список всех уникальных рёбер графа
        private static List<EdgeData> GetAllEdges(Graph graph)
        {
            var edges = new List<EdgeData>();
            var vertices = graph.GetVertices();

            foreach (int vertex in vertices)
            {
                var adjacent = graph.GetAdjacentVertices(vertex);
                foreach (var adj in adjacent)
                {
                    // Для неориентированного графа добавляем каждое ребро только один раз
                    if (!graph.IsDirected)
                    {
                        // Добавляем ребро, если оно ещё не добавлено в обратном направлении
                        if (!edges.Any(e => (e.From == adj.Target && e.To == vertex)))
                        {
                            edges.Add(new EdgeData(vertex, adj.Target, adj.Weight));
                        }
                    }
                    else
                    {
                        // Для ориентированного графа добавляем все рёбра
                        edges.Add(new EdgeData(vertex, adj.Target, adj.Weight));
                    }
                }
            }

            return edges;
        }

        /// Проверка на наличие циклов отрицательного веса
        private static bool CheckNegativeCycle(Graph graph, List<EdgeData> edges, Dictionary<int, double> distances)
        {
            foreach (var edge in edges)
            {
                int u = edge.From;
                int v = edge.To;
                double weight = edge.Weight;

                if (distances[u] + weight < distances[v])
                {
                    return true; // Найден цикл отрицательного веса
                }

                // Для неориентированных графов проверяем также обратное направление
                if (!graph.IsDirected)
                {
                    if (distances[v] + weight < distances[u])
                    {
                        return true; // Найден цикл отрицательного веса
                    }
                }
            }

            return false;
        }

        /// Вывести результаты алгоритма Беллмана-Форда в консоль
        public static void DisplayResults(Graph graph, int startVertex)
        {
            try
            {
                Console.WriteLine($"\n=== АЛГОРИТМ БЕЛЛМАНА-ФОРДА (из вершины {startVertex}) ===");

                var result = FindShortestPaths(graph, startVertex);

                if (result == null)
                {
                    Console.WriteLine("В графе обнаружен цикл отрицательного веса!");
                    Console.WriteLine("Кратчайшие пути не могут быть найдены.");
                    return;
                }

                var vertices = graph.GetVertices().OrderBy(v => v).ToList();

                Console.WriteLine($"{"Вершина",-10} {"Расстояние",-15} {"Путь",-30}");
                Console.WriteLine(new string('-', 60));

                foreach (int vertex in vertices)
                {
                    if (vertex == startVertex)
                        continue;

                    double distance = result.Distances[vertex];
                    string distanceStr = distance == double.PositiveInfinity ? "?" : distance.ToString("F2");
                    string path = ReconstructPath(result, vertex);

                    Console.WriteLine($"{vertex,-10} {distanceStr,-15} {path,-30}");
                }

                // Дополнительная информация
                Console.WriteLine($"\nОбщая информация:");
                Console.WriteLine($"- Вершин достижимо: {result.Distances.Count(d => d.Value < double.PositiveInfinity && d.Key != startVertex)}");
                Console.WriteLine($"- Вершин недостижимо: {result.Distances.Count(d => d.Value == double.PositiveInfinity && d.Key != startVertex)}");

                if (graph.IsDirected)
                {
                    Console.WriteLine($"- Граф ориентированный");
                }
                else
                {
                    Console.WriteLine($"- Граф неориентированный");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка: {ex.Message}");
            }
        }

        /// Восстановить путь от начальной вершины до целевой
        public static string ReconstructPath(BellmanFordResult result, int targetVertex)
        {
            if (result == null)
                throw new ArgumentNullException(nameof(result));

            if (result.Distances[targetVertex] == double.PositiveInfinity)
                return "Нет пути";

            var path = new List<int>();
            int? current = targetVertex;

            while (current.HasValue)
            {
                path.Add(current.Value);
                current = result.Predecessors[current.Value];
            }

            path.Reverse();

            // Проверяем, начинается ли путь с начальной вершины
            if (path[0] != result.StartVertex)
                return "Нет пути";

            return string.Join(" -> ", path);
        }

      
        /// Получить полный путь в виде списка вершин
        public static List<int> GetPath(BellmanFordResult result, int targetVertex)
        {
            if (result == null)
                throw new ArgumentNullException(nameof(result));

            if (result.Distances[targetVertex] == double.PositiveInfinity)
                return new List<int>();

            var path = new List<int>();
            int? current = targetVertex;

            while (current.HasValue)
            {
                path.Add(current.Value);
                current = result.Predecessors[current.Value];
            }

            path.Reverse();

            // Проверяем, начинается ли путь с начальной вершины
            if (path.Count == 0 || path[0] != result.StartVertex)
                return new List<int>();

            return path;
        }


        /// Вспомогательный класс для хранения информации о ребре
        private class EdgeData
        {
            public int From { get; }
            public int To { get; }
            public double Weight { get; }

            public EdgeData(int from, int to, double weight)
            {
                From = from;
                To = to;
                Weight = weight;
            }
        }
    }

 
    /// Класс для хранения результатов алгоритма Беллмана-Форда
    public class BellmanFordResult
    {
        public int StartVertex { get; }
        public Dictionary<int, double> Distances { get; }
        public Dictionary<int, int?> Predecessors { get; }

        public BellmanFordResult(int startVertex, Dictionary<int, double> distances, Dictionary<int, int?> predecessors)
        {
            StartVertex = startVertex;
            Distances = distances ?? throw new ArgumentNullException(nameof(distances));
            Predecessors = predecessors ?? throw new ArgumentNullException(nameof(predecessors));
        }
    }

}
