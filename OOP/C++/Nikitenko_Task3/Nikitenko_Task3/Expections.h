#pragma once
#include <iostream>
using namespace std;

class ExpectionsSamaners {

public:
	virtual void print() { cerr << " Ошибка: введен не тот тип данных\n"; }
};

// Класс для исключния ошибки связанной с выбором варианта
class ExptectionsVar : public ExpectionsSamaners {

	const int* expvar;
public:
	ExptectionsVar(const int* expv) :expvar(expv){}
	void print() const{ cerr << "Ошибка введения некоректного типа данных. Переменная " << expvar << " не является целочисленным типом (int) " << "\n"; }

};