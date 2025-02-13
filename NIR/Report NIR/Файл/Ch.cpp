private: System::Void ChoiseRaceBut_Click(System::Object^ sender, System::EventArgs^ e) {

		errorProvider1->Clear();
		errorProvider2->Clear();
		this->Table2->RowCount = 1;
		for (int i = 0; i < this->Table2->RowCount; i++) {
			for (int j = 0; j < this->Table2->ColumnCount; j++) {
				this->Table2->Rows[i]->Cells[j]->Value = nullptr;
			}
		}
		if (ChoiceRace->Text == "") {
			errorProvider1->SetError(ChoiceRace, "Сначала введите навзание гостиницы");
			return;
		}
		int n = this->Table1->RowCount;
		int m = this->Table1->ColumnCount;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m; j++) {
				if (this->Table1->Rows[i]->Cells[j]->Value == nullptr) {
					errorProvider1->SetError(this->Table1, "В строке " + Convert::ToString(i + 1) + " отсутствую какие-то данные");
					return;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (this->Table1->Rows[i]->Cells[6]->Value == ChoiceRace->Text) {
				this->Table2->Rows->Add(1);
			}
		}
		for (int i = 0; i < n; i++) {
			if (System::Convert::ToString(this->Table1->Rows[i]->Cells[3]->Value) == ChoiceRace->Text) {
				for (int k = 0; k < this->Table2->RowCount; k++) {
					for (int j = 0; j < m; j++) {
						this->Table2->Rows[k]->Cells[j]->Value = this->Table1->Rows[i]->Cells[j]->Value;
					}
				}
			}
		}
	}