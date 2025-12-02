// Task6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

// Функция правой части дифференциального уравнения
double f(double x, double y, double V) {
    return 2 * V * x + V * x * x - y;
}

// Точное решение
double exact_solution(double x, double V) {
    return V * x * x;
}

// Метод Эйлера
vector<pair<double, double>> euler_method(double x0, double y0, double h, int n, double V) {
    vector<pair<double, double>> result;
    double x = x0;
    double y = y0;

    result.push_back({ x, y });

    for (int i = 0; i < n; i++) {
        y = y + h * f(x, y, V);
        x = x + h;
        result.push_back({ x, y });
    }

    return result;
}

// Усовершенствованный метод Эйлера
vector<pair<double, double>> improved_euler_method(double x0, double y0, double h, int n, double V) {
    vector<pair<double, double>> result;
    double x = x0;
    double y = y0;

    result.push_back({ x, y });

    for (int i = 0; i < n; i++) {
        double y_half = y + (h / 2) * f(x, y, V);
        double x_half = x + h / 2;

        y = y + h * f(x_half, y_half, V);
        x = x + h;

        result.push_back({ x, y });
    }

    return result;
}

// Функция для форматированного вывода таблицы
void print_table(const string& title, const vector<pair<double, double>>& numerical,
    const vector<double>& exact, const vector<double>& errors) {
    int n = numerical.size();

    cout << "\n" << title << ":" << endl;
    cout << string(120, '-') << endl;

    // Вывод x
    cout << "| x:    ";
    for (int i = 0; i < n; i++) {
        cout << "| " << fixed << setprecision(3) << setw(7) << numerical[i].first << " ";
    }
    cout << "|" << endl;

    // Вывод y_N (численного решения)
    cout << "| y_N:  ";
    for (int i = 0; i < n; i++) {
        cout << "| " << fixed << setprecision(3) << setw(7) << numerical[i].second << " ";
    }
    cout << "|" << endl;

    // Вывод y_T (точного решения)
    cout << "| y_T:  ";
    for (int i = 0; i < n; i++) {
        cout << "| " << fixed << setprecision(3) << setw(7) << exact[i] << " ";
    }
    cout << "|" << endl;

    // Вывод погрешности
    cout << "| погрешность: ";
    for (int i = 0; i < n; i++) {
        cout << "| " << fixed << setprecision(3) << setw(7) << errors[i] << " ";
    }
    cout << "|" << endl;

    cout << string(120, '-') << endl;
}

int main() {
    setlocale(LC_ALL, "RUS");

    double x0, y0, h, V;
    int n;

    // Ввод данных с клавиатуры
    cout << "Введите начальное значение x0: ";
    cin >> x0;

    cout << "Введите начальное значение y0: ";
    cin >> y0;

    cout << "Введите шаг h: ";
    cin >> h;

    cout << "Введите количество шагов n: ";
    cin >> n;

    cout << "Введите параметр V: ";
    cin >> V;

    // Вычисление решений
    vector<pair<double, double>> euler_result = euler_method(x0, y0, h, n, V);
    vector<pair<double, double>> improved_result = improved_euler_method(x0, y0, h, n, V);

    // Вычисление точных решений и погрешностей
    vector<double> exact_euler, exact_improved;
    vector<double> errors_euler, errors_improved;

    for (int i = 0; i < euler_result.size(); i++) {
        double exact_val = exact_solution(euler_result[i].first, V);
        exact_euler.push_back(exact_val);
        errors_euler.push_back(fabs(euler_result[i].second - exact_val));
    }

    for (int i = 0; i < improved_result.size(); i++) {
        double exact_val = exact_solution(improved_result[i].first, V);
        exact_improved.push_back(exact_val);
        errors_improved.push_back(fabs(improved_result[i].second - exact_val));
    }

    // Вывод результатов
    cout << "\nДифференциальное уравнение: y' = 2Vx + Vx^2 - y, y(x0) = V*x0^2" << endl;
    cout << "Параметры: x0 = " << x0 << ", y0 = " << y0 << ", h = " << h
        << ", n = " << n << ", V = " << V << endl;

    print_table("Метод Эйлера", euler_result, exact_euler, errors_euler);
    print_table("Усовершенствованный метод Эйлера", improved_result, exact_improved, errors_improved);

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
