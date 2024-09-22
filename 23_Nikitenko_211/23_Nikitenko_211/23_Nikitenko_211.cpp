// 23_Nikitenko_211.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// Я решила выбрать саламндру, так как, они милые UwU

#include <iostream>

using namespace std;


class BlueSpottedSalamander {
	//
private:
	string Name; // Имя нашей саламандры
	string ColorMane; // Основной цвет
	string ColorPattern; // Цвет узора
	float Lengh; // Длина
	int Age; // Возраст
	string FavoriteFood; // Любимые вкусняшки
	string Pattern; // Тип узора
	string Species; // Вид саламандры



	// Функция бонус, что будет если не правильно погладить
	void actionPet() {
		cout << "Вы получили урон от " << Name << "! " << "Вашу руку жжет от яда!";
	}
	//
//

//
public:
	BlueSpottedSalamander() {} // Конструктор для саламандры
	BlueSpottedSalamander(string N, string CM, string CP, float L, int A, string FF, string P, string S) {
		Name = N;
		ColorMane = CM;
		ColorPattern = CP;
		Lengh = L;
		Age = A;
		FavoriteFood = FF;
		Pattern = P;
		Species = S;
	}

	//
	string getName() { return Name; }
	string getColorMane() { return ColorMane; }
	string getColorPattern() { return ColorPattern; }
	float getLengh() { return Lengh; }
	int getAge() { return Age; }
	string getFavoriteFood() { return FavoriteFood; }
	string getPattern() { return Pattern; }
	string getSpesies() { return Species; }





	// Функия для выбора саламандры
	void ChoiceSalamander() {
		int choice;

		cout << "Вы выбираете салмандру..." << endl;
		cout << "Вариант 1: Тигровая" << endl;
		cout << "Вариант 2: Пятнистая" << endl;
		cout << "Вариант 3: Красноспинная" << endl;
		cout << "Вариант 4: Северная" << endl;
		cout << "Вариант 5: Северозападная" << endl;

		cout << "Вариант 6: Вы решаете внимательно пригледется к земноводным..." << endl;
		cout << "Вариант 7: Вы подумали неплохо бы найти человека которорый знает об этих созданиях хоть что-то..." << endl;

		cout << "Какой выриант вы выбиараете? ";
		cin >> choice;

		switch (choice) {
		case 1:
			Species = "Тигровая";
			break;
		case 2:
			Species = "Пятнистая";
			break;
		case 3:
			Species = "Красноспинная";
			break;
		case 4:
			Species = "Северная";
			break;
		case 5:
			Species = "Северозападная";
			break;
		case 6:
			InfoSalamander();
		default:
			cout << "Неверный выбор!" << endl;
			return; // Завершение если выбран неверный вариант
		}
	}

	//

	// Вывод инцы про саламандар по первому взгляду
	void InfoSalamander() {
		cout << "Рязглядывая этих созданий вы приходите к следующему выводу\n";
		cout << "Тигровая явно не настроена что бы ее трогали. Возможно контакт с ней закончится плачевно\n";
		cout << "Пятнистая смотрит на вас настороженно. Лучше оставить ее в покое\n";
		cout << "Красноспинная активно размахивает хвостом глядя на вас. Может к ней не стоит сувать свои руки?\n";
		cout << "Северная глядит на вас спокойны взлядом. Она выглядит вполне дружелюбно\n";
		cout << "Северозападная с интересом разглядывает вас. В прицнипе она не выглядит агресивно\n";

		ChoiceSalamander();

	}


	// сравнение саламандер на сходство по признакам - взяли двух саламандер и 
	// задали им условие сравнения - условие будет любым
	bool  similarity(BlueSpottedSalamander& sp, bool condition(BlueSpottedSalamander& sp1, BlueSpottedSalamander& sp2)) {
		return condition(*this, sp);
	}

