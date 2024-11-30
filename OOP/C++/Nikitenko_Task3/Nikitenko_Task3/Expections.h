#pragma once
#include <iostream>
using namespace std;


// ����� ��� ������ ��������� ���������� �������� �������� �������� � ����������
class ExpectionsSamaners {

public:
	virtual void print() { cerr << " ������: ������ �� ��� ��� ������\n"; }
};

// ����� ��� ������ ��������� ������ ��������� � ������� ��������
class ExptectionsVar : public ExpectionsSamaners {

	const int* expvar;
public:
	ExptectionsVar(const int* expv) :expvar(expv){}
	void print() const{
		cerr << "������ �������� ������������ ���� ������. ���������� " << *expvar << " �� �������� ������������� ����� (int), ���� �������� ������� �� �������� int \n" <<
		"���������� ��������� �������� " << "\n"; }

};
//

// ����� ��� ������ ���������� ������ ��� �������� ����
class ExpectionZero : public ExpectionsSamaners  {
	const int* zrd;
public:
	ExpectionZero(const int* z) :zrd(z){}
	void print() const{
		cerr << "������ ����� ����, ������� 0 �� ����������\n"<< "���������� ��������� �������� \n";
	}
};
//

// ���� ��� ������ ���������� ������ ������������
class ExptctionOverFlow : public ExpectionsSamaners {
	const int* of; 
public:
	ExptctionOverFlow(const int* o) : of(o) {}
		void print() const{
			cerr << "������ ������������, �������� �������� ������ ��� ������������ ��������� \n"
				<<"���������� ��������� �������� \n";
		}
};
//

//

// ����� ��� ��������� �������� ������
class ListExp {

public:
	virtual void print() const { cerr << "��������! ���� �� ������ ��� ��������� ������ ������� � ������ �������� �������, �������� ������ ������"; }
};

// ����� ��� ��������� ���������� ��������� � int
class ListExpInt : public ListExp {
	const string* msg;
	// �����������
public:
	ListExpInt(const string* message) : msg(message) {}

	void print() const {
		cerr << "�����: " << msg << endl;
	}

};
//

// ����� ��� ��������� ���������� ��������� �� string
class ListExpString : public ListExp {





};
//