﻿// steck4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stack>
#include <iostream>

using namespace std;

bool isPrime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {


	setlocale(LC_ALL, "RUS");

	stack<int> s;

	cout << "Введите целые числа (введите 0 чтобы закончить ввод): ";
	int num;
	while (true) {
		cin >> num;
		if (num == 0) break;
		s.push(num);
	}

	stack<int> result;
	while (!s.empty()) {
		int num = s.top();
		s.pop();
		if (!isPrime(num)) {
			result.push(num);
		}
	}

	cout << "Результат: ";
	while (!result.empty()) {
		cout << result.top() << " ";
		result.pop();
	}
	cout << endl;

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