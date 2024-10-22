// 18_Nikitenko_211.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Ваш выбор: 18 Заповедник и его обитатели разных видов
// В начале сделать виртуальную функцию для общего класса(Pokemon)для всех покемонов, с попркавкой на вид; определить количество особоей одного вида(static),

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
    int Weight;// вес

    static unordered_map<string, int> speciesCount;


public:
public:
    Pokemon() {}
    Pokemon(string s, string ty, string n, string te, int A, int W)
        : Species(s), Type(ty), NickName(n), TypeEating(te), Age(A), Weight(W) {
        speciesCount[Species]++; // Увеличиваем счетчик для данного вида
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
        return (Species == p.getSpecies() &&Type==p.getType() && NickName==p.getNickName() && TypeEating == p.getTypeEating() &&
            Age == p.getAge() && Weight == p.getWeight());
    }

    virtual std::ostream& print(ostream& out) {
        return out << " Покемон  вида " << Species << " принадлежит типу " << Type <<  "по характеру " << NickName <<" является " << TypeEating
            << " имеет вес " << Weight << " и возраст " << Age << "\n";
    }

    friend ostream& operator<< (ostream& out, Pokemon& p)
    {
        return p.print(out);
    }

};

// Инициализация статического члена
unordered_map<string, int> Pokemon::speciesCount;

class Pidgeotto : public Pokemon {

