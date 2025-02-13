private: System::Void btnNext_Click(System::Object^ sender, System::EventArgs^ e) {
	//скрытие ненужных элементов формы
	btnNext->Visible = false;
	lblAnswer->Visible = false;
	textBox1->Visible = false;
	radioButton1->Visible = false;
	radioButton2->Visible = false;
	radioButton3->Visible = false;
	checkBox1->Visible = false;
	checkBox2->Visible = false;
	checkBox3->Visible = false;
	btnCheck->Visible = true;

	//снятие выбора
	radioButton1->Checked = false;
	radioButton2->Checked = false;
	radioButton3->Checked = false;
	checkBox1->Checked = false;
	checkBox2->Checked = false;
	checkBox3->Checked = false;

	//разрешение выбора вариантов и очистка поля 
	radioButton1->Enabled = true;
	radioButton2->Enabled = true;
	radioButton3->Enabled = true;
	checkBox1->Enabled = true;
	checkBox2->Enabled = true;
	checkBox3->Enabled = true;
	textBox1->Text = "";

	curElem = 0;	//переменная для номера текущего вопроса
	num += 1;	//кол-во вопросов
	
	lblNum2->Text = num.ToString();
	Random^ rand = gcnew Random();
	while (curElem == 0) {	//рандомный выбор номера вопроса из массива
		curElem = Arr[rand->Next(0, Arr->Length)];
	}
	Arr[curElem - 1] = 0;

	//описание каждого вопроса и вариантов ответа
	switch (curElem)
	{
	case 1:
		lblQuestion->Text = "Как сокращенно называют теранозавра рекса?";
		radioButton1->Visible = true;
		radioButton2->Visible = true;
		radioButton3->Visible = true;
		radioButton1->Text = "Король";
		radioButton2->Text = "Аллик";
		radioButton3->Text = "Т-рекс";
		break;

	case 2:
		lblQuestion->Text = " В каком пероиде жил аллозавр?";
		radioButton1->Visible = true;
		radioButton2->Visible = true;
		radioButton3->Visible = true;
		radioButton1->Text = "Юриский период";
		radioButton2->Text = "Меловой период";
		radioButton3->Text = "Триасовый период";
		break;

	case 3:
		lblQuestion->Text = "Какого динозавра можно назвать предком птиц?";
		radioButton1->Visible = true;
		radioButton2->Visible = true;
		radioButton3->Visible = true;
		radioButton1->Text = "Архиоптерикс";
		radioButton2->Text = "Рамфоринх";
		radioButton3->Text = "Птеранодон";
		break;

	case 4:
		lblQuestion->Text = "Какой раптор жил на территории штата Юта?";
		radioButton1->Visible = true;
		radioButton2->Visible = true;
		radioButton3->Visible = true;
		radioButton1->Text = "Велоцераптор";
		radioButton2->Text = "Ютараптор";
		radioButton3->Text = "Австрораптор";
		break;

	case 5:
		lblQuestion->Text = "Какой(какие) динозавр(ы) был(и) покрыт(ы) перьями?";
		checkBox1->Visible = true;
		checkBox2->Visible = true;
		checkBox3->Visible = true;
		checkBox1->Text = "Теризинозавр";
		checkBox2->Text = "Австрораптор";
		checkBox3->Text = "Птеранодон";
		break;

	case 6:
		lblQuestion->Text = "Овераптор питаелся яйцами?";
		radioButton1->Visible = true;
		radioButton2->Visible = true;
		radioButton1->Text = "Да";
		radioButton2->Text = "Нет";
		break;

	case 7:
		lblQuestion->Text = "Выберите плавающих динозвров";
		checkBox1->Visible = true;
		checkBox2->Visible = true;
		checkBox3->Visible = true;
		checkBox1->Text = "Ихтиозавр";
		checkBox2->Text = "Спинозавр";
		checkBox3->Text = "Зухомим";
		break;

	case 8:
		lblQuestion->Text = "Самый маленький динозвр";
		textBox1->Visible = true;
		textBox1->ReadOnly = false;
		break;

	case 9:
		lblQuestion->Text = "Какой динозавр питался лисьтями?";
		radioButton1->Visible = true;
		radioButton2->Visible = true;
		radioButton3->Visible = true;
		radioButton1->Text = "Гуанлонг";
		radioButton2->Text = "Австрораптор";
		radioButton3->Text = "Диплодок";
		break;

	case 10:
		lblQuestion->Text = "Какой дизовр назван в честь языческого божества?";
		checkBox1->Visible = true;
		checkBox2->Visible = true;
		checkBox3->Visible = true;
		checkBox1->Text = "Кетцалькоатль";
		checkBox2->Text = "Гуанлонг";
		checkBox3->Text = "Брахиозавр";
		break;

	default:
		break;
	}
}