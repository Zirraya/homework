#pragma once

namespace MatrixNikitenko211 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MatrixForm
	/// </summary>
	public ref class MatrixForm : public System::Windows::Forms::Form
	{
	public:
		MatrixForm(void)
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
		~MatrixForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ Matrix1;
	private: System::Windows::Forms::DataGridView^ Matrix2;
	private: System::Windows::Forms::DataGridView^ Vector1;
	private: System::Windows::Forms::DataGridView^ Vector2;
	private: System::Windows::Forms::DataGridView^ Result;
	protected:

	protected:




	private: System::Windows::Forms::Button^ AddString;
	private: System::Windows::Forms::Button^ DeleteString;
	private: System::Windows::Forms::Button^ AddColumn;
	private: System::Windows::Forms::Button^ DeleteColumn;
	private: System::Windows::Forms::Button^ DeleteColumn2;
	private: System::Windows::Forms::Button^ AddColumn2;
	private: System::Windows::Forms::Button^ DeleteString2;
	private: System::Windows::Forms::Button^ AddString2;
	private: System::Windows::Forms::Button^ DeleteStringV;
	private: System::Windows::Forms::Button^ AddStringV;
	private: System::Windows::Forms::Button^ DeleteStringV2;
	private: System::Windows::Forms::Button^ AddStringV2;
	private: System::Windows::Forms::RadioButton^ MultiNumber;
	private: System::Windows::Forms::RadioButton^ MultiMV;
	private: System::Windows::Forms::RadioButton^ MultiMM;
	private: System::Windows::Forms::RadioButton^ AddMM;
	private: System::Windows::Forms::RadioButton^ SubMM;
	private: System::Windows::Forms::RadioButton^ AddVV;
	private: System::Windows::Forms::RadioButton^ SubVV;
	private: System::Windows::Forms::RadioButton^ CreateMV;









	private: System::Windows::Forms::RadioButton^ CreateM1;

	private: System::Windows::Forms::RadioButton^ OprM;

	private: System::Windows::Forms::RadioButton^ TransM;

	private: System::Windows::Forms::RadioButton^ MultiV;

	private: System::Windows::Forms::RadioButton^ ScalV;

	private: System::Windows::Forms::Label^ Actions;

	private: System::Windows::Forms::TextBox^ MatrixSize;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ InPutNumber;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ErrorProvider^ errorM1;
	private: System::Windows::Forms::ErrorProvider^ errorM2;
	private: System::Windows::Forms::ErrorProvider^ errorV1;
	private: System::Windows::Forms::ErrorProvider^ errorV2;
	private: System::Windows::Forms::ErrorProvider^ errorInPut;
	private: System::Windows::Forms::Button^ Execute;
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
			this->Matrix1 = (gcnew System::Windows::Forms::DataGridView());
			this->Matrix2 = (gcnew System::Windows::Forms::DataGridView());
			this->Vector1 = (gcnew System::Windows::Forms::DataGridView());
			this->Vector2 = (gcnew System::Windows::Forms::DataGridView());
			this->Result = (gcnew System::Windows::Forms::DataGridView());
			this->AddString = (gcnew System::Windows::Forms::Button());
			this->DeleteString = (gcnew System::Windows::Forms::Button());
			this->AddColumn = (gcnew System::Windows::Forms::Button());
			this->DeleteColumn = (gcnew System::Windows::Forms::Button());
			this->DeleteColumn2 = (gcnew System::Windows::Forms::Button());
			this->AddColumn2 = (gcnew System::Windows::Forms::Button());
			this->DeleteString2 = (gcnew System::Windows::Forms::Button());
			this->AddString2 = (gcnew System::Windows::Forms::Button());
			this->DeleteStringV = (gcnew System::Windows::Forms::Button());
			this->AddStringV = (gcnew System::Windows::Forms::Button());
			this->DeleteStringV2 = (gcnew System::Windows::Forms::Button());
			this->AddStringV2 = (gcnew System::Windows::Forms::Button());
			this->MultiNumber = (gcnew System::Windows::Forms::RadioButton());
			this->MultiMV = (gcnew System::Windows::Forms::RadioButton());
			this->MultiMM = (gcnew System::Windows::Forms::RadioButton());
			this->AddMM = (gcnew System::Windows::Forms::RadioButton());
			this->SubMM = (gcnew System::Windows::Forms::RadioButton());
			this->AddVV = (gcnew System::Windows::Forms::RadioButton());
			this->SubVV = (gcnew System::Windows::Forms::RadioButton());
			this->CreateMV = (gcnew System::Windows::Forms::RadioButton());
			this->CreateM1 = (gcnew System::Windows::Forms::RadioButton());
			this->OprM = (gcnew System::Windows::Forms::RadioButton());
			this->TransM = (gcnew System::Windows::Forms::RadioButton());
			this->MultiV = (gcnew System::Windows::Forms::RadioButton());
			this->ScalV = (gcnew System::Windows::Forms::RadioButton());
			this->Actions = (gcnew System::Windows::Forms::Label());
			this->MatrixSize = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->InPutNumber = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->errorM1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->errorM2 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->errorV1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->errorV2 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->errorInPut = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->Execute = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Matrix1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Matrix2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Vector1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Vector2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Result))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorM1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorM2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorV1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorV2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorInPut))->BeginInit();
			this->SuspendLayout();
			// 
			// Matrix1
			// 
			this->Matrix1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Matrix1->Location = System::Drawing::Point(21, 50);
			this->Matrix1->Name = L"Matrix1";
			this->Matrix1->RowHeadersWidth = 51;
			this->Matrix1->RowTemplate->Height = 24;
			this->Matrix1->Size = System::Drawing::Size(255, 266);
			this->Matrix1->TabIndex = 0;
			// 
			// Matrix2
			// 
			this->Matrix2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Matrix2->Location = System::Drawing::Point(342, 50);
			this->Matrix2->Name = L"Matrix2";
			this->Matrix2->RowHeadersWidth = 51;
			this->Matrix2->RowTemplate->Height = 24;
			this->Matrix2->Size = System::Drawing::Size(255, 266);
			this->Matrix2->TabIndex = 1;
			// 
			// Vector1
			// 
			this->Vector1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Vector1->Location = System::Drawing::Point(674, 50);
			this->Vector1->Name = L"Vector1";
			this->Vector1->RowHeadersWidth = 51;
			this->Vector1->RowTemplate->Height = 24;
			this->Vector1->Size = System::Drawing::Size(255, 266);
			this->Vector1->TabIndex = 2;
			// 
			// Vector2
			// 
			this->Vector2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Vector2->Location = System::Drawing::Point(1002, 50);
			this->Vector2->Name = L"Vector2";
			this->Vector2->RowHeadersWidth = 51;
			this->Vector2->RowTemplate->Height = 24;
			this->Vector2->Size = System::Drawing::Size(255, 266);
			this->Vector2->TabIndex = 3;
			// 
			// Result
			// 
			this->Result->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Result->Location = System::Drawing::Point(915, 460);
			this->Result->Name = L"Result";
			this->Result->RowHeadersWidth = 51;
			this->Result->RowTemplate->Height = 24;
			this->Result->Size = System::Drawing::Size(369, 241);
			this->Result->TabIndex = 4;
			// 
			// AddString
			// 
			this->AddString->Location = System::Drawing::Point(21, 334);
			this->AddString->Name = L"AddString";
			this->AddString->Size = System::Drawing::Size(105, 49);
			this->AddString->TabIndex = 5;
			this->AddString->Text = L"Добавить строку";
			this->AddString->UseVisualStyleBackColor = true;
			this->AddString->Click += gcnew System::EventHandler(this, &MatrixForm::AddString_Click);
			// 
			// DeleteString
			// 
			this->DeleteString->Location = System::Drawing::Point(21, 405);
			this->DeleteString->Name = L"DeleteString";
			this->DeleteString->Size = System::Drawing::Size(105, 49);
			this->DeleteString->TabIndex = 6;
			this->DeleteString->Text = L"Уадлить строку";
			this->DeleteString->UseVisualStyleBackColor = true;
			this->DeleteString->Click += gcnew System::EventHandler(this, &MatrixForm::DeleteString_Click);
			// 
			// AddColumn
			// 
			this->AddColumn->Location = System::Drawing::Point(132, 334);
			this->AddColumn->Name = L"AddColumn";
			this->AddColumn->Size = System::Drawing::Size(105, 49);
			this->AddColumn->TabIndex = 7;
			this->AddColumn->Text = L"Добавить столбец";
			this->AddColumn->UseVisualStyleBackColor = true;
			this->AddColumn->Click += gcnew System::EventHandler(this, &MatrixForm::AddColumn_Click);
			// 
			// DeleteColumn
			// 
			this->DeleteColumn->Location = System::Drawing::Point(132, 405);
			this->DeleteColumn->Name = L"DeleteColumn";
			this->DeleteColumn->Size = System::Drawing::Size(105, 49);
			this->DeleteColumn->TabIndex = 8;
			this->DeleteColumn->Text = L"Удалить столбец";
			this->DeleteColumn->UseVisualStyleBackColor = true;
			this->DeleteColumn->Click += gcnew System::EventHandler(this, &MatrixForm::DeleteColumn_Click);
			// 
			// DeleteColumn2
			// 
			this->DeleteColumn2->Location = System::Drawing::Point(471, 405);
			this->DeleteColumn2->Name = L"DeleteColumn2";
			this->DeleteColumn2->Size = System::Drawing::Size(105, 49);
			this->DeleteColumn2->TabIndex = 12;
			this->DeleteColumn2->Text = L"Удалить столбец";
			this->DeleteColumn2->UseVisualStyleBackColor = true;
			this->DeleteColumn2->Click += gcnew System::EventHandler(this, &MatrixForm::DeleteColumn2_Click);
			// 
			// AddColumn2
			// 
			this->AddColumn2->Location = System::Drawing::Point(471, 334);
			this->AddColumn2->Name = L"AddColumn2";
			this->AddColumn2->Size = System::Drawing::Size(105, 49);
			this->AddColumn2->TabIndex = 11;
			this->AddColumn2->Text = L"Добавить столбец";
			this->AddColumn2->UseVisualStyleBackColor = true;
			this->AddColumn2->Click += gcnew System::EventHandler(this, &MatrixForm::AddColumn2_Click);
			// 
			// DeleteString2
			// 
			this->DeleteString2->Location = System::Drawing::Point(360, 405);
			this->DeleteString2->Name = L"DeleteString2";
			this->DeleteString2->Size = System::Drawing::Size(105, 49);
			this->DeleteString2->TabIndex = 10;
			this->DeleteString2->Text = L"Уадлить строку";
			this->DeleteString2->UseVisualStyleBackColor = true;
			this->DeleteString2->Click += gcnew System::EventHandler(this, &MatrixForm::DeleteString2_Click);
			// 
			// AddString2
			// 
			this->AddString2->Location = System::Drawing::Point(360, 334);
			this->AddString2->Name = L"AddString2";
			this->AddString2->Size = System::Drawing::Size(105, 49);
			this->AddString2->TabIndex = 9;
			this->AddString2->Text = L"Добавить строку";
			this->AddString2->UseVisualStyleBackColor = true;
			this->AddString2->Click += gcnew System::EventHandler(this, &MatrixForm::AddString2_Click);
			// 
			// DeleteStringV
			// 
			this->DeleteStringV->Location = System::Drawing::Point(785, 334);
			this->DeleteStringV->Name = L"DeleteStringV";
			this->DeleteStringV->Size = System::Drawing::Size(105, 49);
			this->DeleteStringV->TabIndex = 14;
			this->DeleteStringV->Text = L"Уадлить строку";
			this->DeleteStringV->UseVisualStyleBackColor = true;
			this->DeleteStringV->Click += gcnew System::EventHandler(this, &MatrixForm::DeleteStringV_Click);
			// 
			// AddStringV
			// 
			this->AddStringV->Location = System::Drawing::Point(674, 334);
			this->AddStringV->Name = L"AddStringV";
			this->AddStringV->Size = System::Drawing::Size(105, 49);
			this->AddStringV->TabIndex = 13;
			this->AddStringV->Text = L"Добавить строку";
			this->AddStringV->UseVisualStyleBackColor = true;
			this->AddStringV->Click += gcnew System::EventHandler(this, &MatrixForm::AddStringV_Click);
			// 
			// DeleteStringV2
			// 
			this->DeleteStringV2->Location = System::Drawing::Point(1138, 334);
			this->DeleteStringV2->Name = L"DeleteStringV2";
			this->DeleteStringV2->Size = System::Drawing::Size(105, 49);
			this->DeleteStringV2->TabIndex = 16;
			this->DeleteStringV2->Text = L"Уадлить строку";
			this->DeleteStringV2->UseVisualStyleBackColor = true;
			this->DeleteStringV2->Click += gcnew System::EventHandler(this, &MatrixForm::DeleteStringV2_Click);
			// 
			// AddStringV2
			// 
			this->AddStringV2->Location = System::Drawing::Point(1027, 334);
			this->AddStringV2->Name = L"AddStringV2";
			this->AddStringV2->Size = System::Drawing::Size(105, 49);
			this->AddStringV2->TabIndex = 15;
			this->AddStringV2->Text = L"Добавить строку";
			this->AddStringV2->UseVisualStyleBackColor = true;
			this->AddStringV2->Click += gcnew System::EventHandler(this, &MatrixForm::AddStringV2_Click);
			// 
			// MultiNumber
			// 
			this->MultiNumber->AutoSize = true;
			this->MultiNumber->Location = System::Drawing::Point(12, 509);
			this->MultiNumber->Name = L"MultiNumber";
			this->MultiNumber->Size = System::Drawing::Size(216, 20);
			this->MultiNumber->TabIndex = 17;
			this->MultiNumber->TabStop = true;
			this->MultiNumber->Text = L"Умножить матрицу 1 на чило";
			this->MultiNumber->UseVisualStyleBackColor = true;
			// 
			// MultiMV
			// 
			this->MultiMV->AutoSize = true;
			this->MultiMV->Location = System::Drawing::Point(45, 561);
			this->MultiMV->Name = L"MultiMV";
			this->MultiMV->Size = System::Drawing::Size(240, 20);
			this->MultiMV->TabIndex = 18;
			this->MultiMV->TabStop = true;
			this->MultiMV->Text = L"Умножить матрицу 1 на вектор 1";
			this->MultiMV->UseVisualStyleBackColor = true;
			// 
			// MultiMM
			// 
			this->MultiMM->AutoSize = true;
			this->MultiMM->Location = System::Drawing::Point(45, 587);
			this->MultiMM->Name = L"MultiMM";
			this->MultiMM->Size = System::Drawing::Size(250, 20);
			this->MultiMM->TabIndex = 19;
			this->MultiMM->TabStop = true;
			this->MultiMM->Text = L"Умножить матрицу 1 на матрицу 2";
			this->MultiMM->UseVisualStyleBackColor = true;
			// 
			// AddMM
			// 
			this->AddMM->AutoSize = true;
			this->AddMM->Location = System::Drawing::Point(45, 613);
			this->AddMM->Name = L"AddMM";
			this->AddMM->Size = System::Drawing::Size(233, 20);
			this->AddMM->TabIndex = 20;
			this->AddMM->TabStop = true;
			this->AddMM->Text = L"Сложить матрицу 1 и матрицу 2";
			this->AddMM->UseVisualStyleBackColor = true;
			// 
			// SubMM
			// 
			this->SubMM->AutoSize = true;
			this->SubMM->Location = System::Drawing::Point(45, 639);
			this->SubMM->Name = L"SubMM";
			this->SubMM->Size = System::Drawing::Size(241, 20);
			this->SubMM->TabIndex = 21;
			this->SubMM->TabStop = true;
			this->SubMM->Text = L"Вычисть матрицу 2 из матрицы 1";
			this->SubMM->UseVisualStyleBackColor = true;
			// 
			// AddVV
			// 
			this->AddVV->AutoSize = true;
			this->AddVV->Location = System::Drawing::Point(45, 665);
			this->AddVV->Name = L"AddVV";
			this->AddVV->Size = System::Drawing::Size(206, 20);
			this->AddVV->TabIndex = 22;
			this->AddVV->TabStop = true;
			this->AddVV->Text = L"Сложить ветор 1 и вектор 2";
			this->AddVV->UseVisualStyleBackColor = true;
			// 
			// SubVV
			// 
			this->SubVV->AutoSize = true;
			this->SubVV->Location = System::Drawing::Point(45, 691);
			this->SubVV->Name = L"SubVV";
			this->SubVV->Size = System::Drawing::Size(221, 20);
			this->SubVV->TabIndex = 23;
			this->SubVV->TabStop = true;
			this->SubVV->Text = L"Вычесть вектор 2 из ветора 1";
			this->SubVV->UseVisualStyleBackColor = true;
			// 
			// CreateMV
			// 
			this->CreateMV->AutoSize = true;
			this->CreateMV->Location = System::Drawing::Point(439, 665);
			this->CreateMV->Name = L"CreateMV";
			this->CreateMV->Size = System::Drawing::Size(268, 20);
			this->CreateMV->TabIndex = 28;
			this->CreateMV->TabStop = true;
			this->CreateMV->Text = L"Создать матрицу как набор веторов";
			this->CreateMV->UseVisualStyleBackColor = true;
			// 
			// CreateM1
			// 
			this->CreateM1->AutoSize = true;
			this->CreateM1->Location = System::Drawing::Point(439, 613);
			this->CreateM1->Name = L"CreateM1";
			this->CreateM1->Size = System::Drawing::Size(219, 20);
			this->CreateM1->TabIndex = 27;
			this->CreateM1->TabStop = true;
			this->CreateM1->Text = L"Создать еденичную матрицу";
			this->CreateM1->UseVisualStyleBackColor = true;
			// 
			// OprM
			// 
			this->OprM->AutoSize = true;
			this->OprM->Location = System::Drawing::Point(439, 587);
			this->OprM->Name = L"OprM";
			this->OprM->Size = System::Drawing::Size(230, 20);
			this->OprM->TabIndex = 26;
			this->OprM->TabStop = true;
			this->OprM->Text = L"Опрделитель и ранг матрицы 1";
			this->OprM->UseVisualStyleBackColor = true;
			// 
			// TransM
			// 
			this->TransM->AutoSize = true;
			this->TransM->Location = System::Drawing::Point(439, 561);
			this->TransM->Name = L"TransM";
			this->TransM->Size = System::Drawing::Size(215, 20);
			this->TransM->TabIndex = 25;
			this->TransM->TabStop = true;
			this->TransM->Text = L"Транспонировать матрицу 1";
			this->TransM->UseVisualStyleBackColor = true;
			// 
			// MultiV
			// 
			this->MultiV->AutoSize = true;
			this->MultiV->Location = System::Drawing::Point(439, 535);
			this->MultiV->Name = L"MultiV";
			this->MultiV->Size = System::Drawing::Size(263, 20);
			this->MultiV->TabIndex = 24;
			this->MultiV->TabStop = true;
			this->MultiV->Text = L"Векторное произведение векторов";
			this->MultiV->UseVisualStyleBackColor = true;
			// 
			// ScalV
			// 
			this->ScalV->AutoSize = true;
			this->ScalV->Location = System::Drawing::Point(439, 509);
			this->ScalV->Name = L"ScalV";
			this->ScalV->Size = System::Drawing::Size(263, 20);
			this->ScalV->TabIndex = 30;
			this->ScalV->TabStop = true;
			this->ScalV->Text = L"Скалярное произведение векторов";
			this->ScalV->UseVisualStyleBackColor = true;
			// 
			// Actions
			// 
			this->Actions->AutoSize = true;
			this->Actions->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Actions->Location = System::Drawing::Point(29, 483);
			this->Actions->Name = L"Actions";
			this->Actions->Size = System::Drawing::Size(97, 23);
			this->Actions->TabIndex = 31;
			this->Actions->Text = L"Действие";
			// 
			// MatrixSize
			// 
			this->MatrixSize->Location = System::Drawing::Point(797, 636);
			this->MatrixSize->Multiline = true;
			this->MatrixSize->Name = L"MatrixSize";
			this->MatrixSize->Size = System::Drawing::Size(61, 20);
			this->MatrixSize->TabIndex = 32;
			this->MatrixSize->TextChanged += gcnew System::EventHandler(this, &MatrixForm::textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(477, 636);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(314, 16);
			this->label2->TabIndex = 33;
			this->label2->Text = L"Введите размерность для еденичный матрицы";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(42, 532);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(284, 16);
			this->label3->TabIndex = 35;
			this->label3->Text = L"Введите число на которе нужно умножить";
			// 
			// InPutNumber
			// 
			this->InPutNumber->Location = System::Drawing::Point(332, 532);
			this->InPutNumber->Multiline = true;
			this->InPutNumber->Name = L"InPutNumber";
			this->InPutNumber->Size = System::Drawing::Size(56, 20);
			this->InPutNumber->TabIndex = 34;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(912, 438);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(77, 16);
			this->label4->TabIndex = 36;
			this->label4->Text = L"Результат";
			// 
			// errorM1
			// 
			this->errorM1->ContainerControl = this;
			// 
			// errorM2
			// 
			this->errorM2->ContainerControl = this;
			// 
			// errorV1
			// 
			this->errorV1->ContainerControl = this;
			// 
			// errorV2
			// 
			this->errorV2->ContainerControl = this;
			// 
			// errorInPut
			// 
			this->errorInPut->ContainerControl = this;
			// 
			// Execute
			// 
			this->Execute->Location = System::Drawing::Point(1103, 716);
			this->Execute->Name = L"Execute";
			this->Execute->Size = System::Drawing::Size(181, 48);
			this->Execute->TabIndex = 37;
			this->Execute->Text = L"Вычислить";
			this->Execute->UseVisualStyleBackColor = true;
			this->Execute->Click += gcnew System::EventHandler(this, &MatrixForm::Execute_Click);
			// 
			// MatrixForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1306, 786);
			this->Controls->Add(this->Execute);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->InPutNumber);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->MatrixSize);
			this->Controls->Add(this->Actions);
			this->Controls->Add(this->ScalV);
			this->Controls->Add(this->CreateMV);
			this->Controls->Add(this->CreateM1);
			this->Controls->Add(this->OprM);
			this->Controls->Add(this->TransM);
			this->Controls->Add(this->MultiV);
			this->Controls->Add(this->SubVV);
			this->Controls->Add(this->AddVV);
			this->Controls->Add(this->SubMM);
			this->Controls->Add(this->AddMM);
			this->Controls->Add(this->MultiMM);
			this->Controls->Add(this->MultiMV);
			this->Controls->Add(this->MultiNumber);
			this->Controls->Add(this->DeleteStringV2);
			this->Controls->Add(this->AddStringV2);
			this->Controls->Add(this->DeleteStringV);
			this->Controls->Add(this->AddStringV);
			this->Controls->Add(this->DeleteColumn2);
			this->Controls->Add(this->AddColumn2);
			this->Controls->Add(this->DeleteString2);
			this->Controls->Add(this->AddString2);
			this->Controls->Add(this->DeleteColumn);
			this->Controls->Add(this->AddColumn);
			this->Controls->Add(this->DeleteString);
			this->Controls->Add(this->AddString);
			this->Controls->Add(this->Result);
			this->Controls->Add(this->Vector2);
			this->Controls->Add(this->Vector1);
			this->Controls->Add(this->Matrix2);
			this->Controls->Add(this->Matrix1);
			this->DoubleBuffered = true;
			this->Name = L"MatrixForm";
			this->Text = L"MatrixForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Matrix1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Matrix2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Vector1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Vector2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Result))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorM1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorM2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorV1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorV2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorInPut))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}



