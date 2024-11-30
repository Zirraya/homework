#pragma once
#include <iostream>
using namespace std;


// Класс для вывода обработки исключения введений значений вводимых с клавиатуры
class ExpectionsSamaners {

public:
	virtual void print() { cerr << " Ошибка: введен не тот тип данных\n"; }
};

// Класс для вывода исключния ошибки связанной с выбором варианта
class ExptectionsVar : public ExpectionsSamaners {

	const int* expvar;
public:
	ExptectionsVar(const int* expv) :expvar(expv){}
	void print() const{
		cerr << "Ошибка введения некоректного типа данных. Переменная " << *expvar << " не является целочисленным типом (int), либо значение выходит за пределеы int \n" <<
		"Выполнение программы прервано " << "\n"; }

};
//

// Класс для вывода исключения ошибки при введения нуля
class ExpectionZero : public ExpectionsSamaners  {
	const int* zrd;
public:
	ExpectionZero(const int* z) :zrd(z){}
	void print() const{
		cerr << "Ошибка ввода нуля, варинта 0 не существует\n"<< "Выполнение программы прервано \n";
	}
};
//

// Клас для вывода исключения ошибки переполнения
class ExptctionOverFlow : public ExpectionsSamaners {
	const int* of; 
public:
	ExptctionOverFlow(const int* o) : of(o) {}
		void print() const{
			cerr << "Ошибка переполнения, введенно значение больше чем существующих вариантов \n"
				<<"Выполнение программы прервано \n";
		}
};
//

//

// Класс для обработки объектов списка
class ListExp {

public:
	virtual void print() const { cerr << "Внимание! Еслы вы видите это сообщение значит объекты в список занесены неверно, возможна потеря данных"; }
};

// Класс для обработки исключений связанных с int
class ListExpInt : public ListExp {
	const string* msg;
	// Конструктор
public:
	ListExpInt(const string* message) : msg(message) {}

	void print() const {
		cerr << "Хуита: " << msg << endl;
	}

};
//

// Класс для обработки исключений связанных со string
class ListExpString : public ListExp {





};
//