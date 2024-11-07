#pragma once

#include "Pokemon.h"





class Magikarp : public Pokemon {

    string ColorFin; // ���� ���������

public:
    Magikarp() {}
    Magikarp(string N, string C, string Ab, string CF, string s, string ty, string n, string te, double H, double W) : Pokemon(N, C, Ab,s, ty, n, te, H, W) {
        Name = N; // ��� 
        Color = C; // ����
        Ability = Ab; // �����������
        ColorFin = CF; // ���� ���������


    }
    // �����������, ��� � ������ ��������� ���� ���� � �����, ��� � �������� ����� ��������� �������� ��� 
    // (���� ��������� ���������� ���������), � ����� ������ ������ � ���������
    string getColorFin() { return ColorFin; }

    // ��������� ������� �� �������� �� ��������� - ����� ���� ������� � 
  // ������ �� ������� ��������� - ������� ����� �����
    bool  similarity(Magikarp& p, bool condition(Magikarp& p1, Magikarp& p2)) {
        return condition(*this, p);
    }

    // �������� ������� �� ��������������� �� ����� - ���������� ��������� ==
    bool operator==(Magikarp& p) {
        return (Name == p.getName() && NickName == p.getNickName() && Color == p.getColor() &&
            Ability == p.getAbility() && Height == p.getHeight() && Weight == p.getWeight());
    }

    // ����� ���� � ������� - ���������� ������
    virtual std::ostream& print(ostream& out) {
        return out << "���������  �� ����� " << Name << "� �� ���������" << NickName << " ����� " << Color << "�� ������������" << Ability
           <<" �������� ����� "<< ColorFin << " ����� ��� " << Weight << " � ������ " << Height << "\n";
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