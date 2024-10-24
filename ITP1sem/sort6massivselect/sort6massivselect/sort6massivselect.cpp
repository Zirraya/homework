// sort6massivselect.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


// Функция сортировки Шелла с шагом 2
void shellSort(vector<int>& arr, int n, bool ascending) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            if (ascending) {
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
            }
            else {
                for (j = i; j >= gap && arr[j - gap] < temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
            }
            arr[j] = temp;
        }
    }
}



int main()
{
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    int n = 5; // Размерность массива
    vector<vector<int>> matrix(n, vector<int>(n));


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inFile >> matrix[i][j];
        }
    }

    for (int j = 0; j < n; j++) {
        vector<int> column;
        for (int i = 0; i < n; i++) {
            column.push_back(matrix[i][j]);
        }

        if (j % 2 == 0) {
            shellSort(column, n, false); // Сортировка по убыванию для четных столбцов
        }
        else {
            shellSort(column, n, true); // Сортировка по возрастанию для нечетных столбцов
        }

        for (int i = 0; i < n; i++) {
            matrix[i][j] = column[i];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            outFile << matrix[i][j] << " ";
        }
        outFile << endl;
    }

    inFile.close();
    outFile.close();

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
