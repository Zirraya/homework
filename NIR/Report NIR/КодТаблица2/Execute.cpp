private: System::Void Execute_Click(System::Object^ sender, System::EventArgs^ e) {

		// Обработка неккоректных данных в таблице
		if (this->DataMassivInPut->RowCount == 0) {
			errorProvider1->SetError(DataMassivInPut, " Пустая таблица. Нужно создать стоблцы и строки ");
			return;
		}
		int number;
		bool flag = true;

		// Определение минимальные и максимальные значения для int, да весьма грубо но работает
		const int MinV = -2147483648;
		const int MaxV = 2147483647;
		//

		for (int i = 0; i < DataMassivInPut->RowCount; i++) {
			for (int j = 0; j < DataMassivInPut->ColumnCount; j++) {
				// Попытка преобразовать значение в строке в число
				bool res = Int32::TryParse(System::Convert::ToString(this->DataMassivInPut->Rows[i]->Cells[j]->Value), number);

				// Если преобразование не удалось или число выходит за пределы int
				if (!res || number < MinV || number > MaxV) {
					errorProvider1->SetError(DataMassivInPut, "В таблице есть некорректные значения! Введите целые числа в диапазоне int, чтобы продолжить работу.");
					this->DataMassivInPut->Rows[i]->Cells[j]->Value = "";
					flag = false;
				}
			}
		}

		if (flag == false) {
			return;
		}
		//

		int minRowIndex = -1, maxRowIndex = -1;
		int minColIndex = -1, maxColIndex = -1;

		int minValue = Int32::MaxValue; // Инициализация для поиска минимума
		int maxValue = Int32::MinValue; // Инициализация для поиска максимума

		// Поиск первого минимального и максимального элемента  
		for (int col = 0; col < DataMassivInPut->ColumnCount; col++) {
			for (int row = 0; row < DataMassivInPut->RowCount; row++) {
				if (DataMassivInPut->Rows[row]->Cells[col]->Value != nullptr &&
					DataMassivInPut->Rows[row]->Cells[col]->Value->ToString() != "") {

					int value;
					if (Int32::TryParse(DataMassivInPut->Rows[row]->Cells[col]->Value->ToString(), value)) {
						// Поиск минимального элемента  
						if (value < minValue) {
							minValue = value;
							minRowIndex = row;
							minColIndex = col;
						}
						//

						// Поиск максимального элемента  
						if (value > maxValue) {
							maxValue = value;
							maxRowIndex = row;
							maxColIndex = col;
						}
						//
					}
				}
			}
		}
		//

		// Копирование данных из DataMassivInPut в DataMassivOutPut
		DataMassivOutPut->Columns->Clear();
		for (int i = 0; i < DataMassivInPut->ColumnCount; i++) {
			DataMassivOutPut->Columns->Add("Column" + i, "" + (i + 1));
		}

		for (int row = 0; row < DataMassivInPut->RowCount; row++) {
			array<Object^>^ rowData = gcnew array<Object^>(DataMassivInPut->ColumnCount);
			for (int col = 0; col < DataMassivInPut->ColumnCount; col++) {
				rowData[col] = DataMassivInPut->Rows[row]->Cells[col]->Value;
			}
			DataMassivOutPut->Rows->Add(rowData);
		}
		//

		// Поиск первого минимального и максимального элементов в DataMassivOutPut
		for (int col = 0; col < DataMassivOutPut->ColumnCount; col++) {
			for (int row = 0; row < DataMassivOutPut->RowCount; row++) {
				Object^ currentValue = DataMassivOutPut->Rows[row]->Cells[col]->Value;

				Object^ minValue = DataMassivOutPut->Rows[0]->Cells[0]->Value;
				Object^ maxValue = DataMassivOutPut->Rows[0]->Cells[0]->Value;

				for (int col = 0; col < DataMassivOutPut->ColumnCount; col++) {
					for (int row = 0; row < DataMassivOutPut->RowCount; row++) {
						Object^ currentValue = DataMassivOutPut->Rows[row]->Cells[col]->Value;

						// Проверка на минимальное значение
						if (currentValue != nullptr && Convert::ToDouble(currentValue) < Convert::ToDouble(minValue)) {
							minValue = currentValue;
							minRowIndex = row;
							minColIndex = col;
						}
						//

						// Проверка на максимальное значение
						if (currentValue != nullptr && Convert::ToDouble(currentValue) > Convert::ToDouble(maxValue)) {
							maxValue = currentValue;
							maxRowIndex = row;
							maxColIndex = col;
						}
						//
					}
				}
			}
		}
		//

		// Проверка, что минимальный и максимальный элементы найдены и что они находятся в разных столбцах
		if (minRowIndex != -1 && maxRowIndex != -1 && minColIndex != maxColIndex) {
			// Обмен значениями в найденных столбцах
			for (int row = 0; row < DataMassivOutPut->RowCount; row++) {
				auto tempValue = DataMassivOutPut->Rows[row]->Cells[minColIndex]->Value;
				DataMassivOutPut->Rows[row]->Cells[minColIndex]->Value = DataMassivOutPut->Rows[row]->Cells[maxColIndex]->Value;
				DataMassivOutPut->Rows[row]->Cells[maxColIndex]->Value = tempValue;
			}
		}
		//
	}