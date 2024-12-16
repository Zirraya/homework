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
	private: System::Windows::Forms::ErrorProvider^ errorResult;
	private: System::Windows::Forms::TextBox^ ResultText;
	private: System::Windows::Forms::ErrorProvider^ errorMatrixSize;

	private: System::Windows::Forms::GroupBox^ ChoiceAct;
	private: System::Windows::Forms::ErrorProvider^ errorChoiceAct;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label8;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MatrixForm::typeid));
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
			this->errorResult = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->ResultText = (gcnew System::Windows::Forms::TextBox());
			this->errorMatrixSize = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->ChoiceAct = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->errorChoiceAct = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorResult))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorMatrixSize))->BeginInit();
			this->ChoiceAct->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorChoiceAct))->BeginInit();
			this->SuspendLayout();
			// 
			// Matrix1
			// 
			this->Matrix1->AllowUserToAddRows = false;
			this->Matrix1->AllowUserToDeleteRows = false;
			this->Matrix1->AllowUserToResizeColumns = false;
			this->Matrix1->AllowUserToResizeRows = false;
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
			this->Matrix2->AllowUserToAddRows = false;
			this->Matrix2->AllowUserToDeleteRows = false;
			this->Matrix2->AllowUserToResizeColumns = false;
			this->Matrix2->AllowUserToResizeRows = false;
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
			this->Vector1->AllowUserToAddRows = false;
			this->Vector1->AllowUserToDeleteRows = false;
			this->Vector1->AllowUserToResizeColumns = false;
			this->Vector1->AllowUserToResizeRows = false;
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
			this->Vector2->AllowUserToAddRows = false;
			this->Vector2->AllowUserToDeleteRows = false;
			this->Vector2->AllowUserToResizeColumns = false;
			this->Vector2->AllowUserToResizeRows = false;
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
			this->MultiNumber->Location = System::Drawing::Point(3, 24);
			this->MultiNumber->Name = L"MultiNumber";
			this->MultiNumber->Size = System::Drawing::Size(232, 21);
			this->MultiNumber->TabIndex = 17;
			this->MultiNumber->TabStop = true;
			this->MultiNumber->Text = L"Умножить матрицу 1 на чило";
			this->MultiNumber->UseVisualStyleBackColor = true;
			// 
			// MultiMV
			// 
			this->MultiMV->AutoSize = true;
			this->MultiMV->Location = System::Drawing::Point(22, 76);
			this->MultiMV->Name = L"MultiMV";
			this->MultiMV->Size = System::Drawing::Size(260, 21);
			this->MultiMV->TabIndex = 18;
			this->MultiMV->TabStop = true;
			this->MultiMV->Text = L"Умножить матрицу 1 на вектор 1";
			this->MultiMV->UseVisualStyleBackColor = true;
			// 
			// MultiMM
			// 
			this->MultiMM->AutoSize = true;
			this->MultiMM->Location = System::Drawing::Point(22, 102);
			this->MultiMM->Name = L"MultiMM";
			this->MultiMM->Size = System::Drawing::Size(269, 21);
			this->MultiMM->TabIndex = 19;
			this->MultiMM->TabStop = true;
			this->MultiMM->Text = L"Умножить матрицу 1 на матрицу 2";
			this->MultiMM->UseVisualStyleBackColor = true;
			// 
			// AddMM
			// 
			this->AddMM->AutoSize = true;
			this->AddMM->Location = System::Drawing::Point(22, 128);
			this->AddMM->Name = L"AddMM";
			this->AddMM->Size = System::Drawing::Size(252, 21);
			this->AddMM->TabIndex = 20;
			this->AddMM->TabStop = true;
			this->AddMM->Text = L"Сложить матрицу 1 и матрицу 2";
			this->AddMM->UseVisualStyleBackColor = true;
			// 
			// SubMM
			// 
			this->SubMM->AutoSize = true;
			this->SubMM->Location = System::Drawing::Point(22, 154);
			this->SubMM->Name = L"SubMM";
			this->SubMM->Size = System::Drawing::Size(264, 21);
			this->SubMM->TabIndex = 21;
			this->SubMM->TabStop = true;
			this->SubMM->Text = L"Вычисть матрицу 2 из матрицы 1";
			this->SubMM->UseVisualStyleBackColor = true;
			// 
			// AddVV
			// 
			this->AddVV->AutoSize = true;
			this->AddVV->Location = System::Drawing::Point(22, 180);
			this->AddVV->Name = L"AddVV";
			this->AddVV->Size = System::Drawing::Size(225, 21);
			this->AddVV->TabIndex = 22;
			this->AddVV->TabStop = true;
			this->AddVV->Text = L"Сложить ветор 1 и вектор 2";
			this->AddVV->UseVisualStyleBackColor = true;
			// 
			// SubVV
			// 
			this->SubVV->AutoSize = true;
			this->SubVV->Location = System::Drawing::Point(27, 207);
			this->SubVV->Name = L"SubVV";
			this->SubVV->Size = System::Drawing::Size(238, 21);
			this->SubVV->TabIndex = 23;
			this->SubVV->TabStop = true;
			this->SubVV->Text = L"Вычесть вектор 2 из ветора 1";
			this->SubVV->UseVisualStyleBackColor = true;
			// 
			// CreateMV
			// 
			this->CreateMV->AutoSize = true;
			this->CreateMV->Location = System::Drawing::Point(409, 128);
			this->CreateMV->Name = L"CreateMV";
			this->CreateMV->Size = System::Drawing::Size(280, 21);
			this->CreateMV->TabIndex = 28;
			this->CreateMV->TabStop = true;
			this->CreateMV->Text = L"Создать матрицу как набор веторов";
			this->CreateMV->UseVisualStyleBackColor = true;
			// 
			// CreateM1
			// 
			this->CreateM1->AutoSize = true;
			this->CreateM1->Location = System::Drawing::Point(409, 155);
			this->CreateM1->Name = L"CreateM1";
			this->CreateM1->Size = System::Drawing::Size(228, 21);
			this->CreateM1->TabIndex = 27;
			this->CreateM1->TabStop = true;
			this->CreateM1->Text = L"Создать еденичную матрицу";
			this->CreateM1->UseVisualStyleBackColor = true;
			// 
			// OprM
			// 
			this->OprM->AutoSize = true;
			this->OprM->Location = System::Drawing::Point(409, 102);
			this->OprM->Name = L"OprM";
			this->OprM->Size = System::Drawing::Size(250, 21);
			this->OprM->TabIndex = 26;
			this->OprM->TabStop = true;
			this->OprM->Text = L"Опрделитель и ранг матрицы 1";
			this->OprM->UseVisualStyleBackColor = true;
			// 
			// TransM
			// 
			this->TransM->AutoSize = true;
			this->TransM->Location = System::Drawing::Point(409, 76);
			this->TransM->Name = L"TransM";
			this->TransM->Size = System::Drawing::Size(225, 21);
			this->TransM->TabIndex = 25;
			this->TransM->TabStop = true;
			this->TransM->Text = L"Транспонировать матрицу 1";
			this->TransM->UseVisualStyleBackColor = true;
			// 
			// MultiV
			// 
			this->MultiV->AutoSize = true;
			this->MultiV->Location = System::Drawing::Point(409, 50);
			this->MultiV->Name = L"MultiV";
			this->MultiV->Size = System::Drawing::Size(277, 21);
			this->MultiV->TabIndex = 24;
			this->MultiV->TabStop = true;
			this->MultiV->Text = L"Векторное произведение векторов";
			this->MultiV->UseVisualStyleBackColor = true;
			// 
			// ScalV
			// 
			this->ScalV->AutoSize = true;
			this->ScalV->Location = System::Drawing::Point(409, 24);
			this->ScalV->Name = L"ScalV";
			this->ScalV->Size = System::Drawing::Size(276, 21);
			this->ScalV->TabIndex = 30;
			this->ScalV->TabStop = true;
			this->ScalV->Text = L"Скалярное произведение векторов";
			this->ScalV->UseVisualStyleBackColor = true;
			// 
			// MatrixSize
			// 
			this->MatrixSize->Location = System::Drawing::Point(805, 178);
			this->MatrixSize->Multiline = true;
			this->MatrixSize->Name = L"MatrixSize";
			this->MatrixSize->Size = System::Drawing::Size(61, 20);
			this->MatrixSize->TabIndex = 32;
			this->MatrixSize->TextChanged += gcnew System::EventHandler(this, &MatrixForm::textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(447, 178);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(338, 17);
			this->label2->TabIndex = 33;
			this->label2->Text = L"Введите размерность для еденичный матрицы";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(19, 47);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(305, 17);
			this->label3->TabIndex = 35;
			this->label3->Text = L"Введите число на которе нужно умножить";
			// 
			// InPutNumber
			// 
			this->InPutNumber->Location = System::Drawing::Point(336, 47);
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
			// errorResult
			// 
			this->errorResult->ContainerControl = this;
			// 
			// ResultText
			// 
			this->ResultText->Location = System::Drawing::Point(915, 707);
			this->ResultText->Multiline = true;
			this->ResultText->Name = L"ResultText";
			this->ResultText->Size = System::Drawing::Size(182, 67);
			this->ResultText->TabIndex = 38;
			// 
			// errorMatrixSize
			// 
			this->errorMatrixSize->ContainerControl = this;
			// 
			// ChoiceAct
			// 
			this->ChoiceAct->BackColor = System::Drawing::Color::LightSeaGreen;
			this->ChoiceAct->Controls->Add(this->pictureBox1);
			this->ChoiceAct->Controls->Add(this->label3);
			this->ChoiceAct->Controls->Add(this->InPutNumber);
			this->ChoiceAct->Controls->Add(this->label2);
			this->ChoiceAct->Controls->Add(this->MatrixSize);
			this->ChoiceAct->Controls->Add(this->ScalV);
			this->ChoiceAct->Controls->Add(this->CreateMV);
			this->ChoiceAct->Controls->Add(this->CreateM1);
			this->ChoiceAct->Controls->Add(this->OprM);
			this->ChoiceAct->Controls->Add(this->TransM);
			this->ChoiceAct->Controls->Add(this->MultiV);
			this->ChoiceAct->Controls->Add(this->SubVV);
			this->ChoiceAct->Controls->Add(this->AddVV);
			this->ChoiceAct->Controls->Add(this->SubMM);
			this->ChoiceAct->Controls->Add(this->AddMM);
			this->ChoiceAct->Controls->Add(this->MultiMM);
			this->ChoiceAct->Controls->Add(this->MultiMV);
			this->ChoiceAct->Controls->Add(this->MultiNumber);
			this->ChoiceAct->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ChoiceAct->Location = System::Drawing::Point(4, 485);
			this->ChoiceAct->Name = L"ChoiceAct";
			this->ChoiceAct->Size = System::Drawing::Size(886, 241);
			this->ChoiceAct->TabIndex = 39;
			this->ChoiceAct->TabStop = false;
			this->ChoiceAct->Text = L"Действие";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(706, 13);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(170, 136);
			this->pictureBox1->TabIndex = 44;
			this->pictureBox1->TabStop = false;
			// 
			// errorChoiceAct
			// 
			this->errorChoiceAct->ContainerControl = this;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(28, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 16);
			this->label1->TabIndex = 40;
			this->label1->Text = L"Матрица 1";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(353, 20);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(84, 16);
			this->label5->TabIndex = 41;
			this->label5->Text = L"Матрица 2";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(682, 20);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(72, 16);
			this->label6->TabIndex = 42;
			this->label6->Text = L"Вектор 1";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(1008, 20);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(72, 16);
			this->label7->TabIndex = 43;
			this->label7->Text = L"Вектор 2";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(671, 748);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(237, 16);
			this->label8->TabIndex = 44;
			this->label8->Text = L"Вывод, для не табличных значений";
			// 
			// MatrixForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(1306, 786);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ChoiceAct);
			this->Controls->Add(this->ResultText);
			this->Controls->Add(this->Execute);
			this->Controls->Add(this->label4);
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
			this->Text = L"Матричный калькулятор";
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorResult))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorMatrixSize))->EndInit();
			this->ChoiceAct->ResumeLayout(false);
			this->ChoiceAct->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorChoiceAct))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}


