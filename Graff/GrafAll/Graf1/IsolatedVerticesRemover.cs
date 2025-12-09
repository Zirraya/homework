using Graph1;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Graf1
{
    public class IsolatedVerticesRemover
    {
        private Graph originalGraph;

        public IsolatedVerticesRemover(Graph graph)
        {
            this.originalGraph = graph ?? throw new ArgumentNullException(nameof(graph));
        }

        // Основной метод: создать новый орграф с удалением изолированных вершин
        public Graph RemoveIsolatedVertices()
        {
            if (originalGraph.VertexCount == 0)
            {
                Console.WriteLine("Исходный граф пуст.");
                return new Graph(originalGraph.IsDirected, originalGraph.IsWeighted);
            }

            // Находим все изолированные вершины
            List<int> isolatedVertices = GetIsolatedVertices();

            Console.WriteLine($"Найдено изолированных вершин: {isolatedVertices.Count}");

            // Создаем новый граф с теми же параметрами
            Graph newGraph = new Graph(originalGraph.IsDirected, originalGraph.IsWeighted);

            // Копируем все вершины, кроме изолированных
            CopyVerticesWithoutIsolated(newGraph, isolatedVertices);

            // Копируем все ребра
            CopyEdges(newGraph, isolatedVertices);

            return newGraph;
        }

        // Получить список изолированных вершин
        public List<int> GetIsolatedVertices()
        {
            List<int> isolatedVertices = new List<int>();

            foreach (int vertex in originalGraph.GetVertices())
            {
                if (IsIsolatedVertex(vertex))
                {
                    isolatedVertices.Add(vertex);
                }
            }

            return isolatedVertices;
        }

        // Проверка, является ли вершина изолированной
        public bool IsIsolatedVertex(int vertex)
        {
            if (!originalGraph.ContainsVertex(vertex))
                return false;

            if (!originalGraph.IsDirected)
            {
                // Для неориентированного графа: нет инцидентных ребер
                return originalGraph.GetAdjacentVertices(vertex).Count == 0;
            }
            else
            {
                // Для ориентированного графа: нет входящих и исходящих ребер
                int outDegree = originalGraph.GetAdjacentVertices(vertex).Count;
                int inDegree = CalculateInDegree(vertex);
                return outDegree == 0 && inDegree == 0;
            }
        }

        // Вычисление полустепени захода (для ориентированного графа)
        private int CalculateInDegree(int vertex)
        {
            if (!originalGraph.ContainsVertex(vertex))
                return 0;

            int inDegree = 0;
            foreach (int otherVertex in originalGraph.GetVertices())
            {
                if (originalGraph.ContainsEdge(otherVertex, vertex))
                {
                    inDegree++;
                }
            }
            return inDegree;
        }

        // Копирование вершин без изолированных
        private void CopyVerticesWithoutIsolated(Graph newGraph, List<int> isolatedVertices)
        {
            foreach (int vertex in originalGraph.GetVertices())
            {
                if (!isolatedVertices.Contains(vertex))
                {
                    try
                    {
                        newGraph.AddVertex(vertex);
                    }
                    catch (ArgumentException)
                    {
                        // Вершина уже существует (маловероятно, но на всякий случай)
                    }
                }
            }
        }

        // Копирование ребер
        private void CopyEdges(Graph newGraph, List<int> isolatedVertices)
        {
            foreach (int fromVertex in originalGraph.GetVertices())
            {
                // Пропускаем изолированные вершины (как источники)
                if (isolatedVertices.Contains(fromVertex))
                    continue;

                foreach (var edge in originalGraph.GetAdjacentVertices(fromVertex))
                {
                    int toVertex = edge.Target;

                    // Пропускаем изолированные вершины (как цели)
                    if (isolatedVertices.Contains(toVertex))
                        continue;

                    // Пропускаем ребра, где обе вершины изолированные (хотя это невозможно)
                    if (isolatedVertices.Contains(fromVertex) && isolatedVertices.Contains(toVertex))
                        continue;

                    try
                    {
                        newGraph.AddEdge(fromVertex, toVertex, edge.Weight);
                    }
                    catch (ArgumentException ex)
                    {
                        // Игнорируем только ошибку "ребро уже существует"
                        if (!ex.Message.Contains("уже существует"))
                        {
                            Console.WriteLine($"Ошибка при копировании ребра {fromVertex} -> {toVertex}: {ex.Message}");
                        }
                    }
                }
            }
        }

        // Статический метод для быстрого использования
        public static Graph CreateGraphWithoutIsolatedVertices(Graph originalGraph)
        {
            IsolatedVerticesRemover remover = new IsolatedVerticesRemover(originalGraph);
            return remover.RemoveIsolatedVertices();
        }

        // Метод для демонстрации работы
        public static void Demonstrate(Graph originalGraph)
        {
            Console.WriteLine("=== УДАЛЕНИЕ ИЗОЛИРОВАННЫХ ВЕРШИН ===");
            Console.WriteLine("\nИсходный граф:");
            Console.WriteLine($"Тип: {(originalGraph.IsDirected ? "Ориентированный" : "Неориентированный")}");
            Console.WriteLine($"Вершин: {originalGraph.VertexCount}, Рёбер: {originalGraph.EdgeCount}");

            IsolatedVerticesRemover remover = new IsolatedVerticesRemover(originalGraph);

            // Находим изолированные вершины
            List<int> isolated = remover.GetIsolatedVertices();
            if (isolated.Count > 0)
            {
                Console.WriteLine($"Изолированные вершины: {string.Join(", ", isolated)}");
            }
            else
            {
                Console.WriteLine("Изолированных вершин нет.");
            }

            // Создаем новый граф без изолированных вершин
            Graph newGraph = remover.RemoveIsolatedVertices();

            Console.WriteLine("\nНовый граф (без изолированных вершин):");
            Console.WriteLine($"Тип: {(newGraph.IsDirected ? "Ориентированный" : "Неориентированный")}");
            Console.WriteLine($"Вершин: {newGraph.VertexCount}, Рёбер: {newGraph.EdgeCount}");

            Console.WriteLine("\nСписок смежности нового графа:");
            Console.WriteLine(newGraph.GetAdjacencyListString());

            Console.WriteLine("\nСравнение:");
            Console.WriteLine($"Удалено вершин: {originalGraph.VertexCount - newGraph.VertexCount}");
            Console.WriteLine($"Удалено рёбер: {originalGraph.EdgeCount - newGraph.EdgeCount}");
        }
    }
}



