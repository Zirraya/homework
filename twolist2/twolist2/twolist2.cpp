﻿// twolist2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


using namespace std;

// Структура для узла двусвязного списка
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};
//

// Класс для двусвязного списка
class DoublyLinkedList {
public:
    Node* head; // Указатель на начало списка
    Node* tail; // Указатель на конец списка

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Добавление элемента в конец списка
    void push_back(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) { // Если список пуст
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    //

    void moveEvenToFront() {
        Node* current = head;
        Node* prev = nullptr;  // Добавим указатель на предыдущий узел
        while (current != nullptr) {
            if (current->data % 2 == 0 && current != head) {
                // Удаление из текущей позиции
                if (current == tail) {
                    tail = current->prev;
                }
                else {
                    current->next->prev = current->prev;
                }
                current->prev->next = current->next;

                // Вставка в начало
                current->next = head;
                current->prev = nullptr;
                head->prev = current;
                head = current;

                if (prev != nullptr) {
                    prev->next = current;
                }
                else {
                    head = current;  // Если prev равен nullptr, значит, текущий элемент становится новой головой списка
                }

                // Переходим к следующему элементу
                current = prev->next;
            }
            else {
                prev = current;  // Обновляем prev перед переходом к следующему элементу
                current = current->next;
            }
        }
    }
    //

// Вывод списка
void printList() {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
//
};

int main()
{
    setlocale(LC_ALL, "RUS");


    DoublyLinkedList list;
    int num;

    cout << "Вводите целые числа (что бы завершить ввод надо ввести не число):" << endl;
    while (cin >> num) {
        list.push_back(num);
    }
    cin.clear(); // Очистка состояния ошибки ввода
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера ввода

    cout << "Исходный список: ";
    list.printList();

   
    list.moveEvenToFront();
    cout << "Список после изменений: ";
    list.printList();

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