// Фукнции для проверки
		// Функция для проверки матрицы 1
		bool checkMatr1() {
			int num;
			bool flag = true;
			for (int i = 0; i < Matrix1->RowCount; i++) {
				for (int j = 0; j < Matrix1->ColumnCount; j++) {
					bool res = Int32::TryParse(System::Convert::ToString(Matrix1->Rows[i]->Cells[j]->Value), num);
					if (!res) {
						Matrix1->Rows[i]->Cells[j]->Value = "";
						flag = false;
					}
				}
			}
			if (!flag) return 0;
			else return 1;
		}
		//
		
		// Функция для проверки матрицы 1
		bool checkMatr2() {
			int num;
			bool flag = true;
			for (int i = 0; i < Matrix2->RowCount; i++) {
				for (int j = 0; j < Matrix2->ColumnCount; j++) {
					bool res = Int32::TryParse(System::Convert::ToString(Matrix2->Rows[i]->Cells[j]->Value), num);
					if (!res) {
						Matrix2->Rows[i]->Cells[j]->Value = "";
						flag = false;
					}
				}
			}
			if (!flag) return 0;
			else return 1;
		}//

		// Функция для проверки вектора 1
		bool checkVect1() {
			int num;
			bool flag = true;
			for (int i = 0; i < Vector1->RowCount; i++) {
				for (int j = 0; j < Vector1->ColumnCount; j++) {
					bool res = Int32::TryParse(System::Convert::ToString(Vector1->Rows[i]->Cells[j]->Value), num);
					if (!res) {
						Vector1->Rows[i]->Cells[j]->Value = "";
						flag = false;
					}
				}
			}
			if (!flag) return 0;
			else return 1;
		}//

		// Функция для проверки вектора 2
		bool checkVect2() {
			int num;
			bool flag = true;
			for (int i = 0; i < Vector2->RowCount; i++) {
				for (int j = 0; j < Vector2->ColumnCount; j++) {
					bool res = Int32::TryParse(System::Convert::ToString(Vector2->Rows[i]->Cells[j]->Value), num);
					if (!res) {
						Vector2->Rows[i]->Cells[j]->Value = "";
						flag = false;
					}
				}
			}
			if (!flag) return 0;
			else return 1;
		}//

		// Функции для поиска определителя для матрицы 1
		void GetMatrix(int** mas, int** p, int i, int j, int m) {
			int di = 0;
			int dj;
			for (int ki = 0; ki < m - 1; ki++) { // проверка индекса строки   
				if (ki == i)
					di = 1;
				dj = 0;
				for (int kj = 0; kj < m - 1; kj++) { // проверка индекса столбца
					if (kj == j)
						dj = 1;
					p[ki][kj] = mas[ki + di][kj + dj];
				}
			}
		}
		int Det(int** mas, int m) {
			int** p = new int* [m];
			for (int i = 0; i < m; i++)
				p[i] = new int[m];
			int d = 0;
			int k = 1;
			int n = m - 1;

			if (m == 1) {
				d = mas[0][0];
				return (d);
			}
			if (m == 2) {
				d = mas[0][0] * mas[1][1] - (mas[1][0] * mas[0][1]);
				return(d);
			}
			if (m > 2) {
				for (int i = 0; i < m; i++) {
					GetMatrix(mas, p, i, 0, m);
					d = d + k * mas[i][0] * Det(p, n);
					k = -k;
				}
				return(d);
			}
		}
		//


