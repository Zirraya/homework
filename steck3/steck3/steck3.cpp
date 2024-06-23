// steck3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

using namespace std;

class MyQueue {
private:
    struct Node {
        char data;
        Node* next;
    };

    Node* front;
    Node* rear;

public:
    MyQueue() : front(nullptr), rear(nullptr) {}

    void enqueue(char item) {
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

    char dequeue() {
        if (isEmpty()) {
            cout << "Очередь пуста" << endl;
            return '\0'; // Возвращение значения по умолчанию для пустой очереди
        }
        char frontItem = front->data;
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

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    setlocale(LC_ALL, "RUS");

    MyQueue originalQueue;
    MyQueue modifiedQueue;

    ifstream inputFile("input.txt");

    if (!inputFile) {
        cerr << "Не удалось открыть файл. :О" << endl;
        return 1;
    }

    char letter;
    bool foundVowel = false;
    while (inputFile >> letter) {
        originalQueue.enqueue(letter);
        if (isVowel(letter)) {
            foundVowel = true;
        }
        else {
            if (foundVowel) {
                modifiedQueue.enqueue('!'); // Встатвка восклицательного знака после последней гласной буквы
                foundVowel = false;
            }
        }
    }

    while (!originalQueue.isEmpty()) {
        modifiedQueue.enqueue(originalQueue.dequeue());
    }

    cout << "Очередь :D : ";
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
