// shablonfuct6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


using namespace std;

// создание и ввод массива
template < typename X>
 X * *create(X c, int n, int m) {//создание
     X * *a = new X * [n]; //выделение памяти
     for (int i = 0; i < n; i++)
         a[i] = new X[m];
     for (int i = 0; i < n; i++) //ввод массива
         for (int j = 0; j < m; j++)
         cin >> a[i][j];
     return a;
    
}
 //

 // функция вывода изначального массива 
 template < typename X>
 void print(X * *a, int n, int m) { 
     for (int i = 0; i < n; i++, cout << endl)
         for (int j = 0; j < m; j++)
         cout << a[i][j] << " ";
    
}
 //

// Нахождение первого минимального и паследнего максимального элемента и замена столбцов
 template<typename X>
 X** change(X** a, int n, int m, int jmin = 0, int jmax = 0) {//замена
     cout << "Измененный массив a:\n";
     for (int i = 0; i < n; i++)
     {
         swap(a[i][jmin], a[i][jmax]);
         for (int j = 0; j < m; j++)
             cout << a[i][j] << " ";
         cout << endl;
     }

     for (int i = 0; i < n; i++)
         delete[] a[i];
     delete[] a;
     return a;
 }
 //

int main()
{

    setlocale(LC_ALL, "rus");
     int n, m;
     cout << "Input dimension\n";
     cin >> n >> m;
     char c;
     do {
         cout << "Введите тип:\n1 - int\n2 - double\n3 - char\n4 - float\n";
         int k;
         cin >> k;
         switch (k) {//вызываем различные типы данных
         case 1:
         {
             int c = 1;
             int** a = create(c, n, m);
             cout << "INT:\n";
             print(a, n, m);
             a = change(a, n, m);
             cout << "New:\n";
             print(a, n, m);
             break;
         }
         case 2:
         {
             double c1 = 1;
             double** a1 = create(c1, n, m);
             cout << "DOUBLE:\n";
             print(a1, n, m);
             a1 = change(a1, n, m);
             cout << "New:\n";
             print(a1, n, m);
             break;
         }

         case 3:
         {
             float c3 = 1;
             float** a3 = create(c3, n, m);
             cout << "FLOAT:\n";
             print(a3, n, m);
             a3 = change(a3, n, m);
             cout << "New:\n";
             print(a3, n, m);
             break;
         }
         default: cout << "Неправильно введены данные\n";

         }
         cout << "Еще раз? Y - да, N - нет\n";
         cin >> c; // повторяем запуск программы пока не введем N
     }
     while (c != 'N');

    system("pause");
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
