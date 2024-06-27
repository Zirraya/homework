// twolist3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
    Node* head;
    Node* tail;

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Добавление элемента в конец списка
    void push_back(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    //

    // Сортировка вставками с изменением указателей
    void insertionSort() {
        if (head == nullptr || head->next == nullptr) {
            return; // Пустой список или один элемент
        }

        Node* sortedEnd = head; // Конец отсортированной части
        Node* current = head->next; // Текущий элемент для вставки

        while (current != nullptr) {
            Node* next = current->next; // Сохраняем следующий элемент

            // Отсоединяем current от списка
            if (current->prev) {
                current->prev->next = current->next;
            }
            if (current->next) {
                current->next->prev = current->prev;
            }

            // Находим позицию для вставки current в отсортированной части
            Node* search = sortedEnd;
            while (search != nullptr && search->data > current->data) {
                search = search->prev;
            }

            // Вставляем current перед search (или в начало, если search == nullptr)
            if (search == nullptr) {
                // Вставка в начало
                current->next = head;
                current->prev = nullptr;
                head->prev = current;
                head = current;
            }
            else {
                // Вставка после search
                current->next = search->next;
                current->prev = search;
                if (search->next) {
                    search->next->prev = current;
                }
                search->next = current;
            }

            if (current->next == nullptr) {
                tail = current; // Обновляем tail, если current стал последним
            }

            current = next; // Переходим к следующему элементу
            sortedEnd = current ? current->prev : tail;
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

int main() {
    setlocale(LC_ALL, "RUS");

    DoublyLinkedList list;
    int num;

    cout << "Вводите целые числа (что бы завершить ввод надо ввести не число):" << endl;
    while (cin >> num) {
        list.push_back(num);
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Исходный список: ";
    list.printList();

    list.insertionSort();
    cout << "Отсортированный список: ";
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
