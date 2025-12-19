using Graph1;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Graph1
{
    // Класс для проверки возможности удаления вершины для получения дерева
    public static class TreeAfterVertexRemove
    {
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

        // Проверка для неориентированного графа
        private static void CheckForUndirectedGraph(Graph graph)
        {
            Console.WriteLine("\n--- Проверка для неориентированного графа ---");

            var vertices = graph.GetVertices();
            var validRemovals = new List<int>();

            foreach (var vertex in vertices)
            {
                // Создаём копию графа и удаляем вершину
                Graph graphCopy = new Graph(graph);
                try
                {
                    graphCopy.RemoveVertex(vertex);

                    // Проверяем, является ли полученный граф деревом
                    if (IsTree(graphCopy))
                    {
                        validRemovals.Add(vertex);
                        Console.WriteLine($"Удаление вершины {vertex} приводит к дереву:");
                        Console.WriteLine($"  Вершин осталось: {graphCopy.VertexCount}");
                        Console.WriteLine($"  Рёбер осталось: {graphCopy.EdgeCount}");
                        Console.WriteLine($"  Связный: {IsConnected(graphCopy)}");
                        Console.WriteLine($"  Нет циклов: {!HasCycleUndirected(graphCopy)}");
                    }
                }
                catch (Exception ex)
                {
                    // Вершина не может быть удалена
                }
            }

            // Вывод результатов
            if (validRemovals.Count == 0)
            {
                Console.WriteLine("\nНЕВОЗМОЖНО получить дерево удалением одной вершины.");
            }
            else
            {
                Console.WriteLine($"\nМОЖНО получить дерево удалением одной вершины.");
                Console.WriteLine($"Подходящие вершины для удаления: {string.Join(", ", validRemovals.OrderBy(v => v))}");

                // Если есть несколько вариантов, предлагаем выбрать лучший
                if (validRemovals.Count > 1)
                {
                    // Находим вершину, удаление которой даёт дерево с максимальным количеством вершин
                    int bestVertex = FindBestVertexToRemove(graph, validRemovals);
                    Console.WriteLine($"\nРекомендуемая вершина для удаления: {bestVertex} " +
                                     $"(максимальное сохранение вершин)");

                    // Показываем получившееся дерево
                    ShowResultingTree(graph, bestVertex);
                }
                else
                {
                    // Показываем получившееся дерево для единственного варианта
                    ShowResultingTree(graph, validRemovals[0]);
                }
            }

            // Дополнительный анализ
            AnalyzeGraphForTreeConversion(graph);
        }

        // Проверка для ориентированного графа
        private static void CheckForDirectedGraph(Graph graph)
        {
            var vertices = graph.GetVertices();
            var validRemovals = new List<int>();

            foreach (var vertex in vertices)
            {
                // Создаём копию графа и удаляем вершину
                Graph graphCopy = new Graph(graph);
                try
                {
                    graphCopy.RemoveVertex(vertex);

                    // Проверяем, является ли полученный граф ориентированным деревом
                    if (IsDirectedTree(graphCopy))
                    {
                        validRemovals.Add(vertex);
                    }
                }
                catch (Exception ex)
                {
                    // Вершина не может быть удалена
                }
            }

            // Вывод результатов
            if (validRemovals.Count == 0)
            {
                Console.WriteLine("Невозможно получить ориентированное дерево удалением одной вершины.");
            }
            else
            {
                Console.WriteLine($"Можно получить ориентированное дерево удалением вершины/вершин.");
                Console.WriteLine($"Подходящие вершины для удаления: {string.Join(", ", validRemovals.OrderBy(v => v))}");
            }
        }

        // Проверка, является ли граф деревом (для неориентированного графа)
        private static bool IsTree(Graph graph)
        {
            // Граф должен быть неориентированным
            if (graph.IsDirected) return false;

            // Дерево должно быть связным и не иметь циклов
            return IsConnected(graph) && !HasCycleUndirected(graph);
        }

        // Проверка, является ли граф ориентированным деревом
        private static bool IsDirectedTree(Graph graph)
        {
            // В ориентированном дереве должна быть одна корневая вершина (полустепень захода = 0)
            // и все остальные вершины должны иметь полустепень захода = 1
            var vertices = graph.GetVertices();

            if (vertices.Count == 0) return true;

            // Вычисляем полустепени захода
            var inDegree = new Dictionary<int, int>();
            foreach (var vertex in vertices)
            {
                inDegree[vertex] = 0;
            }

            foreach (var vertex in vertices)
            {
                foreach (var edge in graph.GetAdjacentVertices(vertex))
                {
                    inDegree[edge.Target]++;
                }
            }

            // Считаем вершины с разными полустепенями захода
            int zeroInDegree = inDegree.Count(kv => kv.Value == 0);
            int oneInDegree = inDegree.Count(kv => kv.Value == 1);

            // Должна быть ровно одна вершина с полустепенью захода 0 (корень)
            // и все остальные вершины должны иметь полустепень захода 1
            if (zeroInDegree != 1) return false;
            if (oneInDegree != vertices.Count - 1) return false;

            // Также граф должен быть связным (в слабом смысле)
            return IsConnected(ConvertToUndirected(graph));
        }

        // Проверка связности графа
        private static bool IsConnected(Graph graph)
        {
            var vertices = graph.GetVertices();
            if (vertices.Count == 0) return true;

            var visited = new HashSet<int>();
            DFS(graph, vertices[0], visited);

            return visited.Count == vertices.Count;
        }

        // Проверка наличия циклов в неориентированном графе
        private static bool HasCycleUndirected(Graph graph)
        {
            var vertices = graph.GetVertices();
            var visited = new HashSet<int>();

            foreach (var vertex in vertices)
            {
                if (!visited.Contains(vertex))
                {
                    if (HasCycleDFS(graph, vertex, -1, visited))
                    {
                        return true;
                    }
                }
            }

            return false;
        }

        // Рекурсивный DFS для поиска циклов в неориентированном графе
        private static bool HasCycleDFS(Graph graph, int vertex, int parent, HashSet<int> visited)
        {
            visited.Add(vertex);

            foreach (var edge in graph.GetAdjacentVertices(vertex))
            {
                if (!visited.Contains(edge.Target))
                {
                    if (HasCycleDFS(graph, edge.Target, vertex, visited))
                    {
                        return true;
                    }
                }
                else if (edge.Target != parent)
                {
                    return true;
                }
            }

            return false;
        }

        // Обход в глубину
        private static void DFS(Graph graph, int vertex, HashSet<int> visited)
        {
            visited.Add(vertex);

            foreach (var edge in graph.GetAdjacentVertices(vertex))
            {
                if (!visited.Contains(edge.Target))
                {
                    DFS(graph, edge.Target, visited);
                }
            }
        }

        // Конвертация ориентированного графа в неориентированный для проверки связности
        private static Graph ConvertToUndirected(Graph directedGraph)
        {
            Graph undirected = new Graph(false, directedGraph.IsWeighted);

            // Добавляем все вершины
            foreach (var vertex in directedGraph.GetVertices())
            {
                undirected.AddVertex(vertex);
            }

            // Добавляем рёбра в обоих направлениях
            foreach (var vertex in directedGraph.GetVertices())
            {
                foreach (var edge in directedGraph.GetAdjacentVertices(vertex))
                {
                    try
                    {
                        undirected.AddEdge(vertex, edge.Target, edge.Weight);
                    }
                    catch
                    {
                        // Ребро уже существует
                    }
                }
            }

            return undirected;
        }

        // Нахождение лучшей вершины для удаления
        private static int FindBestVertexToRemove(Graph originalGraph, List<int> candidates)
        {
            int bestVertex = candidates[0];
            int maxVertices = 0;

            foreach (var vertex in candidates)
            {
                Graph graphCopy = new Graph(originalGraph);
                graphCopy.RemoveVertex(vertex);

                if (graphCopy.VertexCount > maxVertices)
                {
                    maxVertices = graphCopy.VertexCount;
                    bestVertex = vertex;
                }
            }

            return bestVertex;
        }

        // Показ получившегося дерева
        private static void ShowResultingTree(Graph originalGraph, int vertexToRemove)
        {
        
            Graph resultGraph = new Graph(originalGraph);
            resultGraph.RemoveVertex(vertexToRemove);

            Console.WriteLine("Список смежности получившегося дерева:");
            Console.WriteLine(resultGraph.GetAdjacencyListString());

            Console.WriteLine("\nХарактеристики дерева:");
            Console.WriteLine($"Вершин: {resultGraph.VertexCount}");
            Console.WriteLine($"Рёбер: {resultGraph.EdgeCount}");

            // Дерево должно иметь V-1 рёбер
            if (resultGraph.EdgeCount == resultGraph.VertexCount - 1)
            {
                Console.WriteLine(" Соотношение вершин и рёбер корректно для дерева");
            }
            else
            {
                Console.WriteLine($" Несоответствие: для дерева должно быть {resultGraph.VertexCount - 1} рёбер");
            }
        }

        // Анализ графа для конвертации в дерево
        private static void AnalyzeGraphForTreeConversion(Graph graph)
        {
            var vertices = graph.GetVertices();
            int edgeCount = graph.EdgeCount;
            int vertexCount = graph.VertexCount;

            Console.WriteLine($"Всего вершин: {vertexCount}");
            Console.WriteLine($"Всего рёбер: {edgeCount}");

            // Для дерева должно быть V-1 рёбер
            int expectedEdgesForTree = vertexCount - 1;
            Console.WriteLine($"Для дерева из {vertexCount} вершин нужно {expectedEdgesForTree} рёбер");

            // Вычисляем, сколько рёбер нужно добавить или удалить
            int edgesDifference = edgeCount - expectedEdgesForTree;

            if (edgesDifference > 0)
            {
                Console.WriteLine($"Нужно удалить {edgesDifference} рёбер чтобы получить дерево");
            }
            else if (edgesDifference < 0)
            {
                Console.WriteLine($"Нужно добавить {-edgesDifference} рёбер чтобы получить дерево");
            }
            else
            {
                Console.WriteLine($"Граф уже имеет правильное количество рёбер для дерева");
            }

            // Анализ циклов
            if (HasCycleUndirected(graph))
            {
                Console.WriteLine("Граф содержит циклы");
            }
            else
            {
                Console.WriteLine("Граф не содержит циклов");
            }

            // Анализ связности
            if (IsConnected(graph))
            {
                Console.WriteLine("Граф связный");
            }
            else
            {
                Console.WriteLine("Граф не связный (имеет несколько компонент связности)");
            }

            // Анализ степеней вершин
            Console.WriteLine("\nСтепени вершин:");
            foreach (var vertex in vertices.OrderBy(v => v))
            {
                int degree = graph.GetAdjacentVertices(vertex).Count;
                Console.WriteLine($"Вершина {vertex}: степень {degree}");
            }
        }
    }
}



