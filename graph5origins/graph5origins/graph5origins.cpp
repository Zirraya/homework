﻿// graph5origins.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


// Добавление ребра только в одну сторону для ориентированного графа в функции addDirectedEdge
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
}
//


// Функция DFS для запуска обхода графа в глубину из каждой непосещенной вершины.
void DFS(const vector<vector<int>>& adj, vector<bool>& visited, int u) {
    visited[u] = true;
    cout << u << " ";

    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(adj, visited, v);
        }
    }
}
//


// Введение функции - обертки DFSWrapper, которая вызывает DFS для каждой непосещенной вершины.
void DFSWrapper(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            DFS(adj, visited, i);
            cout << endl;
        }
    }
}
//

int main()
{
    setlocale(LC_ALL, "RUS");

    int V = 5; // Количество вершин
    vector<vector<int>>* adj = new vector<vector<int>>(V);

    addEdge(*adj, 0, 1);
    addEdge(*adj, 0, 2);
    addEdge(*adj, 1, 3);
    addEdge(*adj, 2, 3);
    addEdge(*adj, 4, 3);

    cout << "Граф, созданный с использованием списка смежности:" << endl;
    for (int i = 0; i < V; ++i) {
        cout << "Вершина " << i << " смежные вершины: ";
        for (int j = 0; j < (*adj)[i].size(); ++j) {
            cout << (*adj)[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Результат обхода в глубину:" << endl;
    DFSWrapper(*adj);

    delete adj; // Освобождение памяти

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
