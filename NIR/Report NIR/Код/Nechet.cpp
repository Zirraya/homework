double summ = 0;
	int AmountofNumberss = 0;
	bool hasNonNumeric = false; // Флаг для проверки не числовых значений

	// Строка для вывода индекса(ну почему бы и нет)
	System::String^ oddIndices = "";
	int oddCount = 0; // Счетчик нечетных чисел, дабы могла работать проверка на наличе нечетных чисел

	
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


		double numm;
		
		if (Double::TryParse(grdMassiv->Rows[i]->Cells[0]->Value->ToString(), numm)) { // Проверка, можно ли преобразовать значение в число
			
			if (static_cast<int>(numm) % 2 != 0 && numm != 0) { // Проверка, является ли число нечетным
				oddIndices += i.ToString() + " "; // Индекс добавляется к строке с пробелом
				oddCount++; // Увеличиваем счетчик нечетных чисел
			}
		}
		else {
			hasNonNumeric = true; // Установка флага если, значение не числовое
		}
	}

	// Проверка наличия нечетных чисел
	if (oddCount > 0) {
		this->NomeraResult->Text = oddIndices; // Вывод индексов
	}
	else {
		this->NomeraResult->Text = "Увы их нет :0"; // Сообщение о том, что нечетных элементов нет, мда треш
		
	}

	// Проверка на наличие нечисловых значений
	if (hasNonNumeric) {
		errorProvider1->SetError(NomeraResult, "Присутствуют нечисловые значения в массиве. Возможны неточности");
	}
	else {
		errorProvider1->SetError(NomeraResult, ""); // Очищение сообщения об ошибки, если все норм
	}
	//