// Для матрицы 1

	//Добавление строк
private: System::Void AddString_Click(System::Object^ sender, System::EventArgs^ e) {

	// Проверка на наличие столбцов 
	if (this->Matrix1->Columns->Count == 0) {
		errorM1->SetError(Matrix1, "Столбцы должны быть добавлены перед добавлением строк.");
		return;
	}

	this->Matrix1->Rows->Add(1);
	
	if (this->Matrix1->Rows->Count > 0) {
		errorM1->SetError(Matrix1, "");
	}

}
	//

	//Удаление строк
private: System::Void DeleteString_Click(System::Object^ sender, System::EventArgs^ e) {


	// Проверка на наличие строк
	if (this->Matrix1->Rows->Count == 0) {
		errorM1->SetError(Matrix1, " Что бы удалить строку, нужно в начале добавить ее "); //  Установка ошибки, если нет строк
		return;
	}

	// Удаление
	if (!this->Matrix1->CurrentRow->IsNewRow) {
		int i = this->Matrix1->CurrentRow->Index;
		this->Matrix1->Rows->Remove(this->Matrix1->Rows[i]);

	}

}
	//


	// Добавление стоблоцов
private: System::Void AddColumn_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Matrix1->Columns->Add("COLUMN", " ");
	
	if (this->Matrix1->Columns->Count > 0) {
		errorM1->SetError(Matrix1, "");
	}
	for (int i = 0; i < this->Matrix1->Columns->Count; i++) {
		this->Matrix1->Columns[i]->Width = System::Convert::ToInt32(this->Matrix1->Width / (1.25 * this->Matrix1->Columns->Count));
	}
	
}

	//

	// Удаление столбцов
