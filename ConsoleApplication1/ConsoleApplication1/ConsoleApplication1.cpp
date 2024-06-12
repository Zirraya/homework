// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double Series(double x, double eps)
{
    double term = x * x * x / 6, sum = term;
    x = x * x;
    for (int n = 4; abs(term) > eps; n += 2)
        sum += term *= -x / (n * (n + 1));
    return sum;
}


int main()
    
{
    
    for (double x = 0; x < 1; x += 0.1)
        cout << setw(5) << x << setw(12) << x - sin(x) << setw(12) << Series(x, 1e-7) << endl;
}




//int i, n, fl;
//double z;
//cout << "n=";
//cin >> n;
//system("cls");
//
//double* a = new double[n];
//
//for (i = 0; i < n; i++)
//{
//    cout << "a[" << i + 1 << "]=";
//    cin >> a[i];
//    cout << "\n";
//}
//system("cls");
//do
//{
//    fl = 0;
//    for (i = 0; i < n - 1; i++)
//    {
//        if (a[i] > a[i + 1]) { fl = 1; z = a[i]; a[i] = a[i + 1]; a[i + 1] = z; }
//    }
//} while (fl == 1);
//
//
//z = a[0];
//a[0] = a[n - 1];
//a[n - 1] = z;
//
//for (i = 0; i < n; i++)
//{
//    cout << a[i] << " ";
//}
//
//cout << "\n\n\n";
//system("pause");
//delete[] a;
  


//setlocale(LC_ALL, "RUS");
//int a, b, h;
//cout << "Введите игнтервал (a < b):\n";
//cout << "a = ";
//cin >> a;
//cout << "b = ";
//cin >> b;
//cout << "\nEnter a step:\n";
//cout << "h = ";
//cin >> h;
//cout << "\nOutput of the program:\n";
//do {
//    cout << a << " ";
//    a += h;
//} while (a <= b);
//system("pause");
//return 0;



 /*   setlocale(LC_ALL, "RUS");
    int a, b, c, X;
    cout << "Enter integer a, b, c, X:\n";
    cin >> a >> b >> c >> X;

    if ((a + b + c) % 2 == 0 && (a + b + c) % X == 0)
        cout << "YES\n";
    else
        cout << "NO\n";

    system("pause");
    return 0;
}*/

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