    string Name;
    string Color;
    string Ability;

public:
    Pidgeotto(){}
    Pidgeotto (string N, string C, string Ab, string s, string ty, string n, string te, int A, int W) : Pokemon(s,ty,n, te, A, W) {
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
    bool  similarity(Pidgeotto& p, bool condition(Pidgeotto& p1, Pidgeotto& p2)) {
        return condition(*this, p);
    }

    // проверка пегасов на тождественность по имени - перегрузка оператора ==
    bool operator==(Pidgeotto& p) {
        return (Name == p.getName() && NickName==p.getNickName() && Color == p.getColor() &&
           Ability==p.getAbility()  && Age == p.getAge() && Weight == p.getWeight());
    }

    // вывод инфы о пегасах - перегрузка вывода
    virtual std::ostream& print(ostream& out) {
        return out << "Пиджеотто  по имени " << Name << " и по характеру" << NickName << " цвета " << Color << "со способностью" << Ability
            << " имеет вес " << Weight << " и возраст " << Age << "\n";
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

class Rhyhorn : public Pokemon {

    string Name;
    string Color;
    string Ability;

public:
    Rhyhorn() {}
    Rhyhorn(string N, string C, string Ab, string s, string ty, string n, string te, int A, int W) : Pokemon(s, ty, n, te, A, W) {
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
    bool  similarity(Rhyhorn& p, bool condition(Rhyhorn& p1, Rhyhorn& p2)) {
        return condition(*this, p);
    }

    // проверка пегасов на тождественность по имени - перегрузка оператора ==
    bool operator==(Rhyhorn& p) {
        return (Name == p.getName() && NickName == p.getNickName() && Color == p.getColor() &&
            Ability == p.getAbility() && Age == p.getAge() && Weight == p.getWeight());
    }

    // вывод инфы о пегасах - перегрузка вывода
    virtual std::ostream& print(ostream& out) {
        return out << "Рейхорн  по имени " << Name << "и по характеру" << NickName << " цвета " << Color << "со способностью" << Ability
            << " имеет вес " << Weight << " и возраст " << Age << "\n";
    }

    friend ostream& operator<< (ostream& out, Rhyhorn& p)
    {
        return p.print(out);
    }
    // Переопределяем функцию для получения количества особей данного вида
    int getSpeciesCount() override {
        return Pokemon::getSpeciesCount();
    }

};

class Magikarp : public Pokemon {

    string Name;
    string Color;
    string Ability;

public:
    Magikarp() {}
    Magikarp(string N, string C, string Ab, string s, string ty, string n, string te, int A, int W) : Pokemon(s, ty, n, te, A, W) {
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

// А вот как программист переделал список, чтобы теперь в нем могли жить все (даже драконы, если прилетят)
struct node {
    Pokemon* inf; // так как здесь указатель, то подставить можно любого потомка животного Animals
    node* next;
    node* prev;
};

// Список
class List {
private:
    node* head;
    node* tail;
public:
    List() { head = NULL; tail = NULL; }
    void push(Pokemon* p);
    void print(ostream& out);
    void ListPrint();
    bool find(Pokemon* p); //  найти одного конкретного животного
    bool findAll(bool condition(Pokemon* p1));  // найти всех животных по условию
};

void List::push(Pokemon* p) { // принимаем животное в зоопарк
    node* r = new node;
    r->inf = p;
    r->next = NULL;
    if (!head && !tail) {
        r->prev = NULL;
        head = r;
    }
    else {
        tail->next = r;
        r->prev = tail;
    }
    tail = r;
}


void List::print(ostream& out)
{
    node* r = head;
    while (r != NULL) {
        (*(r->inf)).print(out);
        r = r->next;
    }
    cout << '\n';
}

void List::ListPrint()
{
    node* r = head;
    int i = 1;

    while (r != NULL) {
        cout << "Вариант " << i << ": " << r->inf->getNickName() << endl;
        r = r->next;
        i++;
    }
    cout << '\n';
}

bool List::find(Pokemon* p) {
    node* r = head;
    while (r != NULL) {
        if (*(r->inf) == *p)
            return true;
        r = r->next;
    }
    return false;
}

// а это программист решил обдумать завтра
bool List::findAll(bool condition(Pokemon* p1)) {
    node* r = head;
    while (r != NULL) {
        if (condition(r->inf))
        {
            (*(r->inf)).print(cout);
        }
        r = r->next;
    }
    return (r != NULL);
}
// Список


int main()
{
	setlocale(LC_ALL, "RUS");


    // Списки

    //Pidgeotto(string N, string C, string Ab, string s, string ty, string n, string te, int A, int W) : Pokemon(s, ty, n, te, A, W) {

    Pidgeotto p1(" Кестрель ", " Горчичный ", " Зоркий глаз ", " Птица ", " Летающий ", " Осторожный ", " Хищник ", 25, 30.0); 
    Pidgeotto p2(" Перышко ", " Коричневый ", " Порыв ", " Птица ", " Летающий ", " Мягкий ", " Хищник ", 15, 25.0);
    Pidgeotto p3(" Вальтур ", " Горчичный ", " Танец Перьев ", " Птица ", " Летающий ", " Послушный ", " Хищник ", 25, 30.8);  
   
    Pidgeotto p;
    List lstpidge;
    lstpidge.push(&p1);
    lstpidge.push(&p2);
    lstpidge.push(&p3);

   

    Rhyhorn r1(" Дефендер ", " Серый ", " Громоотвод ", " Шипастый ", " Земленно-каменный ", " Поспешный ", " Травоядный ", 50, 115.0); 
    Rhyhorn r2(" Граунд ", " Бурый ", " Безрасудный ", " Шипастый ", " Земленно-каменный ", " Одинокий ", " Травоядный ", 30, 115.7); 
    Rhyhorn r3(" Рейн ", " Горчичный ", " Камменая голова ", " Шипастый ", " Земленно-каменный ", " Смелый  ", " Травоядный ", 23, 111.8);  
    
    Rhyhorn r;
    List lstprhyh;
    lstprhyh.push(&r1);
    lstprhyh.push(&r2);
    lstprhyh.push(&r3);

    Magikarp m1(" Голден ", " Золотой ", " Быстрое плаванье ", " Рыба ", " Водный ", " Озорной ", "Всеядный ", 12, 11.0);  
    Magikarp m2(" Нова ", " Красный ", " Встревожонность ", " Рыба ", " Водный  ", " Скромный ", "Всеядный ", 11, 10.5); 
    Magikarp m3(" Ривер ", " Оранжевый ", " Танец Перьев ", " Рыба ", " Водный  ", " Робкий ", "Всеядный ", 9, 9.8);  
   
    Magikarp m;
    List lstcarp;
    lstcarp.push(&m1);
    lstcarp.push(&m2);
    lstcarp.push(&m3);

    //

    

	cout << "В регионе Хоенн, есть прекрасный заповедник - Сафари зона,";
	cout << "это специальный заповедник покемонов, куда тренеры могут войти, чтобы поймать определенные редкие виды покемонов.\n";
	cout << "Вы тоже захотели поймать несколько новых питомцев\n";
    cout << "К вашему сожелению вы не смогли увидеть и поймать много покемонов, но те которых вы встретели были очень милыми\n";
    cout << " \n";

    lstpidge.print(cout);
    lstprhyh.print(cout);
    lstcarp.print(cout);

    cout << endl;

    cout << "Внезапно в заповедние прилетели пара неизвестных покемонов из региона Унова! Их начали обследовать";

    Pokemon pk1(" Птица ", " Летающе-водный "," Тихий ", " Травоядный ", 19, 24.2);
    Pokemon pk2(" Первобытная птица ", " Летающе-каменный ", " Нахальный ", " Хищник ", 51, 32.2); 
   
    
    
    cout << endl;
    Pokemon pk;
    List lstpok;
    lstpok.push(&pk1);
    lstpok.push(&pk2);
    lstpok.print(cout);

    cout << "Теперь в заповеднике стало на пару покемонов больше!\n";
    List lstzapovednik;

    lstzapovednik.push(&p1);
    lstzapovednik.push(&p2);
    lstzapovednik.push(&p3);

    lstzapovednik.push(&r1);
    lstzapovednik.push(&r2);
    lstzapovednik.push(&r3);

    lstzapovednik.push(&m1);
    lstzapovednik.push(&m2);
    lstzapovednik.push(&m3);

    lstzapovednik.push(&pk1);
    lstzapovednik.push(&pk2);
    
    lstzapovednik.print(cout);

    cout << "Сотрудники заповедника решили посчтиать количество особоей каждого вида, и вот что вышло: \n";

    cout << "Количество особей вида Птица: " << p1.getSpeciesCount() << endl;
    cout << "Количество особей вида Шипастый: " << r1.getSpeciesCount() << endl;
    cout << "Количество особей вида Рыба: " << m1.getSpeciesCount() << endl;

    system("pause");
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
