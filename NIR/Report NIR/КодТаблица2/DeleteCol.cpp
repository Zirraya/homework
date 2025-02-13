// Уадление слолбцов
private: System::Void DeleteColumn_Click(System::Object^ sender, System::EventArgs^ e) {

	// Проверка на наличие строк
	if (this->DataMassivInPut->Columns->Count == 0) {
		errorProvider1->SetError(DataMassivInPut, " Что бы удалить столбец, нужно в начале добавить его "); //  Установка ошибки, если нет строк
		return; //  Выход из метода
	}

	
	// Проверяем, есть ли столбцы в DataGridView
	if (this->DataMassivInPut->Columns->Count > 0) {
		// Получение индекса последнего столбца 
		int i = this->DataMassivInPut->Columns->Count - 1; // Индекс последнего столбца
		int o = this->DataMassivOutPut->Columns->Count - 1;

		// Удалаление
		this->DataMassivInPut->Columns->RemoveAt(i);
		this->DataMassivOutPut->Columns->RemoveAt(o);
	}

