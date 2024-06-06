// graph1nesmeshnvseversh.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
}

void printNonAdjacentVertices(const vector<vector<int>>& adj, int vertex) {
    int n = adj.size();
    for (int i = 0; i < n; ++i) {
        if (i != vertex) {
            bool isAdjacent = false;
            for (int j = 0; j < adj[vertex].size(); ++j) {
                if (adj[vertex][j] == i) {
                    isAdjacent = true;
                    break;
                }
            }
            if (!isAdjacent) {
                cout << i << " ";
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");

    int V = 5; // Количество вершин
    vector<vector<int>> adj(V);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);

    int vertex = 0; // Вершина, для которой нужно найти несмежные вершины
    cout << "Несмежные вершины с вершиной " << vertex << " : ";
    printNonAdjacentVertices(adj, vertex);

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
