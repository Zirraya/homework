// steck4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

class MyQueue {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* front;
    Node* rear;

public:
    MyQueue() : front(nullptr), rear(nullptr) {}

    void enqueue(int item) {
        Node* newNode = new Node;
        newNode->data = item;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Очередь пуста :O" << endl;
            return 0; // Возвращаем значение по умолчанию для пустой очереди
        }
        int frontItem = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        return frontItem;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "RUS");

    MyQueue originalQueue;
    MyQueue modifiedQueue;

    cout << "Введите целые числа (введите 0 чтобы закончить ввод): ";
    int num;
    while (true) {
        cin >> num;
        if (num == 0) break;
        originalQueue.enqueue(num);
    }

    while (!originalQueue.isEmpty()) {
        int num = originalQueue.dequeue();
        if (!isPrime(num)) {
            modifiedQueue.enqueue(num);
        }
    }

    cout << "Результат :D : ";
    while (!modifiedQueue.isEmpty()) {
        cout << modifiedQueue.dequeue() << " ";
    }
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
