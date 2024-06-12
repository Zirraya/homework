// 1vector2(variant2).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void replaceInRange(vector<int>& sequence, int a, int b, int X) 
{

    for (int& num : sequence) {
        if (num >= a && num <= b) {
            num = X;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    cout << "Изначальная последовательность: ";
    vector<int> sequence = { 5, 2, 8, 3, 5, 2, 8, 10 };
 
    for (int elem : sequence) {
        cout << elem << " ";
    }
    cout << endl;
    

  
    
    cout << "Последовательность в обратном порядке: ";
    reverse(sequence.begin(), sequence.end()); // Вывод последовательности в обратном порядке
    for (int elem : sequence) {
        cout << elem << " ";
    }

    cout << endl;
    cout << "Введите интервал" << endl;
    cout << "Введите a: "; int a; cin >> a; cout << endl;
    cout << "Введите b: "; int b; cin >> b; cout << endl;

    cout << "Введите эелемент X: "; int X; cin >> X;
    replaceInRange(sequence, a, b, X);  // Замена чисел в интервале [a, b] на X
    cout << "Полученная последоватьеность с элементом X: ";
    for (int elem : sequence) {
        cout << elem << " ";
    }
    cout << endl;

    cout << "Отсотрированная последовательность: ";
    sort(sequence.begin(), sequence.end()); // Сортировка элементов
    for (int elem : sequence) {
        cout << elem << " ";
    }
    cout << endl;
    cout << endl;

    // Вставка нового элемента в отсортированную последовательность

    cout << "Последовательность с Y: "; cout << endl;
    cout << "Введите новый элемент в отсартированную последовательность: "; int Y; cin >> Y;
    auto it = upper_bound(sequence.begin(), sequence.end(), Y);
    sequence.insert(it, Y);
    for (int elem : sequence) {
        cout << elem << " ";
    }
    cout << endl;
    cout << endl;
    //

    cout << "Последовательность с удаленными повторяющимеся элементами: ";
    sequence.erase(unique(sequence.begin(), sequence.end()), sequence.end()); // Удаление повторяющихся элементов

    // Вывод результирующей последовательности
    for (int num : sequence) {
        cout << num << " ";
    }
    cout << endl;

    //

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
