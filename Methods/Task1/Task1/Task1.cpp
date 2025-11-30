// Task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <locale>

using namespace std;

// Функция для ввода данных с клавиатуры
void inputData(vector<double>& x_data, vector<double>& f_data) {
    int n;
    cout << "Введите количество точек: ";
    cin >> n;

    x_data.resize(n);
    f_data.resize(n);

    cout << "\nВведите значения X:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "X[" << i << "] = ";
        cin >> x_data[i];
    }

    cout << "\nВведите значения F(X):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "F(" << x_data[i] << ") = ";
        cin >> f_data[i];
    }
}

// Функция для вывода введенных данных
void printInputData(const vector<double>& x_data, const vector<double>& f_data) {
    cout << "\nВведенные данные:" << endl;
    cout << setw(10) << "X" << setw(10) << "F(X)" << endl;
    cout << string(20, '-') << endl;
    for (int i = 0; i < x_data.size(); i++) {
        cout << setw(10) << x_data[i] << setw(10) << f_data[i] << endl;
    }
    cout << endl;
}

// Функция для решения системы линейных уравнений методом Гаусса
vector<double> solveLinearSystem(vector<vector<double>> A, vector<double> b) {
    int n = A.size();

    // Прямой ход метода Гаусса
    for (int i = 0; i < n; i++) {
        // Поиск главного элемента
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (abs(A[k][i]) > abs(A[maxRow][i])) {
                maxRow = k;
            }
        }

        // Перестановка строк
        swap(A[i], A[maxRow]);
        swap(b[i], b[maxRow]);

        // Исключение
        for (int k = i + 1; k < n; k++) {
            double factor = A[k][i] / A[i][i];
            for (int j = i; j < n; j++) {
                A[k][j] -= factor * A[i][j];
            }
            b[k] -= factor * b[i];
        }
    }

    // Обратный ход
    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }

    return x;
}

// Функция для вычисления значения полинома
double polynomial(double x, const vector<double>& coeffs) {
    double result = 0.0;
    for (int i = 0; i < coeffs.size(); i++) {
        result += coeffs[i] * pow(x, i);
    }
    return result;
}

// Функция для представления полинома в виде строки
string polynomialToString(const vector<double>& coeffs) {
    string result;
    int degree = coeffs.size() - 1;

    for (int i = 0; i < coeffs.size(); i++) {
        if (coeffs[i] != 0 || degree == 0) {
            if (!result.empty() && coeffs[i] >= 0) {
                result += " + ";
            }
            else if (!result.empty() && coeffs[i] < 0) {
                result += " - ";
            }

            string term;
            if (i == 0) {
                term = to_string(coeffs[i]);
            }
            else {
                double absCoef = abs(coeffs[i]);
                if (absCoef != 1.0) {
                    term = to_string(absCoef) + " * ";
                }
                term += "x";
                if (i > 1) {
                    term += "^" + to_string(i);
                }
            }

            // Удаляем лишние нули после запятой
            size_t pos = term.find('.');
            if (pos != string::npos) {
                size_t lastNonZero = term.find_last_not_of('0');
                if (lastNonZero == pos) {
                    term = term.substr(0, pos);
                }
                else {
                    term = term.substr(0, lastNonZero + 1);
                }
            }

            result += term;
        }
        degree--;
    }

    return result;
}

// Функция для вычисления коэффициентов многочлена Ньютона
vector<double> newtonCoefficients(const vector<double>& x, const vector<double>& y) {
    int n = x.size();
    vector<double> coeffs = y;

    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            coeffs[i] = (coeffs[i] - coeffs[i - 1]) / (x[i] - x[i - j]);
        }
    }

    return coeffs;
}

// Функция для вычисления значения многочлена Ньютона
double newtonPolynomial(double x, const vector<double>& coeffs, const vector<double>& x_data) {
    int n = coeffs.size() - 1;
    double p = coeffs[n];

    for (int k = 1; k <= n; k++) {
        p = coeffs[n - k] + (x - x_data[n - k]) * p;
    }

    return p;
}

