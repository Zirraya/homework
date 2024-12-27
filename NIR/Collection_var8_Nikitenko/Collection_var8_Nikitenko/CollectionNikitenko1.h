#pragma once

namespace Collectionvar8Nikitenko {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	

	/// <summary>
	/// Сводка для CollectionNikitenko
	/// </summary>
	public ref class CollectionNikitenko : public System::Windows::Forms::Form
	{
	public:
		CollectionNikitenko(void)
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
		~CollectionNikitenko()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ CreateQ;
	protected:

	private: System::Windows::Forms::TextBox^ InPutQu;
	private: System::Windows::Forms::TextBox^ OutPutQu;

	private: System::Windows::Forms::Button^ DeleteQu;
	private: System::Windows::Forms::TextBox^ ChotElem;
	private: System::Windows::Forms::Button^ Interval;
	private: System::Windows::Forms::TextBox^ a;
	private: System::Windows::Forms::TextBox^ b;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ NewElIn;
	private: System::Windows::Forms::Button^ AddEl;
	private: System::Windows::Forms::Button^ DeleteEl;



	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ NewQOut;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ NewQ;

	private: System::Collections::Generic::Queue<int> q; // Коллекция
	private: System::Windows::Forms::ErrorProvider^ errorProvider1;
	private: System::Windows::Forms::ErrorProvider^ errorProvider2;
	private: System::Windows::Forms::ErrorProvider^ errora;
	private: System::Windows::Forms::ErrorProvider^ errorb;

	private: System::ComponentModel::IContainer^ components;



	protected:


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
			this->components = (gcnew System::ComponentModel::Container());
			this->CreateQ = (gcnew System::Windows::Forms::Button());
			this->InPutQu = (gcnew System::Windows::Forms::TextBox());
			this->OutPutQu = (gcnew System::Windows::Forms::TextBox());
			this->DeleteQu = (gcnew System::Windows::Forms::Button());
			this->ChotElem = (gcnew System::Windows::Forms::TextBox());
			this->Interval = (gcnew System::Windows::Forms::Button());
			this->a = (gcnew System::Windows::Forms::TextBox());
			this->b = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->NewElIn = (gcnew System::Windows::Forms::TextBox());
			this->AddEl = (gcnew System::Windows::Forms::Button());
			this->DeleteEl = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->NewQOut = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->NewQ = (gcnew System::Windows::Forms::Button());
			this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->errorProvider2 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->errora = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->errorb = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errora))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorb))->BeginInit();
			this->SuspendLayout();
			// 
			// CreateQ
			// 
			this->CreateQ->Location = System::Drawing::Point(380, 84);
			this->CreateQ->Name = L"CreateQ";
			this->CreateQ->Size = System::Drawing::Size(169, 40);
			this->CreateQ->TabIndex = 0;
			this->CreateQ->Text = L"Создать Очередь";
			this->CreateQ->UseVisualStyleBackColor = true;
			this->CreateQ->Click += gcnew System::EventHandler(this, &CollectionNikitenko::CreateQ_Click);
			// 
			// InPutQu
			// 
			this->InPutQu->Location = System::Drawing::Point(119, 84);
			this->InPutQu->Multiline = true;
			this->InPutQu->Name = L"InPutQu";
			this->InPutQu->Size = System::Drawing::Size(255, 54);
			this->InPutQu->TabIndex = 1;
			// 
			// OutPutQu
			// 
			this->OutPutQu->Location = System::Drawing::Point(119, 188);
			this->OutPutQu->Multiline = true;
			this->OutPutQu->Name = L"OutPutQu";
			this->OutPutQu->Size = System::Drawing::Size(255, 54);
			this->OutPutQu->TabIndex = 2;
			// 
			// DeleteQu
			// 
			this->DeleteQu->Location = System::Drawing::Point(380, 130);
			this->DeleteQu->Name = L"DeleteQu";
			this->DeleteQu->Size = System::Drawing::Size(169, 40);
			this->DeleteQu->TabIndex = 3;
			this->DeleteQu->Text = L"Удалить Очередь";
			this->DeleteQu->UseVisualStyleBackColor = true;
			this->DeleteQu->Click += gcnew System::EventHandler(this, &CollectionNikitenko::DeleteQu_Click);
			// 
			// ChotElem
			// 
			this->ChotElem->Location = System::Drawing::Point(893, 183);
			this->ChotElem->Multiline = true;
			this->ChotElem->Name = L"ChotElem";
			this->ChotElem->Size = System::Drawing::Size(193, 44);
			this->ChotElem->TabIndex = 4;
			// 
			// Interval
			// 
			this->Interval->Location = System::Drawing::Point(875, 137);
			this->Interval->Name = L"Interval";
			this->Interval->Size = System::Drawing::Size(315, 40);
			this->Interval->TabIndex = 5;
			this->Interval->Text = L"Найти сумму элементов в интервале";
			this->Interval->UseVisualStyleBackColor = true;
			this->Interval->Click += gcnew System::EventHandler(this, &CollectionNikitenko::Interval_Click);
			// 
			// a
			// 
			this->a->Location = System::Drawing::Point(710, 134);
			this->a->Multiline = true;
			this->a->Name = L"a";
			this->a->Size = System::Drawing::Size(52, 40);
			this->a->TabIndex = 6;
			// 
			// b
			// 
			this->b->Location = System::Drawing::Point(781, 134);
			this->b->Multiline = true;
			this->b->Name = L"b";
			this->b->Size = System::Drawing::Size(52, 40);
			this->b->TabIndex = 7;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(619, 147);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(85, 18);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Диапазон [";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(839, 147);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(12, 18);
			this->label2->TabIndex = 9;
			this->label2->Text = L"]";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(54, 109);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 18);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Ввод";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(54, 205);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(55, 18);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Вывод";
			// 
			// NewElIn
			// 
			this->NewElIn->Location = System::Drawing::Point(141, 277);
			this->NewElIn->Multiline = true;
			this->NewElIn->Name = L"NewElIn";
			this->NewElIn->Size = System::Drawing::Size(84, 48);
			this->NewElIn->TabIndex = 12;
			// 
			// AddEl
			// 
			this->AddEl->Location = System::Drawing::Point(231, 268);
			this->AddEl->Name = L"AddEl";
			this->AddEl->Size = System::Drawing::Size(125, 40);
			this->AddEl->TabIndex = 13;
			this->AddEl->Text = L"Добавить элемент";
			this->AddEl->UseVisualStyleBackColor = true;
			this->AddEl->Click += gcnew System::EventHandler(this, &CollectionNikitenko::AddEl_Click);
			// 
			// DeleteEl
			// 
			this->DeleteEl->Location = System::Drawing::Point(232, 314);
			this->DeleteEl->Name = L"DeleteEl";
			this->DeleteEl->Size = System::Drawing::Size(124, 40);
			this->DeleteEl->TabIndex = 14;
			this->DeleteEl->Text = L"Удалить элемент";
			this->DeleteEl->UseVisualStyleBackColor = true;
			this->DeleteEl->Click += gcnew System::EventHandler(this, &CollectionNikitenko::DeleteEl_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(7, 290);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(118, 18);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Новый элемент";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(619, 111);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(518, 18);
			this->label6->TabIndex = 16;
			this->label6->Text = L"Найти сумму четных элементов, попадающих в заданный интервал [a, b].";
			// 
			// NewQOut
			// 
			this->NewQOut->Location = System::Drawing::Point(621, 314);
			this->NewQOut->Multiline = true;
			this->NewQOut->Name = L"NewQOut";
			this->NewQOut->Size = System::Drawing::Size(255, 54);
			this->NewQOut->TabIndex = 17;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(619, 290);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(594, 18);
			this->label7->TabIndex = 18;
			this->label7->Text = L"Получить новую очередь, вставив после максимального элемента новый элемент.";
			// 
			// NewQ
			// 
			this->NewQ->Location = System::Drawing::Point(896, 314);
			this->NewQ->Name = L"NewQ";
			this->NewQ->Size = System::Drawing::Size(225, 40);
			this->NewQ->TabIndex = 19;
			this->NewQ->Text = L"Новая очередь";
			this->NewQ->UseVisualStyleBackColor = true;
			this->NewQ->Click += gcnew System::EventHandler(this, &CollectionNikitenko::NewQ_Click);
			// 
			// errorProvider1
			// 
			this->errorProvider1->ContainerControl = this;
			// 
			// errorProvider2
			// 
			this->errorProvider2->ContainerControl = this;
			// 
			// errora
			// 
			this->errora->ContainerControl = this;
			// 
			// errorb
			// 
			this->errorb->ContainerControl = this;
			// 
			// CollectionNikitenko
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1317, 484);
			this->Controls->Add(this->NewQ);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->NewQOut);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->DeleteEl);
			this->Controls->Add(this->AddEl);
			this->Controls->Add(this->NewElIn);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->b);
			this->Controls->Add(this->a);
			this->Controls->Add(this->Interval);
			this->Controls->Add(this->ChotElem);
			this->Controls->Add(this->DeleteQu);
			this->Controls->Add(this->OutPutQu);
			this->Controls->Add(this->InPutQu);
			this->Controls->Add(this->CreateQ);
			this->DoubleBuffered = true;
			this->Name = L"CollectionNikitenko";
			this->Text = L"CollectionNikitenko";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errora))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorb))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
