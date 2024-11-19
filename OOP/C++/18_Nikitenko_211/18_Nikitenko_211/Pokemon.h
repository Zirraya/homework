#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <unordered_map>

using namespace std;

class Pokemon {
public:
    string Name;
    string Color;
    string Ability;
    string Type;// ���
    string Species;// ���
    string TypeEating; // ��� ���

    static int cntP;



protected:// ������� ����� ������ ��� ��������
    string NickName; // ��������
    double Height;// �������
    double Weight;// ���

    static unordered_map<string, int> speciesCount;


public:
    Pokemon() {}
    Pokemon(string N, string C, string Ab, string s, string ty, string n, string te, double H, double W)
        : Name(N), Color(C), Ability(Ab),Species(s), Type(ty), NickName(n), TypeEating(te), Height(H), Weight(W) {
        speciesCount[Species]++; // ����������� ������� ��� ������� ����
        cntP++;
    }


    // ����������� �����������
    Pokemon(const Pokemon& p) 
        : Species(p.Species), Type(p.Type), NickName(p.NickName),
          TypeEating(p.TypeEating), Height(p.Height), Weight(p.Weight) {
        // �� ����������� ������� ��� �����������
        evolve(); //����� �������
    }


    string getName() { return Name; }
    string getColor() { return Color; }
    string getAbility() { return Ability; }
    int getHeight() { return Height; }
    int getWeight() { return Weight; }
    string getNickName() { return NickName; }
    string getType() { return Type; }
    string getSpecies() { return Species; }
    string getTypeEating() { return TypeEating; }


    // ����������� ������� ��� ��������� ���������� ������ ������� ����
    virtual int getSpeciesCount() {
        return speciesCount[Species];
    }

    // ������� �������� ���� ���, ����� ����� ����� ����������� ��������������
    virtual bool operator==(Pokemon& p) {
        return (Species == p.getSpecies() && Type == p.getType() && NickName == p.getNickName() && TypeEating == p.getTypeEating() &&
            Height == p.getHeight() && Weight == p.getWeight() && Name==p.getName() && Color==p.getColor() && Ability == p.getAbility() );
    }

    virtual std::ostream& print(ostream& out) {
        return out << " �������  ���� " << Species << " ����������� ���� " << Type << "�� ��������� " << NickName << " �������� " << TypeEating
            << " ����� ��� " << Weight << " � ������ " << Height << "\n";
    }

    friend ostream& operator<< (ostream& out, Pokemon& p)
    {
        return p.print(out);
    }

    void evolve() {
            Height += 1; // ����������� ���� �� 10 ��� ��������
            Weight += 15;
            cout << Type << "������� ��������������� � ���� �������: ���� " << Height << " ��� " << Weight << "!\n";
    }

};
// ������������� ������������ �����
unordered_map<string, int> Pokemon::speciesCount;

// ������ ������� ����� ����������������
class Evolv {
private:
    int V;
public:
    Evolv() { V = 100; }

    void Evoolv(Pokemon& p) {
        if (V > 0) {
            V--;
            cout << "������� ������� ��������������!\n";
            p.evolve(); // �������� ����� �������� ��������
        }
        else {
            cout << "�������� ����������, ������������ �����!\n";
        }
    }
    int getV() { return V; }
};
//
