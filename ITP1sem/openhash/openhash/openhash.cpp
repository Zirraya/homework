// openhash.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int HASH_TABLE_SIZE = 25; // Размер хэш-таблицы

// Структура для хранения данных о сотруднике
struct Employee {
    string lastName;
    string position;
    int day, month, year;
    int experience;
    int salary;

    // Указатели для двусвязного списка
    Employee* prev;
    Employee* next;
    //

    Employee(string lname = "", string pos = "", int d = 0, int m = 0, int y = 0, int exp = 0, int sal = 0)
        : lastName(lname), position(pos), day(d), month(m), year(y), experience(exp), salary(sal), prev(nullptr), next(nullptr) {}
};

// Структура для узла хэш-таблицы
struct HashNode {
    Employee* head;
    HashNode() : head(nullptr) {}
};

// Класс хэш-таблицы
class HashTable {
private:
    HashNode table[HASH_TABLE_SIZE];

    // Хэш-функция (деление по зарплате)
    int hashFunction(int salary) {
        return salary % HASH_TABLE_SIZE;
    }
    //

public:
    // Вставка нового сотрудника
    void insertEmployee(const Employee& emp) {
        int index = hashFunction(emp.salary);
        Employee* newEmp = new Employee(emp);

        // Вставка в начало списка
        if (table[index].head == nullptr) {
            table[index].head = newEmp;
        }
        else {
            newEmp->next = table[index].head;
            table[index].head->prev = newEmp;
            table[index].head = newEmp;
        }
    }
    //

    // Поиск сотрудника
    void searchEmployee(int salary) {
        int index = hashFunction(salary);
        Employee* current = table[index].head;
        bool found = false;

        while (current != nullptr) {
            if (current->salary == salary) {
                cout << "Найден сотрудник:\n";
                cout << "Фамилия: " << current->lastName << endl;
                cout << "Должность: " << current->position << endl;
                cout << "Дата рождения: " << current->day << "." << current->month << "." << current->year << endl;
                cout << "Стаж работы: " << current->experience << endl;
                cout << "Зарплата: " << current->salary << endl << endl;
                found = true;
            }
            current = current->next;
        }

        if (!found) {
            cout << "Сотрудник с зарплатой " << salary << " не найден.\n";
        }
    }
    //

    // Удаление сотрудника
    void deleteEmployee(int salary) {
        int index = hashFunction(salary);
        Employee* current = table[index].head;
        bool found = false; // Флаг для отслеживания, были ли найдены удаляемые сотрудники

        while (current != nullptr) {
            if (current->salary == salary) {
                // Удаление из списка
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                }
                else {
                    table[index].head = current->next;
                }
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }
                Employee* toDelete = current; // Сохранения указателя на удаляемый элемент
                current = current->next; // Переход к следующему элементу перед удалением
                delete toDelete; // Удаление текущий элемент
                found = true; // Устанановка флаг, что был найден и удален сотрудник
            }
            else {
                current = current->next; // Переход к следующему элементу
            }
        }
        if (found) {
            cout << "Сотрудники с зарплатой " << salary << " удалены.\n";
        }
        else {
            cout << "Сотрудники с зарплатой " << salary << " не найдены.Увы\n";
        }
    }
    //

    // Вывод хэш-таблицы
    void displayTable() {
    for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
        Employee* current = table[i].head;
        while (current != nullptr) {
            cout << "Хэш " << i++ << ": ";
            cout << current->lastName << " " << current->position << " " << current->day << "." << current->month << "." << current->year << " " << current->experience << " " << current->salary;
            current = current->next;
            cout << " " << endl;
        }  
    }
}
//
};
//

// Функция для загрузки данных о сотрудниках из файла
void loadEmployeesFromFile(HashTable& ht, const string& filaname) {
    ifstream file(filaname);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла: " << filaname << endl;
        return;
    }

    string lastName, position;
    int day, month, year, experience, salary;
    while (file >> lastName >> position >> day >> month >> year >> experience >> salary) {
        ht.insertEmployee(Employee(lastName, position, day, month, year, experience, salary));
    }

    file.close();
}
//

int main() {

    setlocale(LC_ALL, "RUS");

    HashTable ht;

    // Загрузка данных о сотрудниках из файла (замените "employees.txt" на имя вашего файла)
    loadEmployeesFromFile(ht, "input.txt");

    int choice, salary;
    do {
        cout << "\nМеню:\n";
        cout << "1. Вывести хэш-таблицу\n";
        cout << "2. Добавить сотрудника\n";
        cout << "3. Найти сотрудника\n";
        cout << "4. Удалить сотрудника\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            ht.displayTable();
            break;
        case 2: {
            string lastName, position;
            int day, month, year, experience, salary;
            cout << "Введите данные сотрудника:\n";
            cout << "Фамилия: "; cin >> lastName;
            cout << "Должность: "; cin >> position;
            cout << "Дата рождения (день месяц год): "; cin >> day >> month >> year;
            cout << "Стаж работы: "; cin >> experience;
            cout << "Зарплата: "; cin >> salary;
            ht.insertEmployee(Employee(lastName, position, day, month, year, experience, salary));
            break;
        }
        case 3:
            cout << "Введите зарплату для поиска: ";
            cin >> salary;
            ht.searchEmployee(salary);
            break;
        case 4:
            cout << "Введите зарплату для удаления: ";
            cin >> salary;
            ht.deleteEmployee(salary);
            break;
        case 0:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Некорректный выбор.\n";
        }
    } while (choice != 0);

    return 0;
}



//if (current->next != nullptr) {
//    current->next->prev = current->prev;
//}
//delete current;
//cout << "Сотрудник с зарплатой " << salary << " удален.\n";
//return; // Удаляем только первое вхождение
//            }
//            current = current->next;
//        }
//
//        cout << "Сотрудник с зарплатой " << salary << " не найден.\n";
//    }
//    //  Старая часть кода

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
