private: System::Void DeleteColumn_Click(System::Object^ sender, System::EventArgs^ e) {
	// Проверка на наличие строк
	if (this->Matrix1->Columns->Count == 0) {
		errorM1->SetError(Matrix1, " Что бы удалить столбец, нужно в начале добавить его "); //  Установка ошибки, если нет строк
		return; //  Выход из метода
	}
		clearMatr1();

	// Проверяем, есть ли столбцы в DataGridView
	if (this->Matrix1->Columns->Count > 0) {
		// Получение индекса последнего столбца 
		int i = this->Matrix1->Columns->Count - 1; // Индекс последнего столбца
		// Удалаление
		this->Matrix1->Columns->RemoveAt(i);
		
	}

}