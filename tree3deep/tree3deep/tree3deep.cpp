// tree3deep.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Задача 4

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

int findDepth(Node* root, int value, int depth) {
    if (root == nullptr) {
        return -1;  // Узел не найден
    }
    if (root->data == value) {
        return depth;
    }

    int leftDepth = findDepth(root->left, value, depth + 1);
    if (leftDepth != -1) {
        return leftDepth;
    }

    int rightDepth = findDepth(root->right, value, depth + 1);
    return rightDepth;
}

int main()
{
    setlocale(LC_ALL, "RUS");

    Node* root = nullptr;
    int values[] = { 8, 4, 12, 2, 6, 10, 14, 5, 7, 2, 1 }; 

    for (int value : values) {
        root = insert(root, value);
    }

    cout << "Введите нужную глубину узла: "; int x; cin >> x; // Значение узла, глубину которого нужно найти
    int depth = findDepth(root, x, 0);

    if (depth != -1) {
        cout << "Глубина узла " << x << " равна " << depth << endl;
    }
    else {
        cout << "Узел " << x << " не найден в дереве." << endl;
    }

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
