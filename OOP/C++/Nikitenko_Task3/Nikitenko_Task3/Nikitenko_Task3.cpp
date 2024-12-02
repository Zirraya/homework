
#include <iostream>
#include "Expections.h"
#include <limits> // Для std::numeric_limits
#include <stdexcept> // Для std::runtime_error
#include <vector>

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

		ListExp list;
		list.validate(N, L, A, CM, CP, FF, P, S); // Проверка данных при создании объекта

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
	 // Функция для сравнения двух саламандр
	bool similarity(BlueSpottedSalamander& sp, bool (*condition)(BlueSpottedSalamander&, BlueSpottedSalamander&)) {
		return condition(*this, sp);
	}


	// проверка саламандер на тождественность по имени - перегрузка оператора ==
	bool operator==(BlueSpottedSalamander& sp) {
		return (Name == sp.getName() && ColorMane == sp.getColorMane() &&
			ColorPattern == sp.getColorPattern() && Lengh == sp.getLengh() && Age == sp.getAge() && FavoriteFood == sp.getFavoriteFood() && Pattern == sp.getPattern());


	}
	// Точная ифнормация о саламандрах
	friend ostream& operator<< (ostream& out, BlueSpottedSalamander sp)
	{
		out << "Саламндра по имени" << sp.Name << " Цвета " << sp.ColorMane << " Ее цвет узора " << sp.ColorPattern << " Длина " << sp.Lengh << " Возраста " << sp.Age
			<< " Ее любимая еда " << sp.FavoriteFood << " Ее узор " << sp.Pattern << " Ее вид " << sp.Species << "\n";
		return out;
	}

	// Взаимодействие двух саламандер
	bool ToIteract(BlueSpottedSalamander& sp) {

		if (this == &sp) {
			cout << "Саламандра не может взаимодействовать с сама собой... Из-за вас ей одиноко. На вас наваливается чувство вины";
			return false;
		}

		cout << "Произошло следующие: \n ";

		if (sp.getSpesies() == " Тигровая ") {
			cout << "Тигровая агрессивно шипит на ";
			cout << Name << ". Она явно настроена агрессивно!\n" << endl;
			return false;
		}

		else if (sp.getSpesies() == " Пятнистая ") {
			cout << "Пятнистая отворачивается от  ";
			cout << Name << ". Видимо, ей не интересно.\n" << endl;
			return false;
		}

		else if (sp.getSpesies() == " Красноспинная ") {
			cout << "Красноспинная активно размахивает хвостом, смотря на ";
			cout << Name << ". Очевидно, она недовольна!\n" << endl;
			return false;
		}


		else if (sp.getSpesies() == " Северная ") {
			cout << "Северная радостно глядит на ";
			cout << Name << ".  Кажется, она хочет поиграть!\n" << endl;
			return true;

		}

		else if (sp.getSpesies() == " Северозападная ") {
			cout << "Северозападная смотрит с явным равнодушием на " << Name;
			return true;
		}


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
			cout << "Пятнистая смотрит на вас настороженно. Лучше оставить ее в покое\n" << endl;
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
	//

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
	int size;

	vector<BlueSpottedSalamander*> salamanders; // Вектор для хранения указателей на объекты
	vector<string> invalidEntries; // Вектор для хранения сообщений об ошибках

public:
	List() { head = NULL; tail = NULL; size = NULL; }
	void push(BlueSpottedSalamander* sp);
	void print();
	void ListPrint();
	bool find(BlueSpottedSalamander sp); // Найти  одну нужную саламандру
	bool findAll(bool condition(BlueSpottedSalamander& sp1)); // Найти всех соломандр по условию
	bool DeleteCond(bool condition(BlueSpottedSalamander& sp1));
	BlueSpottedSalamander& getByID(int id);

	void printInvalidEntries() const {
		if (!invalidEntries.empty()) {
			cout << "Некорректные объекты:" << endl;
			for (const auto& entry : invalidEntries) {
				cout << entry << endl;
			}
		}
		else {
			cout << "Некорректных объектов нет." << endl;
		}
	}

	void printAll() const {
		for (const auto& salamander : salamanders) {
			cout << *salamander << endl;
		}
	}

};

