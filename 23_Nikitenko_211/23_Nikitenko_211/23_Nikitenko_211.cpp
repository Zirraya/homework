// 23_Nikitenko_211.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// Я решила выбрать саламндру, так как, они милые UwU

// 1 лаба 4 задания 2 лаба 6 задания

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
			out << "Саламндра по имени" << sp.Name << " Цвета " << sp.ColorMane << " Ее цвет узора " << sp.ColorPattern << " Длина " << sp.Lengh << " Возраста " << sp.Age
				<< " Ее любимая еда " << sp.FavoriteFood << " Ее узор " << sp.Pattern << "\n";
			return out;
		}
	
	//






	// Функция для взгляда на саламандр
		bool ToLook() {

			cout << "Рязглядывая этих созданий вы приходите к следующему выводу\n " << endl;

			if (Species == " Тигровая ") {
				cout << "Тигровая явно не настроена что бы ее трогали.Возможно контакт с ней закончится плачевно\n" << endl;
				return false;
			}
			else if (Species == " Пятнистая ") {
				cout  << "Пятнистая смотрит на вас настороженно. Лучше оставить ее в покое\n" << endl;
				return false;
			}
			else if (Species == " Красноспинная ") {
				cout << "Красноспинная активно размахивает хвостом глядя на вас. Может к ней не стоит сувать свои руки?" << endl;
				return false;
			}
			else if (Species == " Северная ") {
				cout << "Северная глядит на вас спокойны взлядом. Она выглядит вполне дружелюбно\n" << endl;
				return true;
			}
			else if (Species == " Северозападная ") {
				cout << "Северозападная с интересом разглядывает вас. В прицнипе она не выглядит агресивно\n" << endl;
				return true;
			}
			return false;

		}

	// Реакция
	bool ToReact() {

		cout << "Вы решаете погладить " << Name << endl;

		if (Species == " Тигровая ") {
			cout << Name << " Наносит мощный удар хвостом!" << endl;
			actionPet();
			return false;
		}
		else if (Species == " Пятнистая ") {
			cout << Name << " Делает быстрый удар хвостом!" << endl;
			actionPet();
			return false;
		}
		else if (Species == " Красноспинная ") {
			cout << Name << " Яростно машет хвостом!" << endl;
			actionPet();
			return false;
		}
		else if (Species == " Северная ") {
			cout << Name << " Кажется ей нравится!" << endl;
			return true;
		}
		else if (Species == " Северозападная ") {
			cout << Name << " В замашатльстве!" << endl;
			return true;
		}
		return false;

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
		void ListPrint();
		bool find(BlueSpottedSalamander sp); // Найти  одну нужную саламандру
		bool findAll(bool condition(BlueSpottedSalamander& sp1)); // Найти всех соломандр по условию
		BlueSpottedSalamander& getByID(int id);

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

	void List::ListPrint()
	{
		node* r = head;
		int i = 1;

		while (r != NULL) {
			cout << "Вариант " << i  << ": " << r->inf->getName() << endl;
			r = r->next;
			i++;
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


	bool CondFavorFoodAndName(BlueSpottedSalamander& sp) {
		return (sp.getFavoriteFood() == " Бабочки " && sp.getName() == " Сумрак");
	}

	bool CondColorPatternAndSpesies(BlueSpottedSalamander& sp) {
		return (sp.getColorPattern() == " Синий " && sp.getSpesies() == "Тигровая");
	}

	BlueSpottedSalamander& List::getByID(int id) {
		node* r = head;
		int i = 1;

		while (r != NULL) {
			if (i == id)
			{
				return *(r->inf);
			}
			i++;
			r = r->next;
		}
	}




int main()
{
	setlocale(LC_ALL, "RUS");

	//string N, string CM, string CP, float L, int A, string FF, string P, string S
	BlueSpottedSalamander sp1(" Огниво", " Черный ", " Оранжевый ", 21.0, 5, " Моллюски ", " Полосатая ", " Тигровая "); cout << sp1;
	BlueSpottedSalamander sp2(" Винтер", " Черный ", " Синий ", 8.0, 17, " Черви ", " Полосатая ", " Пятнистая "); cout << sp2;
	BlueSpottedSalamander sp3(" Рэдди", " Красный ", " Черный ", 9.0, 8, " Пауки ", " Полосатая ", " Красноспинная "); cout << sp3;
	BlueSpottedSalamander sp4(" Сумрак", " Бежевый ", " Тмено-коричневый ", 11.0, 7, " Бабочки ", " Пятнистая ", " Северная "); cout << sp4;
	BlueSpottedSalamander sp5(" Можжевельник", " Коричневый ", " Оранжевый ", 9.0, 27, " Гусиницы ", " Крапинки ", " Северозападная "); cout << sp5;

	cout << endl;

	BlueSpottedSalamander sp;

	List lstSalamander;

	lstSalamander.push(&sp1);
	lstSalamander.push(&sp2);
	lstSalamander.push(&sp3);
	lstSalamander.push(&sp4);
	lstSalamander.push(&sp5);



	// Функия для выбора саламандры
		int choice;
		int choiseMove;

		cout << "Несколько саламандр греются на солнышке\n";
		cout << "Вы выбираете салмандру..." << endl;

		lstSalamander.ListPrint();

		cout << "C какой саламандрой вы хоите познакомиться поближе (Введите номер варианта)? ";
		cin >> choice;
		BlueSpottedSalamander b = lstSalamander.getByID(choice);


		cout << "Вариант 1: Вы решаете погладить"<< endl; cout << "Вариант 2: Вы решаете присмотреться"<< endl;


		cout << "Что вы хотите сделать? ";
		cin >> choiseMove;

		switch (choiseMove)
		{
		case 1:
			b.ToReact();
			break;
		case 2:
			b.ToLook();
		default:
			cout << "Вы уходите" << endl;
			
		}


		
		cout << "\n Ваш друг решил приютить пару саламандр. он выбрал саламандру с синим узором и тигровую \n";
		lstSalamander.findAll(CondColorPatternAndSpesies);
		
		cout << "\n Вам захотели к себе тоже взять саламандр. Вы выбрали ту которая любит бабочек -  дружелюбную Сумрак\n";
		lstSalamander.findAll(CondFavorFoodAndName);

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
