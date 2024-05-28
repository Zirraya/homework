// sort1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>


using namespace std;



struct Employee {
    string surname; // фамилия
    string position; // должность
    int day, month, year; // день, месяц, год
    int experience; // стаж работы
    int salary; // зарплата
};



bool compareEmployees(const Employee& emp1, const Employee& emp2) {
    if (emp1.salary != emp2.salary) {
        return emp1.salary < emp2.salary;
    }
    else if (emp1.surname != emp2.surname) {
        return emp1.surname < emp2.surname;
    }
    else if (emp1.experience != emp2.experience) {
        return emp1.experience < emp2.experience;
    }
    else if (emp1.position != emp2.position) {
        return emp1.position < emp2.position;
    }

    else {
        
        if (emp1.year != emp2.year) {
            return emp1.year < emp2.year;
        }
        else if (emp1.month != emp2.month) {
            return emp1.month < emp2.month;
        }
        else {
            return emp1.day < emp2.day;
        }
    }


}



int main()
{

    setlocale(LC_ALL, "RUS");
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Ошибка открытия файлов" << endl;
        return 1;
    }

    vector<Employee> employees;
    Employee emp;

    while (inputFile >> emp.surname >> emp.position >> emp.day >> emp.month >> emp.year >> emp.experience >> emp.salary) {
        employees.push_back(emp);
    }

    sort(employees.begin(), employees.end(), compareEmployees);

    for (const auto& employee : employees) {
        outputFile << employee.surname << " " << employee.position << " " << employee.day << " " << employee.month << " " << employee.year << " " << employee.experience << " " << employee.salary << endl;
    }

    inputFile.close();
    outputFile.close();

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
