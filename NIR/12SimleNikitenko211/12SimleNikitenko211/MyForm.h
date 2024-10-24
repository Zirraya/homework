#pragma once

namespace My12SimleNikitenko211 {

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
	private: System::Windows::Forms::Button^ Calculate;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtOutput;


	private: System::Windows::Forms::TextBox^ txtInputX;

	private: System::Windows::Forms::TextBox^ txtInputY;



	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ErrorProvider^ errorProvider1;
	private: System::Windows::Forms::ErrorProvider^ errorProvider2;

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
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->Calculate = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtOutput = (gcnew System::Windows::Forms::TextBox());
			this->txtInputX = (gcnew System::Windows::Forms::TextBox());
			this->txtInputY = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->errorProvider2 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider2))->BeginInit();
			this->SuspendLayout();
			// 
			// Calculate
			// 
			this->Calculate->Location = System::Drawing::Point(304, 338);
			this->Calculate->Name = L"Calculate";
			this->Calculate->Size = System::Drawing::Size(100, 73);
			this->Calculate->TabIndex = 0;
			this->Calculate->Text = L"Вычислить";
			this->Calculate->UseVisualStyleBackColor = true;
			this->Calculate->Click += gcnew System::EventHandler(this, &MyForm::Calculate_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(246, 80);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(22, 22);
			this->label1->TabIndex = 1;
			this->label1->Text = L"X";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(246, 152);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(22, 22);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Y";
			// 
			// txtOutput
			// 
			this->txtOutput->Location = System::Drawing::Point(30, 230);
			this->txtOutput->Multiline = true;
			this->txtOutput->Name = L"txtOutput";
			this->txtOutput->Size = System::Drawing::Size(248, 265);
			this->txtOutput->TabIndex = 3;
			// 
			// txtInputX
			// 
			this->txtInputX->Location = System::Drawing::Point(297, 66);
			this->txtInputX->Multiline = true;
			this->txtInputX->Name = L"txtInputX";
			this->txtInputX->Size = System::Drawing::Size(177, 48);
			this->txtInputX->TabIndex = 4;
			// 
			// txtInputY
			// 
			this->txtInputY->Location = System::Drawing::Point(297, 141);
			this->txtInputY->Multiline = true;
			this->txtInputY->Name = L"txtInputY";
			this->txtInputY->Size = System::Drawing::Size(177, 48);
			this->txtInputY->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(98, 205);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(108, 22);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Результаты";
			// 
			// errorProvider1
			// 
			this->errorProvider1->ContainerControl = this;
			// 
			// errorProvider2
			// 
			this->errorProvider2->ContainerControl = this;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(513, 507);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txtInputY);
			this->Controls->Add(this->txtInputX);
			this->Controls->Add(this->txtOutput);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Calculate);
			this->Name = L"MyForm";
			this->Text = L"Простые Вычисления";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void ClearAll() {//очистка полей
			this->txtOutput->Text = "";
			errorProvider1->SetError(txtInputX, String::Empty);
			errorProvider2->SetError(txtInputY, String::Empty);
		}

	private: System::Void Calculate_Click(System::Object^ sender, System::EventArgs^ e) {
		ClearAll();

		double InputNumberX, InputNumberY;
		bool hasError = false; // Флаг для ошибки

		// Проверка
		bool resultX = Double::TryParse(this->txtInputX->Text, InputNumberX);
		if (!resultX) { // Если не число
			errorProvider1->SetError(txtInputX, "¬ведено не целое число");
			hasError = true; // Установка флага
		}
		else if (InputNumberX < 0) { // Проверка на отрицательное число
			errorProvider1->SetError(txtInputX, "¬ведено отрицательное число");
			hasError = true; // Установка флага
		}

		// Проверяем второе число
		bool resultY = Double::TryParse(this->txtInputY->Text, InputNumberY);
		if (!resultY) { // Если не число
			errorProvider2->SetError(txtInputY, "¬ведено не целое число");
			hasError = true; // // Установка флага
		}
		else if (InputNumberY < 0) { // // Проверка на отрицательное число
			errorProvider2->SetError(txtInputY, "¬ведено отрицательное число");
			hasError = true; // // Установка флага
		}

		// Если есть ошибки, то гг :0
		if (hasError) {
			return;
		}


		// Результат
		double OutputNumber = Simple(InputNumberX, InputNumberY);
		this->txtOutput->Text = System::Convert::ToString(OutputNumber); // Записываем в поле
		
	}


	};
}

