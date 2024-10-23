#pragma once

#include "Pokemon.h"





class Magikarp : public Pokemon {

    string Name;
    string Color;
    string Ability;

public:
    Magikarp() {}
    Magikarp(string N, string C, string Ab, string s, string ty, string n, string te, int A, double W) : Pokemon(s, ty, n, te, A, W) {
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
    bool  similarity(Magikarp& p, bool condition(Magikarp& p1, Magikarp& p2)) {
        return condition(*this, p);
    }

    // �������� ������� �� ��������������� �� ����� - ���������� ��������� ==
    bool operator==(Magikarp& p) {
        return (Name == p.getName() && NickName == p.getNickName() && Color == p.getColor() &&
            Ability == p.getAbility() && Age == p.getAge() && Weight == p.getWeight());
    }

    // ����� ���� � ������� - ���������� ������
    virtual std::ostream& print(ostream& out) {
        return out << "���������  �� ����� " << Name << "� �� ���������" << NickName << " ����� " << Color << "�� ������������" << Ability
            << " ����� ��� " << Weight << " � ������� " << Age << "\n";
    }

    friend ostream& operator<< (ostream& out, Magikarp& p)
    {
        return p.print(out);
    }
    // �������������� ������� ��� ��������� ���������� ������ ������� ����
    int getSpeciesCount() override {
        return Pokemon::getSpeciesCount();
    }

};