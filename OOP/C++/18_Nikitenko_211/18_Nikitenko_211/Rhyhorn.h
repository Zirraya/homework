#pragma once
#include "Pokemon.h"


class Rhyhorn : public Pokemon {

   
    double LenhgHorn; // ����� ����

public:
    Rhyhorn() {}
    Rhyhorn(string N, string C, string Ab, double LH, string s, string ty, string n, string te, double H, double W) : Pokemon(N, C, Ab,s, ty, n, te, H, W) {
        Name = N; // ��� 
        Color = C; // ����
        Ability = Ab; // �����������
        LenhgHorn = LH;
    }
    // �����������, ��� � ������ ��������� ���� ���� � �����, ��� � �������� ����� ��������� �������� ��� 
    // (���� ��������� ���������� ���������), � ����� ������ ������ � ���������
    double getLenhgHorn() { return LenhgHorn; }
   

    // ��������� ������� �� �������� �� ��������� - ����� ���� ������� � 
  // ������ �� ������� ��������� - ������� ����� �����
    bool  similarity(Rhyhorn& p, bool condition(Rhyhorn& p1, Rhyhorn& p2)) {
        return condition(*this, p);
    }

    // �������� ������� �� ��������������� �� ����� - ���������� ��������� ==
    bool operator==(Rhyhorn& p) {
        return (Name == p.getName() && NickName == p.getNickName() && Color == p.getColor() &&
            Ability == p.getAbility() && Height == p.getHeight() && Weight == p.getWeight());
    }

    // ����� ���� � ������� - ���������� ������
    virtual std::ostream& print(ostream& out) {
        return out << "�������  �� ����� " << Name << "� �� ���������" << NickName << " ����� " << Color << "�� ������������" << Ability
           <<" � ������� ���� " <<LenhgHorn<< " ����� ��� " << Weight << " � ������ " << Height << "\n";
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