#pragma once

namespace FactorialNikitenko {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
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
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnCalculate;
	protected:
	private: System::Windows::Forms::Label^ lblInput;
	private: System::Windows::Forms::Label^ lblOutput;
	private: System::Windows::Forms::TextBox^ txtInput;
	private: System::Windows::Forms::TextBox^ txtOutput;
	private: System::Windows::Forms::ErrorProvider^ errorProvider1;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->btnCalculate = (gcnew System::Windows::Forms::Button());
			this->lblInput = (gcnew System::Windows::Forms::Label());
			this->lblOutput = (gcnew System::Windows::Forms::Label());
			this->txtInput = (gcnew System::Windows::Forms::TextBox());
			this->txtOutput = (gcnew System::Windows::Forms::TextBox());
			this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->BeginInit();
			this->SuspendLayout();
			// 
			// btnCalculate
			// 
			this->btnCalculate->Location = System::Drawing::Point(170, 391);
			this->btnCalculate->Name = L"btnCalculate";
			this->btnCalculate->Size = System::Drawing::Size(158, 54);
			this->btnCalculate->TabIndex = 0;
			this->btnCalculate->Text = L"¬ычислить";
			this->btnCalculate->UseVisualStyleBackColor = true;
			this->btnCalculate->Click += gcnew System::EventHandler(this, &MyForm::btnCalculate_Click);
			// 
			// lblInput
			// 
			this->lblInput->AutoSize = true;
			this->lblInput->Location = System::Drawing::Point(28, 186);
			this->lblInput->Name = L"lblInput";
			this->lblInput->Size = System::Drawing::Size(30, 16);
			this->lblInput->TabIndex = 1;
			this->lblInput->Text = L" N =";
			// 
			// lblOutput
			// 
			this->lblOutput->AutoSize = true;
			this->lblOutput->Location = System::Drawing::Point(28, 225);
			this->lblOutput->Name = L"lblOutput";
			this->lblOutput->Size = System::Drawing::Size(30, 16);
			this->lblOutput->TabIndex = 2;
			this->lblOutput->Text = L"N! =";
			// 
			// txtInput
			// 
			this->txtInput->Location = System::Drawing::Point(76, 183);
			this->txtInput->Name = L"txtInput";
			this->txtInput->Size = System::Drawing::Size(155, 22);
			this->txtInput->TabIndex = 3;
			// 
			// txtOutput
			// 
			this->txtOutput->Location = System::Drawing::Point(76, 222);
			this->txtOutput->Name = L"txtOutput";
			this->txtOutput->ReadOnly = true;
			this->txtOutput->Size = System::Drawing::Size(155, 22);
			this->txtOutput->TabIndex = 4;
			// 
			// errorProvider1
			// 
			this->errorProvider1->ContainerControl = this;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(465, 474);
			this->Controls->Add(this->txtOutput);
			this->Controls->Add(this->txtInput);
			this->Controls->Add(this->lblOutput);
			this->Controls->Add(this->lblInput);
			this->Controls->Add(this->btnCalculate);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Factorial";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		 void ClearAll() {//очистка полей
			 this->txtOutput->Text = "";
			 errorProvider1->SetError(txtInput, String::Empty);	
		}

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
};
}