private: System::Void DeleteColumn_Click(System::Object^ sender, System::EventArgs^ e) {
	// Проверка на наличие строк
	if (this->Matrix1->Columns->Count == 0) {
		errorM1->SetError(Matrix1, " Что бы удалить столбец, нужно в начале добавить его "); //  Установка ошибки, если нет строк
		return; //  Выход из метода
	}


	// Проверяем, есть ли столбцы в DataGridView
	if (this->Matrix1->Columns->Count > 0) {
		// Получение индекса последнего столбца 
		int i = this->Matrix1->Columns->Count - 1; // Индекс последнего столбца
		// Удалаление
		this->Matrix1->Columns->RemoveAt(i);
		
	}

}
	 //

//



// Для матрицы 2


	// Добавление строк
private: System::Void AddString2_Click(System::Object^ sender, System::EventArgs^ e) {

	// Проверка на наличие столбцов 
	if (this->Matrix2->Columns->Count == 0) {
		errorM2->SetError(Matrix2, "Столбцы должны быть добавлены перед добавлением строк.");
		return;
	}

	this->Matrix2->Rows->Add(1);

	if (this->Matrix2->Rows->Count > 0) {
		errorM2->SetError(Matrix2, "");
	}

}	//
	// Удаление строк
private: System::Void DeleteString2_Click(System::Object^ sender, System::EventArgs^ e) {

	// Проверка на наличие строк
	if (this->Matrix2->Rows->Count == 0) {
		errorM2->SetError(Matrix2, " Что бы удалить строку, нужно в начале добавить ее "); //  Установка ошибки, если нет строк
		return;
	}

	// Удаление
	if (!this->Matrix2->CurrentRow->IsNewRow) {
		int i = this->Matrix2->CurrentRow->Index;
		this->Matrix2->Rows->Remove(this->Matrix2->Rows[i]);

	}

}//
	// Добавление столбоцв
