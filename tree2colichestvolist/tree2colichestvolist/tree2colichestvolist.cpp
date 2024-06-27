// tree2colichestvolist.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Задча 2. Найти количество листьев

#include <iostream>
#include <queue>

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

Node* insertBalanced(Node* root, int start, int end, int arr[]) {
    if (start > end) {
        return nullptr;
    }
    int mid = (start + end) / 2;
    root = createNode(arr[mid]);
    root->left = insertBalanced(root->left, start, mid - 1, arr);
    root->right = insertBalanced(root->right, mid + 1, end, arr);
    return root;
}

void preOrderTraversal(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void printPretty(Node* root, int space) {
    if (root == nullptr) return;

    space += 5;

    printPretty(root->right, space);

    cout << endl;
    for (int i = 5; i < space; i++) {
        cout << " ";
    }
    cout << root->data << "\n";

    printPretty(root->left, space);
}

void printLeaves(Node* root) {
    if (root == nullptr) {
        return;
    }
    if (root->left == nullptr && root->right == nullptr) {
        cout << root->data << " ";
    }
    printLeaves(root->left);
    printLeaves(root->right);
}

int main() {
    setlocale(LC_ALL, "RUS");

    Node* root = nullptr;
    int values[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int n = sizeof(values) / sizeof(values[0]);

    root = insertBalanced(root, 0, n - 1, values);

    cout << "Прямой обход дерева: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "Идеально сбалансированное дерево в красивом виде:\n";
    printPretty(root, 0);

    cout << "Листья дерева: ";
    printLeaves(root);
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
