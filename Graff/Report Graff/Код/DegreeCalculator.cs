
        public DegreeCalculator(Graph graph)
        {
            this.graph = graph ?? throw new ArgumentNullException(nameof(graph));
        }

        // Метод для вычисления и вывода степени каждой вершины
        public void CalculateAndPrintDegrees()
        {
            if (graph.VertexCount == 0)
            {
                Console.WriteLine("Граф пуст.");
                return;
            }

            var vertices = graph.GetVertices();

            if (!graph.IsDirected)
            {
                // Для неориентированного графа степень вершины равна количеству смежных рёбер
                Console.WriteLine("=== СТЕПЕНИ ВЕРШИН (неориентированный граф) ===");
                foreach (var vertex in vertices)
                {
                    int degree = graph.GetAdjacentVertices(vertex).Count;
                    Console.WriteLine($"Вершина {vertex}: степень {degree}");
                }
            }
            else
            {
                // Для ориентированного графа считаем полустепени исхода и захода
                Console.WriteLine("=== СТЕПЕНИ ВЕРШИН (ориентированный граф) ===");
                Console.WriteLine("(Полустепень исхода / Полустепень захода / Суммарная степень)");

                foreach (var vertex in vertices)
                {
                    int outDegree = graph.GetAdjacentVertices(vertex).Count; // смежные вершины - это исходящие рёбра
                    int inDegree = CalculateInDegree(vertex); // нужно посчитать входящие рёбра
                    int totalDegree = outDegree + inDegree;

                    Console.WriteLine($"Вершина {vertex}: исходящая = {outDegree}, входящая = {inDegree}, общая = {totalDegree}");
                }
            }
        }

        // Вспомогательный метод для вычисления полустепени захода в ориентированном графе
        private int CalculateInDegree(int vertex)
        {
            if (!graph.ContainsVertex(vertex))
                return 0;

            int inDegree = 0;
            var allVertices = graph.GetVertices();

            foreach (var v in allVertices)
            {
                if (v != vertex)
                {
                    // Проверяем, есть ли ребро из v в vertex
                    if (graph.ContainsEdge(v, vertex))
                        inDegree++;
                }
                else
                {
                    // Петля учитывается и как входящее, и как исходящее ребро
                    if (graph.ContainsEdge(vertex, vertex))
                        inDegree++;
                }
            }

            return inDegree;
        }

        // Метод для получения словаря степеней (может пригодиться для других операций)
        public Dictionary<int, int> GetDegreeDictionary()
        {
            var degreeDict = new Dictionary<int, int>();
            var vertices = graph.GetVertices();

            if (!graph.IsDirected)
            {
                foreach (var vertex in vertices)
                {
                    degreeDict[vertex] = graph.GetAdjacentVertices(vertex).Count;
                }
            }
            else
            {
                foreach (var vertex in vertices)
                {
                    int outDegree = graph.GetAdjacentVertices(vertex).Count;
                    int inDegree = CalculateInDegree(vertex);
                    degreeDict[vertex] = outDegree + inDegree;
                }
            }

            return degreeDict;
        }

        // Статический метод для быстрого использования без создания экземпляра класса
        public static void CalculateDegrees(Graph graph)
        {
            var calculator = new DegreeCalculator(graph);
            calculator.CalculateAndPrintDegrees();
        }
    }

}
