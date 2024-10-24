#pragma once

#include "Pokemon.h"



class Pidgeotto : public Pokemon {

    string Name;
    string Color;
    string Ability;

    Evolv* b;
public:
    Pidgeotto() {}
    Pidgeotto(string N, string C, string Ab, string s, string ty, string n, string te, int A, double W) : Pokemon(s, ty, n, te, A, W) {
        Name = N; // ��� 
        Color = C; // ����
        Ability = Ab; // �����������
        b = NULL;

    }
    // �����������, ��� � ������ ��������� ���� ���� � �����, ��� � �������� ����� ��������� �������� ��� 
    // (���� ��������� ���������� ���������), � ����� ������ ������ � ���������

    string getName() { return Name; }
    string getColor() { return Color; }
    string getAbility() { return Ability; }

    // ��������� ������� �� �������� �� ��������� - ����� ���� ������� � 
  // ������ �� ������� ��������� - ������� ����� �����
    bool  similarity(Pidgeotto& p, bool condition(Pidgeotto& p1, Pidgeotto& p2)) {
        return condition(*this, p);
    }

    // �������� ������� �� ��������������� �� ����� - ���������� ��������� ==
    bool operator==(Pidgeotto& p) {
        return (Name == p.getName() && NickName == p.getNickName() && Color == p.getColor() &&
            Ability == p.getAbility() && Age == p.getAge() && Weight == p.getWeight());
    }

    // ����� ���� � ������� - ���������� ������
    virtual std::ostream& print(ostream& out) {
        return out << "���������  �� ����� " << Name << " � �� ���������" << NickName << " ����� " << Color << "�� ������������" << Ability
            << " ����� ��� " << Weight << " � ������� " << Age << "\n";
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
