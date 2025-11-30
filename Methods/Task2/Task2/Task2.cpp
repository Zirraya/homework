// Task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <locale>

using namespace std;

// Структура для хранения коэффициентов полинома
struct PolynomialCoeffs {
    double a3, a2, a1, a0;
};

// Структура для хранения коэффициентов сплайна на отрезке
struct SplineSegment {
    double a, b, c, d;
    double x_left;
};

// Функция для решения СЛАУ методом прогонки (трехдиагональная матрица)
vector<double> solveTridiagonal(const vector<vector<double>>& A, const vector<double>& b) {
    int n = b.size();
    vector<double> alpha(n, 0), beta(n, 0), x(n, 0);

    // Прямой ход
    alpha[0] = -A[0][1] / A[0][0];
    beta[0] = b[0] / A[0][0];

    for (int i = 1; i < n - 1; i++) {
        double denominator = A[i][i] + A[i][i - 1] * alpha[i - 1];
        alpha[i] = -A[i][i + 1] / denominator;
        beta[i] = (b[i] - A[i][i - 1] * beta[i - 1]) / denominator;
    }

    // Обратный ход
    x[n - 1] = (b[n - 1] - A[n - 1][n - 2] * beta[n - 2]) /
        (A[n - 1][n - 1] + A[n - 1][n - 2] * alpha[n - 2]);

    for (int i = n - 2; i >= 0; i--) {
        x[i] = alpha[i] * x[i + 1] + beta[i];
    }

    return x;
}

// Вычисление значения полинома в точке x
double evaluatePolynomial(double x, const PolynomialCoeffs& coeffs) {
    return coeffs.a3 * x * x * x + coeffs.a2 * x * x + coeffs.a1 * x + coeffs.a0;
}

int main() {
    setlocale(LC_ALL, "Russian");

    vector<double> x_data, f_data;
    int n;

    // Ввод данных с клавиатуры
    cout << "Введите количество узлов интерполяции: ";
    cin >> n;

    cout << "Введите узлы интерполяции (x и f(x)):" << endl;
    for (int i = 0; i < n; i++) {
        double x, fx;
        cout << "Узел " << i + 1 << " - x: ";
        cin >> x;
        cout << "Узел " << i + 1 << " - f(x): ";
        cin >> fx;
        x_data.push_back(x);
        f_data.push_back(fx);
    }

    // Сортируем узлы по x
    vector<pair<double, double>> points;
    for (int i = 0; i < n; i++) {
        points.push_back({ x_data[i], f_data[i] });
    }
    sort(points.begin(), points.end());
    for (int i = 0; i < n; i++) {
        x_data[i] = points[i].first;
        f_data[i] = points[i].second;
    }

    // Ввод коэффициентов кубического полинома
    PolynomialCoeffs poly_coeffs;
    cout << "\nВведите коэффициенты кубического многочлена:" << endl;
    cout << "a3: ";
    cin >> poly_coeffs.a3;
    cout << "a2: ";
    cin >> poly_coeffs.a2;
    cout << "a1: ";
    cin >> poly_coeffs.a1;
    cout << "a0: ";
    cin >> poly_coeffs.a0;

    // Вычисление промежуточных точек
    vector<double> x_half;
    for (int i = 0; i < x_data.size() - 1; i++) {
        x_half.push_back((x_data[i] + x_data[i + 1]) / 2.0);
    }

    // Объединение всех точек
    vector<double> x_combined = x_data;
    x_combined.insert(x_combined.end(), x_half.begin(), x_half.end());
    sort(x_combined.begin(), x_combined.end());

    // Вывод таблицы
    cout << fixed << setprecision(3);
    cout << "\nТаблица с кубическим сплайном:" << endl;
    cout << "X\tF (исходные)\tF (Сплайн)" << endl;

    for (double x : x_combined) {
        // Проверяем, является ли точка исходной
        bool is_original = false;
        double original_value = 0.0;
        for (int i = 0; i < x_data.size(); i++) {
            if (abs(x - x_data[i]) < 1e-6) {
                is_original = true;
                original_value = f_data[i];
                break;
            }
        }

        double spline_value = evaluatePolynomial(x, poly_coeffs);

        if (is_original) {
            cout << x << "\t" << original_value << "\t\t" << spline_value << endl;
        }
        else {
            cout << x << "\t\t\t" << spline_value << endl;
        }
    }

    // Вывод коэффициентов полинома
    cout << "\nКоэффициенты кубического многочлена:" << endl;
    cout << "a3 = " << fixed << setprecision(6) << poly_coeffs.a3 << endl;
    cout << "a2 = " << fixed << setprecision(6) << poly_coeffs.a2 << endl;
    cout << "a1 = " << fixed << setprecision(6) << poly_coeffs.a1 << endl;
    cout << "a0 = " << fixed << setprecision(6) << poly_coeffs.a0 << endl;

    // Построение кубического сплайна
    int m = x_data.size() - 1;
    vector<double> h(m);
    for (int i = 0; i < m; i++) {
        h[i] = x_data[i + 1] - x_data[i];
    }

    // Построение матрицы СЛАУ
    vector<vector<double>> A(m + 1, vector<double>(m + 1, 0.0));
    vector<double> b(m + 1, 0.0);

    // Граничные условия
    A[0][0] = 1.0;
    A[m][m] = 1.0;

    // Заполнение внутренних строк
    for (int i = 1; i < m; i++) {
        A[i][i - 1] = h[i - 1];
        A[i][i] = 2.0 * (h[i - 1] + h[i]);
        A[i][i + 1] = h[i];
        b[i] = 3.0 * ((f_data[i + 1] - f_data[i]) / h[i] -
            (f_data[i] - f_data[i - 1]) / h[i - 1]);
    }

    // Вывод матрицы СЛАУ
    cout << "Матрица СЛАУ для сплайна:" << endl;
    cout << fixed << setprecision(1);
    for (int i = 0; i <= m; i++) {
        cout << "[";
        for (int j = 0; j <= m; j++) {
            cout << A[i][j];
            if (j < m) cout << " ";
        }
        cout << "]" << endl;
    }

    // Вывод вектора правой части
    cout << "\nВектор правой части СЛАУ для сплайна:" << endl;
    for (int i = 0; i <= m; i++) {
        cout << " " << b[i];
        if (i < m) cout << endl;
    }
 

    // Решение СЛАУ для коэффициентов c
    vector<double> c = solveTridiagonal(A, b);


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
