// graph4neorientsvaz.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

    // Добавки ееее
    void addEdge(int v, int w) {
        adj[v].push_back(w); // Добавляем w в список смежности v
        adj[w].push_back(v); // Добавляем v в список смежности w (неориентированный граф)
    }
    //

    // Счас будем выяснять связан или развязан граф
    bool isConnected() {
        vector<bool> visited(V, false);
        int count = 0;

        // BFS для обходу в ширину
        queue<int> q;
        q.push(0); // Наааачааало
        visited[0] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            count++;

            for (int neighbor : adj[u]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return count == V; // Если количество посещенных вершин равно количеству вершин в графе, то граф связан (нет блин развязан)
    }
    //

    // Обход в ширину
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "Обход с вершины " << start << ": ";

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (int neighbor : adj[u]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << std::endl;
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
//

int main() {

    setlocale(LC_ALL, "RUS");

    int V = 5; // Количество вершин
    Graph g(V);

    // Ребра
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    //
    
    
    g.printGraph(); // Вывод графа

    // Проверка связоннсти 
    if (g.isConnected()) {
        cout << "Граф связан" <<endl;
    }
    else {
        cout << "Граф не связан" << endl;
    }
    //

    // Обход
    g.BFS(0); // Начало с 0
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
