// sort6shellwith2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>


using namespace std;


ifstream in("input.txt");
ofstream out("output.txt");

struct date {
    int dd, mm, yy;
};

struct people {
    string Surname; // фамилия
    date DateOfBirth; // дата рождения
    int Salary; // зарплата
    string Position; // должность
    int Experience; // стаж работы
};

date Str_to_Date(string str) {
    date x;
    string temp = str.substr(0, 2);
    x.dd = atoi(temp.c_str());
    temp = str.substr(3, 2);
    x.mm = atoi(temp.c_str());
    temp = str.substr(6, 4);
    x.yy = atoi(temp.c_str());
    return x;
}

void shellSort(vector<people>& x, int h) {
    int n = x.size();
    for (int step = n / h; step > 0; step /= h) {
        for (int i = step; i < n; i++) {
            people temp = x[i];
            int j;
            for (j = i; j >= step && (x[j - step].Surname > temp.Surname || (x[j - step].Surname == temp.Surname && x[j - step].Position > temp.Position));
                j -= step) {
                x[j] = x[j - step];
            }
            x[j] = temp;
        }
    }
}

void sortBySurnameAndPosition(vector<people>& x, int h) {
    shellSort(x, h);
}


people inFile() {
    people temp;

    in >> temp.Surname;


    in >> temp.Position;
    string tmp;
    in >> tmp;
    temp.DateOfBirth = Str_to_Date(tmp);

    in >> temp.Experience;
    in >> temp.Salary;

    return temp;
}

void print(vector<people>& x) {
    for (const auto& person : x) {
        out << setw(10) << left << person.Surname << " ";

        out << setw(20) << left << person.Position << " ";

        if (person.DateOfBirth.dd < 10) out << left << '0' << person.DateOfBirth.dd << '.';
        else out << left << person.DateOfBirth.dd << '.';
        if (person.DateOfBirth.mm < 10) out << '0' << person.DateOfBirth.mm << '.';
        else out << person.DateOfBirth.mm << '.';
        out << person.DateOfBirth.yy << ' ';

        out << setw(2) << left << person.Experience << " ";

        out << setw(2) << left << person.Salary << endl;

    }
}




int main()
{
  
    vector<people> employees;

    while (in.peek() != EOF) {
        people temp = inFile();
        employees.push_back(temp);
    }

   sortBySurnameAndPosition(employees, 2);
    print(employees);

    in.close();
    out.close();

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
