// Tree_Nikitenko.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <iomanip>

#define RED true
#define BLACK false

using namespace std;

HANDLE outp = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbInfo;

void max_height(node* x, short& max, short deepness = 1) { // требует проверки на существование корня
	if (deepness > max) max = deepness;
	if (x->left) max_height(x->left, max, deepness + 1);
	if (x->right) max_height(x->right, max, deepness + 1);
}
bool isSizeOfConsoleCorrect(const short& width, const short& height) {
	GetConsoleScreenBufferInfo(outp, &csbInfo);
	COORD szOfConsole = csbInfo.dwSize;
	if (szOfConsole.X < width && szOfConsole.Y < height) cout << "Please increase the height and width of the terminal. ";
	else if (szOfConsole.X < width) cout << "Please increase the width of the terminal. ";
	else if (szOfConsole.Y < height) cout << "Please increase the height of the terminal. ";
	if (szOfConsole.X < width || szOfConsole.Y < height) {
		cout << "Size of your terminal now: " << szOfConsole.X << ' ' << szOfConsole.Y
			<< ". Minimum required: " << width << ' ' << height << ".\n";
		return false;
	}
	
		return true;
}

void print_helper(node* x, const COORD pos, const short offset) {
	SetConsoleTextAttribute(outp, x->color == RED ? 12 : 8);
	SetConsoleCursorPosition(outp, pos);
	cout << setw(offset + 1) << x->key;

	if (x->left) print_helper(x->left, { pos.X, short(pos.Y + 1) }, offset >> 1);
	if (x->right) print_helper(x->right, { short(pos.X + offset), short(pos.Y + 1) }, offset
		, → >> 1);
}
void print() {
	if (root) {
		short max = 1;
		max_height(root, max);
		short width = 1 << max + 1, max_w = 128; // вычисляем ширину вывода
		if (width > max_w) width = max_w;
		while (!isSizeOfConsoleCorrect(width, max)) system("pause");
		for (short i = 0; i < max; ++i) cout << '\n'; // резервируем место для вывода
		GetConsoleScreenBufferInfo(outp, &csbInfo); // получаем данные
		COORD endPos = csbInfo.dwCursorPosition;
		print_helper(root, { 0, short(endPos.Y - max) }, width >> 1);
		SetConsoleCursorPosition(outp, endPos);
		SetConsoleTextAttribute(outp, 7);
	}
}




int main()
{
	HANDLE outp = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int k = 0; k <= 255; ++k) {
		SetConsoleTextAttribute(outp, k);
		cout << k << " Some text" << '\n';
	}
	SetConsoleTextAttribute(outp, 7);
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
