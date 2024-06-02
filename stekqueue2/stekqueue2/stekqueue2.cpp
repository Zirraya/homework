// stekqueue2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Функция для вставки четного элемента
void insertLastEven(queue<int>& q, int lastEven, int minNum) {
	queue<int> temp;
	while (!q.empty()) {
		if (q.front() == minNum) {
			temp.push(lastEven);
		}
		temp.push(q.front());
		q.pop();
	}
	q = temp;
}

// Функция для нахождения минимального элемента
int findMin(queue<int> qCopy) { // Создание копии
	int minNum = qCopy.front();
	while (!qCopy.empty()) {
		if (qCopy.front() < minNum) minNum = qCopy.front();
		qCopy.pop();
	}
	return minNum;
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

	queue<int> qCopy = q; // Создание копии
	int minNum = findMin(qCopy); // Нахождение минимального элемента

	qCopy = q; // Сбросить копию
	int lastEven = -1;
	while (!qCopy.empty()) {
		if (qCopy.front() % 2 == 0) lastEven = qCopy.front();
		qCopy.pop();
	}

	insertLastEven(q, lastEven, minNum);

	cout << "Измененная очередь: ";
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
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
