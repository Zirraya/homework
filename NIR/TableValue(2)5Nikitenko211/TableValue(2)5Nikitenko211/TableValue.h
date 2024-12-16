#pragma once

namespace TableValue25Nikitenko211 {
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
	private: System::Windows::Forms::DataGridView^ DataMassivInPut;
	protected:

	private: System::Windows::Forms::DataGridView^ DataMassivOutPut;
	protected:




	private: System::Windows::Forms::Button^ AddString;
	private: System::Windows::Forms::Button^ DeleteString;
	private: System::Windows::Forms::Button^ AddColumn;
	private: System::Windows::Forms::Button^ DeleteColumn;
	private: System::Windows::Forms::Button^ Execute;

	private: System::Windows::Forms::TextBox^ Task;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(TableValue::typeid));
			this->DataMassivInPut = (gcnew System::Windows::Forms::DataGridView());
			this->DataMassivOutPut = (gcnew System::Windows::Forms::DataGridView());
			this->AddString = (gcnew System::Windows::Forms::Button());
			this->DeleteString = (gcnew System::Windows::Forms::Button());
			this->AddColumn = (gcnew System::Windows::Forms::Button());
			this->DeleteColumn = (gcnew System::Windows::Forms::Button());
			this->Execute = (gcnew System::Windows::Forms::Button());
			this->Task = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DataMassivInPut))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DataMassivOutPut))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->BeginInit();
			this->SuspendLayout();
			// 
			// DataMassivInPut
			// 
			this->DataMassivInPut->AllowUserToAddRows = false;
			this->DataMassivInPut->AllowUserToDeleteRows = false;
			this->DataMassivInPut->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DataMassivInPut->Location = System::Drawing::Point(12, 75);
			this->DataMassivInPut->Name = L"DataMassivInPut";
			this->DataMassivInPut->RowHeadersWidth = 51;
			this->DataMassivInPut->RowTemplate->Height = 24;
			this->DataMassivInPut->Size = System::Drawing::Size(332, 376);
			this->DataMassivInPut->TabIndex = 0;
			// 
			// DataMassivOutPut
			// 
			this->DataMassivOutPut->AllowUserToAddRows = false;
			this->DataMassivOutPut->AllowUserToDeleteRows = false;
			this->DataMassivOutPut->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DataMassivOutPut->Location = System::Drawing::Point(350, 75);
			this->DataMassivOutPut->Name = L"DataMassivOutPut";
			this->DataMassivOutPut->ReadOnly = true;
			this->DataMassivOutPut->RowHeadersWidth = 51;
			this->DataMassivOutPut->RowTemplate->Height = 24;
			this->DataMassivOutPut->Size = System::Drawing::Size(332, 376);
			this->DataMassivOutPut->TabIndex = 1;
			// 
			// AddString
			// 
			this->AddString->Location = System::Drawing::Point(12, 469);
			this->AddString->Name = L"AddString";
			this->AddString->Size = System::Drawing::Size(138, 66);
			this->AddString->TabIndex = 2;
			this->AddString->Text = L"Добавить строку";
			this->AddString->UseVisualStyleBackColor = true;
			this->AddString->Click += gcnew System::EventHandler(this, &TableValue::AddString_Click);
			// 
			// DeleteString
			// 
			this->DeleteString->Location = System::Drawing::Point(165, 469);
			this->DeleteString->Name = L"DeleteString";
			this->DeleteString->Size = System::Drawing::Size(138, 66);
			this->DeleteString->TabIndex = 3;
			this->DeleteString->Text = L"Удалить строку";
			this->DeleteString->UseVisualStyleBackColor = true;
			this->DeleteString->Click += gcnew System::EventHandler(this, &TableValue::DeleteString_Click);
			// 
			// AddColumn
			// 
			this->AddColumn->Location = System::Drawing::Point(324, 469);
			this->AddColumn->Name = L"AddColumn";
			this->AddColumn->Size = System::Drawing::Size(138, 66);
			this->AddColumn->TabIndex = 4;
			this->AddColumn->Text = L"Добавить столбец";
			this->AddColumn->UseVisualStyleBackColor = true;
			this->AddColumn->Click += gcnew System::EventHandler(this, &TableValue::AddColumn_Click);
			// 
			// DeleteColumn
			// 
			this->DeleteColumn->Location = System::Drawing::Point(478, 469);
			this->DeleteColumn->Name = L"DeleteColumn";
			this->DeleteColumn->Size = System::Drawing::Size(138, 66);
			this->DeleteColumn->TabIndex = 5;
			this->DeleteColumn->Text = L"Удалить столбец";
			this->DeleteColumn->UseVisualStyleBackColor = true;
			this->DeleteColumn->Click += gcnew System::EventHandler(this, &TableValue::DeleteColumn_Click);
			// 
			// Execute
			// 
			this->Execute->Location = System::Drawing::Point(892, 470);
			this->Execute->Name = L"Execute";
			this->Execute->Size = System::Drawing::Size(138, 65);
			this->Execute->TabIndex = 6;
			this->Execute->Text = L"Выполнить";
			this->Execute->UseVisualStyleBackColor = true;
			this->Execute->Click += gcnew System::EventHandler(this, &TableValue::Execute_Click);
			// 
			// Task
			// 
			this->Task->Location = System::Drawing::Point(12, 12);
			this->Task->Multiline = true;
			this->Task->Name = L"Task";
			this->Task->Size = System::Drawing::Size(710, 42);
			this->Task->TabIndex = 7;
			this->Task->Text = L"Найти первый минимальный и первый максимальный элементы массива. Поиск производит"
				L"ь построчно. Поменять местами столбцы, содержащие эти элементы.";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(791, 231);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(239, 220);
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			// 
			// errorProvider1
			// 
			this->errorProvider1->ContainerControl = this;
			// 
			// TableValue
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(1042, 547);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->Task);
			this->Controls->Add(this->Execute);
			this->Controls->Add(this->DeleteColumn);
			this->Controls->Add(this->AddColumn);
			this->Controls->Add(this->DeleteString);
			this->Controls->Add(this->AddString);
			this->Controls->Add(this->DataMassivOutPut);
			this->Controls->Add(this->DataMassivInPut);
			this->DoubleBuffered = true;
			this->MaximumSize = System::Drawing::Size(1060, 594);
			this->MinimumSize = System::Drawing::Size(1060, 594);
			this->Name = L"TableValue";
			this->Text = L"TableValue";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DataMassivInPut))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DataMassivOutPut))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

