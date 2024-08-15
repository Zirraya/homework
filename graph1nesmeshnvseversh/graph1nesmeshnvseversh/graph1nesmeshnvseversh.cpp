// graph1nesmeshnvseversh.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

// Структура 
struct Graph {
    vector<vector<int>> adj; // Список смежности

    // Конструктор для инициализации графа с заданным количеством вершин
    Graph(int V) {
        adj.resize(V);
    }
    //

    // Метод для добавления ребра в граф
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    //

    // Рекурсивная функция для обхода в глубину
    void DFSUtil(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int v : adj[vertex]) {
            if (!visited[v]) {
                DFSUtil(v, visited);
            }
        }
    }
    //

    // Метод для запуска обхода в глубину
    void DFS() {
        int n = adj.size();
        vector<bool> visited(n, false);

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }
    //

    //  Вывод
    void printGraph() {
        cout << "Граф: " << endl;
        for (int i = 0; i < adj.size(); ++i) {
            cout << i << ": ";
            for (int j : adj[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
    //
};
//

int main() {
    setlocale(LC_ALL, "RUS");

    int V = 5; // Количество вершин
    Graph graph(V); // Создание графа

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);

    graph.printGraph(); // Вывод графа

    cout << "Результат обхода в глубину: ";
    graph.DFS(); // Реузльат 

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
