#pragma once

namespace Filevar3Nikitenko {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для PlaneForm
	/// </summary>


	struct date
	{
		int dd, mm, yy;
	};
	date StringToDate(String^ str) {
		date data;
		if (str->Length != 10) {
			data.dd = 1;
			data.mm = 1;
			data.yy = 1970;
			return data;
		}
		data.dd = System::Convert::ToInt32(str->Substring(0, 2));
		data.mm = System::Convert::ToInt32(str->Substring(3, 2));
		data.yy = System::Convert::ToInt32(str->Substring(6, 4));
		if (data.dd < 1 || data.dd>31 || data.mm < 1 || data.mm>12 || data.yy < 2000 || data.yy >= 2100) {
			data.dd = 1;
			data.mm = 1;
			data.yy = 1970;
			return data;
		}
		return data;
	}
	String^ DateToString(date data) {
		String^ str = "";
		String^ dd_s = Convert::ToString(data.dd);
		if (data.dd < 10) dd_s = "0" + Convert::ToString(data.dd);
		String^ mm_s = Convert::ToString(data.mm);
		if (data.mm < 10) mm_s = "0" + Convert::ToString(data.mm);

		return str + dd_s + "." + mm_s + "." + Convert::ToString(data.yy);
	}


	public ref class PlaneForm : public System::Windows::Forms::Form
	{
	public:
		PlaneForm(void)
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
		~PlaneForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ Table1;
















	private: System::Windows::Forms::Button^ Add;
	private: System::Windows::Forms::Button^ Delete;
	private: System::Windows::Forms::Button^ OpenFile;
	private: System::Windows::Forms::Button^ SaveInFile;
	private: System::Windows::Forms::Button^ SaveInforPass;






	private: System::Windows::Forms::Button^ ChoiseRaceBut;

	private: System::Windows::Forms::TextBox^ ChoiceRace;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ErrorProvider^ errorProvider1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog2;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::ErrorProvider^ errorProvider2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ LastNamee;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ FirstName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Otchestvo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Hotell;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Live;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DateArrave;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DateMoveOut;
	private: System::Windows::Forms::DataGridView^ Table2;


	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn7;





























	private: System::ComponentModel::IContainer^ components;

	protected:


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
			this->Table1 = (gcnew System::Windows::Forms::DataGridView());
			this->LastNamee = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->FirstName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Otchestvo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Hotell = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Live = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DateArrave = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DateMoveOut = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Add = (gcnew System::Windows::Forms::Button());
			this->Delete = (gcnew System::Windows::Forms::Button());
			this->OpenFile = (gcnew System::Windows::Forms::Button());
			this->SaveInFile = (gcnew System::Windows::Forms::Button());
			this->SaveInforPass = (gcnew System::Windows::Forms::Button());
			this->ChoiseRaceBut = (gcnew System::Windows::Forms::Button());
			this->ChoiceRace = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->saveFileDialog2 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->errorProvider2 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->Table2 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table2))->BeginInit();
			this->SuspendLayout();
			// 
			// Table1
			// 
			this->Table1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Table1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->LastNamee, this->FirstName,
					this->Otchestvo, this->Hotell, this->Live, this->DateArrave, this->DateMoveOut
			});
			this->Table1->Location = System::Drawing::Point(34, 44);
			this->Table1->Name = L"Table1";
			this->Table1->RowHeadersWidth = 51;
			this->Table1->RowTemplate->Height = 24;
			this->Table1->Size = System::Drawing::Size(942, 184);
			this->Table1->TabIndex = 0;
			// 
			// LastNamee
			// 
			this->LastNamee->HeaderText = L"Фамилия";
			this->LastNamee->MinimumWidth = 6;
			this->LastNamee->Name = L"LastNamee";
			this->LastNamee->Width = 125;
			// 
			// FirstName
			// 
			this->FirstName->HeaderText = L"Имя";
			this->FirstName->MinimumWidth = 6;
			this->FirstName->Name = L"FirstName";
			this->FirstName->Width = 125;
			// 
			// Otchestvo
			// 
			this->Otchestvo->HeaderText = L"Отчество";
			this->Otchestvo->MinimumWidth = 6;
			this->Otchestvo->Name = L"Otchestvo";
			this->Otchestvo->Width = 125;
			// 
			// Hotell
			// 
			this->Hotell->HeaderText = L"Гостиница";
			this->Hotell->MinimumWidth = 6;
			this->Hotell->Name = L"Hotell";
			this->Hotell->Width = 125;
			// 
			// Live
			// 
			this->Live->HeaderText = L"Срок пребывания";
			this->Live->MinimumWidth = 6;
			this->Live->Name = L"Live";
			this->Live->Width = 125;
			// 
			// DateArrave
			// 
			this->DateArrave->HeaderText = L"Дата приезда";
			this->DateArrave->MinimumWidth = 6;
			this->DateArrave->Name = L"DateArrave";
			this->DateArrave->Width = 125;
			// 
			// DateMoveOut
			// 
			this->DateMoveOut->HeaderText = L"Дата отьезда";
			this->DateMoveOut->MinimumWidth = 6;
			this->DateMoveOut->Name = L"DateMoveOut";
			this->DateMoveOut->Width = 125;
			// 
			// Add
			// 
			this->Add->Location = System::Drawing::Point(997, 57);
			this->Add->Name = L"Add";
			this->Add->Size = System::Drawing::Size(94, 38);
			this->Add->TabIndex = 2;
			this->Add->Text = L"Добавить";
			this->Add->UseVisualStyleBackColor = true;
			this->Add->Click += gcnew System::EventHandler(this, &PlaneForm::Add_Click);
			// 
			// Delete
			// 
			this->Delete->Location = System::Drawing::Point(997, 101);
			this->Delete->Name = L"Delete";
			this->Delete->Size = System::Drawing::Size(94, 35);
			this->Delete->TabIndex = 3;
			this->Delete->Text = L"Удалить";
			this->Delete->UseVisualStyleBackColor = true;
			this->Delete->Click += gcnew System::EventHandler(this, &PlaneForm::Delete_Click);
			// 
			// OpenFile
			// 
			this->OpenFile->Location = System::Drawing::Point(1110, 57);
			this->OpenFile->Name = L"OpenFile";
			this->OpenFile->Size = System::Drawing::Size(162, 38);
			this->OpenFile->TabIndex = 4;
			this->OpenFile->Text = L"Открыть файл";
			this->OpenFile->UseVisualStyleBackColor = true;
			this->OpenFile->Click += gcnew System::EventHandler(this, &PlaneForm::OpenFile_Click);
			// 
			// SaveInFile
			// 
			this->SaveInFile->Location = System::Drawing::Point(1110, 101);
			this->SaveInFile->Name = L"SaveInFile";
			this->SaveInFile->Size = System::Drawing::Size(162, 35);
			this->SaveInFile->TabIndex = 5;
			this->SaveInFile->Text = L"Сохранить в файл";
			this->SaveInFile->UseVisualStyleBackColor = true;
			this->SaveInFile->Click += gcnew System::EventHandler(this, &PlaneForm::SaveInFile_Click);
			// 
			// SaveInforPass
			// 
			this->SaveInforPass->Location = System::Drawing::Point(1172, 412);
			this->SaveInforPass->Name = L"SaveInforPass";
			this->SaveInforPass->Size = System::Drawing::Size(165, 66);
			this->SaveInforPass->TabIndex = 6;
			this->SaveInforPass->Text = L"Сохранение информации о туристе";
			this->SaveInforPass->UseVisualStyleBackColor = true;
			this->SaveInforPass->Click += gcnew System::EventHandler(this, &PlaneForm::SaveInforPass_Click);
			// 
			// ChoiseRaceBut
			// 
			this->ChoiseRaceBut->Location = System::Drawing::Point(1168, 366);
			this->ChoiseRaceBut->Name = L"ChoiseRaceBut";
			this->ChoiseRaceBut->Size = System::Drawing::Size(169, 40);
			this->ChoiseRaceBut->TabIndex = 7;
			this->ChoiseRaceBut->Text = L"Выбрать нужную гостиницу";
			this->ChoiseRaceBut->UseVisualStyleBackColor = true;
			this->ChoiseRaceBut->Click += gcnew System::EventHandler(this, &PlaneForm::ChoiseRaceBut_Click);
			// 
			// ChoiceRace
			// 
			this->ChoiceRace->Location = System::Drawing::Point(997, 397);
			this->ChoiceRace->Multiline = true;
			this->ChoiceRace->Name = L"ChoiceRace";
			this->ChoiceRace->Size = System::Drawing::Size(118, 42);
			this->ChoiceRace->TabIndex = 8;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(994, 378);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(143, 16);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Выберете гостиницу";
			// 
			// errorProvider1
			// 
			this->errorProvider1->ContainerControl = this;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// errorProvider2
			// 
			this->errorProvider2->ContainerControl = this;
			// 
			// Table2
			// 
			this->Table2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Table2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4, this->dataGridViewTextBoxColumn5,
					this->dataGridViewTextBoxColumn6, this->dataGridViewTextBoxColumn7
			});
			this->Table2->Location = System::Drawing::Point(34, 270);
			this->Table2->Name = L"Table2";
			this->Table2->RowHeadersWidth = 51;
			this->Table2->RowTemplate->Height = 24;
			this->Table2->Size = System::Drawing::Size(942, 184);
			this->Table2->TabIndex = 10;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"Фамилия";
			this->dataGridViewTextBoxColumn1->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->Width = 125;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Имя";
			this->dataGridViewTextBoxColumn2->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->Width = 125;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"Отчество";
			this->dataGridViewTextBoxColumn3->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->Width = 125;
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->HeaderText = L"Гостиница";
			this->dataGridViewTextBoxColumn4->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			this->dataGridViewTextBoxColumn4->Width = 125;
			// 
			// dataGridViewTextBoxColumn5
			// 
			this->dataGridViewTextBoxColumn5->HeaderText = L"Срок пребывания";
			this->dataGridViewTextBoxColumn5->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			this->dataGridViewTextBoxColumn5->Width = 125;
			// 
			// dataGridViewTextBoxColumn6
			// 
			this->dataGridViewTextBoxColumn6->HeaderText = L"Дата приезда";
			this->dataGridViewTextBoxColumn6->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn6->Name = L"dataGridViewTextBoxColumn6";
			this->dataGridViewTextBoxColumn6->Width = 125;
			// 
			// dataGridViewTextBoxColumn7
			// 
			this->dataGridViewTextBoxColumn7->HeaderText = L"Дата отьезда";
			this->dataGridViewTextBoxColumn7->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn7->Name = L"dataGridViewTextBoxColumn7";
			this->dataGridViewTextBoxColumn7->Width = 125;
			// 
			// PlaneForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1349, 538);
			this->Controls->Add(this->Table2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ChoiceRace);
			this->Controls->Add(this->ChoiseRaceBut);
			this->Controls->Add(this->SaveInforPass);
			this->Controls->Add(this->SaveInFile);
			this->Controls->Add(this->OpenFile);
			this->Controls->Add(this->Delete);
			this->Controls->Add(this->Add);
			this->Controls->Add(this->Table1);
			this->DoubleBuffered = true;
			this->Name = L"PlaneForm";
			this->Text = L"Никитенко 9 вариант";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// Добавление строки
	private: System::Void Add_Click(System::Object^ sender, System::EventArgs^ e) {

		this->Table1->Rows->Add(1);
	}
		   //

		   // Удаление строки
	private: System::Void Delete_Click(System::Object^ sender, System::EventArgs^ e) {

		if (this->Table1->RowCount == 0) {
			errorProvider1->SetError(Table1, "Пустая таблица");
			return;
		}
		int i = this->Table1->CurrentCell->RowIndex;
		this->Table1->Rows->RemoveAt(i);
	}
		   //

		   // Открытие файла
	private: System::Void OpenFile_Click(System::Object^ sender, System::EventArgs^ e) {


		if (this->openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			System::IO::Stream^ myStream;
			if ((myStream = openFileDialog1->OpenFile()) != nullptr) {
				System::IO::StreamReader^ sw = gcnew System::IO::StreamReader(myStream);
				String^ str = "";
				String^ person;
				date DoR;

				int pos = 0;
				int at = 0;
				int i = 0;

				// Очищаем старые данные из Table1
				this->Table1->Rows->Clear();

				while (sw->Peek() > -1) {
					this->Table1->Rows->Add(1);

					person = sw->ReadLine();
					person += " ";
					at = 0;
					pos = person->IndexOf(" ");
					for (int j = 0; j < 5; j++) {
						this->Table1->Rows[i]->Cells[j]->Value = person->Substring(at, pos - at);
						at = pos + 1;
						pos = person->IndexOf(" ", at);
					}
					DoR = StringToDate(person->Substring(at, pos - at));
					this->Table1->Rows[i]->Cells[5]->Value = DateToString(DoR);
					at = pos + 1;
					pos = person->IndexOf(" ", at);
					this->Table1->Rows[i]->Cells[6]->Value = person->Substring(at, pos - at);

					i++;
				}
			}
			else {
				errorProvider1->SetError(OpenFile, "Файл не открыт");
			}
		}
		else {
			errorProvider1->SetError(OpenFile, "Файл не открыт");
		}
	}
		   //

		   // Сохранение в файл
	private: System::Void SaveInFile_Click(System::Object^ sender, System::EventArgs^ e) {

		errorProvider1->Clear();
		System::IO::Stream^ MyStream;
		if (this->saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if ((MyStream = this->saveFileDialog1->OpenFile()) != nullptr) {
				System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(MyStream);
				String^ str = "";
				int n = this->Table1->RowCount;
				for (int i = 0; i < n - 1; i++) {
					str = "";
					for (int j = 0; j < this->Table1->ColumnCount; j++) {
						str += this->Table1->Rows[i]->Cells[j]->Value + " ";
					}
					sw->WriteLine(str);
				}
				str = "";
				for (int j = 0; j < this->Table1->ColumnCount; j++) {
					str += this->Table1->Rows[n - 1]->Cells[j]->Value + " ";
				}
				sw->Write(str);
				sw->Close();
			}
		}
	}
		   //

		   // Выбор гостиницы
	private: System::Void ChoiseRaceBut_Click(System::Object^ sender, System::EventArgs^ e) {

		errorProvider1->Clear();
		errorProvider2->Clear();
		this->Table2->RowCount = 1;
		for (int i = 0; i < this->Table2->RowCount; i++) {
			for (int j = 0; j < this->Table2->ColumnCount; j++) {
				this->Table2->Rows[i]->Cells[j]->Value = nullptr;
			}
		}
		if (ChoiceRace->Text == "") {
			errorProvider1->SetError(ChoiceRace, "Сначала введите навзание гостиницы");
			return;
		}
		int n = this->Table1->RowCount;
		int m = this->Table1->ColumnCount;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m; j++) {
				if (this->Table1->Rows[i]->Cells[j]->Value == nullptr) {
					errorProvider1->SetError(this->Table1, "В строке " + Convert::ToString(i + 1) + " отсутствую какие-то данные");
					return;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (this->Table1->Rows[i]->Cells[6]->Value == ChoiceRace->Text) {
				this->Table2->Rows->Add(1);
			}
		}
		for (int i = 0; i < n; i++) {
			if (System::Convert::ToString(this->Table1->Rows[i]->Cells[3]->Value) == ChoiceRace->Text) {
				for (int k = 0; k < this->Table2->RowCount; k++) {
					for (int j = 0; j < m; j++) {
						this->Table2->Rows[k]->Cells[j]->Value = this->Table1->Rows[i]->Cells[j]->Value;
					}
				}
			}
		}
	}
		   //

		   // Сохранение информации о пассажирах в файл
	private: System::Void SaveInforPass_Click(System::Object^ sender, System::EventArgs^ e) {
		errorProvider1->Clear();
		errorProvider2->Clear();
		if (ChoiceRace->Text != "") {
			System::IO::Stream^ MyStream;
			if (this->saveFileDialog2->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				if ((MyStream = this->saveFileDialog2->OpenFile()) != nullptr) {
					System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(MyStream);
					String^ str = "";
					int n = this->Table2->RowCount;
					for (int i = 0; i < n - 1; i++) {
						str = "";
						for (int j = 0; j < this->Table2->ColumnCount; j++) {
							str += this->Table2->Rows[i]->Cells[j]->Value + " ";
						}
						sw->WriteLine(str);
					}
					str = "";
					for (int j = 0; j < this->Table2->ColumnCount; j++) {
						str += this->Table2->Rows[n - 1]->Cells[j]->Value + " ";
					}
					sw->Write(str);
					sw->Close();
				}
			}
		}
		else {
			errorProvider2->SetError(ChoiceRace, "Сначала выберите гостиницу");
		}

	}//

	};
	}


