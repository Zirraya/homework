double sum = 0; // Переменная для хранения суммы значений
	int AmountOfNumbers = 0; //  счетчик
	bool hasNonNumeric = false; // Флаг для проверки не числовых значений



	// Вычисление суммы, счетчик и нахождения четных элементов
	for (int i = 0; i < this->grdMassiv->Rows->Count; i++) {



	// Пропуск путсых ячеек
		// Проверка на наличие значения в ячейке
		if (grdMassiv->Rows[i]->Cells[0]->Value == nullptr) {
			continue; // Пропустить пустую клетку
		}
		
		// Получаем значение ячейки
		String^ cellValue = grdMassiv->Rows[i]->Cells[0]->Value->ToString();

		// Проверка на пустую клетку
		if (String::IsNullOrEmpty(cellValue)) {
			continue; // Пропустить пустую клетку
		}

	//

		double num;
		if (Double::TryParse(grdMassiv->Rows[i]->Cells[0]->Value->ToString(), num)) {
			if (static_cast<int>(num) % 2 == 0 && num != 0) { // Нахождение четных элементов
				sum += num; // Суммирование элементов
				AmountOfNumbers++; // Счетчик
			}	
		}
		else {
			hasNonNumeric = true; // Установка флага если, значение не числовое
		}
	}
	//

	// Вычисление среднего арифметического, 
	if (AmountOfNumbers > 0) {
		double average = sum / AmountOfNumbers;
		this->SrResult->Text = System::Convert::ToString(average); // Отображение результата
	}
	else {
		this->SrResult->Text = "Увы их нет :0"; // Если будет все плохо, 0
		
	}

	// Проверка на наличие нечисловых значений
	if (hasNonNumeric) {
		errorProvider1->SetError(SrResult, "Присутствуют нечисловые значения в массиве. Возможны неточности");
	}
	else {
		errorProvider1->SetError(SrResult, ""); // Очищение сообщения об ошибки, если все норм
	}
	//