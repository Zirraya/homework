
        // Основной метод: найти и вывести все висячие вершины
        public void FindAndPrintPendantVertices()
        {
            Console.WriteLine("=== ПОИСК ВИСЯЧИХ ВЕРШИН (СТЕПЕНИ 1) ===");

            if (graph == null || graph.VertexCount == 0)
            {
                Console.WriteLine("Граф пуст или не создан.");
                return;
            }

            // Получаем список всех висячих вершин
            List<int> pendantVertices = GetPendantVertices();

            // Выводим результат
            if (pendantVertices.Count == 0)
            {
                Console.WriteLine("В графе нет висячих вершин (степени 1).");
            }
            else
            {
                Console.WriteLine($"Найдено {pendantVertices.Count} висячих вершин:");
                foreach (int vertex in pendantVertices)
                {
                    PrintVertexInfo(vertex);
                }
            }

            // Дополнительная статистика
            PrintStatistics(pendantVertices);
        }
