#pragma once
#include "Pokemon.h"


class Rhyhorn : public Pokemon {

   
    double LenhgHorn; // ƒлина рога

public:
    Rhyhorn() {}
    Rhyhorn(string N, string C, string Ab, double LH, string s, string ty, string n, string te, double H, double W) : Pokemon(N, C, Ab,s, ty, n, te, H, W) {
        Name = N; // им€ 
        Color = C; // цвет
        Ability = Ab; // способность
        LenhgHorn = LH;
    }
    // естественно, что у пегаса посто€нны цвет глаз и масть, его в принципе можно уговорить помен€ть им€ 
    // (если правильно предложить вкусн€шку), а также пегасы растут и взрослеют
    double getLenhgHorn() { return LenhgHorn; }
   

    // сравнение пегасов на сходство по признакам - вз€ли двух пегасов и 
  // задали им условие сравнени€ - условие будет любым
    bool  similarity(Rhyhorn& p, bool condition(Rhyhorn& p1, Rhyhorn& p2)) {
        return condition(*this, p);
    }

    // проверка пегасов на тождественность по имени - перегрузка оператора ==
    bool operator==(Rhyhorn& p) {
        return (Name == p.getName() && NickName == p.getNickName() && Color == p.getColor() &&
            Ability == p.getAbility() && Height == p.getHeight() && Weight == p.getWeight());
    }

    // вывод инфы о пегасах - перегрузка вывода
    virtual std::ostream& print(ostream& out) {
        return out << "–ейхорн  по имени " << Name << "и по характеру" << NickName << " цвета " << Color << "со способностью" << Ability
           <<" с длинной рога " <<LenhgHorn<< " имеет вес " << Weight << " и ростом " << Height << "\n";
    }

    friend ostream& operator<< (ostream& out, Rhyhorn& p)
    {
        return p.print(out);
    }
    // ѕереопредел€ем функцию дл€ получени€ количества особей данного вида
    int getSpeciesCount() override {
        return Pokemon::getSpeciesCount();
    }

};