void List::push(BlueSpottedSalamander* sp) { // берем саламандру
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



	try {
		// Проверка на корректность указателя
		if (sp == nullptr) {
			throw invalid_argument("Указатель на объект не может быть нулевым.");
		}
		salamanders.push_back(sp);
	}
	catch (const exception& e) {
		invalidEntries.push_back(e.what());
	}

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
		cout << "Вариант " << i << ": " << r->inf->getName() << endl;
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


// Функия для удаления

bool List::DeleteCond(bool condition(BlueSpottedSalamander& sp1))
{
	node* current = head;
	bool deleted = false; // Флаг, чтобы отслеживать, были ли удалены элементы

	while (current != NULL)
	{
		if (condition(*(current->inf))) // Проверяем условие
		{
			node* temp = current; // Сохраняем текущий узел для удаления

			if (current == head) // Если текущий узел - голова
			{
				head = current->next;
				if (head != NULL)
					head->prev = NULL; // Обновляем указатель на предыдущий узел
			}
			else if (current == tail) // Если текущий узел - хвост
			{
				tail = current->prev;
				tail->next = NULL; // Обновляем указатель на следующий узел
			}
			else // Если узел находится в середине списка
			{
				current->prev->next = current->next;
				current->next->prev = current->prev;
			}

			current = current->next; // Переходим к следующему узлу
			delete temp; // Удаляем текущий узел
			deleted = true; // Устанавливаем флаг удаления
			size--; // Уменьшаем размер списка
		}
		else
		{
			current = current->next; // Переходим к следующему узлу
		}
	}

	return deleted; // Возвращаем true, если были удалены элементы, иначе false
}
//


// Разные условия
bool CondFavorFoodAndName(BlueSpottedSalamander& sp) {
	return (sp.getFavoriteFood() == " Бабочки " && sp.getName() == " Сумрак");
}

bool CondColorPatternAndSpesies(BlueSpottedSalamander& sp) {
	return (sp.getColorPattern() == " Оранжевый " || sp.getSpesies() == " Тигровая ");
}

// Условие для сравнения
bool condition(BlueSpottedSalamander& sp1, BlueSpottedSalamander& sp7) {
	//Сравниваем по виду и еде
	return (sp1.getSpesies() == sp7.getSpesies() ||
		sp1.getFavoriteFood() == sp7.getFavoriteFood());
}
//

bool CondColorManeAndSpesies(BlueSpottedSalamander& sp) {
	return (sp.getColorMane() == " Черный " && (sp.getSpesies() == " Пятнистая " || sp.getSpesies() == " Тигровая "));
}

bool NonCorrect(BlueSpottedSalamander& sp) {

	return(sp.getName() == "" || sp.getAge() <= 0 || sp.getLengh() <= 0);
	cout << " Безымянных саламандр небывет, тем более чья длина или возраст меньше нуля " << endl;


}
//

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


// Функции для ловли исключений




int main()
{
	setlocale(LC_ALL, "RUS");

	ListExp list;
	List lstSalamander;

	try {
		// Проверка корректности значений в списке (не превышения значений int, и прочее) ошибка памяти(превышения размера int, string и тд), ошибка файла
		//string N, string CM, string CP, float L, int A, string FF, string P, string S
		BlueSpottedSalamander sp1(" Огниво", " Черный ", " Оранжевый ", 21.0, 5, " Моллюски ", " Полосатая ", " Тигровая "); cout << sp1;
		BlueSpottedSalamander sp2(" Винтер", " Черный ", " Синий ", 8.0, 17, " Моллюски ", " Полосатая ", " Пятнистая "); cout << sp2;
		BlueSpottedSalamander sp3(" Рэдди", " Красный ", " Черный ", 9.0, 8, " Пауки ", " Полосатая ", " Красноспинная "); cout << sp3;
		BlueSpottedSalamander sp4(" Сумрак", " Бежевый ", " Тмено-коричневый ", 11.0, 7, " Бабочки ", " Пятнистая ", " Северная "); cout << sp4;
		BlueSpottedSalamander sp5(" Можжевельник", " Коричневый ", " Оранжевый ", 9.0, 27, " Гусиницы ", " Крапинки ", " Северозападная "); cout << sp5;
		BlueSpottedSalamander sp6(" Флейм", " Черный ", " Желтый ", 18.0, 3, " Моллюски ", " Полосатая ", " Тигровая "); cout << sp6;
		BlueSpottedSalamander sp7(" Бёрн", " Желтый ", " Черный ", 21.0, 5, " Улитки ", " Полосатая ", " Тигровая "); cout << sp7;

		BlueSpottedSalamander sp8(" Ривер", " Серая ", " Синий ", 7.5, 12, " Моллюски ", " Крапинки ", " Пятнистая "); cout << sp8;
		BlueSpottedSalamander sp9(" Луна", " Серая ", " Синий ", 7.5, 17, " Моллюски ", " Крапинки ", " Пятнистая "); cout << sp9;
		BlueSpottedSalamander sp10("Мунн", " Серая ", " Синий ", 7.5, 17, " Моллюски ", " Крапинки ", " Пятнистая "); cout << sp10;


		cout << endl;

		BlueSpottedSalamander sp;


		lstSalamander.push(&sp1);
		lstSalamander.push(&sp2);
		lstSalamander.push(&sp3);
		lstSalamander.push(&sp4);
		lstSalamander.push(&sp5);
		lstSalamander.push(&sp6);
		lstSalamander.push(&sp7);
		lstSalamander.push(&sp8);
		lstSalamander.push(&sp9);
		lstSalamander.push(&sp10);


		// Функия для выбора саламандры
		int choice;
		int choiseMove;

		cout << "Несколько саламандр греются на солнышке. Их можно погладить, но некоторые виды этих созданий не любят, когда их трогают. Так что может лучше последить за их поведением?\n";
		cout << "Ой, ой вы не можете взаимодействовать со всеми, так как некоторые данные занесены не верно \n ";
		cout << "Вы выбираете саламандру..." << endl;
		lstSalamander.DeleteCond(NonCorrect); cout << endl; // удаляет некоректные данные
		lstSalamander.ListPrint();


		cout << "C какой саламандрой вы хотите познакомиться поближе (Введите номер варианта)? ";

		// Проверка на корректной ввод
		if (!(cin >> choice)) { // Проверка ввода
			cin.clear(); // Сброс состояния cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорируем некорректный ввод
			throw ExptectionsVar(&choice);
		}
		//

		// Проверка, что введенное число в пределах допустимых значений
		if (choice > 10) {
			cin.clear(); // Сброс состояния cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорируем некорректный ввод
			throw ExptctionOverFlow(&choice);
		}
		//

		// Проверка, на введения 0
		if (choice == 0) {
			cin.clear(); // Сброс состояния cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорируем некорректный ввод
			throw ExpectionZero(&choice);
		}
		//


		BlueSpottedSalamander b = lstSalamander.getByID(choice);

		cout << "Вариант 1: Вы решаете погладить" << endl;
		cout << "Вариант 2: Вы решаете присмотреться" << endl;
		cout << "Вариант 3: Вы решаете посмотреть на взаимодействие " << b.getName() << " и другой саламандрой" << endl;

		cout << "Что вы хотите сделать? ";

		// Проверка на корректный ввод
		if (!(cin >> choiseMove)) { // Проверка ввода
			cin.clear(); // Сброс состояния cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорируем некорректный ввод
			throw ExptectionsVar(&choiseMove);
		}
		//

		BlueSpottedSalamander a;

		switch (choiseMove) {
		case 1:
			b.ToReact();
			break;
		case 2:
			b.ToLook();
			break;
		case 3:
			cout << "\n С какой саламандрой будет взаимодействовать ваша избранная? " << endl;
			int inp;
			cout << "Саламандра взаимодействует с вашей избранной: ";

			// Проверка на корректный ввод
			if (!(cin >> inp)) { // Проверка ввода
				cin.clear(); // Сброс состояния cin
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорируем некорректный ввод
				throw ExptectionsVar(&inp);
			}
			//

			// Проверка на недопустимые варианты
			if (inp > choice) {
				cin.clear(); // Сброс состояния cin
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорируем некорректный ввод
				throw ExptctionOverFlow(&choice);
			}
			//

			// Проверка, на введения 0
			if (inp == 0) {
				cin.clear(); // Сброс состояния cin
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорируем некорректный ввод
				throw ExpectionZero(&choice);
			}
			//

			a = lstSalamander.getByID(inp);
			b.ToIteract(a);
			break;
		default:
			cout << "Вы уходите" << endl;
			break;
		}

		// Вывести только тех у которых оранжевый узор и узоры
		cout << "\n Ваш друг решил приютить несколько саламандр. Он выбрал тигровых и тех у которых цвет узора оранжевый \n";
		lstSalamander.findAll(CondColorPatternAndSpesies);

		// Вывести только только самаандры у которых ТОЛЬКО имя "Сумрак" и любят бабочек
		cout << "\n Вам захотели к себе тоже взять саламандр. Вы выбрали ту которая любит бабочек -  дружелюбную Сумрак\n";
		lstSalamander.findAll(CondFavorFoodAndName);

		if (sp1.similarity(sp7, condition)) {
			cout << " Саламандры одного вида почему то шипят друг на друга, и не могут поделить еду!" << endl;
		}
		else {
			cout << " Саламандры спокойно лежат!" << endl;
		}

		// 
		cout << "\n Тигровые и пятнистые черные салмандры уползли. Остались они\n";
		lstSalamander.DeleteCond(CondColorManeAndSpesies); cout << endl;
		lstSalamander.ListPrint();


		cout << endl;

		// Печать всех корректных объектов
		cout << "Корректные объекты:" << endl;
		lstSalamander.printAll();

		// Печать некорректных объектов
		lstSalamander.printInvalidEntries();

	}
	

	// Ловли исключений
	//-------------------------------------------------------------------------------------------------------------------

	// Ловля исключения некорректного ввода
	catch (const ExptectionsVar& expvar) {
		expvar.print(); // Вывод сообщения об оишибке
	}

	// Ловля исключения переполнения (юзер выбирает номер варинта превышающий количетсво доупситмых)
	catch (const ExptctionOverFlow& of) {
		of.print();
	}

	// Ловля исключения ввода нуля
	catch (const ExpectionZero& zrd) {
		zrd.print();
	}

	catch (const invalid_argument& e) {
		list.print(); // Выводим сообщение об ошибке
		cerr << " " << e.what() << endl;	
		
	}	

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
