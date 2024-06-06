// openhash.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct Employee {
    string lastName;
    string position;
    int day, month, year; // Дата рождения
    int experience; // Стаж работы
    int salary;

    Employee(string lname, string pos, int d, int m, int y, int exp, int sal)
        : lastName(move(lname)), position(move(pos)), day(d), month(m), year(y), experience(exp), salary(sal) {}
};

class HashTable {
private:
    static const int TABLE_SIZE = 20;
    vector<list<Employee>> table;

    // Функция хэширования (метод деления по зарплате)
    int hashFunction(int salary) {
        return salary % TABLE_SIZE;
    }

public:
    HashTable() : table(TABLE_SIZE) {}

    // Добавление сотрудника в хэш-таблицу
    void insertEmployee(const Employee& emp) {
        int index = hashFunction(emp.salary);
        table[index].push_back(emp);
    }

    // Поиск сотрудника по зарплате
    void searchBySalary(int salary) {
        int index = hashFunction(salary);
        for (const auto& emp : table[index]) {
            if (emp.salary == salary) {
                std::cout << "Find employeer: " << emp.lastName << ", " << emp.position << ", " << emp.day << "." << emp.month << "." << emp.year << ", experience: " << emp.experience << " year" << std::endl;
            }
        }
    }

    // Удаление сотрудника по зарплате
    void deleteBySalary(int salary) {
        int index = hashFunction(salary);
        table[index].remove_if([salary](const Employee& emp) { return emp.salary == salary; });
    }

    // Вывод хэш-таблицы
    void displayTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << "Hash " << i << ": ";
            for (const auto& emp : table[i]) {
                cout << emp.lastName << " -> ";
            }
            cout << endl;
        }
    }
};

int main()
{
    HashTable ht;

    // Добавление сотрудников
    ht.insertEmployee(Employee("Esnault", "Manager", 10, 5, 1980, 10, 50000));
    ht.insertEmployee(Employee("Faivre", "Accountant", 15, 8, 1975, 15, 60000));
    ht.insertEmployee(Employee("Arquette", "Programmer", 20, 11, 1990, 5, 70000));

    // Вывод хэш-таблицы
    ht.displayTable();

    // Поиск и удаление сотрудника по зарплате
    ht.searchBySalary(60000);
    ht.deleteBySalary(60000);

    // Вывод обновленной хэш-таблицы
    ht.displayTable();

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
