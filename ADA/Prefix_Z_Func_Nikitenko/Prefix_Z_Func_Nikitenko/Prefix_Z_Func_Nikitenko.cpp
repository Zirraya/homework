// Prefix_Z_Func_Nikitenko.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// Обработка строк

#include <iostream>
#include <vector>
#include <string>

using namespace std;


// Префикс функция
vector<int> Prefix_Function(const string& s) {
    int n = s.length();
    vector<int> pi(n, 0); //вектор для хранения значений префикс-функции

    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1]; //длина предыдущего префикса

        //пока символы не совпадают и j больше 0, уменьшаем j
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }

        //если символы совпадают, увеличиваем j
        if (s[i] == s[j]) {
            j++;
        }

        pi[i] = j; //записываем значение префикс-функции
    }

    return pi;
}
//

// Z функция
vector<int> Z_function(const std::string& s) {
    int n = s.length();
    std::vector<int> Z(n, 0);
    int L = 0, R = 0;

    for (int i = 1; i < n; ++i) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R] == s[R - L]) {
                R++;
            }
            Z[i] = R - L;
            R--;
        }
        else {
            int k = i - L;
            if (Z[k] < R - i + 1) {
                Z[i] = Z[k];
            }
            else {
                L = i;
                while (R < n && s[R] == s[R - L]) {
                    R++;
                }
                Z[i] = R - L;
                R--;
            }
        }
    }
    return Z;
}
//

// Функция для меню
 void Menu() 
 {
     cout << "Выбирите функцию, которую вы хоитите использовать\n";
     cout << "1. Префикс-функция\n";
     cout << "2. Z-функция\n";
     cout << "3. Закрыть программу\n";
 }
//


int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Введите строку, желательно используя латинские буквы. \n";
    string s;
    cout << "Ваша строка: "; cin >> s;

    // Вектора для хранения значений
    vector<int> pi; 
    vector<int> z;
    // 

    int choice;
    while (true) {
        Menu();
        cout << "Выберите действие: ";
        cin >> choice;


        switch (choice)
        {
        case 1:
            pi = Prefix_Function(s);
            for (int i = 0; i < s.length(); i++) {
                cout << s[i] << " ";
            }
            cout << endl;

            for (int value : pi) {
                cout << value << " ";
            }
            cout << endl;
            cout << "Вы выбрали префикс-функцию\n"<<endl;
            cout << endl;
            break;

        case 2:
            z = Z_function(s);
            for (int i = 0; i < s.length(); i++) {
                cout << s[i] << " ";
            }
            cout << endl;
            for (int value : z) {
                cout << value << " ";
            }
            cout << endl;
            cout << "Вы выбрали Z-функцию\n";
            cout << endl;
            break;

        case 3:
            cout << "Выход из программы.\n";
            return 0;
            break;
        default:
            cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
            break;
        }
    }




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