// Добавление строк
private: System::Void AddString_Click(System::Object^ sender, System::EventArgs^ e) {

	// Проверка на наличие столбцов 
	if (this->DataMassivInPut->Columns->Count == 0) {
		errorProvider1->SetError(DataMassivInPut, "Столбцы должны быть добавлены перед добавлением строк.");
		return; 
	}

	this->DataMassivInPut->Rows->Add(1);
	this->DataMassivOutPut->Rows->Add(1);
	if (this->DataMassivInPut->Rows->Count > 0 && this->DataMassivOutPut->Rows->Count > 0) {
		errorProvider1->SetError(DataMassivInPut, ""); 
	}

}
// Удаление строк
private: System::Void DeleteString_Click(System::Object^ sender, System::EventArgs^ e) {


	// Проверка на наличие строк
	if (this->DataMassivInPut->Rows->Count == 0) {
		errorProvider1->SetError(DataMassivInPut, " Что бы удалить строку, нужно в начале добавить ее "); //  Установка ошибки, если нет строк
		return; 
	}

	// Удаление
	if (!this->DataMassivInPut->CurrentRow->IsNewRow && !this->DataMassivOutPut->CurrentRow->IsNewRow) {
		int i = this->DataMassivInPut->CurrentRow->Index;
		this->DataMassivInPut->Rows->Remove(this->DataMassivInPut->Rows[i]);

		int o = this->DataMassivOutPut->CurrentRow->Index;
		this->DataMassivOutPut->Rows->Remove(this->DataMassivOutPut->Rows[o]);
	}

}
// Добавление стоблцов
private: System::Void AddColumn_Click(System::Object^ sender, System::EventArgs^ e) {

	this->DataMassivInPut->Columns->Add("COLUMN"," ");
	this->DataMassivOutPut->Columns->Add("COLUMN", " ");
	if (this->DataMassivInPut->Columns->Count > 0 && this->DataMassivOutPut->Columns->Count > 0) {
		errorProvider1->SetError(DataMassivInPut, ""); 
	}
	for (int i = 0; i < this->DataMassivInPut->Columns->Count; i++) {
		this->DataMassivInPut->Columns[i]->Width = System::Convert::ToInt32(this->DataMassivInPut->Width / (1.25 * this->DataMassivInPut->Columns->Count));
	}
	for (int i = 0; i < this->DataMassivOutPut->Columns->Count; i++) {
		this->DataMassivOutPut->Columns[i]->Width = System::Convert::ToInt32(this->DataMassivOutPut->Width / (1.25 * this->DataMassivOutPut->Columns->Count));
	}
}

