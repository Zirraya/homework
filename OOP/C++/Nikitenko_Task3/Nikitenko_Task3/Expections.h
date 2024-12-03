#pragma once
#include <iostream>
#include <fstream>
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
	// Метод для проверки входных данных
	void validate(const string& N, int L, int A,
		const string& CM, const string& CP,
		const string& FF, const string& P,
		const string& S) {
		if (N.empty())
			throw invalid_argument("Имя не может быть пустым.");
		if (L <= 0)
			throw invalid_argument("Длина должна быть положительной.");
		if (A < 0 || A > 100)
			throw invalid_argument("Возраст должен быть в диапазоне от 0 до 100.");
		if (N.length() > 50 || CM.length() > 50 || CP.length() > 50 ||
			FF.length() > 50 || P.length() > 50 || S.length() > 50) {
			throw invalid_argument("Длина строки не может превышать 50 символов.");
		}
	}

	virtual void print() const { cerr << "Внимание! Еслы вы видите это сообщение значит объекты в список занесены неверно, возможна потеря данных. Программа аварийно завершает свою работу"; }
	
};
//
 
// Класс для вывода сообщения ошибки чтения файла
class ExpFile : public exception {
public:
	// Конструктор принимает сообщение об ошибке
	ExpFile(const string& message) : message(message) {}

	// Переопределение метода what() для возврата сообщения об ошибке
	virtual const char* what() const noexcept override {
		return message.c_str();
	}

private:
	string message; // Сообщение об ошибке
};
//

