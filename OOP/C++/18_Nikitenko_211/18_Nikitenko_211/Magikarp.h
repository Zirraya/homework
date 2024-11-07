#pragma once

#include "Pokemon.h"





class Magikarp : public Pokemon {

    string ColorFin; // Цвет плавников

public:
    Magikarp() {}
    Magikarp(string N, string C, string Ab, string CF, string s, string ty, string n, string te, double H, double W) : Pokemon(N, C, Ab,s, ty, n, te, H, W) {
        Name = N; // имя 
        Color = C; // цвет
        Ability = Ab; // способность
        ColorFin = CF; // Цвет плавников


    }
    // естественно, что у пегаса постоянны цвет глаз и масть, его в принципе можно уговорить поменять имя 
    // (если правильно предложить вкусняшку), а также пегасы растут и взрослеют
    string getColorFin() { return ColorFin; }

    // сравнение пегасов на сходство по признакам - взяли двух пегасов и 
  // задали им условие сравнения - условие будет любым
    bool  similarity(Magikarp& p, bool condition(Magikarp& p1, Magikarp& p2)) {
        return condition(*this, p);
    }

    // проверка пегасов на тождественность по имени - перегрузка оператора ==
    bool operator==(Magikarp& p) {
        return (Name == p.getName() && NickName == p.getNickName() && Color == p.getColor() &&
            Ability == p.getAbility() && Height == p.getHeight() && Weight == p.getWeight());
    }

    // вывод инфы о пегасах - перегрузка вывода
    virtual std::ostream& print(ostream& out) {
        return out << "Маджикарп  по имени " << Name << "и по характеру" << NickName << " цвета " << Color << "со способностью" << Ability
           <<" плавники цвета "<< ColorFin << " имеет вес " << Weight << " и ростом " << Height << "\n";
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