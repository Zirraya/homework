#pragma once
#include <iostream>
using namespace std;

class ExpectionsSamaners {

public:
	virtual void print() { cerr << " ������: ������ �� ��� ��� ������\n"; }
};

// ����� ��� ��������� ������ ��������� � ������� ��������
class ExptectionsVar : public ExpectionsSamaners {

	const int* expvar;
public:
	ExptectionsVar(const int* expv) :expvar(expv){}
	void print() const{ cerr << "������ �������� ������������ ���� ������. ���������� " << expvar << " �� �������� ������������� ����� (int) " << "\n"; }

};