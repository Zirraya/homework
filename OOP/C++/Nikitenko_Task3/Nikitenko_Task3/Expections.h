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
	// ����� ��� �������� ������� ������
	void validate(const std::string& N, int L, int A,
		const std::string& CM, const std::string& CP,
		const std::string& FF, const std::string& P,
		const std::string& S) {
		if (N.empty())
			throw std::invalid_argument("��� �� ����� ���� ������.");
		if (L <= 0)
			throw std::invalid_argument("����� ������ ���� �������������.");
		if (A < 0 || A > 100)
			throw std::invalid_argument("������� ������ ���� � ��������� �� 0 �� 100.");
		if (N.length() > 50 || CM.length() > 50 || CP.length() > 50 ||
			FF.length() > 50 || P.length() > 50 || S.length() > 50) {
			throw std::invalid_argument("����� ������ �� ����� ��������� 50 ��������.");
		}
	}

	virtual void print() const { cerr << "��������! ���� �� ������ ��� ��������� ������ ������� � ������ �������� �������, �������� ������ ������"; }
	
};

