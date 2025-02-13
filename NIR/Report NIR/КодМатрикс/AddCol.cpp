private: System::Void AddColumn_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Matrix1->Columns->Add("COLUMN", " ");
	
	if (this->Matrix1->Columns->Count > 0) {
		errorM1->SetError(Matrix1, "");
	}
	for (int i = 0; i < this->Matrix1->Columns->Count; i++) {
		this->Matrix1->Columns[i]->Width = System::Convert::ToInt32(this->Matrix1->Width / (1.25 * this->Matrix1->Columns->Count));
	}
	clearMatr1();
	
}