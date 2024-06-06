// closehash.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Employee {
    string lastName;
    string position;
    int day, month, year; // Дата рождения
    int experience; // Стаж работы
    int salary;

    Employee() = default;

    Employee(string lname, std::string pos, int d, int m, int y, int exp, int sal)
        : lastName(move(lname)), position(move(pos)), day(d), month(m), year(y), experience(exp), salary(sal) {}
};

class ClosedHashTable {
private:
    static const int TABLE_SIZE = 20;
    vector<Employee> table;

    // Функция хэширования (метод деления по зарплате)
    int hashFunction(int salary) {
        return salary % TABLE_SIZE;
    }

    // Квадратичное пробирование для разрешения коллизий
    int quadraticProbe(int index, int attempt) {
        return (index + attempt * attempt) % TABLE_SIZE;
    }

public:
    ClosedHashTable() : table(TABLE_SIZE) {}

    // Вставка сотрудника в хэш-таблицу
    void insertEmployee(const Employee& emp) {
        int salary = emp.salary;
        int index = hashFunction(salary);
        int attempt = 0;

        while (!table[index].lastName.empty()) {
            attempt++;
            index = quadraticProbe(index, attempt);
        }

        table[index] = emp;
    }

    // Поиск сотрудника по зарплате
    void searchBySalary(int salary) {
        int index = hashFunction(salary);
        int attempt = 0;

        while (!table[index].lastName.empty() && table[index].salary != salary) {
            attempt++;
            index = quadraticProbe(index, attempt);
        }

        if (table[index].salary == salary) {
            cout << "Employee found: " << table[index].lastName << ", " << table[index].position << ", " << table[index].day << "." << table[index].month << "." << table[index].year << ", expireince: " << table[index].experience << " year" << endl;
        }
        else {
            cout << "employee with salary " << salary << " not find." << endl;
        }
    }

    // Вывод хэш-таблицы
    void displayTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (!table[i].lastName.empty()) {
                cout << "Hash " << i << ": " << table[i].lastName << " -> " << endl;
            }
            else {
                cout << "Hash " << i << ": Empty" << endl;
            }
        }
    }
};

int main()
{
    ClosedHashTable cht;

    // Добавление сотрудников
    // Добавление сотрудников
    cht.insertEmployee(Employee("Esnault", "Manager", 10, 5, 1980, 10, 50000));
    cht.insertEmployee(Employee("Faivre", "Accountant", 15, 8, 1975, 15, 60000));
    cht.insertEmployee(Employee("Arquette", "Programmer", 20, 11, 1990, 5, 70000));


    // Вывод хэш-таблицы
    cht.displayTable();

    // Поиск сотрудника по зарплате
    cht.searchBySalary(60000);

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
