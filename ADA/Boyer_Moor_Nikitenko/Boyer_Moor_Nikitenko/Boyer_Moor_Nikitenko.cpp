// Boyer_Moor_Nikitenko.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Функция для создания таблицы смещений по символам
vector<int> CreateBadCharTable(const string& pattern) {
    const int ALPHABET_SIZE = 256;
    vector<int> badCharTable(ALPHABET_SIZE, -1);

    for (int i = 0; i < pattern.size(); ++i) {
        badCharTable[static_cast<int>(pattern[i])] = i;
    }

    return badCharTable;
}
//

// Функция для поиска подстроки с использованием алгоритма Бойера — Мура
void BoyerMoore(const string& text, const string& pattern) {
    int m = pattern.size();
    int n = text.size();
    vector<int> badCharTable = CreateBadCharTable(pattern);

    int s = 0;
    while (s <= n - m) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }

        if (j < 0) {
            cout << s << endl;
            s += (s + m < n) ? m - badCharTable[static_cast<int>(text[s + m])] : 1;
        }
        else {
            s += max(1, j - badCharTable[static_cast<int>(text[s + j])]);
        }
    }
}
//

int main() {

    setlocale(LC_ALL, "RUS");
    cout << "Введите вашу строку: ";
    string text;
    cin >> text;

    cout << "Введите вашу подстроку: ";
    string pattern;
    cin >> pattern;
    cout << "Результат алгоритма: ";
    BoyerMoore(text, pattern);

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
