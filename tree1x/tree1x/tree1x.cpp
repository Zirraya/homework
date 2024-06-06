// tree1x.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Дано древо. Удалить элементы кратыне x

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

void inOrderTraversal(Node* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

Node* removeMultiples(Node* root, int x) {
    if (root == nullptr) {
        return root;
    }
    root->left = removeMultiples(root->left, x);
    root->right = removeMultiples(root->right, x);
    if (root->data % x == 0) {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node* temp = root->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = removeMultiples(root->right, x);
        }
    }
    return root;
}


int main()
{
  
    setlocale(LC_ALL, "RUS");

    Node* root = nullptr;
    int values[] = { 8, 4, 12, 2, 6, 10, 14 }; 
    cout << "Введите число x:"; int x; cin >> x; 

    for (int value : values) {
        root = insert(root, value);
    }

    cout << "Древо до удаления элементов кратных " << x << ": ";
    inOrderTraversal(root);
    cout << endl;

    root = removeMultiples(root, x);

    cout << "Древо после удаления элементов кратных " << x << ": ";
    inOrderTraversal(root);
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
