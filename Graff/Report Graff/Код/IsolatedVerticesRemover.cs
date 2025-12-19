
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