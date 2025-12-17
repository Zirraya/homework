using Graph1;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Graf1
{
    /// Класс для реализации алгоритма Флойда-Уоршелла
    /// Находит кратчайшие пути между всеми парами вершин
    /// Обнаруживает циклы отрицательного веса
  
    public static class FloydAlgorithm
    {
  
        /// Результат выполнения алгоритма Флойда-Уоршелла
     
        public class FloydResult
        {
            public double[,] Distances { get; set; }
            public int[,] Predecessors { get; set; }
            public bool HasNegativeCycle { get; set; }
            public List<int> NegativeCycle { get; set; }

            public FloydResult(int vertexCount)
            {
                Distances = new double[vertexCount, vertexCount];
                Predecessors = new int[vertexCount, vertexCount];
                HasNegativeCycle = false;
                NegativeCycle = new List<int>();
            }
        }


        /// Выполняет алгоритм Флойда-Уоршелла для заданного графа
        /// <param name="graph">Граф для анализа</param>
        /// <returns>Результат выполнения алгоритма</returns>
        public static FloydResult ExecuteFloydWarshall(Graph graph)
        {
            if (graph == null)
                throw new ArgumentNullException(nameof(graph));

            if (!graph.IsWeighted)
                throw new ArgumentException("Алгоритм Флойда-Уоршелла работает только со взвешенными графами");

            // Получаем отсортированный список вершин
            List<int> vertices = graph.GetVertices();
            int n = vertices.Count;

            // Создаем матрицы расстояний и предшественников
            FloydResult result = new FloydResult(n);

            // Инициализация матриц
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == j)
                    {
                        result.Distances[i, j] = 0;
                        result.Predecessors[i, j] = i;
                    }
                    else
                    {
                        result.Distances[i, j] = double.PositiveInfinity;
                        result.Predecessors[i, j] = -1;
                    }
                }
            }

            // Заполняем матрицу начальными расстояниями (прямыми рёбрами)
            for (int i = 0; i < n; i++)
            {
                int vertexFrom = vertices[i];
                var adjacentEdges = graph.GetAdjacentVertices(vertexFrom);

                foreach (var edge in adjacentEdges)
                {
                    int j = vertices.IndexOf(edge.Target);
                    result.Distances[i, j] = edge.Weight;
                    result.Predecessors[i, j] = i;
                }
            }

            // Основная часть алгоритма Флойда-Уоршелла
            for (int k = 0; k < n; k++)
            {
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        // Проверяем, можно ли улучшить путь через вершину k
                        if (result.Distances[i, k] != double.PositiveInfinity &&
                            result.Distances[k, j] != double.PositiveInfinity)
                        {
                            double newDistance = result.Distances[i, k] + result.Distances[k, j];

                            if (newDistance < result.Distances[i, j])
                            {
                                result.Distances[i, j] = newDistance;
                                result.Predecessors[i, j] = result.Predecessors[k, j];
                            }
                        }
                    }
                }
            }

            // Проверка на наличие циклов отрицательного веса
            for (int i = 0; i < n; i++)
            {
                if (result.Distances[i, i] < 0)
                {
                    result.HasNegativeCycle = true;
                    result.NegativeCycle = FindNegativeCycle(result, vertices, i);
                    break;
                }
            }

            return result;
        }


        /// Находит цикл отрицательного веса
        private static List<int> FindNegativeCycle(FloydResult result, List<int> vertices, int startIndex)
        {
            List<int> cycle = new List<int>();
            int n = vertices.Count;

            // Используем алгоритм для обнаружения цикла
            // Пройдем по предшественникам, чтобы найти цикл
            bool[] visited = new bool[n];
            int current = startIndex;

            while (!visited[current])
            {
                visited[current] = true;
                cycle.Add(vertices[current]);

                // Находим предшественника на пути от startIndex к current
                int pred = -1;
                for (int i = 0; i < n; i++)
                {
                    if (result.Predecessors[startIndex, i] == current && i == startIndex)
                    {
                        pred = i;
                        break;
                    }
                }

                if (pred == -1 || pred == current)
                    break;

                current = pred;

                if (cycle.Count > n) // Защита от бесконечного цикла
                    break;
            }

            // Находим начало цикла
            int cycleStart = cycle.IndexOf(vertices[current]);
            if (cycleStart >= 0)
            {
                cycle = cycle.Skip(cycleStart).ToList();
            }

            return cycle;
        }

        /// Восстанавливает путь от начальной вершины к конечной
        public static List<int> ReconstructPath(FloydResult result, List<int> vertices, int fromIndex, int toIndex)
        {
            if (result == null || vertices == null)
                throw new ArgumentNullException();

            if (fromIndex < 0 || fromIndex >= vertices.Count || toIndex < 0 || toIndex >= vertices.Count)
                throw new ArgumentOutOfRangeException();

            List<int> path = new List<int>();

            // Если путь не существует
            if (result.Distances[fromIndex, toIndex] == double.PositiveInfinity)
                return path;

            // Восстанавливаем путь в обратном порядке
            int current = toIndex;
            while (current != fromIndex)
            {
                path.Add(vertices[current]);
                current = result.Predecessors[fromIndex, current];

                if (current == -1 || path.Count > vertices.Count) // Защита от бесконечного цикла
                {
                    path.Clear();
                    return path;
                }
            }

            path.Add(vertices[fromIndex]);
            path.Reverse();
            return path;
        }

        /// Отображает результаты алгоритма Флойда-Уоршелла
        public static void DisplayResults(Graph graph, int startVertex)
        {
            try
            {
                Console.WriteLine("=== АЛГОРИТМ ФЛОЙДА-УОРШЕЛЛА ===");

                FloydResult result = ExecuteFloydWarshall(graph);

                List<int> vertices = graph.GetVertices();
                int startIndex = vertices.IndexOf(startVertex);

                if (startIndex == -1)
                {
                    Console.WriteLine($"Вершина {startVertex} не найдена в графе!");
                    return;
                }

                // Проверяем наличие циклов отрицательного веса
                if (result.HasNegativeCycle)
                {
                    Console.WriteLine("⚠ ВНИМАНИЕ: В графе обнаружен цикл отрицательного веса!");
                    Console.WriteLine($"Цикл отрицательного веса: {string.Join(" -> ", result.NegativeCycle)}");
                    Console.WriteLine("Кратчайшие пути могут быть не определены корректно!");
                    Console.WriteLine();
                }

                Console.WriteLine($"Кратчайшие пути из вершины {startVertex}:");

                // Выводим расстояния до всех вершин
                for (int i = 0; i < vertices.Count; i++)
                {
                    if (i == startIndex)
                        continue;

                    int vertex = vertices[i];
                    double distance = result.Distances[startIndex, i];

                    if (distance == double.PositiveInfinity)
                    {
                        Console.WriteLine($"  {startVertex} -> {vertex}: Нет пути");
                    }
                    else
                    {
                        Console.WriteLine($"  {startVertex} -> {vertex}: {distance:F2}");

                        // Восстанавливаем и выводим путь
                        List<int> path = ReconstructPath(result, vertices, startIndex, i);
                        if (path.Count > 0)
                        {
                            Console.WriteLine($"       Путь: {string.Join(" -> ", path)}");
                        }
                    }
                }

                // Дополнительная информация
                Console.WriteLine("\n=== МАТРИЦА РАССТОЯНИЙ ===");
                DisplayDistanceMatrix(result, vertices);

                Console.WriteLine("\n=== КРАТЧАЙШИЕ ПУТИ МЕЖДУ ВСЕМИ ПАРАМИ ===");
                DisplayAllPairsPaths(result, vertices);
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка при выполнении алгоритма Флойда: {ex.Message}");
            }
        }


        /// Отображает матрицу расстояний
        private static void DisplayDistanceMatrix(FloydResult result, List<int> vertices)
        {
            int n = vertices.Count;

            // Заголовок
            Console.Write("      ");
            for (int i = 0; i < n; i++)
            {
                Console.Write($"{vertices[i],6}");
            }
            Console.WriteLine();

            // Данные
            for (int i = 0; i < n; i++)
            {
                Console.Write($"{vertices[i],5} ");
                for (int j = 0; j < n; j++)
                {
                    if (result.Distances[i, j] == double.PositiveInfinity)
                        Console.Write("   INF");
                    else
                        Console.Write($"{result.Distances[i, j],6:F1}");
                }
                Console.WriteLine();
            }
        }

        /// Отображает кратчайшие пути между всеми парами вершин
        private static void DisplayAllPairsPaths(FloydResult result, List<int> vertices)
        {
            int n = vertices.Count;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i != j && result.Distances[i, j] != double.PositiveInfinity)
                    {
                        List<int> path = ReconstructPath(result, vertices, i, j);
                        if (path.Count > 0)
                        {
                            Console.WriteLine($"{vertices[i]} -> {vertices[j]}: {result.Distances[i, j]:F2} [{string.Join("->", path)}]");
                        }
                    }
                }
            }
        }

        /// Проверяет граф на наличие циклов отрицательного веса
        public static bool HasNegativeWeightCycle(Graph graph)
        {
            try
            {
                FloydResult result = ExecuteFloydWarshall(graph);
                return result.HasNegativeCycle;
            }
            catch
            {
                return false;
            }
        }

        /// Находит кратчайший путь между двумя конкретными вершинами
        public static Tuple<List<int>, double> FindShortestPath(Graph graph, int from, int to)
        {
            try
            {
                FloydResult result = ExecuteFloydWarshall(graph);
                List<int> vertices = graph.GetVertices();

                int fromIndex = vertices.IndexOf(from);
                int toIndex = vertices.IndexOf(to);

                if (fromIndex == -1 || toIndex == -1)
                    throw new ArgumentException("Одна или обе вершины не найдены в графе");

                List<int> path = ReconstructPath(result, vertices, fromIndex, toIndex);
                double distance = result.Distances[fromIndex, toIndex];

                return Tuple.Create(path, distance);
            }
            catch (Exception ex)
            {
                throw new InvalidOperationException($"Не удалось найти кратчайший путь: {ex.Message}");
            }
        }
    }
}
