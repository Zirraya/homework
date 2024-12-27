#pragma once

namespace Test {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnStart;
	private: System::Windows::Forms::Label^ lblNum1;
	protected:

	private: System::Windows::Forms::Label^ lblQuestion;
	private: System::Windows::Forms::Label^ lblTrue;
	private: System::Windows::Forms::Button^ btnNext;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ lblAnswer;
	private: System::Windows::Forms::Button^ btnCheck;
	private: System::Windows::Forms::Label^ lblFalse;


	private: System::Windows::Forms::Label^ lblNum2;
	private: System::Windows::Forms::Button^ btnRes;
	private: System::Windows::Forms::Label^ label1;



	private: System::ComponentModel::IContainer^ components;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->lblNum1 = (gcnew System::Windows::Forms::Label());
			this->lblQuestion = (gcnew System::Windows::Forms::Label());
			this->lblTrue = (gcnew System::Windows::Forms::Label());
			this->btnNext = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->lblAnswer = (gcnew System::Windows::Forms::Label());
			this->btnCheck = (gcnew System::Windows::Forms::Button());
			this->lblFalse = (gcnew System::Windows::Forms::Label());
			this->lblNum2 = (gcnew System::Windows::Forms::Label());
			this->btnRes = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnStart
			// 
			this->btnStart->Location = System::Drawing::Point(193, 134);
			this->btnStart->Margin = System::Windows::Forms::Padding(4);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(117, 53);
			this->btnStart->TabIndex = 0;
			this->btnStart->Text = L"НАЧАТЬ";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &MyForm::btnStart_Click);
			// 
			// lblNum1
			// 
			this->lblNum1->AutoSize = true;
			this->lblNum1->Location = System::Drawing::Point(20, 33);
			this->lblNum1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblNum1->Name = L"lblNum1";
			this->lblNum1->Size = System::Drawing::Size(72, 16);
			this->lblNum1->TabIndex = 1;
			this->lblNum1->Text = L"Вопрос №";
			this->lblNum1->Visible = false;
			// 
			// lblQuestion
			// 
			this->lblQuestion->AutoSize = true;
			this->lblQuestion->Location = System::Drawing::Point(20, 62);
			this->lblQuestion->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblQuestion->Name = L"lblQuestion";
			this->lblQuestion->Size = System::Drawing::Size(44, 16);
			this->lblQuestion->TabIndex = 2;
			this->lblQuestion->Text = L"label1";
			this->lblQuestion->Visible = false;
			// 
			// lblTrue
			// 
			this->lblTrue->AutoSize = true;
			this->lblTrue->Location = System::Drawing::Point(107, 143);
			this->lblTrue->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblTrue->Name = L"lblTrue";
			this->lblTrue->Size = System::Drawing::Size(226, 16);
			this->lblTrue->TabIndex = 3;
			this->lblTrue->Text = L"Количество правильных ответов:";
			this->lblTrue->Visible = false;
			// 
			// btnNext
			// 
			this->btnNext->Location = System::Drawing::Point(265, 203);
			this->btnNext->Margin = System::Windows::Forms::Padding(4);
			this->btnNext->Name = L"btnNext";
			this->btnNext->Size = System::Drawing::Size(156, 28);
			this->btnNext->TabIndex = 4;
			this->btnNext->Text = L"Следующий вопрос";
			this->btnNext->UseVisualStyleBackColor = true;
			this->btnNext->Visible = false;
			this->btnNext->Click += gcnew System::EventHandler(this, &MyForm::btnNext_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(24, 121);
			this->checkBox1->Margin = System::Windows::Forms::Padding(4);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(95, 20);
			this->checkBox1->TabIndex = 6;
			this->checkBox1->Text = L"checkBox1";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->Visible = false;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(24, 121);
			this->radioButton1->Margin = System::Windows::Forms::Padding(4);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(103, 20);
			this->radioButton1->TabIndex = 7;
			this->radioButton1->Text = L"radioButton1";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->Visible = false;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(24, 146);
			this->checkBox2->Margin = System::Windows::Forms::Padding(4);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(95, 20);
			this->checkBox2->TabIndex = 8;
			this->checkBox2->Text = L"checkBox2";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->Visible = false;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(24, 175);
			this->checkBox3->Margin = System::Windows::Forms::Padding(4);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(95, 20);
			this->checkBox3->TabIndex = 9;
			this->checkBox3->Text = L"checkBox3";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->Visible = false;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(24, 148);
			this->radioButton2->Margin = System::Windows::Forms::Padding(4);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(103, 20);
			this->radioButton2->TabIndex = 10;
			this->radioButton2->Text = L"radioButton2";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->Visible = false;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(24, 175);
			this->radioButton3->Margin = System::Windows::Forms::Padding(4);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(103, 20);
			this->radioButton3->TabIndex = 11;
			this->radioButton3->Text = L"radioButton3";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->Visible = false;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(24, 89);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(132, 22);
			this->textBox1->TabIndex = 12;
			this->textBox1->Visible = false;
			// 
			// lblAnswer
			// 
			this->lblAnswer->AutoSize = true;
			this->lblAnswer->Location = System::Drawing::Point(99, 209);
			this->lblAnswer->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblAnswer->Name = L"lblAnswer";
			this->lblAnswer->Size = System::Drawing::Size(44, 16);
			this->lblAnswer->TabIndex = 13;
			this->lblAnswer->Text = L"label2";
			this->lblAnswer->Visible = false;
			// 
			// btnCheck
			// 
			this->btnCheck->Location = System::Drawing::Point(76, 203);
			this->btnCheck->Margin = System::Windows::Forms::Padding(4);
			this->btnCheck->Name = L"btnCheck";
			this->btnCheck->Size = System::Drawing::Size(153, 28);
			this->btnCheck->TabIndex = 14;
			this->btnCheck->Text = L"Проверить ответ";
			this->btnCheck->UseVisualStyleBackColor = true;
			this->btnCheck->Visible = false;
			this->btnCheck->Click += gcnew System::EventHandler(this, &MyForm::btnCheck_Click);
			// 
			// lblFalse
			// 
			this->lblFalse->AutoSize = true;
			this->lblFalse->Location = System::Drawing::Point(107, 171);
			this->lblFalse->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblFalse->Name = L"lblFalse";
			this->lblFalse->Size = System::Drawing::Size(242, 16);
			this->lblFalse->TabIndex = 15;
			this->lblFalse->Text = L"Количество неправильных ответов:";
			this->lblFalse->Visible = false;
			// 
			// lblNum2
			// 
			this->lblNum2->AutoSize = true;
			this->lblNum2->Location = System::Drawing::Point(99, 33);
			this->lblNum2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblNum2->Name = L"lblNum2";
			this->lblNum2->Size = System::Drawing::Size(44, 16);
			this->lblNum2->TabIndex = 16;
			this->lblNum2->Text = L"label1";
			this->lblNum2->Visible = false;
			// 
			// btnRes
			// 
			this->btnRes->Location = System::Drawing::Point(265, 203);
			this->btnRes->Margin = System::Windows::Forms::Padding(4);
			this->btnRes->Name = L"btnRes";
			this->btnRes->Size = System::Drawing::Size(156, 28);
			this->btnRes->TabIndex = 17;
			this->btnRes->Text = L"Завершить тест";
			this->btnRes->UseVisualStyleBackColor = true;
			this->btnRes->Visible = false;
			this->btnRes->Click += gcnew System::EventHandler(this, &MyForm::btnRes_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(262, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(226, 16);
			this->label1->TabIndex = 18;
			this->label1->Text = L"ТЕСТ НА ЗНАНИЕ ДИНОЗАВРОВ";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(509, 336);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnRes);
			this->Controls->Add(this->lblNum2);
			this->Controls->Add(this->lblFalse);
			this->Controls->Add(this->btnCheck);
			this->Controls->Add(this->lblAnswer);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->btnNext);
			this->Controls->Add(this->lblTrue);
			this->Controls->Add(this->lblQuestion);
			this->Controls->Add(this->lblNum1);
			this->Controls->Add(this->btnStart);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"ДИНОЗАВРИКИ";
			this->ResumeLayout(false);
			this->PerformLayout();

		}


		void CheckAnswer(bool flag) {	//вывод правильного/неправильного ответа
			if (flag == true) {
				lblAnswer->Visible = true;
				lblAnswer->Text = "Правильно!";
				countTrue++;
			}
			else {
				lblAnswer->Visible = true;
				lblAnswer->Text = "Не правильно :(";
				countFalse++;
			}
		}


#pragma endregion
		//переменные
		int countTrue = 0;
		int countFalse = 0;
		int num = 0;
		int curElem = 0;
		int countElem = 0;

		//создание массива с номерами вопросов
		array<int>^ initMyArr() {
			array<int>^ arr = gcnew array<int>(10);
			for (int i = 0; i < arr->Length; i++)
				arr[i] = i + 1;
			return arr;
		}
		array<int>^ Arr = initMyArr();

		// Начать тестирование
	private: System::Void btnStart_Click(System::Object^ sender, System::EventArgs^ e) {
		btnStart->Visible = false;
		lblNum1->Visible = true;
		lblNum2->Visible = true;
		lblQuestion->Visible = true;
		btnCheck->Visible = true;

		btnNext_Click(sender, e);	// Переход к выполнению кода, заданного для кнопки "след. вопрос"
	}
	//

		// Проверка правильного ответа
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

	   // Переход на след. вопрос
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
//

	// Завершение тестирования
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
	 //
};
}
