﻿// stroki4yep.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <regex>
#include <string>

using namespace std;

int main()
{
    ifstream ifs("input.txt");
    ofstream o("output.txt");
    const regex reg(R"(.*?\d{2}([\. ])\d{2}\1\d{4}.*?([\.!?]\s|$))");
    const string str{ istreambuf_iterator<char>(ifs), istreambuf_iterator<char>() };
    using it = sregex_token_iterator;
    copy(it(str.cbegin(), str.cend(), reg), it(), ostream_iterator<ssub_match>(o, "\n"));

    system("pause");
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