
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