// stroki2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

#define COUNT 34
#define LENGTH 2 // символ + нулевой символ

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");

    string bufString;
    string tempString = "";
    string minString;
    string maxString;
    char arrayOfChars[COUNT][LENGTH] = {
        "T", "h", "e", " ", "u", "n", "i", "c", "o", "r", "n", " ",  "l", "i", "v", "e", "d",  " ", "i", "n", " ",  "a", " ",  "l", "i", "l", "a", "c", " ", " ", "w", "o", "o", "d"
    };
    minString = arrayOfChars[0][0];
    maxString = arrayOfChars[0][0];
    int min = 0;
    int max = 0;
    for (int c = 0; c < COUNT; c++) {
        // заполняем исходную строку
        bufString += arrayOfChars[c][0];
        // добавляем символы в строку, пока не встретим пробел
        if (arrayOfChars[c][0] != 32) {
            tempString += arrayOfChars[c][0];
        }
        else {
            if (tempString.size() <= minString.size()) {
                // если строка меньше минимальной
                if (tempString.size() < minString.size()) {
                    // делаем минимальной текущую
                    minString = tempString;
                    min = c - tempString.size();
                }
                else { // если строка равна минимальной, сравниваем посимвольно
                    if (minString.compare(tempString) > 0) {
                        // делаем минимальной строку с меньшими символами
                        minString = tempString;
                        min = c - tempString.size();
                    }
                }
            }
            if (tempString.size() >= maxString.size()) {
                // если строка больше максимальной
                if (tempString.size() > maxString.size()) {
                    maxString = tempString;
                    max = c - tempString.size();
                }
                else {
                    // если строка равна максимальной, сравниваем посимвольно
                    if (maxString.compare(tempString) < 0) {
                        // делаем максимальной строку с бОльшими символами
                        maxString = tempString;
                        max = c - tempString.size();
                    }
                }
            }
            tempString = "";
        }
    }
    // выводим исходную
    cout << "Изночальная строка: ";
    for (int c = 0; c < COUNT; c++) {
        cout << arrayOfChars[c][0];
    }
    cout << endl;
    if (min < max) {
        // если минимальная строка левее максимальной, то сначала
        // заменяем максимальную строку минимальной
        bufString.erase(max, maxString.size());
        bufString.insert(max, minString);
        bufString.erase(min, minString.size());
        bufString.insert(min, maxString);
    }
    else {
        // если минимальная строка правее максимальной, то сначала
        // заменяем минимальную строку максимальной
        bufString.erase(min, minString.size());
        bufString.insert(min, maxString);
        bufString.erase(max, maxString.size());
        bufString.insert(max, minString);
    }
    // выводим результат
    cout << "Полученая строка: " << bufString << endl;
    
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
