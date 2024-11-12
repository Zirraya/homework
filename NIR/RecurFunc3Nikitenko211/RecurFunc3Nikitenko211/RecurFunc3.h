#pragma once

namespace RecurFunc3Nikitenko211 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для RecurFunc3
	/// </summary>
	public ref class RecurFunc3 : public System::Windows::Forms::Form
	{
	public:
		RecurFunc3(void)
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
		~RecurFunc3()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ ButtonResult;
	protected:

	private: System::Windows::Forms::Label^ N;
	private: System::Windows::Forms::TextBox^ InputForN;
	private: System::Windows::Forms::TextBox^ OutPutForN;
	private: System::Windows::Forms::ErrorProvider^ errorProvider1;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RecurFunc3::typeid));
			this->ButtonResult = (gcnew System::Windows::Forms::Button());
			this->N = (gcnew System::Windows::Forms::Label());
			this->InputForN = (gcnew System::Windows::Forms::TextBox());
			this->OutPutForN = (gcnew System::Windows::Forms::TextBox());
			this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->BeginInit();
			this->SuspendLayout();
			// 
			// ButtonResult
			// 
			this->ButtonResult->Location = System::Drawing::Point(210, 420);
			this->ButtonResult->Name = L"ButtonResult";
			this->ButtonResult->Size = System::Drawing::Size(125, 50);
			this->ButtonResult->TabIndex = 0;
			this->ButtonResult->Text = L"Вычислить";
			this->ButtonResult->UseVisualStyleBackColor = true;
			this->ButtonResult->Click += gcnew System::EventHandler(this, &RecurFunc3::ButtonResult_Click);
			// 
			// N
			// 
			this->N->AutoSize = true;
			this->N->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->N->Location = System::Drawing::Point(147, 234);
			this->N->Name = L"N";
			this->N->Size = System::Drawing::Size(45, 42);
			this->N->TabIndex = 1;
			this->N->Text = L"N";
			// 
			// InputForN
			// 
			this->InputForN->Location = System::Drawing::Point(210, 234);
			this->InputForN->Multiline = true;
			this->InputForN->Name = L"InputForN";
			this->InputForN->Size = System::Drawing::Size(144, 46);
			this->InputForN->TabIndex = 2;
			// 
			// OutPutForN
			// 
			this->OutPutForN->Location = System::Drawing::Point(83, 286);
			this->OutPutForN->Multiline = true;
			this->OutPutForN->Name = L"OutPutForN";
			this->OutPutForN->ReadOnly = true;
			this->OutPutForN->Size = System::Drawing::Size(406, 128);
			this->OutPutForN->TabIndex = 3;
			// 
			// errorProvider1
			// 
			this->errorProvider1->ContainerControl = this;
			// 
			// RecurFunc3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(561, 554);
			this->Controls->Add(this->OutPutForN);
			this->Controls->Add(this->InputForN);
			this->Controls->Add(this->N);
			this->Controls->Add(this->ButtonResult);
			this->DoubleBuffered = true;
			this->MaximumSize = System::Drawing::Size(579, 601);
			this->MinimumSize = System::Drawing::Size(579, 601);
			this->Name = L"RecurFunc3";
			this->Text = L"RecurFunc3";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void ClearAll() { //очистка полей
			this->OutPutForN->Text = "";
			errorProvider1->SetError(InputForN, String::Empty);
		}
	private: System::Void ButtonResult_Click(System::Object^ sender, System::EventArgs^ e) {
		ClearAll();
		long long InputNumber;
		bool result = Int64::TryParse(this->InputForN->Text, InputNumber); //перевод строку из TextBox в число

		if (!result) { // Введено не число 
			errorProvider1->SetError(InputForN, "Введено не целое число");
			return; // Выход из функции, чтобы избежать дальнейших проверок
		}

		if (InputNumber < 0) { // Проверка на отрицательное число
			errorProvider1->SetError(InputForN, "Введено отрицательное число");
			return; // Выход из функции
		}

		if (InputNumber == 0) { // Проверка на отрицательное число
			errorProvider1->SetError(InputForN, "Введен ноль");
			return; // Выходим из функции
		}

		if (InputNumber >= 127) {
			errorProvider1->SetError(InputForN, " Переполнение стека");
			return;

		}
	
		long long OutputNumber = Recur(InputNumber);

		// Запись в поле
		this->OutPutForN->Text = System::Convert::ToString(OutputNumber);
	}
		
};
}
