// struct2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

struct ThePoint {
    static double eps;
    double x, y;
    ThePoint() :x(0), y(0), sum_dist_squire(0) {}
    ThePoint(double x_, double y_) :x(x_), y(y_), sum_dist_squire(0) {}
    bool operator == (const ThePoint& anotherPoint) {
        return (x - anotherPoint.x) < eps && (y - anotherPoint.y) < eps;
    }
    double get_dist_squire(const ThePoint& anotherPoint) {
        double dx = x - anotherPoint.x;
        double dy = y - anotherPoint.y;
        return dx * dx + dy * dy;
    }
    void add_dist_squire(const ThePoint& anotherPoint) {
        sum_dist_squire += get_dist_squire(anotherPoint);
    }
    double sum_dist_squire;
};
double ThePoint::eps = 1e-7;

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "RUS");

    ThePoint th_p[] = {
ThePoint(1,2),
ThePoint(2,3),
ThePoint(2,4),
ThePoint(3,5),
ThePoint(1,5),
ThePoint(2,9),
ThePoint(5,2)
    };
    int sz = sizeof(th_p) / sizeof(*th_p);
    int max_ind(0);
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            if (i != j)th_p[i].add_dist_squire(th_p[j]);
        }
        if (th_p[i].sum_dist_squire > th_p[max_ind].sum_dist_squire)max_ind = i;
    }
    cout << "Точка x=" << th_p[max_ind].x << " y= " << th_p[max_ind].y; 
    cout << endl;
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
