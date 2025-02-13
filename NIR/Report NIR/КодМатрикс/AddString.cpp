private: System::Void AddString_Click(System::Object^ sender, System::EventArgs^ e) {

	// Проверка на наличие столбцов 
	if (this->Matrix1->Columns->Count == 0) {
		errorM1->SetError(Matrix1, "Столбцы должны быть добавлены перед добавлением строк.");
		return;
	}
	clearMatr1();
	this->Matrix1->Rows->Add(1);
	
	if (this->Matrix1->Rows->Count > 0) {
		errorM1->SetError(Matrix1, "");
	}

}