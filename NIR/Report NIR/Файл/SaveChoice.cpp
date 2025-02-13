private: System::Void SaveInforPass_Click(System::Object^ sender, System::EventArgs^ e) {
		errorProvider1->Clear();
		errorProvider2->Clear();
		if (ChoiceRace->Text != "") {
			System::IO::Stream^ MyStream;
			if (this->saveFileDialog2->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				if ((MyStream = this->saveFileDialog2->OpenFile()) != nullptr) {
					System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(MyStream);
					String^ str = "";
					int n = this->Table2->RowCount;
					for (int i = 0; i < n - 1; i++) {
						str = "";
						for (int j = 0; j < this->Table2->ColumnCount; j++) {
							str += this->Table2->Rows[i]->Cells[j]->Value + " ";
						}
						sw->WriteLine(str);
					}
					str = "";
					for (int j = 0; j < this->Table2->ColumnCount; j++) {
						str += this->Table2->Rows[n - 1]->Cells[j]->Value + " ";
					}
					sw->Write(str);
					sw->Close();
				}
			}
		}
		else {
			errorProvider2->SetError(ChoiceRace, "Сначала выберите гостиницу");
		}

	}//