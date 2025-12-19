 // Основной метод для проверки наличия корня в ацикличном орграфе
        public static void FindRootInDAG(Graph graph)
        {
            if (graph == null)
            {
                Console.WriteLine("Граф не создан!");
                return;
            }

            // Проверяем, что граф ориентированный
            if (!graph.IsDirected)
            {
                Console.WriteLine("Граф должен быть ориентированным!");
                return;
            }

            // Проверяем, что граф ацикличен
            if (!IsAcyclic(graph))
            {
                Console.WriteLine("Граф содержит циклы! Алгоритм работает только для ациклических графов.");
                return;
            }

            // Получаем список вершин
            var vertices = graph.GetVertices();

            // Для каждой вершины проверяем, является ли она корнем
            var potentialRoots = new List<int>();

            foreach (var vertex in vertices)
            {
                if (IsRoot(graph, vertex))
                {
                    potentialRoots.Add(vertex);
                }
            }

            // Выводим результат
            if (potentialRoots.Count == 0)
            {
                Console.WriteLine("В орграфе нет корня.");
            }
            else if (potentialRoots.Count == 1)
            {
                Console.WriteLine($"Корень найден: вершина {potentialRoots[0]}");
            }
            else
            {
                Console.WriteLine($"Найдено несколько вершин-корней: {string.Join(", ", potentialRoots)}");
            }
        }

       
          