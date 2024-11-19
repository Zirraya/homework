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
    string Type;// тип
    string Species;// вид
    string TypeEating; // что ест

    static int cntP;



protected:// потомки могут менять эти значения
    string NickName; // Характер
    double Height;// возраст
    double Weight;// вес

    static unordered_map<string, int> speciesCount;


public:
    Pokemon() {}
    Pokemon(string N, string C, string Ab, string s, string ty, string n, string te, double H, double W)
        : Name(N), Color(C), Ability(Ab),Species(s), Type(ty), NickName(n), TypeEating(te), Height(H), Weight(W) {
        speciesCount[Species]++; // Увеличиваем счетчик для данного вида
        cntP++;
    }


    // Конструктор копирования
    Pokemon(const Pokemon& p) 
        : Species(p.Species), Type(p.Type), NickName(p.NickName),
          TypeEating(p.TypeEating), Height(p.Height), Weight(p.Weight) {
        // Не увеличиваем счетчик при копировании
        evolve(); //Вызов функции
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


    // Виртуальная функция для получения количества особей данного вида
    virtual int getSpeciesCount() {
        return speciesCount[Species];
    }

    // сравним животных пока так, чтобы потом иметь возможность переопределить
    virtual bool operator==(Pokemon& p) {
        return (Species == p.getSpecies() && Type == p.getType() && NickName == p.getNickName() && TypeEating == p.getTypeEating() &&
            Height == p.getHeight() && Weight == p.getWeight() && Name==p.getName() && Color==p.getColor() && Ability == p.getAbility() );
    }

    virtual std::ostream& print(ostream& out) {
        return out << " Покемон  вида " << Species << " принадлежит типу " << Type << "по характеру " << NickName << " является " << TypeEating
            << " имеет вес " << Weight << " и ростом " << Height << "\n";
    }

    friend ostream& operator<< (ostream& out, Pokemon& p)
    {
        return p.print(out);
    }

    void evolve() {
            Height += 1; // Увеличиваем рост на 10 при эволюции
            Weight += 15;
            cout << Type << "Покемон эволюционировал и стал болльше: рост " << Height << " Вес " << Weight << "!\n";
    }

};
// Инициализация статического члена
unordered_map<string, int> Pokemon::speciesCount;

// Теперь покемон может эволюцианировать
class Evolv {
private:
    int V;
public:
    Evolv() { V = 100; }

    void Evoolv(Pokemon& p) {
        if (V > 0) {
            V--;
            cout << "Кажется покемон эволюционирует!\n";
            p.evolve(); // Вызываем метод эволюции покемона
        }
        else {
            cout << "Эволюция невозможна, недостаточно опыта!\n";
        }
    }
    int getV() { return V; }
};
//
