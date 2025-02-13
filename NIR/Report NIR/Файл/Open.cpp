private: System::Void OpenFile_Click(System::Object^ sender, System::EventArgs^ e) {


		if (this->openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			System::IO::Stream^ myStream;
			if ((myStream = openFileDialog1->OpenFile()) != nullptr) {
				System::IO::StreamReader^ sw = gcnew System::IO::StreamReader(myStream);
				String^ str = "";
				String^ person;
				date DoR;

				int pos = 0;
				int at = 0;
				int i = 0;

				// Очищаем старые данные из Table1
				this->Table1->Rows->Clear();

				while (sw->Peek() > -1) {
					this->Table1->Rows->Add(1);

					person = sw->ReadLine();
					person += " ";
					at = 0;
					pos = person->IndexOf(" ");
					for (int j = 0; j < 5; j++) {
						this->Table1->Rows[i]->Cells[j]->Value = person->Substring(at, pos - at);
						at = pos + 1;
						pos = person->IndexOf(" ", at);
					}
					DoR = StringToDate(person->Substring(at, pos - at));
					this->Table1->Rows[i]->Cells[5]->Value = DateToString(DoR);
					at = pos + 1;
					pos = person->IndexOf(" ", at);
					this->Table1->Rows[i]->Cells[6]->Value = person->Substring(at, pos - at);

					i++;
				}
			}
			else {
				errorProvider1->SetError(OpenFile, "Файл не открыт");
			}
		}
		else {
			errorProvider1->SetError(OpenFile, "Файл не открыт");
		}
	}