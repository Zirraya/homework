
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

   