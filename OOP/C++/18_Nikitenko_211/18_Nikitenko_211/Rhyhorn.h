#pragma once
#include "Pokemon.h"


class Rhyhorn : public Pokemon {

    string Name;
    string Color;
    string Ability;

public:
    Rhyhorn() {}
    Rhyhorn(string N, string C, string Ab, string s, string ty, string n, string te, int A, double W) : Pokemon(s, ty, n, te, A, W) {
        Name = N; // ��� 
        Color = C; // ����
        Ability = Ab; // �����������



    }
    // �����������, ��� � ������ ��������� ���� ���� � �����, ��� � �������� ����� ��������� �������� ��� 
    // (���� ��������� ���������� ���������), � ����� ������ ������ � ���������

    string getName() { return Name; }
    string getColor() { return Color; }
    string getAbility() { return Ability; }

    // ��������� ������� �� �������� �� ��������� - ����� ���� ������� � 
  // ������ �� ������� ��������� - ������� ����� �����
    bool  similarity(Rhyhorn& p, bool condition(Rhyhorn& p1, Rhyhorn& p2)) {
        return condition(*this, p);
    }

    // �������� ������� �� ��������������� �� ����� - ���������� ��������� ==
    bool operator==(Rhyhorn& p) {
        return (Name == p.getName() && NickName == p.getNickName() && Color == p.getColor() &&
            Ability == p.getAbility() && Age == p.getAge() && Weight == p.getWeight());
    }

    // ����� ���� � ������� - ���������� ������
    virtual std::ostream& print(ostream& out) {
        return out << "�������  �� ����� " << Name << "� �� ���������" << NickName << " ����� " << Color << "�� ������������" << Ability
            << " ����� ��� " << Weight << " � ������� " << Age << "\n";
    }

    friend ostream& operator<< (ostream& out, Rhyhorn& p)
    {
        return p.print(out);
    }
    // �������������� ������� ��� ��������� ���������� ������ ������� ����
    int getSpeciesCount() override {
        return Pokemon::getSpeciesCount();
    }

};