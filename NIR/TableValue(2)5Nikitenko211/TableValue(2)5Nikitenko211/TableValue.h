#pragma once

namespace TableValue25Nikitenko211 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� TableValue
	/// </summary>
	public ref class TableValue : public System::Windows::Forms::Form
	{
	public:
		TableValue(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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
	private: System::Windows::Forms::ErrorProvider^ errorProvider1;
	private: System::ComponentModel::IContainer^ components;






	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
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
			this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DataMassivInPut))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DataMassivOutPut))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->BeginInit();
			this->SuspendLayout();
			// 
			// DataMassivInPut
			// 
			this->DataMassivInPut->AllowUserToAddRows = false;
			this->DataMassivInPut->AllowUserToDeleteRows = false;
			this->DataMassivInPut->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DataMassivInPut->Location = System::Drawing::Point(24, 48);
			this->DataMassivInPut->Name = L"DataMassivInPut";
			this->DataMassivInPut->RowHeadersWidth = 51;
			this->DataMassivInPut->RowTemplate->Height = 24;
			this->DataMassivInPut->Size = System::Drawing::Size(328, 487);
			this->DataMassivInPut->TabIndex = 0;
			// 
			// DataMassivOutPut
			// 
			this->DataMassivOutPut->AllowUserToAddRows = false;
			this->DataMassivOutPut->AllowUserToDeleteRows = false;
			this->DataMassivOutPut->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DataMassivOutPut->Location = System::Drawing::Point(698, 48);
			this->DataMassivOutPut->Name = L"DataMassivOutPut";
			this->DataMassivOutPut->RowHeadersWidth = 51;
			this->DataMassivOutPut->RowTemplate->Height = 24;
			this->DataMassivOutPut->Size = System::Drawing::Size(328, 487);
			this->DataMassivOutPut->TabIndex = 1;
			// 
			// AddString
			// 
			this->AddString->Location = System::Drawing::Point(450, 75);
			this->AddString->Name = L"AddString";
			this->AddString->Size = System::Drawing::Size(138, 66);
			this->AddString->TabIndex = 2;
			this->AddString->Text = L"�������� ������";
			this->AddString->UseVisualStyleBackColor = true;
			this->AddString->Click += gcnew System::EventHandler(this, &TableValue::AddString_Click);
			// 
			// DeleteString
			// 
			this->DeleteString->Location = System::Drawing::Point(452, 147);
			this->DeleteString->Name = L"DeleteString";
			this->DeleteString->Size = System::Drawing::Size(138, 66);
			this->DeleteString->TabIndex = 3;
			this->DeleteString->Text = L"������� ������";
			this->DeleteString->UseVisualStyleBackColor = true;
			this->DeleteString->Click += gcnew System::EventHandler(this, &TableValue::DeleteString_Click);
			// 
			// AddColumn
			// 
			this->AddColumn->Location = System::Drawing::Point(450, 219);
			this->AddColumn->Name = L"AddColumn";
			this->AddColumn->Size = System::Drawing::Size(138, 66);
			this->AddColumn->TabIndex = 4;
			this->AddColumn->Text = L"�������� �������";
			this->AddColumn->UseVisualStyleBackColor = true;
			this->AddColumn->Click += gcnew System::EventHandler(this, &TableValue::AddColumn_Click);
			// 
			// DeleteColumn
			// 
			this->DeleteColumn->Location = System::Drawing::Point(450, 291);
			this->DeleteColumn->Name = L"DeleteColumn";
			this->DeleteColumn->Size = System::Drawing::Size(138, 66);
			this->DeleteColumn->TabIndex = 5;
			this->DeleteColumn->Text = L"������� �������";
			this->DeleteColumn->UseVisualStyleBackColor = true;
			this->DeleteColumn->Click += gcnew System::EventHandler(this, &TableValue::DeleteColumn_Click);
			// 
			// Execute
			// 
			this->Execute->Location = System::Drawing::Point(410, 441);
			this->Execute->Name = L"Execute";
			this->Execute->Size = System::Drawing::Size(217, 94);
			this->Execute->TabIndex = 6;
			this->Execute->Text = L"���������";
			this->Execute->UseVisualStyleBackColor = true;
			this->Execute->Click += gcnew System::EventHandler(this, &TableValue::Execute_Click);
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
			this->ClientSize = System::Drawing::Size(1042, 547);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