private: System::Void AddColumn2_Click(System::Object^ sender, System::EventArgs^ e) {

	this->Matrix2->Columns->Add("COLUMN", " ");

	if (this->Matrix2->Columns->Count > 0) {
		errorM2->SetError(Matrix2, "");
	}
	for (int i = 0; i < this->Matrix2->Columns->Count; i++) {
		this->Matrix2->Columns[i]->Width = System::Convert::ToInt32(this->Matrix2->Width / (1.25 * this->Matrix2->Columns->Count));
	}
}	//
	// Удаление столбцов
private: System::Void DeleteColumn2_Click(System::Object^ sender, System::EventArgs^ e) {

	// Проверка на наличие строк
	if (this->Matrix2->Columns->Count == 0) {
		errorM1->SetError(Matrix2, " Что бы удалить столбец, нужно в начале добавить его "); //  Установка ошибки, если нет строк
		return; //  Выход из метода
	}


	// Проверяем, есть ли столбцы в DataGridView
	if (this->Matrix2->Columns->Count > 0) {
		// Получение индекса последнего столбца 
		int i = this->Matrix2->Columns->Count - 1; // Индекс последнего столбца
		// Удалаление
		this->Matrix2->Columns->RemoveAt(i);

	}
}	//

//


// Для вектора 1
	// Добавление строки
