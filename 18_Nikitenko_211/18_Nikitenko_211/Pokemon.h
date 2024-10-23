#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <unordered_map>

using namespace std;

class Pokemon {
private:
    string Type;// ���
    string Species;// ���
    string TypeEating; // ��� ���
protected:// ������� ����� ������ ��� ��������
    string NickName; // ��������
    int Age;// �������
    double Weight;// ���

    static unordered_map<string, int> speciesCount;


public:
    Pokemon() {}
    Pokemon(string s, string ty, string n, string te, int A, double W)
        : Species(s), Type(ty), NickName(n), TypeEating(te), Age(A), Weight(W) {
        speciesCount[Species]++; // ����������� ������� ��� ������� ����
    }


    // ����������� �����������
    Pokemon(const Pokemon& p) 
        : Species(p.Species), Type(p.Type), NickName(p.NickName),
          TypeEating(p.TypeEating), Age(p.Age), Weight(p.Weight) {
        // �� ����������� ������� ��� �����������
    }

    void evolve() {
        Weight += 15; // ����������� ��� �� 10 ��� ��������
        cout << "������� ��������������� � ������ ����� " << Weight << "!\n";
    }


    int getAge() { return Age; }
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
            Age == p.getAge() && Weight == p.getWeight());
    }

    virtual std::ostream& print(ostream& out) {
        return out << " �������  ���� " << Species << " ����������� ���� " << Type << "�� ��������� " << NickName << " �������� " << TypeEating
            << " ����� ��� " << Weight << " � ������� " << Age << "\n";
    }

    friend ostream& operator<< (ostream& out, Pokemon& p)
    {
        return p.print(out);
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
