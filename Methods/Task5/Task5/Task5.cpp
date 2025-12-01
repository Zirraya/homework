// Task5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

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
            cout << setw(8) << fixed << setprecision(2) << A[i][j];
        }
        cout << " | " << setw(8) << b[i] << "]\n";
    }
}

// Метод простой итерации (Якоби)
vector<double> simpleIteration(const vector<vector<double>>& A, const vector<double>& b,
    double epsilon = 1e-6, int maxIterations = 1000) {
    int n = b.size();
    vector<double> x(n, 0.0);  // Начальное приближение - нулевой вектор
    vector<double> x_new(n, 0.0);

    cout << "\n=== Метод простой итерации ===\n";

    // Итерационный процесс
    for (int iter = 0; iter < maxIterations; iter++) {
        // Вычисление нового приближения
        for (int i = 0; i < n; i++) {
            double sum = 0.0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum += A[i][j] * x[j];
                }
            }
            if (abs(A[i][i]) < 1e-10) {
                cout << "Ошибка: нулевой диагональный элемент!\n";
                return vector<double>(n, 0.0);
            }
            x_new[i] = (b[i] - sum) / A[i][i];
        }

        // Проверка условия остановки
        double maxDiff = 0.0;
        for (int i = 0; i < n; i++) {
            double diff = abs(x_new[i] - x[i]);
            if (diff > maxDiff) {
                maxDiff = diff;
            }
        }

        // Проверка достижения требуемой точности
        if (maxDiff < epsilon) {
            cout << "Метод сошелся за " << iter + 1 << " итераций\n";
            return x_new;
        }

        // Обновление решения для следующей итерации
        x = x_new;
    }

    cout << "Достигнуто максимальное число итераций!\n";
    return x_new;
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
    double epsilon;

    cout << "=== РЕШЕНИЕ СЛАУ МЕТОДОМ ПРОСТОЙ ИТЕРАЦИИ ===\n";

    // Ввод размерности матрицы
    cout << "\nВведите размерность матрицы (n): ";
    cin >> n;

    // Ввод точности
    cout << "Введите точность решения (например, 0.001): ";
    cin >> epsilon;

    // Ручной ввод матрицы
    vector<vector<double>> A = inputMatrix(n);
    vector<double> b = inputVector(n);

    // Решение методом простой итерации
    vector<double> solution = simpleIteration(A, b, epsilon);


    cout << "Метод простой итерации\n\n";
    cout << "Метод сошелся за X итераций\n";
    cout << "Приближенное решение x* = [";
    for (int i = 0; i < n; i++) {
        cout << " " << fixed << setprecision(0) << solution[i];
        if (i < n - 1) cout << ".";
    }
    cout << " ]\n";

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
