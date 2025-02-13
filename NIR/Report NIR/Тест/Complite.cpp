private: System::Void btnRes_Click(System::Object^ sender, System::EventArgs^ e) {
	//скрытие всех ненужных элементов формы
	lblNum1->Visible = false;
	lblNum2->Visible = false;
	lblQuestion->Visible = false;
	btnCheck->Visible = false;
	lblTrue->Visible = true;
	lblFalse->Visible = true;
	btnRes->Visible = false;
	lblAnswer->Visible = false;
	textBox1->Visible = false;
	radioButton1->Visible = false;
	radioButton2->Visible = false;
	radioButton3->Visible = false;
	checkBox1->Visible = false;
	checkBox2->Visible = false;
	checkBox3->Visible = false;

	// вывод правильных и неправильных ответов
	lblTrue->Text += System::Convert::ToString(countTrue);
	lblFalse->Text += System::Convert::ToString(countFalse);
	//
}