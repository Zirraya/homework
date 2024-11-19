#pragma once

#include "Pokemon.h"



class Pidgeotto : public Pokemon {

  
    string ColorCrest; // Цвет хохолка
    double Wingspan; // Размах крыльев

    Evolv* b;



public:
    Pidgeotto() {}
    Pidgeotto(string N, string C, string Ab, string CC,double WS, string s, string ty, string n, string te, double H, double W) : Pokemon(N,C,Ab,s, ty, n, te, H, W) {
        Name = N; // имя 
        Color = C; // цвет
        Ability = Ab; // способность
        ColorCrest = CC;
        Wingspan = WS;
        b = NULL;
      

    }
    // естественно, что у пегаса постоянны цвет глаз и масть, его в принципе можно уговорить поменять имя 
    // (если правильно предложить вкусняшку), а также пегасы растут и взрослеют
    string getColorCrest() { return ColorCrest; }
    double getWingspan() { return Wingspan; }
   
   

    // сравнение пегасов на сходство по признакам - взяли двух пегасов и 
  // задали им условие сравнения - условие будет любым
    bool  similarity(Pidgeotto& p, bool condition(Pidgeotto& p1, Pidgeotto& p2)) {
        return condition(*this, p);
    }

    // проверка пегасов на тождественность по имени - перегрузка оператора ==
    bool operator==(Pidgeotto& p) {
        return (Name == p.getName() && NickName == p.getNickName() && Color == p.getColor() &&
            Ability == p.getAbility() && Height == p.getHeight() && Weight == p.getWeight());
    }

    // вывод инфы о пегасах - перегрузка вывода
    virtual std::ostream& print(ostream& out) {
        return out << "Пиджеотто  по имени " << Name << " и по характеру" << NickName << " цвета " << Color << "со способностью" << Ability
           <<" с хохолком цвета "<< ColorCrest <<" размах крыльев состовляет " << Wingspan << " имеет вес " << Weight << " и ростом " << Height << "\n";
    }

    virtual std::ostream& printPidg(ostream& cout) {
        return cout << "Это же Пиджеотто - покемон птица!\n";
    }

    friend ostream& operator<< (ostream& out, Pidgeotto& p)
    {
        return p.print(out);
    }

    // Переопределяем функцию для получения количества особей данного вида
    int getSpeciesCount() override {
        return Pokemon::getSpeciesCount();
    }

  

};
