// Удаление строк
private: System::Void DeleteString_Click(System::Object^ sender, System::EventArgs^ e) {


	// Проверка на наличие строк
	if (this->DataMassivInPut->Rows->Count == 0) {
		errorProvider1->SetError(DataMassivInPut, " Что бы удалить строку, нужно в начале добавить ее "); //  Установка ошибки, если нет строк
		return; 
	}

	// Удаление
	if (!this->DataMassivInPut->CurrentRow->IsNewRow && !this->DataMassivOutPut->CurrentRow->IsNewRow) {
		int i = this->DataMassivInPut->CurrentRow->Index;
		this->DataMassivInPut->Rows->Remove(this->DataMassivInPut->Rows[i]);

		int o = this->DataMassivOutPut->CurrentRow->Index;
		this->DataMassivOutPut->Rows->Remove(this->DataMassivOutPut->Rows[o]);
	}

}