#pragma once
// Функция для нахождения среднего арифметического четных элементов массива
double Average(int arr[], int size) {
    int even_count = 0;
    int even_sum = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            even_count++;
            even_sum += arr[i];
        }
    }

    if (even_count == 0) {
        return 0; // Если нет четных элементов, то ноль :0
    }
    else {
        return static_cast<double>(even_sum) / even_count;
    }
}

// Функция для вывода номера нечетных максимальных элементов массива
void print_odd_max_indices(int arr[], int size) {
    int max_value = arr[0];
    int odd_max_count = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
            odd_max_count = 0; // Сброс счетчика, если находится новое максимальное
        }

        if (arr[i] == max_value && arr[i] % 2 != 0) {
            odd_max_count++;   
        }
    }

    if (odd_max_count == 0) {  
    }
}

