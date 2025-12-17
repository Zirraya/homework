// Task8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <functional>
#include <clocale>

using namespace std;

double f(double x, double V) {
    return V * (4.0 / 3.0 * x + 1.0 / 4.0 * x * x + 1.0 / 5.0 * x * x * x);
}

// Численное интегрирование на [a, b] методом Симпсона
double integrate_simpson(function<double(double)> integrand,
    double a, double b, int n = 1000) {
    if (n % 2 == 1) n++;
    double h = (b - a) / n;
    double s = integrand(a) + integrand(b);
    for (int i = 1; i < n; ++i) {
        double x = a + h * i;
        s += integrand(x) * (i % 2 == 0 ? 2.0 : 4.0);
    }
    return s * h / 3.0;
}

vector<vector<double>> calc_aik(int n) {
    vector<vector<double>> aik(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            auto integrand = [i, k](double x) {
                double ai, bk;
                if (i == 0) ai = x;
                else if (i == 1) ai = x * x;
                else ai = x * x * x;

                if (k == 0) bk = x;
                else if (k == 1) bk = x * x;
                else bk = x * x * x;

                return ai * bk;
            };
            aik[i][k] = integrate_simpson(integrand, 0.0, 1.0);
        }
    }
    return aik;
}

vector<double> calc_yk(int n, double V) {
    vector<double> yk(n, 0.0);
    for (int k = 0; k < n; ++k) {
        auto integrand = [k, V](double x) {
            double bk;
            if (k == 0) bk = x;
            else if (k == 1) bk = x * x;
            else bk = x * x * x;
            return f(x, V) * bk;
        };
        yk[k] = integrate_simpson(integrand, 0.0, 1.0);
    }
    return yk;
}

vector<double> gauss_solve(const vector<vector<double>>& A,
    const vector<double>& b) {
    int n = static_cast<int>(b.size());
    vector<vector<double>> Ab(n,vector<double>(n + 1));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            Ab[i][j] = A[i][j];
        }
        Ab[i][n] = b[i];
    }

    for (int i = 0; i < n; ++i) {
        double pivot = Ab[i][i];
        for (int j = i + 1; j < n; ++j) {
            double factor = Ab[j][i] / pivot;
            for (int k = i; k <= n; ++k) {
                Ab[j][k] -= factor * Ab[i][k];
            }
        }
    }

    vector<double> x(n, 0.0);
    for (int i = n - 1; i >= 0; --i) {
        double sum = 0.0;
        for (int j = i + 1; j < n; ++j) {
            sum += Ab[i][j] * x[j];
        }
        x[i] = (Ab[i][n] - sum) / Ab[i][i];
    }
    return x;
}

void solve_equation(double V, int n) {
    auto aik = calc_aik(n);
    auto yk = calc_yk(n, V);

    vector<vector<double>> A(n,vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            A[i][k] = aik[i][k];
        }
        A[i][i] += 1.0;
    }

    auto q = gauss_solve(A, yk);

    double h = 0.1;
    vector<double> x_vals;
    for (double x = 0.0; x <= 1.0 + 1e-12; x += h) {
        x_vals.push_back(x);
    }

    vector<double> y_numerical(x_vals.size(), 0.0);
    vector<double> y_exact(x_vals.size(), 0.0);
    vector<double> error(x_vals.size(), 0.0);

    for (size_t i = 0; i < x_vals.size(); ++i) {
        double x = x_vals[i];
        double y_val = f(x, V);
        for (int j = 0; j < n; ++j) {
            double aj;
            if (j == 0) aj = x;
            else if (j == 1) aj = x * x;
            else aj = x * x * x;
            y_val -= q[j] * aj;
        }
        y_numerical[i] = y_val;
        y_exact[i] = V * x;
        error[i] = fabs(y_numerical[i] - y_exact[i]);
    }

    cout << "\nРешение интегрального уравнения Фредгольма в случае вырожденного ядра:\n";
    cout << std::string(150, '-') << "\n";

    cout << "x:          ";
    for (double xv : x_vals) {
        cout << setw(13) << fixed << setprecision(6) << xv;
    }
    cout << "\n";

    cout << "y численное:";
    for (double yn : y_numerical) {
        cout << setw(13) << fixed << setprecision(6) << yn;
    }
    cout << "\n";

    cout << "y точное:   ";
    for (double ye : y_exact) {
        cout << setw(13) << fixed << setprecision(6) << ye;
    }
    cout << "\n";

    cout << "Погрешность:";
    for (double er : error) {
        cout << std::setw(13) << std::fixed << std::setprecision(6) << er;
    }
    cout << "\n";

    cout << std::string(150, '-') << "\n";
}

int main() {
    setlocale(LC_ALL, "Russian"); 

    double V;
    int n;

    cout << "Введите значение V: ";
    std::cin >> V;

    cout << "Введите размерность n (например, 3): ";
    cin >> n;

    solve_equation(V, n);

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
