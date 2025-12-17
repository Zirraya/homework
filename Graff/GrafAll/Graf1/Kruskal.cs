using Graph1;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Graf1
{
    public static class KruskalAlgorithm
    {
        // Класс для хранения информации о ребре с сортировкой по весу
        public class EdgeInfo : IComparable<EdgeInfo>
        {
            public int From { get; set; }
            public int To { get; set; }
            public double Weight { get; set; }

            public EdgeInfo(int from, int to, double weight)
            {
                From = from;
                To = to;
                Weight = weight;
            }

            public int CompareTo(EdgeInfo other)
            {
                return Weight.CompareTo(other.Weight);
            }
        }

        // Класс для системы непересекающихся множеств (DSU/Union-Find)
        private class DisjointSetUnion
        {
            private int[] parent;
            private int[] rank;

            public DisjointSetUnion(int size)
            {
                parent = new int[size];
                rank = new int[size];

                // Изначально каждая вершина - отдельное множество
                for (int i = 0; i < size; i++)
                {
                    parent[i] = i;
                    rank[i] = 0;
                }
            }

            // Найти корень множества с path compression
            public int Find(int x)
            {
                if (parent[x] != x)
                    parent[x] = Find(parent[x]);
                return parent[x];
            }

            // Объединить два множества по рангу
            public bool Union(int x, int y)
            {
                int rootX = Find(x);
                int rootY = Find(y);

                if (rootX == rootY)
                    return false; // Уже в одном множестве

                // Объединение по рангу
                if (rank[rootX] < rank[rootY])
                {
                    parent[rootX] = rootY;
                }
                else if (rank[rootX] > rank[rootY])
                {
                    parent[rootY] = rootX;
                }
                else
                {
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }

                return true;
            }
        }

     
        /// Находит минимальное остовное дерево (каркас минимального веса) с помощью алгоритма Краскала

        /// <param name="graph">Исходный граф</param>
        /// <returns>Новый граф, представляющий минимальное остовное дерево</returns>
        public static Graph FindMinimumSpanningTree(Graph graph)
        {
            // Проверка, что граф неориентированный и взвешенный
            if (graph.IsDirected)
            {
                throw new ArgumentException("Алгоритм Краскала работает только с неориентированными графами");
            }

            if (!graph.IsWeighted)
            {
                throw new ArgumentException("Граф должен быть взвешенным для поиска минимального остовного дерева");
            }

            // Получение всех вершин
            var vertices = graph.GetVertices();
            if (vertices.Count == 0)
            {
                throw new ArgumentException("Граф пустой");
            }

            // Создания словарь для отображения номеров вершин в индексы от 0 до N-1
            Dictionary<int, int> vertexToIndex = new Dictionary<int, int>();
            Dictionary<int, int> indexToVertex = new Dictionary<int, int>();

            for (int i = 0; i < vertices.Count; i++)
            {
                vertexToIndex[vertices[i]] = i;
                indexToVertex[i] = vertices[i];
            }

            // Собираем все ребра
            List<EdgeInfo> allEdges = new List<EdgeInfo>();

            foreach (var vertex in vertices)
            {
                var adjacentEdges = graph.GetAdjacentVertices(vertex);
                foreach (var edge in adjacentEdges)
                {
                    // Добавляем каждое ребро только один раз (From < To)
                    if (vertex < edge.Target)
                    {
                        allEdges.Add(new EdgeInfo(vertex, edge.Target, edge.Weight));
                    }
                }
            }

            // Сортируем ребра по весу
            allEdges.Sort();

            // Инициализируем DSU
            DisjointSetUnion dsu = new DisjointSetUnion(vertices.Count);

            // Создаем новый граф для остовного дерева
            Graph mstGraph = new Graph(false, true);

            // Добавляем все вершины в новый граф
            foreach (var vertex in vertices)
            {
                mstGraph.AddVertex(vertex);
            }

            double totalWeight = 0;
            int edgesAdded = 0;
            List<EdgeInfo> mstEdges = new List<EdgeInfo>();

            // Проходим по всем ребрам в порядке возрастания веса
            foreach (var edge in allEdges)
            {
                int indexFrom = vertexToIndex[edge.From];
                int indexTo = vertexToIndex[edge.To];

                // Если ребро соединяет разные компоненты связности
                if (dsu.Union(indexFrom, indexTo))
                {
                    // Добавляем ребро в остовное дерево
                    mstGraph.AddEdge(edge.From, edge.To, edge.Weight);
                    mstEdges.Add(edge);
                    totalWeight += edge.Weight;
                    edgesAdded++;

                    // Если добавили N-1 ребро, остовное дерево построено
                    if (edgesAdded == vertices.Count - 1)
                        break;
                }
            }

            // Проверка, что граф связный (для связного графа должно быть ровно N-1 ребро в MST)
            if (edgesAdded < vertices.Count - 1)
            {
                Console.WriteLine("Внимание: Граф не является связным. Построен минимальный остовный лес.");
            }

            // Вывод
            Console.WriteLine("=== РЕЗУЛЬТАТЫ АЛГОРИТМА КРАСКАЛА ===");
            Console.WriteLine($"Всего вершин: {vertices.Count}");
            Console.WriteLine($"Всего ребер в исходном графе: {graph.EdgeCount}");
            Console.WriteLine($"Ребер в минимальном остовном дереве: {edgesAdded}");
            Console.WriteLine($"Общий вес остовного дерева: {totalWeight:F2}");
            Console.WriteLine();
            Console.WriteLine("Ребра минимального остовного дерева:");

            foreach (var edge in mstEdges.OrderBy(e => e.From).ThenBy(e => e.To))
            {
                Console.WriteLine($"{edge.From} -- {edge.To} (вес: {edge.Weight:F2})");
            }

            Console.WriteLine();
            Console.WriteLine("Список смежности минимального остовного дерева:");
            Console.WriteLine(mstGraph.GetAdjacencyListString());

            return mstGraph;
        }
    }
}