// Создание очереди	
private: System::Void CreateQ_Click(System::Object^ sender, System::EventArgs^ e) {

	q.Clear();	
	errorProvider1->Clear();	

	System::String^ str = System::Convert::ToString(this -> InPutQu -> Text);
		str += " ";
	 int X, at, pos = 0;
	 at = str -> IndexOf(" "); 
	 while (at != -1) { 
		System::String ^ str1 = str->Substring(pos,at-pos); 
		 pos = at + 1;
		 bool res = Int32::TryParse(str1, X);

		 if (!X) {
			 errorProvider1->SetError(InPutQu, "В строке есть не числа");
			 return;
		 }

		 q.Enqueue(X); 
		 at = str -> IndexOf(" ", pos); 
		
	}
	 System::Collections::Generic::Queue<int> buf; 
	 System::String ^ str2 = "";
	 while (q.Count) {
		 buf.Enqueue(q.Peek()); 
		 str2 += System::Convert::ToString(q.Peek()) + " "; 
		 q.Dequeue(); 		
	}
	 while (buf.Count) { 
		 q.Enqueue(buf.Peek()); 
		 buf.Dequeue(); 
		
	}
		 this -> OutPutQu -> Text = str2; 
}
// 

// Удаление очереди
private: System::Void DeleteQu_Click(System::Object^ sender, System::EventArgs^ e) {

	q.Clear();
	this->OutPutQu->Text = "";
	this->InPutQu->Text = "";
	this->ChotElem->Text = "";
	this->NewElIn->Text = "";
	this->NewQOut->Text = "";
}
//

