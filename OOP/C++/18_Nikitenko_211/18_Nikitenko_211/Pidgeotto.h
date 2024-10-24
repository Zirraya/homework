#pragma once

#include "Pokemon.h"



class Pidgeotto : public Pokemon {

    string Name;
    string Color;
    string Ability;

    Evolv* b;
public:
    Pidgeotto() {}
    Pidgeotto(string N, string C, string Ab, string s, string ty, string n, string te, int A, double W) : Pokemon(s, ty, n, te, A, W) {
        Name = N; // им€ 
        Color = C; // цвет
        Ability = Ab; // способность
        b = NULL;

    }
    // естественно, что у пегаса посто€нны цвет глаз и масть, его в принципе можно уговорить помен€ть им€ 
    // (если правильно предложить вкусн€шку), а также пегасы растут и взрослеют

    string getName() { return Name; }
    string getColor() { return Color; }
    string getAbility() { return Ability; }

    // сравнение пегасов на сходство по признакам - вз€ли двух пегасов и 
  // задали им условие сравнени€ - условие будет любым
    bool  similarity(Pidgeotto& p, bool condition(Pidgeotto& p1, Pidgeotto& p2)) {
        return condition(*this, p);
    }

    // проверка пегасов на тождественность по имени - перегрузка оператора ==
    bool operator==(Pidgeotto& p) {
        return (Name == p.getName() && NickName == p.getNickName() && Color == p.getColor() &&
            Ability == p.getAbility() && Age == p.getAge() && Weight == p.getWeight());
    }

    // вывод инфы о пегасах - перегрузка вывода
    virtual std::ostream& print(ostream& out) {
        return out << "ѕиджеотто  по имени " << Name << " и по характеру" << NickName << " цвета " << Color << "со способностью" << Ability
            << " имеет вес " << Weight << " и возраст " << Age << "\n";
    }

    friend ostream& operator<< (ostream& out, Pidgeotto& p)
    {
        return p.print(out);
    }

    // ѕереопредел€ем функцию дл€ получени€ количества особей данного вида
    int getSpeciesCount() override {
        return Pokemon::getSpeciesCount();
    }

  

};
