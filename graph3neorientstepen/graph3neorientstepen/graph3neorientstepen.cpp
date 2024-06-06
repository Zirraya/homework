// graph3neorientstepen.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

void addUndirectedEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printDegrees(const vector<vector<int>>& adj) {
    for (int i = 0; i < adj.size(); ++i) {
        cout << "Степень вершины " << i << ": " << adj[i].size() << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");

    int V = 5; // Количество вершин
    vector<vector<int>> adj(V);

    addUndirectedEdge(adj, 0, 1);
    addUndirectedEdge(adj, 0, 2);
    addUndirectedEdge(adj, 1, 3);
    addUndirectedEdge(adj, 2, 4);

    cout << "Неориентированный граф:" << endl;
    for (int i = 0; i < V; ++i) {
        cout << "Вершина " << i << " смежные вершины: ";
        for (int j = 0; j < adj[i].size(); ++j) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Степени вершин:" << endl;
    printDegrees(adj);

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
