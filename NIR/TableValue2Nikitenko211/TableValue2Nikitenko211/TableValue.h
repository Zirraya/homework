#pragma once

namespace TableValue2Nikitenko211 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для TableValue
	/// </summary>
	public ref class TableValue : public System::Windows::Forms::Form
	{
	public:
		TableValue(void)
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
		~TableValue()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Add;
	protected:
	private: System::Windows::Forms::Button^ Delete;
	private: System::Windows::Forms::Button^ SredneeArifm;
	private: System::Windows::Forms::Button^ NechotElem;



	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ SrResult;
	private: System::Windows::Forms::TextBox^ NomeraResult;
	private: System::Windows::Forms::DataGridView^ grdMassiv;













	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ MassivForAdd;
	private: System::Windows::Forms::ErrorProvider^ errorProvider1;

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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(TableValue::typeid));
			this->Add = (gcnew System::Windows::Forms::Button());
			this->Delete = (gcnew System::Windows::Forms::Button());
			this->SredneeArifm = (gcnew System::Windows::Forms::Button());
			this->NechotElem = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SrResult = (gcnew System::Windows::Forms::TextBox());
			this->NomeraResult = (gcnew System::Windows::Forms::TextBox());
			this->grdMassiv = (gcnew System::Windows::Forms::DataGridView());
			this->MassivForAdd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grdMassiv))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->BeginInit();
			this->SuspendLayout();
			// 
			// Add
			// 
			this->Add->BackColor = System::Drawing::Color::SteelBlue;
			this->Add->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Add->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->Add->Location = System::Drawing::Point(106, 35);
			this->Add->Name = L"Add";
			this->Add->Size = System::Drawing::Size(132, 43);
			this->Add->TabIndex = 0;
			this->Add->Text = L"Добавить";
			this->Add->UseVisualStyleBackColor = false;
			this->Add->Click += gcnew System::EventHandler(this, &TableValue::Add_Click);
			// 
			// Delete
			// 
			this->Delete->BackColor = System::Drawing::Color::SteelBlue;
			this->Delete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Delete->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->Delete->Location = System::Drawing::Point(106, 74);
			this->Delete->Name = L"Delete";
			this->Delete->Size = System::Drawing::Size(132, 47);
			this->Delete->TabIndex = 1;
			this->Delete->Text = L"Уадалить";
			this->Delete->UseVisualStyleBackColor = false;
			this->Delete->Click += gcnew System::EventHandler(this, &TableValue::Delete_Click);
			// 
			// SredneeArifm
			// 
			this->SredneeArifm->BackColor = System::Drawing::Color::SteelBlue;
			this->SredneeArifm->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SredneeArifm->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->SredneeArifm->Location = System::Drawing::Point(417, 230);
			this->SredneeArifm->Name = L"SredneeArifm";
			this->SredneeArifm->Size = System::Drawing::Size(132, 78);
			this->SredneeArifm->TabIndex = 2;
			this->SredneeArifm->Text = L"Среднее арифметическое";
			this->SredneeArifm->UseVisualStyleBackColor = false;
			this->SredneeArifm->Click += gcnew System::EventHandler(this, &TableValue::SredneeArifm_Click);
			// 
			// NechotElem
			// 
			this->NechotElem->BackColor = System::Drawing::Color::SteelBlue;
			this->NechotElem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->NechotElem->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->NechotElem->Location = System::Drawing::Point(417, 365);
			this->NechotElem->Name = L"NechotElem";
			this->NechotElem->Size = System::Drawing::Size(139, 79);
			this->NechotElem->TabIndex = 3;
			this->NechotElem->Text = L"Номера нечетных элементов";
			this->NechotElem->UseVisualStyleBackColor = false;
			this->NechotElem->Click += gcnew System::EventHandler(this, &TableValue::NechotElem_Click);
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Teal;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Location = System::Drawing::Point(359, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(210, 57);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Найти среднее арифметическое четных элементов. ";
			// 
			// SrResult
			// 
			this->SrResult->BackColor = System::Drawing::Color::Ivory;
			this->SrResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SrResult->ForeColor = System::Drawing::Color::SaddleBrown;
			this->SrResult->Location = System::Drawing::Point(436, 314);
			this->SrResult->Multiline = true;
			this->SrResult->Name = L"SrResult";
			this->SrResult->Size = System::Drawing::Size(97, 27);
			this->SrResult->TabIndex = 12;
			// 
			// NomeraResult
			// 
			this->NomeraResult->BackColor = System::Drawing::Color::Ivory;
			this->NomeraResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->NomeraResult->ForeColor = System::Drawing::Color::SaddleBrown;
			this->NomeraResult->Location = System::Drawing::Point(437, 450);
			this->NomeraResult->Multiline = true;
			this->NomeraResult->Name = L"NomeraResult";
			this->NomeraResult->Size = System::Drawing::Size(97, 27);
			this->NomeraResult->TabIndex = 13;
			
			// 
			// grdMassiv
			// 
			this->grdMassiv->AllowUserToAddRows = false;
			this->grdMassiv->AllowUserToDeleteRows = false;
			this->grdMassiv->BackgroundColor = System::Drawing::Color::LightYellow;
			this->grdMassiv->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->grdMassiv->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->MassivForAdd });
			this->grdMassiv->Location = System::Drawing::Point(123, 148);
			this->grdMassiv->Name = L"grdMassiv";
			this->grdMassiv->RowHeadersWidth = 51;
			this->grdMassiv->RowTemplate->Height = 24;
			this->grdMassiv->Size = System::Drawing::Size(152, 330);
			this->grdMassiv->TabIndex = 14;
			// 
			// MassivForAdd
			// 
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::Ivory;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::SaddleBrown;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::Ivory;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::Color::SaddleBrown;
			this->MassivForAdd->DefaultCellStyle = dataGridViewCellStyle1;
			this->MassivForAdd->HeaderText = L"Массив";
			this->MassivForAdd->MinimumWidth = 6;
			this->MassivForAdd->Name = L"MassivForAdd";
			this->MassivForAdd->Width = 125;
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Teal;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(414, 74);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(149, 79);
			this->label1->TabIndex = 15;
			this->label1->Text = L"Вывести номера нечетных максимальных элементов.";
			// 
			// errorProvider1
			// 
			this->errorProvider1->ContainerControl = this;
			// 
			// TableValue
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(572, 490);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->grdMassiv);
			this->Controls->Add(this->NomeraResult);
			this->Controls->Add(this->SrResult);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->NechotElem);
			this->Controls->Add(this->SredneeArifm);
			this->Controls->Add(this->Delete);
			this->Controls->Add(this->Add);
			this->DoubleBuffered = true;
			this->MaximumSize = System::Drawing::Size(590, 537);
			this->MinimumSize = System::Drawing::Size(590, 537);
			this->Name = L"TableValue";
			this->Text = L"Обработка табличных значений";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grdMassiv))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		

		
