
	private: System::Void ButtonResult_Click(System::Object^ sender, System::EventArgs^ e) {
		ClearAll();
		long long InputNumber;
		bool result = Int64::TryParse(this->InputForN->Text, InputNumber); //перевод строку из TextBox в число

		if (!result) { // Введено не число 
			errorProvider1->SetError(InputForN, "Введено не целое число");
			return; // Выход из функции, чтобы избежать дальнейших проверок
		}

		if (InputNumber < 0) { // Проверка на отрицательное число
			errorProvider1->SetError(InputForN, "Введено отрицательное число");
			return; // Выход из функции
		}

		if (InputNumber == 0) { // Проверка на отрицательное число
			errorProvider1->SetError(InputForN, "Введен ноль");
			return; // Выходим из функции
		}

		if (InputNumber >= 127) {
			errorProvider1->SetError(InputForN, " Переполнение стека");
			return;

		}
	
		long long OutputNumber = Recur(InputNumber);

		// Запись в поле
		this->OutPutForN->Text = System::Convert::ToString(OutputNumber);
	}

