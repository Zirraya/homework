// graph2orientinsert.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack> 

using namespace std;

// Структура вершины (пришлось создать еще структуру для вершины...мда)
struct Vertex {
    string label;
    vector<string> adjacent; // Список смежности
};
//

// Структура для графа
struct Graph {
    unordered_map<string, Vertex> adjacencyList; // Список смежности

    // Вставка ребра
    void addEdge(const string& A, const string& B) {
        // Создание вершины A, если ее нет, но ее же и нет...
        if (adjacencyList.find(A) == adjacencyList.end()) {
            adjacencyList[A] = { A, {} };
        }
        // Создание вершины B, если ее нет, но ее же и нет...
        if (adjacencyList.find(B) == adjacencyList.end()) {
            adjacencyList[B] = { B, {} };
        }
        // Добавка. Новое ребро от A до B
        adjacencyList[A].adjacent.push_back(B);
    }
    //

    // Вывод 
    void display() {
        for (const auto& pair : adjacencyList) {
            cout << "Вершина " << pair.second.label << ": ";
            for (const auto& vertex : pair.second.adjacent) {
                cout << vertex << " ";
            }
            cout << endl;
        }
    }
    //

    // Обход в глубину (что сним случилось, в других задниях он меньше, ну почему от так у меня тут разросся)
    void DFS(const string& startVertex) {
        unordered_set<string> visited; // Отслеживание посещенных вершин
        stack<string> stack; // Стек для хранения вершин

        stack.push(startVertex);

        while (!stack.empty()) {
            string currentVertex = stack.top();
            stack.pop();

            if (visited.find(currentVertex) == visited.end()) {
                visited.insert(currentVertex);
                cout << currentVertex << " ";

                // Добавление в стек соседние непосещенные вершины
                for (const auto& neighbor : adjacencyList[currentVertex].adjacent) {
                    if (visited.find(neighbor) == visited.end()) {
                        stack.push(neighbor);
                    }
                }
            }
        }
    }
    //
};
//

int main() {
    setlocale(LC_ALL, "RUS");

    Graph graph; // Создание графа

    // Добавление ребер
    graph.addEdge("A", "C");
    graph.addEdge("B", "D");
    graph.addEdge("C", "D");
    graph.addEdge("D", "E");
    //

    cout << "Граф до изменения: " << endl;
    graph.display();

    cout << "Обход  с 'A': ";
    graph.DFS("A");
    cout << endl;

    // Вставка ребра A до B (если его нет конечно  же)
    graph.addEdge("A", "B"); // Добавление второго ребра от A до B
    //

    cout << "Граф после добавления ребра от 'A' до 'B':" << endl;
    graph.display();

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
