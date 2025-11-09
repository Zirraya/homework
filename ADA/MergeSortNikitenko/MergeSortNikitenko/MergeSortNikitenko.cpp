// MergeSortNikitenko.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <random> // Для генерации случайных чисел
#include <limits> // Для std::numeric_limits
#include <chrono>  // Для измерения времени
using namespace std;

// Слияния двух подмассивов arr[].
// Первый подмассив arr[left..mid]
// Второй подмассив arr[mid+1..right]
void merge(vector<int>& arr, int left,
    int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    
    vector<int> L(n1), R(n2); // Создания вектора

    // Копирование 
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    //

    int i = 0, j = 0;
    int k = left;

    // Объеденение времееных массиов векторов
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    //

    // Копирование оставшихся элементов в L[], если конечно они существуют
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    //

    // Копирование оставшихся элементов в R[], если конечно они существуют
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Начало — для левого индекса, а конец — для правого индекса
// подмассива arr для сортировки
void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
//

// Функция для вывода вектора
void printVector(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}
//

int main()
{
  
    setlocale(LC_ALL, "RUS");

    int n;
    cout << "Введите количество элементов в массиве: ";
    cin >> n;

    vector<int> arr(n);

    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(time(0)));

    // Генерация случайных элементов массива
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Генерация случайного числа от 0 до 99
    }

    // Вывод исходного массива
    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Измерение времени сортировки
    auto start = chrono::high_resolution_clock::now();

    // Сортировка
    mergeSort(arr, 0, n - 1);

    // Вывод отсортированного массива
    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    auto end = chrono::high_resolution_clock::now();

    // Вывод времени выполнения сортировки
    cout << "Время выполнения сортировки: "
        << chrono::duration<double, milli>(end - start).count()
        << " миллисекунд." << endl;

  

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
