
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