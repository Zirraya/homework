// Task7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Точное решение
double y_exact(double x, double T) {
    return T * x * x * (x - T);
}

// Функции для краевой задачи
double p(double x) { return x * x; }
double q(double x) { return x; }

double f_boundary(double x, double V) {
    return 4 * V * pow(x, 4) - 3 * V * V * pow(x, 3) + 6 * V * x - 2 * V * V;
}

// Функции для метода неопределенных коэффициентов
double fi(double x, int i, double T) {
    return pow(x, i + 1) - T * pow(x, i);
}

double fi_shtrih(double x, int i, double T) {
    return (i + 1) * pow(x, i) - i * T * pow(x, i - 1);
}

double fi_shtrih_shtrih(double x, int i, double T) {
    if (i == 0) return 0;
    else if (i == 1) return 2 - T;
    else return i * (i + 1) * pow(x, i - 1) - (i - 1) * i * T * pow(x, i - 2);
}

// Метод Гаусса для решения СЛАУ
vector<double> gauss_solve(vector<vector<double>>& A, vector<double>& b) {
    int n = A.size();

    // Прямой ход
    for (int k = 0; k < n; k++) {
        // Поиск главного элемента
        int max_row = k;
        double max_val = abs(A[k][k]);

        for (int i = k + 1; i < n; i++) {
            if (abs(A[i][k]) > max_val) {
                max_val = abs(A[i][k]);
                max_row = i;
            }
        }

        // Перестановка строк
        if (max_row != k) {
            swap(A[k], A[max_row]);
            swap(b[k], b[max_row]);
        }

        // Проверка на сингулярность
        if (abs(A[k][k]) < 1e-10) {
            throw runtime_error("Матрица является сингулярной или плохо обусловленной");
        }

        // Нормировка
        double pivot = A[k][k];
        for (int j = k; j < n; j++) {
            A[k][j] /= pivot;
        }
        b[k] /= pivot;

        // Исключение
        for (int i = k + 1; i < n; i++) {
            double factor = A[i][k];
            for (int j = k; j < n; j++) {
                A[i][j] -= factor * A[k][j];
            }
            b[i] -= factor * b[k];
        }
    }

    // Обратный ход
    vector<double> x(n, 0.0);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= A[i][j] * x[j];
        }
    }

    return x;
}

