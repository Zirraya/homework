﻿// 18_Nikitenko_211.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Ваш выбор: 18 Заповедник и его обитатели разных видов
// В начале сделать виртуальную функцию для общего класса(Pokemon)для всех покемонов, с попркавкой на вид; определить количество особоей одного вида(static),
// Почистить классы сделать произваольные классы более уникальными и сделать из private public, dinamc cast, в конструкторе копирование реализовать функцию

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

#include "Pokemon.h"
#include "Pidgeotto.h"
#include "Rhyhorn.h"
#include "Magikarp.h"

#include "List.h"

using namespace std;

// Условия для поиска

bool SearchBird(Pokemon* pk) {

    Pidgeotto* pidj = dynamic_cast<Pidgeotto*>(pk);
    if (pidj) {
        return (pidj->getNickName() == " Мягкий "); // Преобразование покемона в пиджеотта
    }
}


// Узнать имя класса
string getClassName(Pokemon* var) {
    return typeid(*var).name(); // узнали имя класса
}

//
int Pokemon::cntP = 0;
int main()
{
	setlocale(LC_ALL, "RUS");
    // Списки

    //Pidgeotto(string N, string C, string Ab, string CC, double WS, string s, string ty, string n, string te, double H, double W) : Pokemon(s, ty, n, te, H, W)

    Pidgeotto p1(" Кестрель ", " Горчичный ", " Зоркий глаз "," Красно - желтый ",2.0, " Птица ", " Летающий ", " Осторожный ", " Хищник ", 1.1, 30.0); 
    Pidgeotto p2(" Перышко ", " Коричневый ", " Порыв ", " Красный ", 1.9, " Птица ", " Летающий ", " Мягкий ", " Хищник ", 1.5, 25.0);
    Pidgeotto p3(" Вальтур ", " Горчичный ", " Танец Перьев ", " Желтый ", 2.0, " Птица ", " Летающий ", " Послушный ", " Хищник ", 1.2, 30.8);
    Pidgeotto p4(" Скайренджер ", " Рыжий ", " Металические когти ", " Лимонный ", 2.1, " Птица ", " Летающий ", " Свирепый ", " Хищник ", 1.2, 30.3);
    Pidgeotto p5(" Кроуи ", " Горчичный ", " Летящая грация ", " Белый ", 1.8, " Птица ", " Летающий ", " Мягкий ", " Хищник ", 1.2, 30.5);
    

    Rhyhorn r1(" Дефендер ", " Серый ", " Громоотвод ",0.5, " Шипастый ", " Земленно-каменный ", " Поспешный ", " Травоядный ", 1.7, 115.0); 
    Rhyhorn r2(" Граунд ", " Бурый ", " Безрасудный ",0.9, " Шипастый ", " Земленно-каменный ", " Одинокий ", " Травоядный ", 2.0, 115.7); 
    Rhyhorn r3(" Рейн ", " Горчичный ", " Камменая голова ",1.0, " Шипастый ", " Земленно-каменный ", " Смелый  ", " Травоядный ", 1.9, 111.8);  
  
     

    Magikarp m1(" Голден ", " Золотой ", " Быстрое плаванье ","Золотые ", " Рыба ", " Водный ", " Озорной ", "Всеядный ", 0.5, 11.0);  
    Magikarp m2(" Нова ", " Красный ", " Встревожонность ",  " Белые ", " Рыба ", " Водный  ", " Скромный ", "Всеядный ", 0.9, 10.5);
    Magikarp m3(" Ривер ", " Оранжевый ", " Танец Перьев ", " Голубые "," Рыба ", " Водный  ", " Робкий ", "Всеядный ", 0.3, 9.8);  
   

    //

	cout << "В регионе Хоенн, есть прекрасный заповедник - Сафари зона,";
	cout << "это специальный заповедник покемонов, куда тренеры могут войти, чтобы поймать определенные редкие виды покемонов.\n";
    cout << " \n";

    cout << "Прогуливаясь по заповеднику вы зашли в покемон центр. Тут обследуют покемонов. Н обследовании вы увидели следующих покемонов: \n";
   
    List lstzapovednik;

    lstzapovednik.push(&p1);
    lstzapovednik.push(&p2);
    lstzapovednik.push(&p3);
    lstzapovednik.push(&p4);
    lstzapovednik.push(&p5);

    lstzapovednik.push(&r1);
    lstzapovednik.push(&r2);
    lstzapovednik.push(&r3);

    lstzapovednik.push(&m1);
    lstzapovednik.push(&m2);
    lstzapovednik.push(&m3);

    lstzapovednik.print(cout);

    cout << "Сотрудники заповедника решили посчтиать количество особоей каждого вида, и вот что вышло: \n";

    cout << "Количество особей вида Птица: " << p1.getSpeciesCount() << endl;
    cout << "Количество особей вида Шипастый: " << r1.getSpeciesCount() << endl;
    cout << "Количество особей вида Рыба: " << m1.getSpeciesCount() << endl;

    cout << endl;

    // Динамическое пробразование
    cout << "Динамическое преобразование\n";
    Pokemon* pokemon = &p5;
    cout << *pokemon;
    Pidgeotto* pidg{ dynamic_cast<Pidgeotto*>(pokemon) };
    pidg->printPidg(cout); // Вызов доп функции из класса Пиджеотто
    //

    cout << endl;
    cout << "Кажется один из покемонов играя и сражаясь с другими набрался опыта...Что же происходит?!\n";
    Evolv evolver;
    evolver.Evoolv(p1); // Эволюция покемона
    cout << p1;
    cout << endl;

    cout << " Вы захотели взять к себе пиджеотто, которые являются самыми неконфликтными\n";
    lstzapovednik.findAll(SearchBird);

    cout << endl;
   
    system("pause");
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