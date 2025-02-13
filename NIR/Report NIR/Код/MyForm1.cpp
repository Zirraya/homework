
	private: System::Void btnCalculate_Click(System::Object^ sender, System::EventArgs^ e) {
		ClearAll();
		 long long InputNumber;
		 bool result = Int64::TryParse(this->txtInput->Text, InputNumber); //переводим строку из TextBox в число
		
			 if (!result) //dвели не число
			 errorProvider1->SetError(txtInput, "¬ведено не целое число");
		 else {//число
			 if (InputNumber >= 20)
				 this->txtOutput->Text = "—лишком большое число";
			 else {
				 long long OutputNumber = fact(InputNumber);//результат
				 if (OutputNumber == -1) //отрицательное число
					 errorProvider1->SetError(txtInput, "¬ведено отрицательное число");
				 else //все нормально
					 this->txtOutput->Text = System::Convert::ToString(OutputNumber);//записываем в поле
						
			}
			
		}

	}

