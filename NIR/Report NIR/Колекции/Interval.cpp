private: System::Void Interval_Click(System::Object^ sender, System::EventArgs^ e) {

	ChotElem->Text = String::Empty;	//очистка поля
	int InterA;
	int interB;
	bool resultA = Int32::TryParse(this->a->Text, InterA);
	bool resultB = Int32::TryParse(this->b->Text, interB);

	if (!resultA && !resultB) {	//если a и b не числа
		errora->SetError(a, "Введено не целое число");
		errorb->SetError(b, "Введено не целое число");

	}
	else if (!resultB) {	//если b не число
		errorb->SetError(b, "Введено не целое число");
		errora->SetError(a, String::Empty);
	}
	else if (!resultA) {	//если a не число
		errora->SetError(a, "Введено не целое число");
		errorb->SetError(b, String::Empty);
	}
	else {
		if (InterA > interB) {	//если a > b
			errora->SetError(a, "Неправильно введен диапазон");
			errorb->SetError(b, String::Empty);
		}
		// Получение элементов из OutPutQu
		array<String^>^ elements = OutPutQu->Text->Split(' ');

		int sum = 0;
		int count1 = 0;

		for each (String ^ element in elements) {
			int number;
			if (Int32::TryParse(element->Trim(), number)) {
				if (number >= InterA && number <= interB && number % 2 == 0) { // проверка на четность и диапазон
					sum += number;
					count1++;
				}
			}
		}

		if (count1 == 0) { // если нет таких элементов
			ChotElem->Text = "Таких элементов нет";
		}
		else { // элементы есть
			ChotElem->Text = System::Convert::ToString(sum); // вывод суммы четных элементов
		}
	}
}