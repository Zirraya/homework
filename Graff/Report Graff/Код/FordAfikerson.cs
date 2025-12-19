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