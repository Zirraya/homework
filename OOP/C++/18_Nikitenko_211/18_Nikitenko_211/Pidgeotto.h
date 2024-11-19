#pragma once

#include "Pokemon.h"



class Pidgeotto : public Pokemon {

  
    string ColorCrest; // ���� �������
    double Wingspan; // ������ �������

    Evolv* b;



public:
    Pidgeotto() {}
    Pidgeotto(string N, string C, string Ab, string CC,double WS, string s, string ty, string n, string te, double H, double W) : Pokemon(N,C,Ab,s, ty, n, te, H, W) {
        Name = N; // ��� 
        Color = C; // ����
        Ability = Ab; // �����������
        ColorCrest = CC;
        Wingspan = WS;
        b = NULL;
      

    }
    // �����������, ��� � ������ ��������� ���� ���� � �����, ��� � �������� ����� ��������� �������� ��� 
    // (���� ��������� ���������� ���������), � ����� ������ ������ � ���������
    string getColorCrest() { return ColorCrest; }
    double getWingspan() { return Wingspan; }
   
   

    // ��������� ������� �� �������� �� ��������� - ����� ���� ������� � 
  // ������ �� ������� ��������� - ������� ����� �����
    bool  similarity(Pidgeotto& p, bool condition(Pidgeotto& p1, Pidgeotto& p2)) {
        return condition(*this, p);
    }

    // �������� ������� �� ��������������� �� ����� - ���������� ��������� ==
    bool operator==(Pidgeotto& p) {
        return (Name == p.getName() && NickName == p.getNickName() && Color == p.getColor() &&
            Ability == p.getAbility() && Height == p.getHeight() && Weight == p.getWeight());
    }

    // ����� ���� � ������� - ���������� ������
    virtual std::ostream& print(ostream& out) {
        return out << "���������  �� ����� " << Name << " � �� ���������" << NickName << " ����� " << Color << "�� ������������" << Ability
           <<" � �������� ����� "<< ColorCrest <<" ������ ������� ���������� " << Wingspan << " ����� ��� " << Weight << " � ������ " << Height << "\n";
    }

    virtual std::ostream& printPidg(ostream& cout) {
        return cout << "��� �� ��������� - ������� �����!\n";
    }

    friend ostream& operator<< (ostream& out, Pidgeotto& p)
    {
        return p.print(out);
    }

    // �������������� ������� ��� ��������� ���������� ������ ������� ����
    int getSpeciesCount() override {
        return Pokemon::getSpeciesCount();
    }

  

};
