private: System::Void SaveInFile_Click(System::Object^ sender, System::EventArgs^ e) {

		errorProvider1->Clear();
		System::IO::Stream^ MyStream;
		if (this->saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if ((MyStream = this->saveFileDialog1->OpenFile()) != nullptr) {
				System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(MyStream);
				String^ str = "";
				int n = this->Table1->RowCount;
				for (int i = 0; i < n - 1; i++) {
					str = "";
					for (int j = 0; j < this->Table1->ColumnCount; j++) {
						str += this->Table1->Rows[i]->Cells[j]->Value + " ";
					}
					sw->WriteLine(str);
				}
				str = "";
				for (int j = 0; j < this->Table1->ColumnCount; j++) {
					str += this->Table1->Rows[n - 1]->Cells[j]->Value + " ";
				}
				sw->Write(str);
				sw->Close();
			}
		}
	}