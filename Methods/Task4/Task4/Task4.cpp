// Task4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

// Функция для ввода трехдиагональной матрицы с клавиатуры
void inputTridiagonalMatrix(int n, vector<double>& a, vector<double>& b, vector<double>& c) {
    cout << "\nВведите элементы трехдиагональной матрицы:\n";

    // Нижняя диагональ (a)
    cout << "Нижняя диагональ (a), " << n - 1 << " элементов (a1...a" << n - 1 << "): ";
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }

    // Главная диагональ (b)
    cout << "Главная диагональ (b), " << n << " элементов (b1...b" << n << "): ";
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    // Верхняя диагональ (c)
    cout << "Верхняя диагональ (c), " << n - 1 << " элементов (c1...c" << n - 1 << "): ";
    for (int i = 0; i < n - 1; i++) {
        cin >> c[i];
    }
}

// Функция для ввода вектора с клавиатуры
vector<double> inputVector(int n) {
    vector<double> d(n);

    cout << "\nВведите элементы вектора правых частей d (" << n << " элементов): ";
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    return d;
}

// Метод прогонки для решения трехдиагональной системы
vector<double> tridiagonalSolve(const vector<double>& a, const vector<double>& b,
    const vector<double>& c, const vector<double>& d) {
    int n = b.size();

    // Проверка размеров
    if (a.size() != n - 1 || c.size() != n - 1 || d.size() != n) {
        cout << "Ошибка: неверные размеры входных данных!\n";
        return vector<double>();
    }

    // Векторы для прогоночных коэффициентов
    vector<double> alpha(n - 1);
    vector<double> beta(n);
    vector<double> x(n);

    // Прямой ход
    // Первое уравнение
    alpha[0] = -c[0] / b[0];
    beta[0] = d[0] / b[0];

    // Промежуточные уравнения
    for (int i = 1; i < n - 1; i++) {
        double denominator = b[i] + a[i - 1] * alpha[i - 1];
        alpha[i] = -c[i] / denominator;
        beta[i] = (d[i] - a[i - 1] * beta[i - 1]) / denominator;
    }

    // Последнее уравнение
    beta[n - 1] = (d[n - 1] - a[n - 2] * beta[n - 2]) / (b[n - 1] + a[n - 2] * alpha[n - 2]);

    // Обратный ход
    x[n - 1] = beta[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        x[i] = alpha[i] * x[i + 1] + beta[i];
    }

    return x;
}

// Функция для вывода трехдиагональной системы
void printTridiagonalSystem(const vector<double>& a, const vector<double>& b,
    const vector<double>& c, const vector<double>& d) {
    int n = b.size();

    cout << "\nТрехдиагональная система:\n";
    for (int i = 0; i < n; i++) {
        cout << "Уравнение " << (i + 1) << ": ";

        if (i > 0) {
            cout << fixed << setprecision(2) << a[i - 1] << "*x" << i << " + ";
        }

        cout << b[i] << "*x" << (i + 1);

        if (i < n - 1) {
            cout << " + " << c[i] << "*x" << (i + 2);
        }

        cout << " = " << d[i] << endl;
    }
}


int main() {
    setlocale(LC_ALL, "RUS");

    int n;

    cout << "=== Метод прогонки ===\n";

    // Ввод размерности системы
    cout << "\nВведите размерность системы (n, n >= 2): ";
    cin >> n;

    if (n < 2) {
        cout << "Ошибка: размерность должна быть не менее 2!\n";
        return 1;
    }

    // Векторы для хранения диагоналей
    vector<double> a(n - 1);  // нижняя диагональ (элементы под главной)
    vector<double> b(n);    // главная диагональ
    vector<double> c(n - 1);  // верхняя диагональ (элементы над главной)

    // Ввод трехдиагональной матрицы
    inputTridiagonalMatrix(n, a, b, c);

    // Ввод вектора правых частей
    vector<double> d = inputVector(n);

    // Вывод системы
    printTridiagonalSystem(a, b, c, d);

    // Решение методом прогонки
    cout << "\n\n=== РЕШЕНИЕ МЕТОДОМ ПРОГОНКИ ===\n";
    vector<double> solution = tridiagonalSolve(a, b, c, d);

    if (solution.empty()) {
        cout << "Ошибка при решении системы!\n";
        return 1;
    }

    // Вывод решения
    cout << "\nРешение системы:\n";
    cout << string(40, '-') << "\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << (i + 1) << " = " << fixed << setprecision(8) << solution[i] << endl;
    }

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
