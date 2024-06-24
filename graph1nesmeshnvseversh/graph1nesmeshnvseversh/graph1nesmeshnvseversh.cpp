// graph1nesmeshnvseversh.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;


// Добавление ребра в обе стороны для неориентированного графа в функции addEdge.

void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); 
}


// DFSUtil для рекурсивного обхода графа в глубину.
void DFSUtil(int vertex, vector<bool>& visited, vector<vector<int>>& adj) {
    visited[vertex] = true;
    cout << vertex << " ";

    for (int i = 0; i < adj[vertex].size(); ++i) {
        int v = adj[vertex][i];
        if (!visited[v]) {
            DFSUtil(v, visited, adj);
        }
    }
}
//

// Функция DFS для запуска обхода графа в глубину из каждой непосещенной вершины.

void DFS(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            DFSUtil(i, visited, adj);
        }
    }
}

//

int main()
{
    setlocale(LC_ALL, "RUS");

    int V = 5; // Количество вершин
    vector<vector<int>> adj(V);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);

    cout << "Граф, созданный с использованием списка смежности:" << endl;
    for (int i = 0; i < V; ++i) {
        cout << i << ": ";
        for (int j = 0; j < adj[i].size(); ++j) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Результат обхода в глубину: ";
    DFS(adj);

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