// Добавление элемента
private: System::Void AddEl_Click(System::Object^ sender, System::EventArgs^ e) {

	q.Clear();
	errorProvider2->Clear();
	System::String^ str = System::Convert::ToString(this->OutPutQu->Text);
	System::String^ chis = System::Convert::ToString(this->NewElIn->Text);
	int num;
	bool _res = Int32::TryParse(chis, num);
	if (chis == "") {
		errorProvider2->SetError(AddEl, "Введите число");
		return;
	}
	else if (!_res) {
		errorProvider2->SetError(NewElIn, "Введено не число");
		return;
	}
	else {
		int x, at, pos = 0;
		at = str->IndexOf(" ");	//позиция первого пробела
		while (at != -1) {	//пока находим пробел
			System::String^ str1 = str->Substring(pos, at - pos);	//считываем число
			pos = at + 1;
			bool res = Int32::TryParse(str1, x);
			q.Enqueue(x);
			at = str->IndexOf(" ", pos);	//ищем след пробел
		}
		q.Enqueue(num);	
		System::String^ str2 = "";
		System::Collections::Generic::Stack<int> buf;
		while (q.Count) {
			buf.Push(q.Peek());
			q.Dequeue();
		}
		while (buf.Count) {
			q.Enqueue(buf.Peek());
			str2 += System::Convert::ToString(buf.Peek()) + " ";
			buf.Pop();
		}

		this->OutPutQu->Text = str2;
	}
}
//

