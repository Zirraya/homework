// graph3neorientstepen.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <queue>
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

    // Метод для добавления неориентированного ребра в граф
    void addEdge(char from, char to) {
        adj[from - 'A'].push_back(to - 'A');
        adj[to - 'A'].push_back(from - 'A'); // Обратоное ребро
    }
    //

    // Метод для подсчёта степени каждой вершины
    void calculateDegrees() {
        cout << "Степени вершин:" << endl;
        for (int i = 0; i < adj.size(); ++i) {
            cout << char('A' + i) << ": " << adj[i].size() << endl;
        }
    }
    //

    // Метод для вывода графа
    void printGraph() {
        for (int i = 0; i < adj.size(); ++i) {
            cout << "Вершина " << char('A' + i) << " смежные вершины: ";
            for (int j : adj[i]) {
                cout << char('A' + j) << " ";
            }
            cout << endl;
        }
    }
    //

    // Метод для обхода в ширину (BFS)
    void BFS(char start) {
        vector<bool> visited(adj.size(), false);
        queue<int> q;

        int startIndex = start - 'A';
        visited[startIndex] = true;
        q.push(startIndex);

        cout << "Обход с вершины " << start << ": ";

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << char('A' + current) << " ";

            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
    //
};
//


int main() {
    setlocale(LC_ALL, "RUS");

    int V = 5; // Количество вершин
    Graph graph(V); // Создание графа

    graph.addEdge('A', 'B');
    graph.addEdge('A', 'C');
    graph.addEdge('B', 'C');
    graph.addEdge('B', 'D');
    graph.addEdge('C', 'E');

    cout << "Граф : " << endl;
    graph.printGraph(); // Вывод графа

    graph.calculateDegrees(); // Подсчёт степеней вершин

    graph.BFS('A');

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
