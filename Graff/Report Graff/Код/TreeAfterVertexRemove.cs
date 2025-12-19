  // Основной метод проверки
        public static void CheckVertexRemoveForTree(Graph graph)
        {
            if (graph == null)
            {
                Console.WriteLine("Граф не создан!");
                return;
            }

            Console.WriteLine("=== ПРОВЕРКА ===");

            var vertices = graph.GetVertices();

            // Вычисляем характеристики исходного графа
            Console.WriteLine($"Характеристики исходного графа:");
            Console.WriteLine($"Количество вершин: {graph.VertexCount}");
            Console.WriteLine($"Количество рёбер: {graph.EdgeCount}");
            Console.WriteLine($"Ориентированный: {(graph.IsDirected ? "да" : "нет")}");
            Console.WriteLine($"Взвешенный: {(graph.IsWeighted ? "да" : "нет")}");

            // Для неориентированных графов
            if (!graph.IsDirected)
            {
                CheckForUndirectedGraph(graph);
            }
            else
            {
                CheckForDirectedGraph(graph);
            }
        }