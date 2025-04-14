// CountingortNikitenko.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Функция сортировки
vector<int> countSort(vector<int>& inputArray)
{
    int N = inputArray.size();
    int M = 0; // Нахождение максимального элемента массива inputArray[]. 

    for (int i = 0; i < N; i++)
        M = max(M, inputArray[i]);

   
    vector<int> countArray(M + 1, 0); // Массив  запоненный нулями для хранения всех вхождений входного массива

    //
    for (int i = 0; i < N; i++)      // Элементы из ввода сопоставленны с индексами
        countArray[inputArray[i]]++;
    //

    //
    for (int i = 1; i <= M; i++)            // Выичсиление суммы префикса по каждому индексу
        countArray[i] += countArray[i - 1];
    //

    // Создания массива вывода
    vector<int> outputArray(N);

    for (int i = N - 1; i >= 0; i--) {
        outputArray[countArray[inputArray[i]] - 1]
            = inputArray[i];

        countArray[inputArray[i]]--;
    }
    return outputArray;
    //
}
//

int main()
{
	setlocale(LC_ALL, "RUS");

    int n;
    cout << "Введите количество элементов в массиве: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Вывод
    vector<int> outputArray = countSort(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << outputArray[i] << " ";
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
