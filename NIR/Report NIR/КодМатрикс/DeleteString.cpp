private: System::Void DeleteString_Click(System::Object^ sender, System::EventArgs^ e) {


	// Проверка на наличие строк
	if (this->Matrix1->Rows->Count == 0) {
		errorM1->SetError(Matrix1, " Что бы удалить строку, нужно в начале добавить ее "); //  Установка ошибки, если нет строк
		return;
	}
	clearMatr1();
	// Удаление
	if (!this->Matrix1->CurrentRow->IsNewRow) {
		int i = this->Matrix1->CurrentRow->Index;
		this->Matrix1->Rows->Remove(this->Matrix1->Rows[i]);

	}

}