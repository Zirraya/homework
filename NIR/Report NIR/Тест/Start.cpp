private: System::Void btnStart_Click(System::Object^ sender, System::EventArgs^ e) {
		btnStart->Visible = false;
		lblNum1->Visible = true;
		lblNum2->Visible = true;
		lblQuestion->Visible = true;
		btnCheck->Visible = true;

		btnNext_Click(sender, e);	// Переход к выполнению кода, заданного для кнопки "след. вопрос"
	}