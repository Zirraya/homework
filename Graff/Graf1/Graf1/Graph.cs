using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using Json.Net;


// Тут все для графа

namespace Graph1
{

    // Клааааас для графа
    public class Graph
    {
        private Dictionary<int, List<Edge>> adjacencyList;
        public bool IsDirected { get; private set; }
        public bool IsWeighted { get; private set; }

        // Конструктор по умолчанию
        public Graph(bool directed = false, bool weighted = false)
        {
            adjacencyList = new Dictionary<int, List<Edge>>();
            IsDirected = directed;
            IsWeighted = weighted;
        }

        // Конструктор из файла
        public Graph(string filename)
        {
            adjacencyList = new Dictionary<int, List<Edge>>();

            try
            {
                string[] lines = File.ReadAllLines(filename);

                if (lines.Length < 2)
                    throw new ArgumentException("Файл должен содержать как минимум 2 строки");

                // Первая строка - параметры графа
                string[] parameters = lines[0].Split(' ');
                if (parameters.Length < 2)
                    throw new ArgumentException("Неверный формат параметров графа");

                IsDirected = parameters[0] == "directed";
                IsWeighted = parameters[1] == "weighted";
                //

                // Остальные строки - список смежности
                for (int i = 1; i < lines.Length; i++)
                {
                    string[] parts = lines[i].Split(':');
                    if (parts.Length != 2)
                        throw new ArgumentException($"Неверный формат строки {i + 1}");

                    int vertex = int.Parse(parts[0].Trim());
                    AddVertex(vertex);
                    //

                    if (!string.IsNullOrWhiteSpace(parts[1]))
                    {
                        string[] edges = parts[1].Split(',');
                        foreach (string edgeStr in edges)
                        {
                            string[] edgeParts = edgeStr.Trim().Split(' ');
                            if (edgeParts.Length == 0) continue;

                            int target = int.Parse(edgeParts[0]);
                            double weight = IsWeighted && edgeParts.Length > 1 ?
                                          double.Parse(edgeParts[1]) : 1.0;

                            AddEdge(vertex, target, weight);
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                throw new ArgumentException($"Ошибка чтения файла: {ex.Message}");
            }
        }

        // Конструктор копирования
        public Graph(Graph other)
        {
            if (other == null)
                throw new ArgumentNullException(nameof(other));

            IsDirected = other.IsDirected;
            IsWeighted = other.IsWeighted;
            adjacencyList = new Dictionary<int, List<Edge>>();

            foreach (var vertex in other.adjacencyList)
            {
                adjacencyList[vertex.Key] = new List<Edge>();
                foreach (var edge in vertex.Value)
                {
                    adjacencyList[vertex.Key].Add(new Edge(edge.Target, edge.Weight));
                }
            }
        }
        //

        // Конструктор для тестирования (из списка рёбер)
        public Graph(List<Tuple<int, int>> edges, bool directed = false, bool weighted = false)
        {
            adjacencyList = new Dictionary<int, List<Edge>>();
            IsDirected = directed;
            IsWeighted = weighted;

            foreach (var edge in edges)
            {
                AddVertex(edge.Item1);
                AddVertex(edge.Item2);
                AddEdge(edge.Item1, edge.Item2);
            }
        }
        //

        // Конструктор для тестирования (из матрицы смежности)
        public Graph(int[,] matrix, bool directed = false, bool weighted = false)
        {
            adjacencyList = new Dictionary<int, List<Edge>>();
            IsDirected = directed;
            IsWeighted = weighted;

            int size = matrix.GetLength(0);
            for (int i = 0; i < size; i++)
            {
                AddVertex(i);
                for (int j = 0; j < size; j++)
                {
                    if (matrix[i, j] != 0)
                    {
                        AddEdge(i, j, matrix[i, j]);
                    }
                }
            }
        }
        //

        // Работа с вершинами //

        // Добавление вершины
        public void AddVertex(int vertex)
        {
            if (adjacencyList.ContainsKey(vertex))
                throw new ArgumentException($"Вершина {vertex} уже существует");

            adjacencyList[vertex] = new List<Edge>();
        }
        //

        // Удаление вершины
        public void RemoveVertex(int vertex)
        {
            if (!adjacencyList.ContainsKey(vertex))
                throw new ArgumentException($"Вершина {vertex} не существует");

            // Удаляем все рёбра, ведущие к этой вершине
            foreach (var v in adjacencyList.Keys.ToList())
            {
                if (v != vertex)
                {
                    adjacencyList[v].RemoveAll(e => e.Target == vertex);
                }
            }

            adjacencyList.Remove(vertex);
        }
        //
        //

        // Работа с ребрами/дугами

        // Добавление ребра/дуги
        public void AddEdge(int from, int to, double weight = 1.0)
        {
            if (!adjacencyList.ContainsKey(from))
                throw new ArgumentException($"Вершина {from} не существует");
            if (!adjacencyList.ContainsKey(to))
                throw new ArgumentException($"Вершина {to} не существует");
            if (from == to && !IsDirected)
                throw new ArgumentException("Петли разрешены только в ориентированных графах");

            // Проверка на существующее ребро (не мультиграф)
            if (adjacencyList[from].Any(e => e.Target == to))
                throw new ArgumentException($"Ребро из {from} в {to} уже существует");

            adjacencyList[from].Add(new Edge(to, weight));

            // Для неориентированного графа добавляем обратное ребро
            if (!IsDirected && from != to)
            {
                if (adjacencyList[to].Any(e => e.Target == from))
                    throw new ArgumentException($"Ребро из {to} в {from} уже существует");
                adjacencyList[to].Add(new Edge(from, weight));
            }
        }
        //

        // Удаление ребра/дуги
        public void RemoveEdge(int from, int to)
        {
            if (!adjacencyList.ContainsKey(from))
                throw new ArgumentException($"Вершина {from} не существует");
            if (!adjacencyList.ContainsKey(to))
                throw new ArgumentException($"Вершина {to} не существует");

            int removedCount = adjacencyList[from].RemoveAll(e => e.Target == to);

            if (removedCount == 0)
                throw new ArgumentException($"Ребро из {from} в {to} не существует");

            // Для неориентированного графа удаляем обратное ребро
            if (!IsDirected && from != to)
            {
                adjacencyList[to].RemoveAll(e => e.Target == from);
            }
        }
        //
        //

        // Получение списка смежности в виде строки
        public string GetAdjacencyListString()
        {
            var result = new List<string>();
            foreach (var vertex in adjacencyList.OrderBy(v => v.Key))
            {
                string edges = string.Join(", ", vertex.Value
                    .OrderBy(e => e.Target)
                    .Select(e => IsWeighted ? $"{e.Target} {e.Weight}" : e.Target.ToString()));

                result.Add($"{vertex.Key}: {edges}");
            }
            return string.Join(Environment.NewLine, result);
        }
        //

        // Запись в файл
        public void SaveToFile(string filename)
        {
            try
            {
                string output = $"{(IsDirected ? "directed" : "undirected")} {(IsWeighted ? "weighted" : "unweighted")}\n";
                output += GetAdjacencyListString();

                File.WriteAllText(filename, output);
            }
            catch (UnauthorizedAccessException ex)
            {
                throw new ArgumentException($"Нет прав доступа для записи в файл: {filename}", ex);
            }
            catch (DirectoryNotFoundException ex)
            {
                throw new ArgumentException($"Директория не найдена: {Path.GetDirectoryName(filename)}", ex);
            }
            catch (IOException ex)
            {
                throw new ArgumentException($"Ошибка ввода-вывода при записи файла: {ex.Message}", ex);
            }
            catch (ArgumentException ex)
            {
                throw;
            }
            catch (Exception ex)
            {
                throw new ArgumentException($"Неожиданная ошибка при записи в файл: {ex.Message}", ex);
            }
        }
        //

        // Получение списка рёбер
        public List<Tuple<int, int, double>> GetEdgeList()
        {
            var edges = new List<Tuple<int, int, double>>();
            var processed = new HashSet<string>();

            foreach (var vertex in adjacencyList)
            {
                foreach (var edge in vertex.Value)
                {
                    string key = IsDirected ? $"{vertex.Key}-{edge.Target}" :
                        string.Compare(vertex.Key.ToString(), edge.Target.ToString()) < 0 ?
                        $"{vertex.Key}-{edge.Target}" : $"{edge.Target}-{vertex.Key}";

                    if (!processed.Contains(key))
                    {
                        edges.Add(Tuple.Create(vertex.Key, edge.Target, edge.Weight));
                        processed.Add(key);
                    }
                }
            }

            return edges;
        }
        //

        // Получение вершин
        public List<int> GetVertices()
        {
            return adjacencyList.Keys.OrderBy(v => v).ToList();
        }
        //

        // Получение смежных вершин
        public List<Edge> GetAdjacentVertices(int vertex)
        {
            if (!adjacencyList.ContainsKey(vertex))
                throw new ArgumentException($"Вершина {vertex} не существует");

            return new List<Edge>(adjacencyList[vertex]);
        }
        //

        // Проверка существования вершины
        public bool ContainsVertex(int vertex)
        {
            return adjacencyList.ContainsKey(vertex);
        }
        //

        // Проверка существования ребра
        public bool ContainsEdge(int from, int to)
        {
            return adjacencyList.ContainsKey(from) &&
                   adjacencyList[from].Any(e => e.Target == to);
        }
        //

        // Количество вершин
        public int VertexCount => adjacencyList.Count;
        //

        // Количество рёбер
        public int EdgeCount
        {
            get
            {
                int count = adjacencyList.Sum(v => v.Value.Count);
                return IsDirected ? count : count / 2;
            }
        }
        //

        // Вложенный класс для хранения рёбер
        public class Edge
        {
            public int Target { get; set; }
            public double Weight { get; set; }

            public Edge(int target, double weight = 1.0)
            {
                Target = target;
                Weight = weight;
            }
        }
        //
    }
}

