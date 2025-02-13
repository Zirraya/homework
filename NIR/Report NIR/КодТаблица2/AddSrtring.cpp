// Добавление строк
private: System::Void AddString_Click(System::Object^ sender, System::EventArgs^ e) {

	// Проверка на наличие столбцов 
	if (this->DataMassivInPut->Columns->Count == 0) {
		errorProvider1->SetError(DataMassivInPut, "Столбцы должны быть добавлены перед добавлением строк.");
		return; 
	}

	this->DataMassivInPut->Rows->Add(1);
	this->DataMassivOutPut->Rows->Add(1);
	if (this->DataMassivInPut->Rows->Count > 0 && this->DataMassivOutPut->Rows->Count > 0) {
		errorProvider1->SetError(DataMassivInPut, ""); 
	}

}