using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Graph1
{
    // Класс для нахождения корня в ацикличном орграфе
    public static class RootFinder
    {
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

        // Проверяет, является ли вершина корнем (существуют ли пути из неё во все остальные вершины)
        private static bool IsRoot(Graph graph, int startVertex)
        {
            var vertices = graph.GetVertices();
            var visited = new HashSet<int>();

            // Запускаем DFS из стартовой вершины
            DFS(graph, startVertex, visited);

            // Проверяем, посетили ли мы все вершины
            return visited.Count == vertices.Count;
        }

        // Обход в глубину (DFS)
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

        // Проверка графа на ацикличность с помощью топологической сортировки
        private static bool IsAcyclic(Graph graph)
        {
            var vertices = graph.GetVertices();
            var visited = new HashSet<int>();
            var inStack = new HashSet<int>();

            foreach (var vertex in vertices)
            {
                if (!visited.Contains(vertex))
                {
                    if (HasCycleDFS(graph, vertex, visited, inStack))
                    {
                        return false; // Найден цикл
                    }
                }
            }

            return true; // Граф ацикличен
        }

        // Рекурсивный DFS для проверки на циклы
        private static bool HasCycleDFS(Graph graph, int vertex, HashSet<int> visited, HashSet<int> inStack)
        {
            visited.Add(vertex);
            inStack.Add(vertex);

            foreach (var edge in graph.GetAdjacentVertices(vertex))
            {
                if (!visited.Contains(edge.Target))
                {
                    if (HasCycleDFS(graph, edge.Target, visited, inStack))
                    {
                        return true;
                    }
                }
                else if (inStack.Contains(edge.Target))
                {
                    return true; // Найден цикл
                }
            }

            inStack.Remove(vertex);
            return false;
        }

        // Альтернативный алгоритм: поиск корня через вершины с нулевой полустепенью захода
        public static void FindRootAlternative(Graph graph)
        {
            if (graph == null)
            {
                Console.WriteLine("Граф не создан!");
                return;
            }

            if (!graph.IsDirected)
            {
                Console.WriteLine("Граф должен быть ориентированным!");
                return;
            }

            Console.WriteLine("Альтернативный поиск");

            var vertices = graph.GetVertices();

            // Вычисляем полустепени захода для всех вершин
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

            Console.WriteLine("Полустепени захода вершин:");
            foreach (var vertex in vertices.OrderBy(v => v))
            {
                Console.WriteLine($"Вершина {vertex}: {inDegree[vertex]}");
            }

            // Ищем вершины с нулевой полустепенью захода
            var zeroInDegreeVertices = vertices.Where(v => inDegree[v] == 0).ToList();

            if (zeroInDegreeVertices.Count == 0)
            {
                Console.WriteLine("Вершин с нулевой полустепенью захода не найдено.");
                return;
            }

            Console.WriteLine($"\nВершины с нулевой полустепенью захода: {string.Join(", ", zeroInDegreeVertices)}");

            // Проверяем, является ли какая-то из этих вершин корнем
            foreach (var vertex in zeroInDegreeVertices)
            {
                if (IsRoot(graph, vertex))
                {
                    Console.WriteLine($"\nКорень найден: вершина {vertex}");
                    return;
                }
            }

            Console.WriteLine("Ни одна из вершин с нулевой полустепенью захода не является корнем.");
        }

    }
}
