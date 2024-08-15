// graph5origins.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

struct Graph {
    int V; // Количество вершин
    vector<list<int>> adj; // Список смежности

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w); // Добавляем ребро от v к w
    }

    // Истоки
    void printSources() {
        vector<int> inDegree(V, 0);

        // Входящая степень каждой вершины
        for (int v = 0; v < V; ++v) {
            for (int neighbor : adj[v]) {
                inDegree[neighbor]++;
            }
        }

        cout << "Истоки графа: ";
        for (int v = 0; v < V; ++v) {
            if (inDegree[v] == 0) {
                cout << v << " "; // Если входящая степень равна 0, это исток
            }
        }
        cout << endl;
    }
    //

    

    // Обход
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true; // Помечаем стартовую вершину как посещенную
        q.push(start);

        cout << "Обход в ширину, начиная с вершины " << start << ": ";

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " "; // Выводим текущую вершину

            // Проходим по всем соседям текущей вершины
            for (int neighbor : adj[v]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true; // Помечаем соседа как посещенного
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
    //

    // Вывод
    void printGraph() {
        for (int v = 0; v < V; ++v) {
            cout << "Вершина " << v << ": ";
            for (int neighbor : adj[v]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
    //

};

int main() {

    setlocale(LC_ALL, "RUS");

    int V = 5; // Количество вершин
    Graph g(V);

    // Добавляем ребра
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(4, 0); // Вершина 4 имеет выходное ребро, но не входящее

    
    g.printGraph(); // Сам граф

    // Тут истоки
    g.printSources();
    //

    // Обход
    g.BFS(0);
    //

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
