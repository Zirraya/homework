// steckqueue1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool isComposite(int num) {
    if (num <= 1) return false; // 0 and 1 are not composite
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return true; // found a divisor, so it's composite
    }
    return false; // no divisors found, so it's prime
}

   queue<int> shiftQueue(std::queue<int> q) {
    vector<int> vec;
    while (!q.empty()) {
        vec.push_back(q.front());
        q.pop();
    }

    int compositeIndex = -1;
    for (int i = 0; i < vec.size(); ++i) {
        if (isComposite(vec[i])) {
            compositeIndex = i;
            break;
        }
    }

    if (compositeIndex != -1) {
        rotate(vec.begin(), vec.begin() + compositeIndex, vec.end());
    }

    queue<int> result;
    for (int num : vec) {
        result.push(num);
    }

    return result;
}



int main()
{
	setlocale(LC_ALL, "RUS");

    queue<int> q;

    int num;
    cout << "Введите очередь (введите 0 что бы закончить введение): ";
    while (true) {
        cin >> num;
        if (num == 0) break;
        q.push(num);
    }
      
    cout << endl; cout << "Очередь псоле циклического свдига: ";

    q = shiftQueue(q);

    while (!q.empty()) {
           cout << q.front() << " ";
        q.pop();
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