// Уадление слолбцов
private: System::Void DeleteColumn_Click(System::Object^ sender, System::EventArgs^ e) {

	// Проверка на наличие строк
	if (this->DataMassivInPut->Columns->Count == 0) {
		errorProvider1->SetError(DataMassivInPut, " Что бы удалить столбец, нужно в начале добавить его "); //  Установка ошибки, если нет строк
		return; //  Выход из метода
	}

	
	// Проверяем, есть ли столбцы в DataGridView
	if (this->DataMassivInPut->Columns->Count > 0) {
		// Получение индекса последнего столбца 
		int i = this->DataMassivInPut->Columns->Count - 1; // Индекс последнего столбца
		int o = this->DataMassivOutPut->Columns->Count - 1;

		// Удалаление
		this->DataMassivInPut->Columns->RemoveAt(i);
		this->DataMassivOutPut->Columns->RemoveAt(o);
	}


}
	private: System::Void Execute_Click(System::Object^ sender, System::EventArgs^ e) {

		// Обработка неккоректных данных в таблице
		if (this->DataMassivInPut->RowCount == 0) {
			errorProvider1->SetError(DataMassivInPut, " Пустая таблица. Нужно создать стоблцы и строки ");
			return;
		}
		int number;
		bool flag = true;

		// Определение минимальные и максимальные значения для int, да весьма грубо но работает
		const int MinV = -2147483648;
		const int MaxV = 2147483647;
		//

		for (int i = 0; i < DataMassivInPut->RowCount; i++) {
			for (int j = 0; j < DataMassivInPut->ColumnCount; j++) {
				// Попытка преобразовать значение в строке в число
				bool res = Int32::TryParse(System::Convert::ToString(this->DataMassivInPut->Rows[i]->Cells[j]->Value), number);

				// Если преобразование не удалось или число выходит за пределы int
				if (!res || number < MinV || number > MaxV) {
					errorProvider1->SetError(DataMassivInPut, "В таблице есть некорректные значения! Введите целые числа в диапазоне int, чтобы продолжить работу.");
					this->DataMassivInPut->Rows[i]->Cells[j]->Value = "";
					flag = false;
				}
			}
		}

		if (flag == false) {
			return;
		}
		//

		int minRowIndex = -1, maxRowIndex = -1;
		int minColIndex = -1, maxColIndex = -1;

		int minValue = Int32::MaxValue; // Инициализация для поиска минимума
		int maxValue = Int32::MinValue; // Инициализация для поиска максимума

		// Поиск первого минимального и максимального элемента  
		for (int col = 0; col < DataMassivInPut->ColumnCount; col++) {
			for (int row = 0; row < DataMassivInPut->RowCount; row++) {
				if (DataMassivInPut->Rows[row]->Cells[col]->Value != nullptr &&
					DataMassivInPut->Rows[row]->Cells[col]->Value->ToString() != "") {

					int value;
					if (Int32::TryParse(DataMassivInPut->Rows[row]->Cells[col]->Value->ToString(), value)) {
						// Поиск минимального элемента  
						if (value < minValue) {
							minValue = value;
							minRowIndex = row;
							minColIndex = col;
						}
						//

						// Поиск максимального элемента  
						if (value > maxValue) {
							maxValue = value;
							maxRowIndex = row;
							maxColIndex = col;
						}
						//
					}
				}
			}
		}
		//

		// Копирование данных из DataMassivInPut в DataMassivOutPut
		DataMassivOutPut->Columns->Clear();
		for (int i = 0; i < DataMassivInPut->ColumnCount; i++) {
			DataMassivOutPut->Columns->Add("Column" + i, "" + (i + 1));
		}

		for (int row = 0; row < DataMassivInPut->RowCount; row++) {
			array<Object^>^ rowData = gcnew array<Object^>(DataMassivInPut->ColumnCount);
			for (int col = 0; col < DataMassivInPut->ColumnCount; col++) {
				rowData[col] = DataMassivInPut->Rows[row]->Cells[col]->Value;
			}
			DataMassivOutPut->Rows->Add(rowData);
		}
		//

		// Поиск первого минимального и максимального элементов в DataMassivOutPut
		for (int col = 0; col < DataMassivOutPut->ColumnCount; col++) {
			for (int row = 0; row < DataMassivOutPut->RowCount; row++) {
				Object^ currentValue = DataMassivOutPut->Rows[row]->Cells[col]->Value;

				Object^ minValue = DataMassivOutPut->Rows[0]->Cells[0]->Value;
				Object^ maxValue = DataMassivOutPut->Rows[0]->Cells[0]->Value;

				for (int col = 0; col < DataMassivOutPut->ColumnCount; col++) {
					for (int row = 0; row < DataMassivOutPut->RowCount; row++) {
						Object^ currentValue = DataMassivOutPut->Rows[row]->Cells[col]->Value;

						// Проверка на минимальное значение
						if (currentValue != nullptr && Convert::ToDouble(currentValue) < Convert::ToDouble(minValue)) {
							minValue = currentValue;
							minRowIndex = row;
							minColIndex = col;
						}
						//

						// Проверка на максимальное значение
						if (currentValue != nullptr && Convert::ToDouble(currentValue) > Convert::ToDouble(maxValue)) {
							maxValue = currentValue;
							maxRowIndex = row;
							maxColIndex = col;
						}
						//
					}
				}
			}
		}
		//

		// Проверка, что минимальный и максимальный элементы найдены и что они находятся в разных столбцах
		if (minRowIndex != -1 && maxRowIndex != -1 && minColIndex != maxColIndex) {
			// Обмен значениями в найденных столбцах
			for (int row = 0; row < DataMassivOutPut->RowCount; row++) {
				auto tempValue = DataMassivOutPut->Rows[row]->Cells[minColIndex]->Value;
				DataMassivOutPut->Rows[row]->Cells[minColIndex]->Value = DataMassivOutPut->Rows[row]->Cells[maxColIndex]->Value;
				DataMassivOutPut->Rows[row]->Cells[maxColIndex]->Value = tempValue;
			}
		}
		//
	}
		
};

}