private: System::Void AddStringV_Click(System::Object^ sender, System::EventArgs^ e) {

	Vector1->ColumnCount = 1;
	this->Vector1->Rows->Add(1);

	if (this->Vector1->Rows->Count > 0) {
		errorV1->SetError(Vector1, "");
	}
}	//

	// Удаление строки
private: System::Void DeleteStringV_Click(System::Object^ sender, System::EventArgs^ e) {

	// Удаление
	if (!this->Vector1->CurrentRow->IsNewRow) {
		int i = this->Vector1->CurrentRow->Index;
		this->Vector1->Rows->Remove(this->Vector1->Rows[i]);
	}

}	//
//


// Для вектора 2
	// Добавление строки
private: System::Void AddStringV2_Click(System::Object^ sender, System::EventArgs^ e) {

	Vector2->ColumnCount = 1;
	this->Vector2->Rows->Add(1);

	if (this->Vector2->Rows->Count > 0) {
		errorV2->SetError(Vector2, "");
	}
}	//
	   // Удаление строки
private: System::Void DeleteStringV2_Click(System::Object^ sender, System::EventArgs^ e) {

	// Удаление
	if (!this->Vector2->CurrentRow->IsNewRow) {
		int i = this->Vector2->CurrentRow->Index;
		this->Vector2->Rows->Remove(this->Vector2->Rows[i]);
	}
}	//
//



// Вычислить

private: System::Void Execute_Click(System::Object^ sender, System::EventArgs^ e) {



}

//


};
}
