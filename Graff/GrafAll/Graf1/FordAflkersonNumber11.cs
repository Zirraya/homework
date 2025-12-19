using Graph1;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Graf1
{
    public class FordFulkersonAlgorithm
    {
        // Класс для хранения ребра в остаточной сети
        private class FlowEdge
        {
            public int To { get; set; }
            public double Capacity { get; set; }
            public FlowEdge Reverse { get; set; } // Ссылка на обратное ребро

            public FlowEdge(int to, double capacity)
            {
                To = to;
                Capacity = capacity;
            }
        }

        // Поиск в ширину для нахождения увеличивающего пути
        private static bool BFS(Dictionary<int, List<FlowEdge>> residualGraph,
                              int source, int sink,
                              Dictionary<int, int> parent,
                              Dictionary<int, FlowEdge> parentEdge)
        {
            Queue<int> queue = new Queue<int>();
            HashSet<int> visited = new HashSet<int>();

            queue.Enqueue(source);
            visited.Add(source);
            parent[source] = -1;

            while (queue.Count > 0)
            {
                int current = queue.Dequeue();

                foreach (var edge in residualGraph[current])
                {
                    if (!visited.Contains(edge.To) && edge.Capacity > 0)
                    {
                        parent[edge.To] = current;
                        parentEdge[edge.To] = edge;
                        visited.Add(edge.To);
                        queue.Enqueue(edge.To);

                        if (edge.To == sink)
                            return true;
                    }
                }
            }

            return false;
        }

        // Реализация алгоритма Форда-Фалкерсона
        public static double FindMaxFlow(Graph graph, int source, int sink,
                                        out Dictionary<Tuple<int, int>, double> flow)
        {
            // Проверка входных данных
            if (graph == null)
                throw new ArgumentException("Граф не задан");

            if (!graph.ContainsVertex(source))
                throw new ArgumentException($"Исходная вершина {source} не существует");

            if (!graph.ContainsVertex(sink))
                throw new ArgumentException($"Стоковая вершина {sink} не существует");

            if (source == sink)
                throw new ArgumentException("Исходная и стоковая вершины не могут совпадать");

            if (!graph.IsDirected)
                throw new ArgumentException("Алгоритм Форда-Фалкерсона работает только с ориентированными графами");

            if (!graph.IsWeighted)
                throw new ArgumentException("Алгоритм Форда-Фалкерсона работает только со взвешенными графами");

            // Инициализация остаточной сети
            Dictionary<int, List<FlowEdge>> residualGraph = new Dictionary<int, List<FlowEdge>>();

            // Копируем вершины
            foreach (var vertex in graph.GetVertices())
            {
                residualGraph[vertex] = new List<FlowEdge>();
            }

            // Копируем рёбра как рёбра с пропускной способностью
            foreach (var vertex in graph.GetVertices())
            {
                foreach (var edge in graph.GetAdjacentVertices(vertex))
                {
                    // Создаём прямое ребро с заданной пропускной способностью
                    FlowEdge forwardEdge = new FlowEdge(edge.Target, edge.Weight);
                    // Создаём обратное ребро с нулевой пропускной способностью
                    FlowEdge reverseEdge = new FlowEdge(vertex, 0);

                    // Связываем рёбра
                    forwardEdge.Reverse = reverseEdge;
                    reverseEdge.Reverse = forwardEdge;

                    // Добавляем рёбра в остаточную сеть
                    residualGraph[vertex].Add(forwardEdge);
                    residualGraph[edge.Target].Add(reverseEdge);
                }
            }

            flow = new Dictionary<Tuple<int, int>, double>();
            double maxFlow = 0;

            // Инициализируем поток нулями
            foreach (var vertex in graph.GetVertices())
            {
                foreach (var edge in graph.GetAdjacentVertices(vertex))
                {
                    flow[Tuple.Create(vertex, edge.Target)] = 0;
                }
            }

            // Основной цикл алгоритма
            Dictionary<int, int> parent = new Dictionary<int, int>();
            Dictionary<int, FlowEdge> parentEdge = new Dictionary<int, FlowEdge>();

            while (BFS(residualGraph, source, sink, parent, parentEdge))
            {
                // Находим минимальную пропускную способность на найденном пути
                double pathFlow = double.MaxValue;

                for (int v = sink; v != source; v = parent[v])
                {
                    FlowEdge edge = parentEdge[v];
                    pathFlow = Math.Min(pathFlow, edge.Capacity);
                }

                // Обновляем остаточные пропускные способности
                for (int v = sink; v != source; v = parent[v])
                {
                    FlowEdge edge = parentEdge[v];
                    FlowEdge reverseEdge = edge.Reverse;

                    // Уменьшаем пропускную способность прямого ребра
                    edge.Capacity -= pathFlow;
                    // Увеличиваем пропускную способность обратного ребра
                    reverseEdge.Capacity += pathFlow;

                    // Обновляем поток
                    int u = parent[v];
                    Tuple<int, int> edgeKey = Tuple.Create(u, v);

                    // Проверяем, существует ли ребро в исходном графе
                    bool isOriginalEdge = graph.ContainsEdge(u, v);

                    if (isOriginalEdge)
                    {
                        // Обновляем поток по прямому ребру
                        if (flow.ContainsKey(edgeKey))
                        {
                            flow[edgeKey] += pathFlow;
                        }
                        else
                        {
                            flow[edgeKey] = pathFlow;
                        }

                        // Обновляем поток по обратному ребру (если оно существует в исходном графе)
                        Tuple<int, int> reverseEdgeKey = Tuple.Create(v, u);
                        if (flow.ContainsKey(reverseEdgeKey))
                        {
                            flow[reverseEdgeKey] -= pathFlow;
                        }
                    }
                }

                // Увеличиваем общий поток
                maxFlow += pathFlow;

                // Очищаем для следующей итерации
                parent.Clear();
                parentEdge.Clear();
            }

            return maxFlow;
        }

        // Метод для демонстрации работы алгоритма с примерами
        public static void Demonstrate(Graph graph)
        {
            Console.WriteLine("=== АЛГОРИТМ ФОРДА-ФАЛКЕРСОНА ===");
            Console.WriteLine("Нахождение максимального потока в сети");

            if (graph == null)
            {
                Console.WriteLine("Граф не создан!");
                return;
            }

            if (!graph.IsDirected)
            {
                Console.WriteLine("Для работы алгоритма граф должен быть ориентированным!");
                return;
            }

            if (!graph.IsWeighted)
            {
                Console.WriteLine("Для работы алгоритма граф должен быть взвешенным (веса = пропускные способности)!");
                return;
            }

            try
            {
                int source = GetSourceVertex(graph);
                int sink = GetSinkVertex(graph, source);

                Console.WriteLine($"Исходная вершина: {source}");
                Console.WriteLine($"Стоковая вершина: {sink}");

                Dictionary<Tuple<int, int>, double> flow;
                double maxFlow = FindMaxFlow(graph, source, sink, out flow);

                Console.WriteLine($"Максимальный поток: {maxFlow:F2}");
                Console.WriteLine("\nПотоки по рёбрам:");

                foreach (var kvp in flow.OrderBy(f => f.Key.Item1).ThenBy(f => f.Key.Item2))
                {
                    if (kvp.Value > 0)
                    {
                        Console.WriteLine($"  {kvp.Key.Item1} -> {kvp.Key.Item2}: {kvp.Value:F2}");
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка: {ex.Message}");
            }
        }

        private static int GetSourceVertex(Graph graph)
        {
            // Находим вершину с нулевой входящей степенью (или минимальной)
            var vertices = graph.GetVertices();
            int source = vertices.First();
            int minInDegree = int.MaxValue;

            foreach (int vertex in vertices)
            {
                int inDegree = CalculateInDegree(graph, vertex);
                if (inDegree < minInDegree)
                {
                    minInDegree = inDegree;
                    source = vertex;
                }
            }

            return source;
        }

        private static int GetSinkVertex(Graph graph, int source)
        {
            // Находим вершину с нулевой исходящей степенью (или минимальной), отличную от source
            var vertices = graph.GetVertices();
            int sink = vertices.First(v => v != source);
            int minOutDegree = int.MaxValue;

            foreach (int vertex in vertices)
            {
                if (vertex == source) continue;

                int outDegree = graph.GetAdjacentVertices(vertex).Count;
                if (outDegree < minOutDegree)
                {
                    minOutDegree = outDegree;
                    sink = vertex;
                }
            }

            return sink;
        }

        private static int CalculateInDegree(Graph graph, int vertex)
        {
            int inDegree = 0;
            foreach (int otherVertex in graph.GetVertices())
            {
                if (graph.ContainsEdge(otherVertex, vertex))
                {
                    inDegree++;
                }
            }
            return inDegree;
        }

 

        // Метод для нахождения максимального потока с выбором вершин
        public static void FindMaxFlowInteractive(Graph graph)
        {
            if (graph == null)
            {
                Console.WriteLine("Граф не создан!");
                return;
            }

            if (!graph.IsDirected)
            {
                Console.WriteLine("Алгоритм Форда-Фалкерсона работает только с ориентированными графами!");
                return;
            }

            if (!graph.IsWeighted)
            {
                Console.WriteLine("Алгоритм Форда-Фалкерсона работает только со взвешенными графами!");
                return;
            }

            Console.WriteLine("=== НАХОЖДЕНИЕ МАКСИМАЛЬНОГО ПОТОКА ===");

            // Вывод вершин графа
            var vertices = graph.GetVertices();
            Console.WriteLine($"Доступные вершины: {string.Join(", ", vertices)}");

            // Ввод исходной вершины
            Console.Write("Введите исходную вершину (source): ");
            if (!int.TryParse(Console.ReadLine(), out int source) || !graph.ContainsVertex(source))
            {
                Console.WriteLine("Неверная исходная вершина!");
                return;
            }

            // Ввод стоковой вершины
            Console.Write("Введите стоковую вершину (sink): ");
            if (!int.TryParse(Console.ReadLine(), out int sink) || !graph.ContainsVertex(sink))
            {
                Console.WriteLine("Неверная стоковая вершина!");
                return;
            }

            if (source == sink)
            {
                Console.WriteLine("Исходная и стоковая вершины не могут совпадать!");
                return;
            }

            try
            {
                Dictionary<Tuple<int, int>, double> flow;
                double maxFlow = FindMaxFlow(graph, source, sink, out flow);

                Console.WriteLine($"\nМаксимальный поток из {source} в {sink}: {maxFlow:F2}");

                Console.WriteLine("\nПотоки по рёбрам (положительные значения):");
                bool hasFlow = false;

                foreach (var kvp in flow.OrderBy(f => f.Key.Item1).ThenBy(f => f.Key.Item2))
                {
                    if (kvp.Value > 0.001) // Используем эпсилон для сравнения с нулём
                    {
                        Console.WriteLine($"  {kvp.Key.Item1} -> {kvp.Key.Item2}: {kvp.Value:F2}");
                        hasFlow = true;
                    }
                }

                if (!hasFlow)
                {
                    Console.WriteLine("  (нет положительных потоков)");
                }

                // Вывод рёбер с нулевым потоком
                Console.WriteLine("\nРёбра с нулевым потоком:");
                var allEdges = graph.GetEdgeList();
                bool hasZeroFlow = false;

                foreach (var edge in allEdges)
                {
                    Tuple<int, int> edgeKey = Tuple.Create(edge.Item1, edge.Item2);
                    if (!flow.ContainsKey(edgeKey) || flow[edgeKey] < 0.001)
                    {
                        Console.WriteLine($"  {edge.Item1} -> {edge.Item2}");
                        hasZeroFlow = true;
                    }
                }

                if (!hasZeroFlow)
                {
                    Console.WriteLine("  (все рёбра используются)");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка: {ex.Message}");
            }
        }
    }
}