//

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
	

	this->Vector1->ColumnCount = 1;
	this->Vector1->Rows->Add(1);

	if (this->Vector1->Rows->Count > 0) {
		errorV1->SetError(Vector1, "");
	}


}	//

	// Удаление строки
private: System::Void DeleteStringV_Click(System::Object^ sender, System::EventArgs^ e) {


	// Проверка на наличие строк
	if (this->Vector1->Rows->Count == 0) {
		errorV1->SetError(Vector1, " Что бы удалить строку, нужно в начале добавить ее "); //  Установка ошибки, если нет строк
		return;
	}

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


	// Проверка на наличие строк
	if (this->Vector2->Rows->Count == 0) {
		errorV2->SetError(Vector2, " Что бы удалить строку, нужно в начале добавить ее "); //  Установка ошибки, если нет строк
		return;
	}

	// Удаление
	if (!this->Vector2->CurrentRow->IsNewRow) {
		int i = this->Vector2->CurrentRow->Index;
		this->Vector2->Rows->Remove(this->Vector2->Rows[i]);
	}
}	//
//



// Вычислить

private: System::Void Execute_Click(System::Object^ sender, System::EventArgs^ e) {

	int X;
	int N;
	bool resX = Int32::TryParse(this->InPutNumber->Text, X);
	bool resN = Int32::TryParse(this->MatrixSize->Text, N);

	int n = 0;

	if (MultiNumber->Checked) n = 1;
	else if (MultiMV->Checked) n = 2;
	else if (MultiMM->Checked) n = 3;
	else if (AddMM->Checked) n = 4;
	else if (SubMM->Checked) n = 5;
	else if (AddVV->Checked) n = 6;
	else if (SubVV->Checked) n = 7;
	else if (ScalV->Checked) n = 8;
	else if (MultiV->Checked) n = 9;
	else if (TransM->Checked) n = 10;
	else if (OprM->Checked) n = 11;
	else if (CreateMV->Checked) n = 12;
	else if (CreateM1->Checked) n = 13;

	switch (n)
	{
		// Умножить матрицу 1 на число
	case 1: {
		// Обработка неккоректных данных в таблице
		if (this->Matrix1->RowCount == 0) {
			errorM1->SetError(Matrix1, " Пустая таблица. Нужно создать стоблцы и строки ");
			return;
		}
		else if (!resX) {
			errorInPut->SetError(InPutNumber, "Введено не число");
		}
		else if (!checkMatr1()) {
			errorM1->SetError(Matrix1, "В таблице есть не числа");
		}
		else {
			Result->RowCount = Matrix1->RowCount;
			Result->ColumnCount = Matrix1->ColumnCount;

			for (int i = 0; i < Result->RowCount; i++) {
				for (int j = 0; j < Result->ColumnCount; j++) {
					int tmp = System::Convert::ToInt32(Matrix1->Rows[i]->Cells[j]->Value) * X;
					Result->Rows[i]->Cells[j]->Value = System::Convert::ToString(tmp);
				}
			}
		}
		break;
	}//


		  // Умножить матрицу 1 на ветокр 1
	case 2: {
		// Обработка неккоректных данных в таблице
		if (this->Matrix1->RowCount == 0) {
			errorM1->SetError(Matrix1, " Пустая таблица. Нужно создать стоблцы и строки ");
			return;
		}
		else if (this->Vector1->RowCount == 0) {
			errorV1->SetError(Vector1, " Пустая таблица. Нужно создать строки ");
			return;
		}

		else if (Matrix1->RowCount != Vector1->RowCount) {
			errorResult->SetError(Result, "Несоответствие размеров");
			return;
		}

		else if (!checkMatr1()) {
			errorM1->SetError(Matrix1, "В таблице есть не числа");
		}

		else if (!checkVect1()) {
			errorV1->SetError(Vector1, "В векторе есть не числа");
		}

		else {
			Result->RowCount = Vector1->RowCount;
			Result->ColumnCount = Vector1->ColumnCount;

			for (int i = 0; i < Result->RowCount; i++) {
				for (int j = 0; j < Result->ColumnCount; j++) {
					int tmp = 0;
					for (int k = 0; k < Result->RowCount; k++) {
						tmp += System::Convert::ToInt32(Matrix1->Rows[i]->Cells[k]->Value) * System::Convert::ToInt32(Vector1->Rows[k]->Cells[j]->Value);
					}
					Result->Rows[i]->Cells[j]->Value = System::Convert::ToString(tmp);
				}
			}
		}
		break;
	}//

		  // Умножить матрицу 1 на матрицу 2
	case 3: {
		if (this->Matrix1->RowCount == 0) {
			errorM1->SetError(Matrix1, " Пустая таблица. Нужно создать стоблцы и строки ");
			return;
		}
		if (this->Matrix2->RowCount == 0) {
			errorM2->SetError(Matrix2, " Пустая таблица. Нужно создать стоблцы и строки ");
			return;
		}
		else if (Matrix1->ColumnCount != Matrix2->RowCount) {
			errorResult->SetError(Result, "Несоответствие размеров");
			return;
		}
		else if (!checkMatr1()) {
			errorM1->SetError(Matrix1, "В таблице есть не числа");
		}
		else if (!checkMatr2()) {
			errorM2->SetError(Matrix2, "В таблице есть не числа");
		}
		else {
			Result->RowCount = Matrix1->RowCount;
			Result->ColumnCount = Matrix2->ColumnCount;

			for (int i = 0; i < Result->RowCount; i++) {
				for (int j = 0; j < Matrix2->ColumnCount; j++) {
					int tmp = 0;
					for (int k = 0; k < Matrix2->RowCount; k++) {
						tmp += System::Convert::ToInt32(Matrix1->Rows[i]->Cells[k]->Value) * System::Convert::ToInt32(Matrix2->Rows[k]->Cells[j]->Value);
					}
					Result->Rows[i]->Cells[j]->Value = System::Convert::ToString(tmp);
				}
			}
		}
		break;
	}//

		  // Сложить матрицу 1 и матрицу 2
	case 4: {
		if (this->Matrix1->RowCount == 0) {
			errorM1->SetError(Matrix1, " Пустая таблица. Нужно создать стоблцы и строки ");
			return;
		}
		if (this->Matrix2->RowCount == 0) {
			errorM2->SetError(Matrix2, " Пустая таблица. Нужно создать стоблцы и строки ");
			return;
		}
		else if (Matrix1->ColumnCount != Matrix2->RowCount) {
			errorResult->SetError(Result, "Несоответствие размеров");
			return;
		}
		else if (!checkMatr1()) {
			errorM1->SetError(Matrix1, "В таблице есть не числа");
		}
		else if (!checkMatr2()) {
			errorM2->SetError(Matrix2, "В таблице есть не числа");
		}
		else {
			Result->RowCount = Matrix1->RowCount;
			Result->ColumnCount = Matrix1->ColumnCount;

			for (int i = 0; i < Result->RowCount; i++) {
				for (int j = 0; j < Result->ColumnCount; j++) {
					Result->Rows[i]->Cells[j]->Value = System::Convert::ToString(System::Convert::ToInt32(Matrix1->Rows[i]->Cells[j]->Value) + System::Convert::ToInt32(Matrix2->Rows[i]->Cells[j]->Value));
				}
			}
		}
		break;
	}//

		  //вычесть из первой матрицы вторую матрицу
	case 5: {
		if (this->Matrix1->RowCount == 0) {
			errorM1->SetError(Matrix1, " Пустая таблица. Нужно создать стоблцы и строки ");
			return;
		}
		if (this->Matrix2->RowCount == 0) {
			errorM2->SetError(Matrix2, " Пустая таблица. Нужно создать стоблцы и строки ");
			return;
		}
		else if (Matrix1->ColumnCount != Matrix2->RowCount) {
			errorResult->SetError(Result, "Несоответствие размеров");
			return;
		}
		else if (!checkMatr1()) {
			errorM1->SetError(Matrix1, "В таблице есть не числа");
		}
		else if (!checkMatr2()) {
			errorM2->SetError(Matrix2, "В таблице есть не числа");
		}
		else {
			Result->RowCount = Matrix1->RowCount;
			Result->ColumnCount = Matrix1->ColumnCount;

			for (int i = 0; i < Result->RowCount; i++) {
				for (int j = 0; j < Result->ColumnCount; j++) {
					Result->Rows[i]->Cells[j]->Value = System::Convert::ToString(System::Convert::ToInt32(Matrix1->Rows[i]->Cells[j]->Value) - System::Convert::ToInt32(Matrix2->Rows[i]->Cells[j]->Value));
				}
			}
		}
		break;
	}//

		  // Сложить вектор 1 и вектор 2
	case 6: {
		if (this->Vector1->RowCount == 0) {
			errorV1->SetError(Vector1, " Пустая таблица. Нужно создать строки ");
			return;
		}

		if (this->Vector2->RowCount == 0) {
			errorV1->SetError(Vector2, " Пустая таблица. Нужно создать строки ");
			return;
		}

		else if (Vector1->RowCount != Vector2->RowCount) {
			errorResult->SetError(Result, "Несоответствие размеров");
			return;
		}
		else if (!checkVect1()) {
			errorV1->SetError(Vector1, "В векторе есть не числа");
		}
		else if (!checkVect2()) {
			errorV2->SetError(Vector2, "В векторе есть не числа");
		}
		else {
			Result->RowCount = Vector1->RowCount;
			Result->ColumnCount = Vector1->ColumnCount;

			for (int i = 0; i < Result->RowCount; i++) {
				for (int j = 0; j < Result->ColumnCount; j++) {
					Result->Rows[i]->Cells[j]->Value = System::Convert::ToString(System::Convert::ToInt32(Vector1->Rows[i]->Cells[j]->Value) + System::Convert::ToInt32(Vector2->Rows[i]->Cells[j]->Value));
				}
			}
		}
		break;
	}//

		  // Вычесть вектор 2 из  вектора 1
	case 7: {
		if (this->Vector1->RowCount == 0) {
			errorV1->SetError(Vector1, " Пустая таблица. Нужно создать строки ");
			return;
		}

		if (this->Vector2->RowCount == 0) {
			errorV1->SetError(Vector2, " Пустая таблица. Нужно создать строки ");
			return;
		}

		else if (Vector1->RowCount != Vector2->RowCount) {
			errorResult->SetError(Result, "Несоответствие размеров");
			return;
		}
		else if (!checkVect1()) {
			errorV1->SetError(Vector1, "В векторе есть не числа");
		}
		else if (!checkVect2()) {
			errorV2->SetError(Vector2, "В векторе есть не числа");
		}
		else {
			Result->RowCount = Vector1->RowCount;
			Result->ColumnCount = Vector1->ColumnCount;

			for (int i = 0; i < Result->RowCount; i++) {
				for (int j = 0; j < Result->ColumnCount; j++) {
					Result->Rows[i]->Cells[j]->Value = System::Convert::ToString(System::Convert::ToInt32(Vector1->Rows[i]->Cells[j]->Value) - System::Convert::ToInt32(Vector2->Rows[i]->Cells[j]->Value));
				}
			}
		}
		break;
	}//

		  // Скалярное произведение
	case 8: {
		if (this->Vector1->RowCount == 0) {
			errorV1->SetError(Vector1, " Пустая таблица. Нужно создать строки ");
			return;
		}

		if (this->Vector2->RowCount == 0) {
			errorV1->SetError(Vector2, " Пустая таблица. Нужно создать строки ");
			return;
		}

		else if (Vector1->RowCount != Vector2->RowCount) {
			errorResult->SetError(Result, "Несоответствие размеров");
			return;
		}
		else if (!checkVect1()) {
			errorV1->SetError(Vector1, "В векторе есть не числа");
		}
		else if (!checkVect2()) {
			errorV2->SetError(Vector2, "В векторе есть не числа");
		}
		else {
			ResultText->Text = "Скалярное произведение векторов:";
			int skal = 0;

			for (int i = 0; i < Vector1->RowCount; i++) {
				for (int j = 0; j < Vector1->ColumnCount; j++) {
					skal += System::Convert::ToInt32(Vector1->Rows[i]->Cells[j]->Value) * System::Convert::ToInt32(Vector2->Rows[i]->Cells[j]->Value);
				}
			}
			ResultText->Text += "\r\n" + System::Convert::ToString(skal);
		}
		break;
	}//

		  // Вектороное произведение
	case 9: {
		if (this->Vector1->RowCount == 0) {
			errorV1->SetError(Vector1, " Пустая таблица. Нужно создать строки ");
			return;
		}

		if (this->Vector2->RowCount == 0) {
			errorV1->SetError(Vector2, " Пустая таблица. Нужно создать строки ");
			return;
		}

		else if (Vector1->RowCount != Vector2->RowCount) {
			errorResult->SetError(Result, "Несоответствие размеров");
			return;
		}
		else if (!checkVect1()) {
			errorV1->SetError(Vector1, "В векторе есть не числа");
		}
		else if (!checkVect2()) {
			errorV2->SetError(Vector2, "В векторе есть не числа");
		}
		else {
			ResultText->Text = "Векторное произведение векторов:" + "\r\n";

			int line = 3; int col = 3;
			int** mas = new int* [line];
			for (int i = 0; i < col; i++)
				mas[i] = new int[col];

			for (int i = 0; i < line; i++) {
				for (int j = 0; j < col; j++) {
					mas[i][j] = 1;
				}
			}
			for (int i = 0; i < col; i++) {
				mas[1][i] = System::Convert::ToInt32(Vector1->Rows[i]->Cells[0]->Value);
			}
			for (int i = 0; i < col; i++) {
				mas[2][i] = System::Convert::ToInt32(Vector2->Rows[i]->Cells[0]->Value);
			}

			int I = mas[1][1] * mas[2][2] - mas[1][2] * mas[2][1];
			int J = mas[1][0] * mas[2][2] - mas[1][2] * mas[2][0];
			int K = mas[1][0] * mas[2][1] - mas[1][1] * mas[2][0];

			ResultText->Text += System::Convert::ToString(I) + "i " + System::Convert::ToString(J) + "j " + System::Convert::ToString(K) + "k ";
		}
		break;
	}//

		  // Транспонировать матрицу
	case 10: {
		if (this->Matrix1->RowCount == 0) {
			errorM1->SetError(Matrix1, " Пустая таблица. Нужно создать стоблцы и строки ");
			return;
		}	
		else if (Matrix1->ColumnCount != Matrix2->RowCount) {
			errorResult->SetError(Result, "Несоответствие размеров");
			return;
		}
		else if (!checkMatr1()) {
			errorM1->SetError(Matrix1, "В таблице есть не числа");
		}
	
		else {
			Result->RowCount = Matrix1->ColumnCount;
			Result->ColumnCount = Matrix1->RowCount;

			for (int i = 0; i < Result->RowCount; i++) {
				for (int j = 0; j < Result->ColumnCount; j++) {
					Result->Rows[i]->Cells[j]->Value = Matrix1->Rows[j]->Cells[i]->Value;
				}
			}
		}
		break;
	}//

		   // Определитель и ранг матрицы 1
	case 11: {
		if (this->Matrix1->RowCount == 0) {
			errorM1->SetError(Matrix1, " Пустая таблица. Нужно создать стоблцы и строки ");
			return;
		}

		else if (Matrix1->RowCount != Matrix1->ColumnCount) {
			errorM1->SetError(Matrix1, "Матрица должна быть квадратная");
			return;
		}
		else if (!checkMatr1()) {
			errorM1->SetError(Matrix1, "В таблице есть не числа");
		}
		else {
			ResultText->Text = "Определитель матрицы: ";
			int opred = 0;
			int line = Matrix1->RowCount;
			int** mas = new int* [line];
			for (int i = 0; i < line; i++)
				mas[i] = new int[line];

			for (int i = 0; i < line; i++) {
				for (int j = 0; j < line; j++) {
					mas[i][j] = System::Convert::ToInt32(Matrix1->Rows[i]->Cells[j]->Value);
				}
			}

			opred = Det(mas, line);
			ResultText->Text += System::Convert::ToString(opred) + "\r\n";

			int rank = line;
			for (int row = 0; row < rank; row++) {
				if (mas[row][row]) {
					for (int col = 0; col < line; col++) {
						if (col != row) {
							double mlt = (double)mas[col][row] / mas[row][row];
							for (int i = 0; i < rank; i++)
								mas[col][i] -= mlt * mas[row][i];
						}
					}
				}
				else {
					bool flag = true;
					for (int i = row + 1; i < line; i++) {
						if (mas[i][row]) {
							// свапаем(mas, row, i, rank);
							for (int ii = 0; ii < rank; ii++) {
								int tmp = mas[row][ii];
								mas[row][ii] = mas[i][ii];
								mas[i][ii] = tmp;
							}
							//
							flag = false;
							break;
						}
					}
					if (flag) {
						rank--;
						for (int i = 0; i < line; i++)
							mas[i][row] = mas[i][rank];
					}
					row--;
				}
			}

			ResultText->Text += "Ранг матрицы: " + System::Convert::ToString(rank);
		}
		break;
	}//

		   // Создание матрицы 1 как набора векторов
	case 12: {
		
		if (this->Vector1->RowCount == 0) {
			errorV1->SetError(Vector1, " Пустая таблица. Нужно создать строки ");
			return;
		}

		if (this->Vector2->RowCount == 0) {
			errorV1->SetError(Vector2, " Пустая таблица. Нужно создать строки ");
			return;
		}

		else if (Vector1->RowCount != Vector2->RowCount) {
			errorResult->SetError(Result, "Несоответствие размеров");
			return;
		}
		else if (!checkVect1()) {
			errorV1->SetError(Vector1, "В векторе есть не числа");
		}
		else if (!checkVect2()) {
			errorV2->SetError(Vector2, "В векторе есть не числа");
		}

		else {
			Result->RowCount = Vector1->RowCount;
			Result->ColumnCount = 2;
			for (int i = 0; i < Result->RowCount; i++) {
				Result->Rows[i]->Cells[0]->Value = Vector1->Rows[i]->Cells[0]->Value;
				Result->Rows[i]->Cells[1]->Value = Vector2->Rows[i]->Cells[0]->Value;
			}
		}
		break;
	}//

		   // Создание еденичной матрицы
	case 13: {
		
		if (!resN)
			errorMatrixSize->SetError(MatrixSize, "Введено не число");
		else {
			if (N <= 0)
				errorMatrixSize->SetError(MatrixSize, "Количество строк должно быть положительным и отличным от нуля");
			else if (N > 20)
				errorMatrixSize->SetError(MatrixSize, "Введите меньший размер матрицы");
			else {
				Result->RowCount = N;
				Result->ColumnCount = N;
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						if (i == j) {
							Result->Rows[i]->Cells[j]->Value = 1;
						}
						else {
							Result->Rows[i]->Cells[j]->Value = 0;
						}
					}
				}
			}
		}
		break;
	}
	default:
		if (n == 0) {
			errorChoiceAct->SetError(ChoiceAct, " Нужно выбрать действие");
			return;
		}
		break;
	}//

}	

//


};
}