// ���������� �����
private: System::Void AddString_Click(System::Object^ sender, System::EventArgs^ e) {

	// �������� �� ������� �������� 
	if (this->DataMassivInPut->Columns->Count == 0) {
		errorProvider1->SetError(DataMassivInPut, "������� ������ ���� ��������� ����� ����������� �����.");
		return; // ����� �� ������, ���� ��� ��������
	}

	this->DataMassivInPut->Rows->Add(1);
	this->DataMassivOutPut->Rows->Add(1);
	if (this->DataMassivInPut->Rows->Count > 0 && this->DataMassivOutPut->Rows->Count > 0) {
		errorProvider1->SetError(DataMassivInPut, ""); 
	}

}
// �������� �����
private: System::Void DeleteString_Click(System::Object^ sender, System::EventArgs^ e) {


	// �������� �� ������� �����
	if (this->DataMassivInPut->Rows->Count == 0) {
		errorProvider1->SetError(DataMassivInPut, " ����� ������ ���, ��� ���� ��� ������� ����� "); //  ��������� ������, ���� ��� �����
		return; //  ����� �� ������
	}

	// ��������
	if (!this->DataMassivInPut->CurrentRow->IsNewRow && !this->DataMassivOutPut->CurrentRow->IsNewRow) {
		int i = this->DataMassivInPut->CurrentRow->Index;
		this->DataMassivInPut->Rows->Remove(this->DataMassivInPut->Rows[i]);

		int o = this->DataMassivOutPut->CurrentRow->Index;
		this->DataMassivOutPut->Rows->Remove(this->DataMassivOutPut->Rows[o]);
	}

}
// ���������� ��������
private: System::Void AddColumn_Click(System::Object^ sender, System::EventArgs^ e) {

	this->DataMassivInPut->Columns->Add("COLUMN"," ");
	this->DataMassivOutPut->Columns->Add("COLUMN", " ");
	if (this->DataMassivInPut->Columns->Count > 0 && this->DataMassivOutPut->Columns->Count > 0) {
		errorProvider1->SetError(DataMassivInPut, ""); // 
	}
	for (int i = 0; i < this->DataMassivInPut->Columns->Count; i++) {
		this->DataMassivInPut->Columns[i]->Width = System::Convert::ToInt32(this->DataMassivInPut->Width / (1.25 * this->DataMassivInPut->Columns->Count));
	}
	for (int i = 0; i < this->DataMassivOutPut->Columns->Count; i++) {
		this->DataMassivOutPut->Columns[i]->Width = System::Convert::ToInt32(this->DataMassivOutPut->Width / (1.25 * this->DataMassivOutPut->Columns->Count));
	}
}

// �������� ��������
private: System::Void DeleteColumn_Click(System::Object^ sender, System::EventArgs^ e) {

	// �������� �� ������� �����
	if (this->DataMassivInPut->Columns->Count == 0) {
		errorProvider1->SetError(DataMassivInPut, " ������� ���, ��� ���� ��� ����� ������� ����� "); //  ��������� ������, ���� ��� �����
		return; //  ����� �� ������
	}

	
	// ���������, ���� �� ������� � DataGridView
	if (this->DataMassivInPut->Columns->Count > 0) {
		// �������� ������ ���������� ������� (��� ������ ������� ������ ������)
		int i = this->DataMassivInPut->Columns->Count - 1; // ������ ���������� �������
		int o = this->DataMassivOutPut->Columns->Count - 1;

		// ������� ������� �� �������
		this->DataMassivInPut->Columns->RemoveAt(i);
		this->DataMassivOutPut->Columns->RemoveAt(o);
	}


}
private: System::Void Execute_Click(System::Object^ sender, System::EventArgs^ e) {



	// ����������� ������ �� ������ DataGridView ����� ������� ��������
	DataMassivOutPut->Columns->Clear();
	for (int i = 0; i < DataMassivInPut->ColumnCount; i++) {
		DataMassivOutPut->Columns->Add("Column" + i, "������� " + (i + 1));
	}

	for (int row = 0; row < DataMassivInPut->RowCount; row++) {
		array<Object^>^ rowData = gcnew array<Object^>(DataMassivInPut->ColumnCount);
		for (int col = 0; col < DataMassivInPut->ColumnCount; col++) {
			rowData[col] = DataMassivInPut->Rows[row]->Cells[col]->Value;
		}
		DataMassivOutPut->Rows->Add(rowData);
	}


	int minRowIndex = -1, maxRowIndex = -1;
	int minColIndex = -1, maxColIndex = -1;

	// ����� ������� ������������ � ������������� �������� 
	for (int col = 0; col < DataMassivInPut->ColumnCount; col++) {
		for (int row = 0; row < DataMassivInPut->RowCount; row++) {
			if (DataMassivInPut->Rows[row]->Cells[col]->Value != nullptr &&
				DataMassivInPut->Rows[row]->Cells[col]->Value->ToString() != "") {

				int value;
				if (Int32::TryParse(DataMassivInPut->Rows[row]->Cells[col]->Value->ToString(), value)) {
					// ����� ������������ �������� 
					if (minRowIndex == -1 || value < Int32::Parse(DataMassivInPut->Rows[minRowIndex]->Cells[minColIndex]->Value->ToString())) {
						minRowIndex = row;
						minColIndex = col;
					}

					// ����� ������������� �������� 
					if (maxRowIndex == -1 || value > Int32::Parse(DataMassivInPut->Rows[maxRowIndex]->Cells[maxColIndex]->Value->ToString())) {
						maxRowIndex = row;
						maxColIndex = col;
					}
				}
			}
		}
	}

	// ��������, ��� ����������� � ������������ �������� ������� 
	if (minRowIndex != -1 && maxRowIndex != -1 && minColIndex != maxColIndex) {
		// ����� ��������� 
		for (int row = 0; row < DataMassivInPut->RowCount; row++) {
			auto tempValue = DataMassivInPut->Rows[row]->Cells[minColIndex]->Value;
			DataMassivInPut->Rows[row]->Cells[minColIndex]->Value = DataMassivInPut->Rows[row]->Cells[maxColIndex]->Value;
			DataMassivInPut->Rows[row]->Cells[maxColIndex]->Value = tempValue;
		}
	}

	// ����������� ���������� �� ������ DataGridView 
	DataMassivOutPut->Columns->Clear();
	for (int i = 0; i < DataMassivInPut->ColumnCount; i++) {
		DataMassivOutPut->Columns->Add("Column" + i, "������� " + (i + 1));
	}

	for (int row = 0; row < DataMassivInPut->RowCount; row++) {
		array<Object^>^ rowData = gcnew array<Object^>(DataMassivInPut->ColumnCount);
		for (int col = 0; col < DataMassivInPut->ColumnCount; col++) {
			rowData[col] = DataMassivInPut->Rows[row]->Cells[col]->Value;
		}
		DataMassivOutPut->Rows->Add(rowData);
	}

}

};







}