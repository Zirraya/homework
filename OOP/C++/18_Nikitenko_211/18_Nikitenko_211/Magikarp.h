#pragma once

#include "Pokemon.h"





class Magikarp : public Pokemon {

    string Name;
    string Color;
    string Ability;

public:
    Magikarp() {}
    Magikarp(string N, string C, string Ab, string s, string ty, string n, string te, int A, double W) : Pokemon(s, ty, n, te, A, W) {
        Name = N; // имя 
        Color = C; // цвет
        Ability = Ab; // способность


    }
    // естественно, что у пегаса постоянны цвет глаз и масть, его в принципе можно уговорить поменять имя 
    // (если правильно предложить вкусняшку), а также пегасы растут и взрослеют
    string getName() { return Name; }
    string getColor() { return Color; }
    string getAbility() { return Ability; }

    // сравнение пегасов на сходство по признакам - взяли двух пегасов и 
  // задали им условие сравнения - условие будет любым
    bool  similarity(Magikarp& p, bool condition(Magikarp& p1, Magikarp& p2)) {
        return condition(*this, p);
    }

    // проверка пегасов на тождественность по имени - перегрузка оператора ==
    bool operator==(Magikarp& p) {
        return (Name == p.getName() && NickName == p.getNickName() && Color == p.getColor() &&
            Ability == p.getAbility() && Age == p.getAge() && Weight == p.getWeight());
    }

    // вывод инфы о пегасах - перегрузка вывода
    virtual std::ostream& print(ostream& out) {
        return out << "Маджикарп  по имени " << Name << "и по характеру" << NickName << " цвета " << Color << "со способностью" << Ability
            << " имеет вес " << Weight << " и возраст " << Age << "\n";
    }

    friend ostream& operator<< (ostream& out, Magikarp& p)
    {
        return p.print(out);
    }
    // Переопределяем функцию для получения количества особей данного вида
    int getSpeciesCount() override {
        return Pokemon::getSpeciesCount();
    }

};