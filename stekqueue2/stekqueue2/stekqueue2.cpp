// stekqueue2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

class MyQueue {
private:
    vector<int> elements;

public:
    void push(int item) {
        elements.push_back(item);
    }

    int pop() {
        if (isEmpty()) {
            cout << "Очередь пуста" << endl;
            return -1; // Возвращаем значение по умолчанию для пустой очереди (грустно, когда очередь пуста :O)
        }
        int frontElement = elements[0];
        elements.erase(elements.begin());
        return frontElement;
    }

    bool isEmpty() {
        return elements.empty();
    }

    void insertLastEven(int lastEven, int minNum) {
        for (size_t i = 0; i < elements.size(); i++) {
            if (elements[i] == minNum) {
                elements.insert(elements.begin() + i, lastEven);
                break;
            }
        }
    }

    int findMin() {
        if (isEmpty()) {
            cout << "Очередь пуста" << endl;
            return -1; // Возвращаем значение по умолчанию для пустой очереди (грустно, когда очередь пуста :O)
        }
        int minNum = elements[0];
        for (size_t i = 1; i < elements.size(); i++) {
            if (elements[i] < minNum) {
                minNum = elements[i];
            }
        }
        return minNum;
    }
};

int main() {
    setlocale(LC_ALL, "RUS");

    MyQueue q;

    int num;
    cout << "Введите очередь (введите 0 чтобы закончить ввод): ";
    while (true) {
        cin >> num;
        if (num == 0) break;
        q.push(num);
    }

    MyQueue qCopy = q; // Создание копии
    int minNum = qCopy.findMin(); // Нахождение минимального элемента

    qCopy = q; // Сбросить копию
    int lastEven = -1;
    while (!qCopy.isEmpty()) {
        int current = qCopy.pop();
        if (current % 2 == 0) lastEven = current;
    }

    q.insertLastEven(lastEven, minNum);

    cout << "Измененная очередь: ";
    while (!q.isEmpty()) {
        cout << q.pop() << " ";
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
