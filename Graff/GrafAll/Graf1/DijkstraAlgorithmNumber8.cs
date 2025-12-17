using Graph1;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace Graph1
{
    public static class DijkstraAlgorithm
    {
        /// Результат алгоритма Дейкстры для одной вершины
        public class DijkstraResult
        {
            public int SourceVertex { get; set; }
            public Dictionary<int, double> Distances { get; set; }
            public Dictionary<int, int> PreviousVertices { get; set; }

            public DijkstraResult(int source)
            {
                SourceVertex = source;
                Distances = new Dictionary<int, double>();
                PreviousVertices = new Dictionary<int, int>();
            }
        }

        /// Находит кратчайшие пути от исходной вершины до всех остальных
        /// <param name="graph">Граф</param>
        /// <param name="source">Исходная вершина</param>
        /// <returns>Результат алгоритма Дейкстры</returns>
        public static DijkstraResult FindShortestPathsFromVertex(Graph graph, int source)
        {
            if (graph == null)
                throw new ArgumentNullException(nameof(graph));

            if (!graph.ContainsVertex(source))
                throw new ArgumentException($"Вершина {source} не существует в графе");

            // Проверка на отрицательные веса (хотя по условию их нет)
            foreach (var vertex in graph.GetVertices())
            {
                foreach (var edge in graph.GetAdjacentVertices(vertex))
                {
                    if (edge.Weight < 0)
                        throw new ArgumentException("Граф содержит ребра с отрицательным весом. Алгоритм Дейкстры не применим.");
                }
            }

            var vertices = graph.GetVertices();
            var result = new DijkstraResult(source);

            // Инициализация
            var unvisitedVertices = new HashSet<int>(vertices);
            var priorityQueue = new SortedSet<Tuple<double, int>>();

            // Установка начальные расстояния
            foreach (var vertex in vertices)
            {
                if (vertex == source)
                {
                    result.Distances[vertex] = 0;
                    priorityQueue.Add(Tuple.Create(0.0, vertex));
                }
                else
                {
                    result.Distances[vertex] = double.PositiveInfinity;
                    priorityQueue.Add(Tuple.Create(double.PositiveInfinity, vertex));
                }
                result.PreviousVertices[vertex] = -1;
            }

            // Основной цикл алгоритма
            while (unvisitedVertices.Count > 0 && priorityQueue.Count > 0)
            {
                // Извлечение вершины с минимальным расстоянием
                var currentTuple = priorityQueue.Min;
                priorityQueue.Remove(currentTuple);

                double currentDistance = currentTuple.Item1;
                int currentVertex = currentTuple.Item2;

                // Если вершина уже посещена, пропускаем
                if (!unvisitedVertices.Contains(currentVertex))
                    continue;

                unvisitedVertices.Remove(currentVertex);

                // Если расстояние до текущей вершины бесконечно, значит остальные вершины недостижимы
                if (currentDistance == double.PositiveInfinity)
                    break;

                // Рассматриваем всех соседей текущей вершины
                foreach (var edge in graph.GetAdjacentVertices(currentVertex))
                {
                    int neighbor = edge.Target;

                    // Если сосед еще не посещен
                    if (unvisitedVertices.Contains(neighbor))
                    {
                        double newDistance = currentDistance + edge.Weight;

                        if (newDistance < result.Distances[neighbor])
                        {
                            // Обновляем расстояние
                            priorityQueue.Remove(Tuple.Create(result.Distances[neighbor], neighbor));
                            result.Distances[neighbor] = newDistance;
                            priorityQueue.Add(Tuple.Create(newDistance, neighbor));
                            result.PreviousVertices[neighbor] = currentVertex;
                        }
                    }
                }
            }

            return result;
        }

       
        /// Находит кратчайшие пути для всех пар вершин
        /// <param name="graph">Граф</param>
        /// <returns>Матрица расстояний между всеми парами вершин</returns>
        public static Dictionary<int, DijkstraResult> FindAllPairsShortestPaths(Graph graph)
        {
            if (graph == null)
                throw new ArgumentNullException(nameof(graph));

            if (graph.IsDirected)
                throw new ArgumentException("Алгоритм работает с неориентированными графами");

            var vertices = graph.GetVertices();
            var allPairsResults = new Dictionary<int, DijkstraResult>();

            Console.WriteLine("=== АЛГОРИТМ ДЕЙКСТРЫ ДЛЯ ВСЕХ ПАР ВЕРШИН ===");
            Console.WriteLine($"Всего вершин: {vertices.Count}");

            // Запуск Дейкстры из каждой вершины
            foreach (var source in vertices)
            {
                var result = FindShortestPathsFromVertex(graph, source);
                allPairsResults[source] = result;

                Console.WriteLine($"\nИз вершины {source}:");
                foreach (var target in vertices.OrderBy(v => v))
                {
                    if (target != source)
                    {
                        double distance = result.Distances[target];
                        if (double.IsPositiveInfinity(distance))
                            Console.WriteLine($"  -> {target}: недостижима");
                        else
                            Console.WriteLine($"  -> {target}: {distance:F2}");
                    }
                }
            }

            // Вывод
            Console.WriteLine("\n=== МАТРИЦА РАССТОЯНИЙ ===");
            Console.Write("     ");
            foreach (var vertex in vertices)
                Console.Write($"{vertex,6} ");
            Console.WriteLine();

            foreach (var source in vertices)
            {
                Console.Write($"{source,3}: ");
                foreach (var target in vertices)
                {
                    if (source == target)
                        Console.Write("     - ");
                    else
                    {
                        double distance = allPairsResults[source].Distances[target];
                        if (double.IsPositiveInfinity(distance))
                            Console.Write("   INF ");
                        else
                            Console.Write($"{distance,6:F2} ");
                    }
                }
                Console.WriteLine();
            }

            // Анализ связности графа
            Console.WriteLine("\n=== АНАЛИЗ СВЯЗНОСТИ ===");
            bool isConnected = true;
            foreach (var source in vertices)
            {
                int unreachableCount = vertices.Count(v =>
                    v != source && double.IsPositiveInfinity(allPairsResults[source].Distances[v]));

                if (unreachableCount > 0)
                {
                    isConnected = false;
                    Console.WriteLine($"Из вершины {source} недостижимы {unreachableCount} вершин:");
                    var unreachable = vertices.Where(v =>
                        v != source && double.IsPositiveInfinity(allPairsResults[source].Distances[v]));
                    Console.WriteLine($"  {string.Join(", ", unreachable)}");
                }
            }

            if (isConnected)
                Console.WriteLine("Граф является связным.");
            else
                Console.WriteLine("Граф не является связным (имеется несколько компонент связности).");

            return allPairsResults;
        }

        /// Восстанавливает кратчайший путь между двумя вершинами
        /// <param name="result">Результат алгоритма Дейкстры</param>
        /// <param name="target">Целевая вершина</param>
        /// <returns>Список вершин, образующих путь, или пустой список, если путь не существует</returns>
        public static List<int> ReconstructPath(DijkstraResult result, int target)
        {
            if (result == null)
                throw new ArgumentNullException(nameof(result));

            var path = new List<int>();

            // Если вершина недостижима
            if (!result.Distances.ContainsKey(target) ||
                double.IsPositiveInfinity(result.Distances[target]))
                return path;

            // Восстанавливает путь в обратном порядке
            int current = target;
            while (current != -1)
            {
                path.Add(current);
                current = result.PreviousVertices[current];
            }

            // Разворачиваем путь
            path.Reverse();
            return path;
        }

    }
}
