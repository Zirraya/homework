	private: System::Void btnCheck_Click(System::Object^ sender, System::EventArgs^ e) {
	switch (curElem)
	{
	case 1:
		if (radioButton3->Checked) CheckAnswer(1);
		else CheckAnswer(0);
		break;

	case 2:
		if (radioButton1->Checked) CheckAnswer(1);
		else CheckAnswer(0);
		break;

	case 3:
		if (radioButton1->Checked) CheckAnswer(1);
		else CheckAnswer(0);
		break;

	case 4:
		if (radioButton2->Checked) CheckAnswer(1);
		else CheckAnswer(0);
		break;

	case 5:
		if (checkBox1->Checked && checkBox2->Checked && !checkBox3->Checked) CheckAnswer(1);
		else CheckAnswer(0);
		break;

	case 6:
		if (radioButton1->Checked) CheckAnswer(1);
		else CheckAnswer(0);
		break;

	case 7:
		if (checkBox1->Checked && checkBox2->Checked && checkBox3->Checked) CheckAnswer(1);
		else CheckAnswer(0);
		break;

	case 8:
		if (textBox1->Text=="эпидексиптерикс" || textBox1->Text=="Эпидексиптерикс") CheckAnswer(1);
		else CheckAnswer(0);
		break;

	case 9:
		if (radioButton3->Checked) CheckAnswer(1);
		else CheckAnswer(0);
		break;

	case 10:
		if (checkBox1->Checked && !checkBox2->Checked && !checkBox3->Checked) CheckAnswer(1);
		else CheckAnswer(0);
		break;

	default:
		break;
	}
	//

	// устанавливается запрет на выбор вариантов/ввод ответа
	textBox1->ReadOnly = true;
	radioButton1->Enabled = false;
	radioButton2->Enabled = false;
	radioButton3->Enabled = false;
	checkBox1->Enabled = false;
	checkBox2->Enabled = false;
	checkBox3->Enabled = false;

	btnCheck->Visible = false;

	if (num < 10) {	// если вопросы не закончились, то появляется кнопка след. вопроса
		btnNext->Visible = true;
	}
	else {	// если вопросы закончились, то появляется кнопка для завершения тестирования
		btnRes->Visible = true;
	}
}