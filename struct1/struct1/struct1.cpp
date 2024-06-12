// struct1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


using namespace std;

struct Train {
    string namePynkt;
    int numTrain;
    string timeArrive;
};

Train putTrain(Train t) {
    cout << "\n Введите номер пунтка - ";
    cin >> t.namePynkt;
    cout << "\n Введите номер позеда - ";
    cin >> t.numTrain;
    cout << "\n Введите время прибытиые - ";
    cin >> t.timeArrive;

    return t;
}

void outTrain(Train t) {
    cout << "\nНомер: " << t.numTrain << " Путь: " << t.namePynkt << " Прибытие: " << t.timeArrive;
}

void outTrainList(Train t[], int  size) {
    for (int i = 0; i < size; i++) {
        outTrain(t[i]);
    }
}

void swap(Train& x, Train& y)
{
    Train temp = x;
    x = y;
    y = temp;
}

void showInfoSort(Train t[], int  size) {
    cout << "\n__________" << "Таблица времени поезда" << "__________";
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (t[i].numTrain < t[j].numTrain) swap(t[i], t[j]);
        }
    }
    outTrainList(t, size);

}

int main()
{
    int size = 5, numTrainEnter;
    bool found = false;
    Train TrainList[size];
    for (int i = 0; i < size; i++) {
        TrainList[i] = putTrain(TrainList[i]);
    }
    cout << "Введите номер поезда:";
    cin >> numTrainEnter;
    for (int i = 0; i < size; i++) {
        if (numTrainEnter == TrainList[i].numTrain) {
            outTrain(TrainList[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "\n Информация о поезде найдена";
    }

    showInfoSort(TrainList, size);

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
