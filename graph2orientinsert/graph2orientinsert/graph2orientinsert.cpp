// graph2orientinsert.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;


// Добавление ребра только в одну сторону для ориентированного графа в функции addDirectedEdge

void addDirectedEdge(vector<vector<int>>& adj, char from, char to) {
    adj[from - 'A'].push_back(to - 'A');
}
//


// Функция DFSUtil для рекурсивного обхода графа в глубину.
void DFSUtil(int vertex, vector<bool>& visited, const vector<vector<int>>& adj) {
    visited[vertex] = true;
    cout << char('A' + vertex) << " ";

    for (int i = 0; i < adj[vertex].size(); ++i) {
        int v = adj[vertex][i];
        if (!visited[v]) {
            DFSUtil(v, visited, adj);
        }
    }
}
//



// Функция DFS для запуска обхода графа в глубину из каждой непосещенной вершины.
void DFS(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            DFSUtil(i, visited, adj);
        }
    }
}
//

// Вывод 
void printGraph(const vector<vector<int>>& adj) {
    for (int i = 0; i < adj.size(); ++i) {
        cout << "Вершина " << char('A' + i) << " смежные вершины: ";
        for (int j = 0; j < adj[i].size(); ++j) {
            cout << char('A' + adj[i][j]) << " ";
        }
        cout << endl;
    }
}
//


int main()
{
    setlocale(LC_ALL, "RUS");

    int V = 5; // Количество вершин
    vector<vector<int>> adj(V);

    addDirectedEdge(adj, 'A', 'B');
    addDirectedEdge(adj, 'A', 'C');
    addDirectedEdge(adj, 'B', 'D');
    addDirectedEdge(adj, 'C', 'E');

    cout << "Граф, созданный с использованием списка смежности:" << endl;
    printGraph(adj);

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
