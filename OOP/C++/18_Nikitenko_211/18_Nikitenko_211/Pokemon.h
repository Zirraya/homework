#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <unordered_map>

using namespace std;

class Pokemon {
private:
    string Type;// тип
    string Species;// вид
    string TypeEating; // что ест
protected:// потомки могут менять эти значения
    string NickName; // Характер
    int Age;// возраст
    double Weight;// вес

    static unordered_map<string, int> speciesCount;


public:
    Pokemon() {}
    Pokemon(string s, string ty, string n, string te, int A, double W)
        : Species(s), Type(ty), NickName(n), TypeEating(te), Age(A), Weight(W) {
        speciesCount[Species]++; // Увеличиваем счетчик для данного вида
    }


    // Конструктор копирования
    Pokemon(const Pokemon& p) 
        : Species(p.Species), Type(p.Type), NickName(p.NickName),
          TypeEating(p.TypeEating), Age(p.Age), Weight(p.Weight) {
        // Не увеличиваем счетчик при копировании
    }

    void evolve() {
        Weight += 15; // Увеличиваем вес на 10 при эволюции
        cout << "Покемон эволюционировал и теперь весит " << Weight << "!\n";
    }


    int getAge() { return Age; }
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
            Age == p.getAge() && Weight == p.getWeight());
    }

    virtual std::ostream& print(ostream& out) {
        return out << " Покемон  вида " << Species << " принадлежит типу " << Type << "по характеру " << NickName << " является " << TypeEating
            << " имеет вес " << Weight << " и возраст " << Age << "\n";
    }

    friend ostream& operator<< (ostream& out, Pokemon& p)
    {
        return p.print(out);
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