// Решение краевой задачи обоими методами
void solve_boundary_problem(double T, int n) {
    double h = T / n;

    // 1. Разностный метод
    vector<double> x_rm(n + 1);
    for (int i = 0; i <= n; i++) {
        x_rm[i] = i * h;
    }

    // Создание матрицы и правой части
    vector<vector<double>> A_rm(n + 1, vector<double>(n + 1, 0.0));
    vector<double> d_rm(n + 1, 0.0);

    // Граничные условия
    A_rm[0][0] = 1.0;
    A_rm[n][n] = 1.0;
    d_rm[0] = 0.0;
    d_rm[n] = 0.0;

    // Внутренние узлы
    for (int i = 1; i < n; i++) {
        double x = x_rm[i];
        A_rm[i][i - 1] = 1.0 / (h * h) - p(x) / (2.0 * h);
        A_rm[i][i] = -2.0 / (h * h) + q(x);
        A_rm[i][i + 1] = 1.0 / (h * h) + p(x) / (2.0 * h);
        d_rm[i] = f_boundary(x, T);
    }

    // Решение СЛАУ
    vector<double> y_rm = gauss_solve(A_rm, d_rm);

    // Точные значения и погрешность
    vector<double> y_exact_rm(n + 1);
    vector<double> error_rm(n + 1);
    for (int i = 0; i <= n; i++) {
        y_exact_rm[i] = y_exact(x_rm[i], T);
        error_rm[i] = abs(y_rm[i] - y_exact_rm[i]);
    }

    // 2. Метод неопределенных коэффициентов
    vector<double> x_nk = x_rm;

    // Проверка граничных условий
    if (abs(y_exact(0, T)) > 1e-6 || abs(y_exact(T, T)) > 1e-6) {
        cout << "Внимание: граничные условия выполняются неточно!" << endl;
    }

    // Создание матрицы для метода неопределенных коэффициентов
    int m = n - 1;  // Количество коэффициентов
    vector<vector<double>> A_nk(m, vector<double>(m, 0.0));
    vector<double> d_nk(m, 0.0);

    // Заполнение матрицы
    for (int i = 0; i < m; i++) {
        double x = x_nk[i + 1];  // Внутренние точки
        d_nk[i] = f_boundary(x, T);

        for (int j = 0; j < m; j++) {
            A_nk[i][j] = fi_shtrih_shtrih(x, j + 1, T) +
                p(x) * fi_shtrih(x, j + 1, T) +
                q(x) * fi(x, j + 1, T);
        }
    }

    // Решение СЛАУ для коэффициентов
    vector<double> a_coeff = gauss_solve(A_nk, d_nk);

    // Вычисление приближенного решения
    vector<double> y_nk(n + 1, 0.0);
    for (int i = 0; i <= n; i++) {
        double x = x_nk[i];
        y_nk[i] = 0.0;
        for (int j = 0; j < m; j++) {
            y_nk[i] += a_coeff[j] * fi(x, j + 1, T);
        }
    }

    // Точные значения и погрешность
    vector<double> y_exact_nk(n + 1);
    vector<double> error_nk(n + 1);
    for (int i = 0; i <= n; i++) {
        y_exact_nk[i] = y_exact(x_nk[i], T);
        error_nk[i] = abs(y_nk[i] - y_exact_nk[i]);
    }

    // Вывод результатов
    cout << "\nРазностный метод:" << endl;
    cout << string(150, '-') << endl;
    cout << "x:    ";
    for (int i = 0; i <= n; i++) {
        cout << fixed << setprecision(3) << setw(12) << x_rm[i];
    }
    cout << "\ny_H:  ";
    for (int i = 0; i <= n; i++) {
        cout << fixed << setprecision(3) << setw(12) << y_rm[i];
    }
    cout << "\ny_T:  ";
    for (int i = 0; i <= n; i++) {
        cout << fixed << setprecision(3) << setw(12) << y_exact_rm[i];
    }
    cout << "\nпогрешность: ";
    for (int i = 0; i <= n; i++) {
        cout << fixed << setprecision(3) << setw(12) << error_rm[i];
    }
    cout << "\n" << string(150, '-') << endl;

    cout << "\nМетод неопределенных коэффициентов:" << endl;
    cout << string(150, '-') << endl;
    cout << "x:    ";
    for (int i = 0; i <= n; i++) {
        cout << fixed << setprecision(3) << setw(12) << x_nk[i];
    }
    cout << "\ny_H:  ";
    for (int i = 0; i <= n; i++) {
        cout << fixed << setprecision(3) << setw(12) << y_nk[i];
    }
    cout << "\ny_T:  ";
    for (int i = 0; i <= n; i++) {
        cout << fixed << setprecision(3) << setw(12) << y_exact_nk[i];
    }
    cout << "\nпогрешность: ";
    for (int i = 0; i <= n; i++) {
        cout << fixed << setprecision(3) << setw(12) << error_nk[i];
    }
    cout << "\n" << string(150, '-') << endl;
}

int main() {

    setlocale(LC_ALL, "RUS");

    double T;
    int n;

    // Ввод данных с клавиатуры
    cout << "Решение краевой задачи:" << endl;
    cout << "y'' + x^2 * y' + x * y = 10Vx - 3VTx^3 - 2VT" << endl;
    cout << "y(0) = 0, y(T) = 0" << endl;
    cout << "\nВведите значение T (V): ";
    cin >> T;
    cout << "Введите количество отрезков разбиения (n, например 9): ";
    cin >> n;

    try {
        solve_boundary_problem(T, n);
    }
    catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
        return 1;
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
