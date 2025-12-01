// Task3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Решить следующую СЛАУ методом Гаусса:

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

// Функция для вывода матрицы
void printMatrix(const vector<vector<double>>& A, const vector<double>& b) {
    int n = A.size();

    cout << "\nМатрица системы A|b:\n";
    for (int i = 0; i < n; i++) {
        cout << "[";
        for (int j = 0; j < n; j++) {
            cout << setw(8) << fixed << setprecision(4) << A[i][j];
        }
        cout << " | " << setw(8) << b[i] << "]\n";
    }
}

// Метод Гаусса с выбором главного элемента
vector<double> gaussElimination(vector<vector<double>> A, vector<double> b) {
    int n = b.size();

    // Прямой ход метода Гаусса
    for (int i = 0; i < n; i++) {
        // Поиск максимального элемента в текущем столбце
        int maxRow = i;
        double maxVal = abs(A[i][i]);

        for (int k = i + 1; k < n; k++) {
            if (abs(A[k][i]) > maxVal) {
                maxVal = abs(A[k][i]);
                maxRow = k;
            }
        }

        // Перестановка строк
        if (maxRow != i) {
            swap(A[i], A[maxRow]);
            swap(b[i], b[maxRow]);
        }

        // Проверка на ноль на диагонали
        if (abs(A[i][i]) < 1e-10) {
            cout << "Матрица вырожденная или плохо обусловлена!\n";
            return vector<double>(n, 0.0);
        }

        // Нормализация текущей строки
        double pivot = A[i][i];
        for (int j = i; j < n; j++) {
            A[i][j] /= pivot;
        }
        b[i] /= pivot;

        // Исключение переменной из последующих строк
        for (int k = i + 1; k < n; k++) {
            double factor = A[k][i];
            for (int j = i; j < n; j++) {
                A[k][j] -= factor * A[i][j];
            }
            b[k] -= factor * b[i];
        }
    }

    // Обратный ход метода Гаусса
    vector<double> x(n, 0.0);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= A[i][j] * x[j];
        }
    }

    return x;
}

// Функция для ввода матрицы с клавиатуры
vector<vector<double>> inputMatrix(int n) {
    vector<vector<double>> A(n, vector<double>(n));

    cout << "\nВведите элементы матрицы A (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        cout << "Строка " << (i + 1) << " (через пробел " << n << " элементов): ";
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    return A;
}

// Функция для ввода вектора с клавиатуры
vector<double> inputVector(int n) {
    vector<double> b(n);

    cout << "\nВведите элементы вектора b (" << n << " элементов): ";
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    return b;
}


int main() {

    setlocale(LC_ALL, "RUS");

    int n;

    cout << "=== РЕШЕНИЕ СЛАУ МЕТОДОМ ГАУССА ===\n";

    // Ввод размерности матрицы
    cout << "\nВведите размерность матрицы (n): ";
    cin >> n;

    // Ручной ввод матрицы
    vector<vector<double>> A = inputMatrix(n);
    vector<double> b = inputVector(n);

    // Решение методом Гаусса
    vector<double> solution = gaussElimination(A, b);

    // Вывод решения
    cout << "\nРешение методом Гаусса:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << (i + 1) << " = " << fixed << setprecision(6) << solution[i] << endl;
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