// Функция для вывода вектора
void printVector(const string& name, const vector<double>& vec) {
    cout << name << ": ";
    for (double val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

// Функция для вывода матрицы
void printMatrix(const string& name, const vector<vector<double>>& matrix) {
    cout << name << ":" << endl;
    for (const auto& row : matrix) {
        for (double val : row) {
            cout << setw(8) << val << " ";
        }
        cout << endl;
    }
}

int main() {


   
     setlocale(LC_ALL, "Russian");   

    vector<double> x_data, f_data;

    // Меню выбора способа ввода данных
    int choice;
    cout << "Выберите способ ввода данных:" << endl;
    cout << "1 - Ввести данные с клавиатуры" << endl;
    cout << "2 - Использовать пример данных (X: -1, 1, 2, 3; F: 0, 2, 9, 28)" << endl;
    cout << "Ваш выбор: ";
    cin >> choice;

    if (choice == 1) {
        inputData(x_data, f_data);
    }
    else {
        // Пример данных по умолчанию
        x_data = { -1, 1, 2, 3 };
        f_data = { 0, 2, 9, 28 };
    }

    printInputData(x_data, f_data);

    // Проверка на достаточное количество точек
    if (x_data.size() < 2) {
        cout << "Ошибка: необходимо как минимум 2 точки для интерполяции!" << endl;
        return 1;
    }

    // Построение матрицы Вандермонда
    int n = x_data.size();
    vector<vector<double>> A(n, vector<double>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = pow(x_data[i], j);
        }
    }

    printMatrix("Матрица Вандермонда", A);
    cout << endl;

    // Решение системы уравнений для нахождения коэффициентов
    vector<double> coefficients = solveLinearSystem(A, f_data);

    cout << "Найденные коэффициенты:" << endl;
    for (int i = 0; i < coefficients.size(); i++) {
        cout << "a" << i << " = " << coefficients[i] << endl;
    }
    cout << endl;

    // Вывод уравнения многочлена
    cout << "Уравнение интерполяционного многочлена:" << endl;
    cout << polynomialToString(coefficients) << endl << endl;

    // Вычисление коэффициентов для многочлена Ньютона
    vector<double> newton_coeffs = newtonCoefficients(x_data, f_data);

    cout << "Коэффициенты многочлена Ньютона:" << endl;
    for (int i = 0; i < newton_coeffs.size(); i++) {
        cout << "b" << i << " = " << newton_coeffs[i] << endl;
    }
    cout << endl;

    // Расчет значений в промежуточных точках
    vector<double> x_half;
    for (int i = 0; i < x_data.size() - 1; i++) {
        x_half.push_back((x_data[i] + x_data[i + 1]) / 2.0);
    }

    // Объединение и сортировка всех точек
    vector<double> x_combined = x_data;
    x_combined.insert(x_combined.end(), x_half.begin(), x_half.end());
    sort(x_combined.begin(), x_combined.end());

    // Вывод итоговой таблицы
    cout << "Итоговая таблица:" << endl;
    cout << setw(10) << "X" << setw(15) << "F (исходные)"
        << setw(15) << "F (Лагранж)" << setw(15) << "F (Ньютон)" << endl;
    cout << string(55, '-') << endl;

    for (double x : x_combined) {
        // Проверяем, является ли x исходной точкой
        bool isOriginal = find(x_data.begin(), x_data.end(), x) != x_data.end();
        double original_f = 0.0;
        if (isOriginal) {
            auto it = find(x_data.begin(), x_data.end(), x);
            int index = distance(x_data.begin(), it);
            original_f = f_data[index];
        }

        double lagrange_f = polynomial(x, coefficients);
        double newton_f = newtonPolynomial(x, newton_coeffs, x_data);

        cout << fixed << setprecision(4);
        cout << setw(10) << x;
        if (isOriginal) {
            cout << setw(15) << original_f;
        }
        else {
            cout << setw(15) << "-";
        }
        cout << setw(15) << lagrange_f << setw(15) << newton_f << endl;
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
