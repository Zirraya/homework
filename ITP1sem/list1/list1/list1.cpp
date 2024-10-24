// list1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <limits> // Для использования std::numeric_limits


using namespace std;

// Структура элемента двусвязного списка
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Класс для работы с двусвязным списком
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Метод для вставки элемента в конец списка
    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Метод для вставки минимального элемента перед каждым значением, равным lastValue
    void insertBeforeLastValue(int lastValue) {
        if (!head) return; // Пустой список

        Node* current = head;
        int minValue = numeric_limits<int>::max(); // Инициализируем с максимальным значением int

        // Находим минимальное значение в списке
        while (current) {
            if (current->data < minValue) {
                minValue = current->data;
            }
            current = current->next;
        }

        // Вставляем минимальное значение перед каждым значением, равным lastValue
        current = head;
        while (current) {
            if (current->data == lastValue) {
                Node* newNode = new Node(minValue);
                newNode->next = current;
                newNode->prev = current->prev;
                if (current->prev) {
                    current->prev->next = newNode;
                }
                else {
                    head = newNode; // Если вставляем перед головой
                }
                current->prev = newNode;
                current = newNode->next; // Продвигаемся дальше, чтобы не вставлять перед каждым элементом
            }
            else {
                current = current->next;
            }
        }
    }

    // Метод для вывода списка
    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {

    setlocale(LC_ALL, "RUS");

    DoublyLinkedList dll;

    // Пример ввода данных
    int arr[] = { 8, 2, 1, 6, 8, 8, 1, 2, 2, 8, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Заполняем список из массива
    for (int i = 0; i < n; ++i) {
        dll.insertEnd(arr[i]);
    }

    cout << "Исходный список: ";
    dll.display();

    // Вставляем минимальные элементы перед последними значениями, равными последнему элементу
    dll.insertBeforeLastValue(arr[n - 1]);

    cout << "Измененный список: ";
    dll.display();

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