// Удаление элемента
private: System::Void DeleteEl_Click(System::Object^ sender, System::EventArgs^ e) {

	q.Clear();
	errorProvider2->Clear();
	System::String^ str = System::Convert::ToString(this->OutPutQu->Text);
	System::String^ chis = System::Convert::ToString(this->NewElIn->Text);
	int num;
	bool _res = Int32::TryParse(chis, num);
	if (chis == "") {
		errorProvider2->SetError(NewElIn, "Введите число");
		return;
	}
	else if (!_res) {
		errorProvider2->SetError(NewElIn, "Введено не число");
		return;
	}
	else {
		int x, at, pos = 0;
		at = str->IndexOf(" ");	//позиция первого пробела
		while (at != -1) {	//пока находим пробел
			System::String^ str1 = str->Substring(pos, at - pos);	//считываем число
			pos = at + 1;
			bool res = Int32::TryParse(str1, x);
			q.Enqueue(x);
			at = str->IndexOf(" ", pos);	//ищем след пробел
		}
		System::String^ str2 = "";
		System::Collections::Generic::Stack<int> buf;
		while (q.Count) {
			buf.Push(q.Peek());
			q.Dequeue();
		}
		while (buf.Count) {
			q.Enqueue(buf.Peek());
			if (buf.Peek() != num) {	
				str2 += System::Convert::ToString(buf.Peek()) + " ";
			}
			buf.Pop();
		}

		this->OutPutQu->Text = str2;
	}


}
//

// Найти сууму элемнтов в заданном интервале
private: System::Void Interval_Click(System::Object^ sender, System::EventArgs^ e) {

	ChotElem->Text = String::Empty;	//очистка поля
	int InterA;
	int interB;
	bool resultA = Int32::TryParse(this->a->Text, InterA);
	bool resultB = Int32::TryParse(this->b->Text, interB);

	if (!resultA && !resultB) {	//если a и b не числа
		errora->SetError(a, "Введено не целое число");
		errorb->SetError(b, "Введено не целое число");

	}
	else if (!resultB) {	//если b не число
		errorb->SetError(b, "Введено не целое число");
		errora->SetError(a, String::Empty);
	}
	else if (!resultA) {	//если a не число
		errora->SetError(a, "Введено не целое число");
		errorb->SetError(b, String::Empty);
	}
	else {
		if (InterA > interB) {	//если a > b
			errora->SetError(a, "Неправильно введен диапазон");
			errorb->SetError(b, String::Empty);
		}
		// Получение элементов из OutPutQu
		array<String^>^ elements = OutPutQu->Text->Split(' ');

		int sum = 0;
		int count1 = 0;

		for each (String ^ element in elements) {
			int number;
			if (Int32::TryParse(element->Trim(), number)) {
				if (number >= InterA && number <= interB && number % 2 == 0) { // проверка на четность и диапазон
					sum += number;
					count1++;
				}
			}
		}

		if (count1 == 0) { // если нет таких элементов
			ChotElem->Text = "Таких элементов нет";
		}
		else { // элементы есть
			ChotElem->Text = System::Convert::ToString(sum); // вывод суммы четных элементов
		}
	}
}
	
//


// Новая очередь после вставки нового элемента после максимального элемента
private: System::Void NewQ_Click(System::Object^ sender, System::EventArgs^ e) {


	// Очистка текстового поля для новой очереди
	NewQOut->Text = String::Empty; // Предположим, что у нас есть текстовое поле для вывода новой очереди

	// Получение элементов из OutPutQu
	array<String^>^ elements = OutPutQu->Text->Split(' ');

	// Переменные для хранения максимального значения и нового элемента
	int maxElement = Int32::MinValue;
	String^ newElement = NewElIn->Text->Trim(); // Получаем новый элемент из текстового поля

	// Проверка, является ли новый элемент целым числом
	int newElementValue;
	if (!Int32::TryParse(newElement, newElementValue)) {
		MessageBox::Show("Введите корректное целое число для нового элемента.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return; // Выход из функции, если ввод некорректен
	}

	// Поиск максимального элемента
	for each (String ^ element in elements) {
		int number;
		if (Int32::TryParse(element->Trim(), number)) {
			if (number > maxElement) {
				maxElement = number; // Обновляем максимальный элемент
			}
		}
	}

	// Создание новой очереди с вставкой нового элемента после максимальных
	String^ newQueue = String::Empty;
	for each (String ^ element in elements) {
		newQueue += element->Trim() + " "; // Добавляем текущий элемент в новую очередь
		int number;
		if (Int32::TryParse(element->Trim(), number) && number == maxElement) {
			newQueue += newElement + " "; // Вставляем новый элемент после максимального
		}
	}


	// Удаление первого элемента (если он есть)
	int firstCommaIndex = newQueue->IndexOf(' ');
	if (firstCommaIndex != -1) {
		newQueue = newQueue->Substring(firstCommaIndex + 1); // Удаляем все символы до первого пробела
	}

	// Вывод новой очереди в текстовое поле
	NewQOut->Text = newQueue;

}
//

};

}
