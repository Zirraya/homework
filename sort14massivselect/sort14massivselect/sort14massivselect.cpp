// sort14massivselect.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void selectionSort(vector<int>& arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            swap(arr[i], arr[maxIndex]);
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

    // Сортировка диагоналей, параллельных главной, по убыванию
    for (int k = 1 - n; k < n; k++) {
        vector<int> diagonalValues;
        for (int i = 0; i < n; i++) {
            int j = i + k;
            if (j >= 0 && j < n) {
                diagonalValues.push_back(matrix[i][j]);
            }
        }
        selectionSort(diagonalValues, diagonalValues.size());
        int index = 0;
        for (int i = 0; i < n; i++) {
            int j = i + k;
            if (j >= 0 && j < n) {
                matrix[i][j] = diagonalValues[index];
                index++;
            }
        }
    }

    // Запись отсортированной матрицы в файл
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
