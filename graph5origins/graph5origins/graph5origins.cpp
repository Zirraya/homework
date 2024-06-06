// graph5origins.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
}

vector<int> findSources(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<int> inDegree(V, 0);
    unordered_set<int> sources;

    // Подсчет входящих степеней для каждой вершины
    for (int u = 0; u < V; ++u) {
        for (int v : adj[u]) {
            inDegree[v]++;
        }
    }

    // Нахождение истоков (вершин без входящих ребер)
    for (int u = 0; u < V; ++u) {
        if (inDegree[u] == 0) {
            sources.insert(u);
        }
    }

    return vector<int>(sources.begin(), sources.end());
}

int main()
{
    setlocale(LC_ALL, "RUS");

    int V = 5; // Количество вершин
    vector<vector<int>> adj(V);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 4, 3);

    cout << "Ориентированный граф:" << endl;
    for (int i = 0; i < V; ++i) {
        cout << "Вершина " << i << " исходящие вершины: ";
        for (int j = 0; j < adj[i].size(); ++j) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> sources = findSources(adj);

    cout << "Истоки графа: ";
    for (int source : sources) {
        cout << source << " ";
    }
    cout << endl;

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
