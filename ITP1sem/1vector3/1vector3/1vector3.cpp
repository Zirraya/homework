// 1vector3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <numeric>
#include <functional>
#include <vector>

using namespace std;


vector<int> generateFibonacciNumbers(int n) {
    vector<int> fibonacciNumbers(n);

    if (n > 0) {
        fibonacciNumbers[0] = 0;
    }
    if (n > 1) {
        fibonacciNumbers[1] = 1;
    }

    for (int i = 2; i < n; ++i) {
        fibonacciNumbers[i] = fibonacciNumbers[i - 1] + fibonacciNumbers[i - 2];
    }

    return fibonacciNumbers;
}


int main()
{
   
    setlocale(LC_ALL, "RUS");

    int n;
    cout << "Введите количество чисел Фибоначчи : ";
    cin >> n;

    vector<int> fibonacciNumbers = generateFibonacciNumbers(n);

    cout << "Первые " << n << " Числа Фибоначчи: ";
    for (int num : fibonacciNumbers) {
        cout << num << " ";
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