	// проверка саламандер на тождественность по имени - перегрузка оператора ==
	bool operator==(BlueSpottedSalamander& sp) {
		return (Name == sp.getName() && ColorMane == sp.getColorMane() &&
			ColorPattern == sp.getColorPattern() && Lengh == sp.getLengh() && Age == sp.getAge() && FavoriteFood == sp.getFavoriteFood() && Pattern == sp.getPattern());


	}
	// Точная ифнормация о саламандрах
		friend ostream& operator<< (ostream & out, BlueSpottedSalamander sp) 
		{
			out << "Саламндра по имени" << sp.Name << " Цвета" << sp.ColorMane << "Ее цвет узора" << sp.ColorPattern << "Длина" << sp.Lengh << "Возраста" << sp.Age
				<< "Ее любимая еда" << sp.FavoriteFood << "Ее узор" << sp.Pattern << "\n";
			return out;
		}
	
	//

	// Реакция
	void ToReact() {

		cout << "Вы решаете погладить " << Name << endl;

		if (Species == "Тигровая") {
			cout << Name << " Наносит мощный удар хвостом!" << endl;
			actionPet();
		}
		else if (Species == "Пятнистая") {
			cout << Name << " Делает быстрый удар хвостом!" << endl;
			actionPet();
		}
		else if (Species == "Красноспинная") {
			cout << Name << " Яростно машет хвостом!" << endl;
			actionPet();
		}
		else if (Species == "Северная") {
			cout << Name << " Кажется ей нравится!" << endl;
		}
		else if (Species == "Северозападная") {
			cout << Name << " В замашатльстве!" << endl;

		}

	}
	//
};


	// Список
	struct node {
		BlueSpottedSalamander* inf;
		node* next;
		node* prev;

	};

	class List {
	private:
		node* head;
		node* tail;
	public:
		List() { head = NULL; tail = NULL; }
		void push(BlueSpottedSalamander* sp);
		void print();
		bool find(BlueSpottedSalamander sp); // Найти  одну нужную саламандру
		bool findAll(bool condition(BlueSpottedSalamander& sp1)); // Найти всех соломандр по условию

	};

	void List::push(BlueSpottedSalamander * sp) { // берем саламандру
		node* r = new node;
		r->inf = sp;
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

	// Будет ли тут перегрузка хороший вопрос
	void List::print()
	{
		node* r = head;
		while (r != NULL) {
			cout << *(r->inf);
			r = r->next;
		}
		cout << '\n';
	}

	bool List::find(BlueSpottedSalamander sp) {
		node* r = head;
		while (r != NULL) {
			if (*(r->inf) == sp)
				return true;
			r = r->next;
		}
		return false;
	}


	bool List::findAll(bool condition(BlueSpottedSalamander& sp1)) {
		node* r = head;
		while (r != NULL) {
			if (condition(*(r->inf)))
			{
				cout << *(r->inf);
			}
			r = r->next;
		}
		return (r != NULL);
	}

//



int main()
{
	setlocale(LC_ALL, "RUS");

	cout << "Несколько саламандр греются на солнышке\n";
	cout << "Вы решаете погладить их...\n";

	//string N, string CM, string CP, float L, int A, string FF, string P, string S
	BlueSpottedSalamander sp1( " Огниво ", " Черный ", " Оранжевый ", 21.0, 5, " Моллюски ", " Полосатая ", " Тигровая "); cout << sp1;
	BlueSpottedSalamander sp2(" Винтер ", " Черный ", " Синий ", 8.0, 17, " Черви ", " Полосатая ", " Пятнистая "); cout << sp2;
	BlueSpottedSalamander sp3(" Рэдди ", " Красный ", " Черный ", 9.0, 8, " Пауки ", " Полосатая ", " Красноспинная "); cout << sp3;
	BlueSpottedSalamander sp4(" Сумрак ", " Бежевый ", " Тмено-коричневый ", 11.0, 7, " Бабочки  ", " Пятнистая ", " Северная "); cout << sp4;
	BlueSpottedSalamander sp5(" Можжевельник ", " Коричневый ", " Оранжевый ", 9.0, 27, " Гусиницы ", " Крапинки ", " Северозападная "); cout << sp5;

	List lstSalamander;
	if (lstSalamander.find(sp1))
		lstSalamander.push(&sp1);
	else if (sp1.ToReact(" Наносит мощный удар хвостом! "))
		lstSalamander.push(&sp1);




	BlueSpottedSalamander salamander;
	salamander.ChoiceSalamander(); // Выбор саламандры
	salamander.ToReact(); // Реакция саламандры

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