private: System::Void Add_Click(System::Object^ sender, System::EventArgs^ e) {

	this->grdMassiv->Rows->Add(1);

}

private: System::Void Delete_Click(System::Object^ sender, System::EventArgs^ e) {

	if (!this->grdMassiv->CurrentRow->IsNewRow) {
		int i = this->grdMassiv->CurrentRow->Index;
		this->grdMassiv->Rows->Remove(this->grdMassiv->Rows[i]);

	}

}

private: System::Void SredneeArifm_Click(System::Object^ sender, System::EventArgs^ e) {
	
	double sum = 0; // Переменная для хранения суммы значений
	int AmountOfNumbers = 0; //  счетчик



	// Вычисление суммы, счетчик и нахождения четных элементов
	for (int i = 0; i < this->grdMassiv->Rows->Count; i++) {
		
		double num;
		if (Double::TryParse(grdMassiv->Rows[i]->Cells[0]->Value->ToString(), num)) {
			if (static_cast<int>(num) % 2 == 0) { // Нахождение четных элементов
				sum += num; // Суммирование элементов
				AmountOfNumbers++; // Счетчик
			}
			
		}	
	}
	//

	// Вычисление среднего арифметического, 
	if (AmountOfNumbers > 0) {
		double average = sum / AmountOfNumbers;
		this->SrResult->Text = System::Convert::ToString(average); // Отображение результата
	}
	else {
		this->SrResult->Text = "0"; // Если будет все плохо, то выведет ноль (по сути рудимент для отлова ошибок в коде) :0
	}
	//
}


private: System::Void NechotElem_Click(System::Object^ sender, System::EventArgs^ e) {


	double summ = 0;
	int AmountofNumberss = 0;



	// Вычисление суммы, счетчик и нахождения четных элементов
	for (int i = 0; i < this->grdMassiv->Rows->Count; i++) {

		double numm;
		if (Double::TryParse(grdMassiv->Rows[i]->Cells[0]->Value->ToString(), numm)) {
			if (static_cast<int>(numm) % 2 != 0) { // Нахождение нечетных элементов
				summ += numm; // Суммирование элементов
				AmountofNumberss++; // Счетчик

			}

		}
	}
	//

	// Нахождение индексов максимальных нечетных элементов, 
	if (AmountofNumberss > 0) {
		double averagge = summ / AmountofNumberss;
		this->NomeraResult->Text = System::Convert::ToString(summ); // Отображение результата
	}
	else {
		this->NomeraResult->Text = "0"; // Если будет все плохо, то выведет ноль (по сути рудимент для отлова ошибок в коде) :0
	}
	//

}


};
}
