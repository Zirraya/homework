// 23_Nikitenko_211.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// Я решила выбрать саламндру, так как, они милые UwU

#include <iostream>

using namespace std;


class BlueSpottedSalamnde {
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

	string Pet; // Теперь ее можно погладить, но надо делть это правильно в противном случае есть получить ядовитым хвостом 
	//

	// Функция бонус, что будет если не правильно погладить
	void actionPet() {
		cout  << "Вы получили урон от "<< Name << "!  " << "Вашу руку жжет от яда!";
	}
	//
//

//
public:
	BlueSpottedSalamnde() {} // Конструктор для саламандры
	BlueSpottedSalamnde(string N, string CM, string CP, float L, int A, string FF, string P, string S) {
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

	string getPet() { return Pet; }


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
			Name = "Огниво";
			ColorMane = "Черный";
			ColorPattern = "Оранжевый";
			Lengh = 21.0;
			Age = 5;
			FavoriteFood = "Моллюск";
			Pattern = "Полосатая";
			break;
		case 2:
			Species = "Пятнистая";
			Name = "Винтер";
			ColorMane = "Черный";
			ColorPattern = "Синий";
			Lengh = 8.0;
			Age = 17;
			FavoriteFood = "Черви";
			Pattern = "Пятнистая";
			break;
		case 3:
			Species = "Красноспинная";
			Name = "Рэдди";
			ColorMane = "Красный";
			ColorPattern = "Черный";
			Lengh = 9.0;
			Age = 8;
			FavoriteFood = "Пауки";
			Pattern = "Полосатая";
			break;
		case 4:
			Species = "Северная";
			Name = "Сумрак";
			ColorMane = "Бежевый";
			ColorPattern = "Тмено-коричневый";
			Lengh = 11.0;
			Age = 7;
			FavoriteFood = "Бабочки";
			Pattern = "Пятнистая";
			break;
		case 5:
			Species = "Северозападная";
			Name = "Можжевельник";
			ColorMane = "Коричневый";
			ColorPattern = "Оранжевый";
			Lengh = 9.0;
			Age = 27;
			FavoriteFood = "Гусиницы";
			Pattern = "Крапинки";
			break;
		case 6:
			InfoSalamander();
			break;
		case 7:
			Call();
			break;
		default:
			cout << "Неверный выбор!" << endl;
			return; // Завершаем выполнение функции, если выбор неверный
		}
	}
	
	//

	// Вывод информации про саламандр
	void InfoSalamander() {
		cout << "Рязглядывая этих созданий вы приходите к следующему выводу\n";
		cout << "Тигровая явно не настроена что бы ее трогали. Возможно контакт с ней закончится плачевно\n";
		cout << "Пятнистая смотрит на вас настороженно. Лучше оставить ее в покое\n";
		cout << "Красноспинная активно размахивает хвостом глядя на вас. Может к ней не стоит сувать свои руки?\n";
		cout << "Северная глядит на вас спокойны взлядом. Она выглядит вполне дружелюбно\n";
		cout << "Северозападная с интересом разглядывает вас. В прицнипе она не выглядит агресивно\n";

		ChoiceSalamander();

	}
	// Точная ифнормация о саламандрах
	void Call() {
		cout << "Вы узнаете от странного человека весьма подробную информацию...";


	}

	// 



	// Функция для реализации удара хвостом
	void ToReact() {

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

		else {

		}
	}

	//
//
};




int main()
{
	setlocale(LC_ALL, "RUS");

	cout << "Несколько саламандр греются на солнышке\n";
	cout << "Вы решаете погладить их...\n";

	BlueSpottedSalamnde salamander;

	salamander.ChoiceSalamander(); // Выбор саламандры
	salamander.ToReact(); // Реакция саламандры

	return 0;

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
