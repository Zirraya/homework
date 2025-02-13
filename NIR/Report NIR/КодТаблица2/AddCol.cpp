// Добавление стоблцов
private: System::Void AddColumn_Click(System::Object^ sender, System::EventArgs^ e) {

	this->DataMassivInPut->Columns->Add("COLUMN"," ");
	this->DataMassivOutPut->Columns->Add("COLUMN", " ");
	if (this->DataMassivInPut->Columns->Count > 0 && this->DataMassivOutPut->Columns->Count > 0) {
		errorProvider1->SetError(DataMassivInPut, ""); 
	}
	for (int i = 0; i < this->DataMassivInPut->Columns->Count; i++) {
		this->DataMassivInPut->Columns[i]->Width = System::Convert::ToInt32(this->DataMassivInPut->Width / (1.25 * this->DataMassivInPut->Columns->Count));
	}
	for (int i = 0; i < this->DataMassivOutPut->Columns->Count; i++) {
		this->DataMassivOutPut->Columns[i]->Width = System::Convert::ToInt32(this->DataMassivOutPut->Width / (1.25 * this->DataMassivOutPut->Columns->Count));
	}
}