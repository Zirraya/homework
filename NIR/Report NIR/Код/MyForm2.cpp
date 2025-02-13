
	private: System::Void Calculate_Click(System::Object^ sender, System::EventArgs^ e) {
		ClearAll();

		double InputNumberX, InputNumberY;
		bool hasError = false; // Флаг для ошибки

		// Проверка
		bool resultX = Double::TryParse(this->txtInputX->Text, InputNumberX);
		if (!resultX) { // Если не число
			errorProvider1->SetError(txtInputX, "¬ведено не целое число");
			hasError = true; // Установка флага
		}
		else if (InputNumberX < 0) { // Проверка на отрицательное число
			errorProvider1->SetError(txtInputX, "¬ведено отрицательное число");
			hasError = true; // Установка флага
		}

		// Проверяем второе число
		bool resultY = Double::TryParse(this->txtInputY->Text, InputNumberY);
		if (!resultY) { // Если не число
			errorProvider2->SetError(txtInputY, "¬ведено не целое число");
			hasError = true; // // Установка флага
		}
		else if (InputNumberY < 0) { // // Проверка на отрицательное число
			errorProvider2->SetError(txtInputY, "¬ведено отрицательное число");
			hasError = true; // // Установка флага
		}

		// Если есть ошибки, то гг :0
		if (hasError) {
			return;
		}


		// Результат
		double OutputNumber = Simple(InputNumberX, InputNumberY);
		this->txtOutput->Text = System::Convert::ToString(OutputNumber); // Записываем в поле
		
	}

