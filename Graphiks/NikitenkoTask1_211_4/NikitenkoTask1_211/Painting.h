#pragma once


namespace NikitenkoTask1211 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;


	vector<model> models;
	float VxR; // ������ ������� �� �����������
	float VyR; // ������ ������� �� ���������
	float aspectFigR; // ����������� ������ �������

	// �������, ��� 3 �������
	mat3 TR; // �������, � ������� ������������� ��� ��������������
	mat3 initTR; // ������� ���������� ��������������

	/// <summary>
	/// ������ ��� Painting
	/// </summary>
	public ref class Painting : public System::Windows::Forms::Form
	{
	public:
		Painting(void)
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
		~Painting()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
	private: System::Windows::Forms::Button^ btnOpen;
	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->btnOpen = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// openFileDialog
			// 
			this->openFileDialog->DefaultExt = L"txt";
			this->openFileDialog->Filter = L" (*.txt)|*.txt|��� ����� (*.*)|*.*";
			this->openFileDialog->Title = L"������� ����";
			// 
			// btnOpen
			// 
			this->btnOpen->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnOpen->AutoSize = true;
			this->btnOpen->Location = System::Drawing::Point(729, 12);
			this->btnOpen->Name = L"btnOpen";
			this->btnOpen->Size = System::Drawing::Size(97, 49);
			this->btnOpen->TabIndex = 0;
			this->btnOpen->Text = L"�������";
			this->btnOpen->UseVisualStyleBackColor = true;
			this->btnOpen->Click += gcnew System::EventHandler(this, &Painting::btnOpen_Click);
			// 
			// Painting
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(857, 438);
			this->Controls->Add(this->btnOpen);
			this->DoubleBuffered = true;
			this->KeyPreview = true;
			this->Name = L"Painting";
			this->Text = L"Painting";
			this->Load += gcnew System::EventHandler(this, &Painting::Painting_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Painting::Painting_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Painting::Painting_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &Painting::Painting_Resize);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: bool keepAspectRatio; // �������� - ��������� �� ����������� ������ �������?
	private: bool changeImage; // ������ �����������
	private: float left = 30, right = 100, top = 20, bottom = 50; // ���������� �� ������ ����
		   float minX = left, maxX; // �������� ��������� ��������� x
		   float minY = top, maxY; // �������� ��������� ��������� y
		   float Wcx = left, Wcy; // ���������� ������ ������� ���� ��������������
		   float Wx, Wy; // ������ � ������ ��������������

	private: System::Void rectCalc() {
		maxX = ClientRectangle.Width - right; // �������� ��������� ��������� x
		maxY = ClientRectangle.Height - bottom; // �������� ��������� ��������� y
		Wcy = maxY; // ���������� ������ ������� ���� ��������������
		Wx = maxX - left; // ������ ��������������
		Wy = maxY - top; // ������ � ������ ��������������
	}
	
	private: System::Void Painting_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

		Graphics^ g = e->Graphics;
		g->Clear(Color::PowderBlue);

		Pen^ rectPen = gcnew Pen(Color::Black, 2);
		g->DrawRectangle(rectPen, left, top, Wx, Wy);

		// ����
			 for (int k = 0; k < models.size(); k++) {
				 vector<path> figure = models[k].figure; // ������ ������� ���������� �������
				  path lines = figure[k]; // lines - ��������� ������� �����
				  mat3 TM = TR * models[k].modelM; // ������� ������ �������������� �������
				  for (int i = 0; i < figure.size(); i++) {
					   path lines = figure[i]; // lines - ��������� ������� �����
					   Pen ^ pen = gcnew Pen(Color::FromArgb(lines.color.x, lines.color.y, lines.color.z));
					   pen->Width = lines.thickness;

				  vec2 start = normalize(TM * vec3(lines.vertices[0], 1.2)); // ������ ��������� �����
				  for (int j = 1; j < lines.vertices.size(); j++) { // ���� �� �������� ������ (�� �������)
					  vec2 end = normalize(TM * vec3(lines.vertices[j], 1.2)); // �������� �����
					  vec2 tmpEnd = end; // �������������� ���������� ����� ��� �������� �������������
					  if (clip(start, end, minX, minY, maxX, maxY)) { // ���� ������� �����
						  // ����� ���������, start � end - ����� ������� ����� �������
						  g->DrawLine(pen, start.x, start.y, end.x, end.y); // ��������� ������� ������  
					  }
					  start = tmpEnd; // �������� ����� ������������� ������� ���������� ��������� ������ ����������
				  }
					 
				 }
				 
			 }	  
		//
	}
	private: System::Void Painting_Resize(System::Object^ sender, System::EventArgs^ e) {
		rectCalc();
		Refresh();
	}

	private: System::Void Painting_Load(System::Object^ sender, System::EventArgs^ e) {
		rectCalc();
	}
	private: System::Void Painting_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	
		float Wcx = ClientRectangle.Width / 2.f; // ���������� ������
		float Wcy = ClientRectangle.Height / 2.f; // �������� ����

		switch (e->KeyCode) {
		case Keys::Escape:
			TR = initTR; 
			break;
		}
		//�������� �� 0.01
		// ������� ����������� ������ ������� ������� �� 0.01 ������ ������������
		// �������� ������ ����
		switch (e->KeyCode) {
		case Keys::Q:
			TR = translate(-Wcx, -Wcy) * TR; // ������� ������ ��������� � (Wcx, Wcy)
			TR = rotate(0.01f) * TR; // ������� �� 0.01 ������ ������������
			// ������ ������
			TR = translate(Wcx, Wcy) * TR; // ������� ������ ��������� �������
			break;
		}
		// ������� ����������� �� ������� ������� �� 0.01 ������ ������������
		// �������� ������ ����
		switch (e->KeyCode){
		case Keys::E:
			TR = translate(-Wcx, -Wcy) * TR; // ������� ������ ��������� � (Wcx, Wcy)
			TR = rotate(-0.01f) * TR; // ������� �� 0.01 ������ ������������
			// ������ ������
			TR = translate(Wcx, Wcy) * TR; // ������� ������ ��������� �������
		default:
			break;
		}
		//

		//�������� �� 0.05
		// ������� ����������� ������ ������� ������� �� 0.05 ������ ������������
		// �������� ������ ����
		switch (e->KeyCode) {
		case Keys::Y:
			TR = translate(-Wcx, -Wcy) * TR; // ������� ������ ��������� � (Wcx, Wcy)
			TR = rotate(0.05f) * TR; // ������� �� 0.01 ������ ������������
			// ������ ������
			TR = translate(Wcx, Wcy) * TR; // ������� ������ ��������� �������
			break;
		}
		// ������� ����������� �� ������� ������� �� 0.05 ������ ������������
		// �������� ������ ����
		switch (e->KeyCode) {
		case Keys::R:
			TR = translate(-Wcx, -Wcy) * TR; // ������� ������ ��������� � (Wcx, Wcy)
			TR = rotate(-0.05f) * TR; // ������� �� 0.01 ������ ������������
			// ������ ������
			TR = translate(Wcx, Wcy) * TR; // ������� ������ ��������� �������
		default:
			break;
		}
		//

		// ������ ����������� �� 1 �������

		switch (e->KeyCode) {
		case Keys::W:
			TR = translate(0.f, -1.f) * TR; // ����� ����� �� ���� ������
			break;

		}

		// ����� ����������� �������������� ���� 1 ������;
		switch (e->KeyCode) {
		case Keys::S:
			TR = translate(0.f, 1.f) * TR; // ����� ���� �� ���� ������
		default:
			break;
		}

		// ����� ����������� �������������� ����� 1 ������;
		switch (e->KeyCode) {
		case Keys::A:
			TR = translate(-1.f, 0.f) * TR; // ����� ����� �� ���� ������
		default:
			break;
		}

		// ����� ����������� �������������� ������ 1 ������;
		switch (e->KeyCode) {
		case Keys::D:
			TR = translate(1.f, 0.f) * TR; // ����� ������ �� ���� ������
		default:
			break;
		}
		//



		// ����� ����������� �� 10 �������� 
		switch (e->KeyCode) {
		case Keys::T:
			TR = translate(0.f, -10.f) * TR; // ����� ����� �� ���� ������
			break;

		}

		// ����� ����������� �������������� ���� 1 ������;
		switch (e->KeyCode) {
		case Keys::G:
			TR = translate(0.f, 10.f) * TR; // ����� ���� �� ���� ������
		default:
			break;
		}

		// ����� ����������� �������������� ����� 1 ������;
		switch (e->KeyCode) {
		case Keys::F:
			TR = translate(-10.f, 0.f) * TR; // ����� ����� �� ���� ������
		default:
			break;
		}

		// ����� ����������� �������������� ������ 1 ������;
		switch (e->KeyCode) {
		case Keys::H:
			TR = translate(10.f, 0.f) * TR; // ����� ������ �� ���� ������
		default:
			break;
		}

		// ���������� ���������
		// ��������� �� ���������;
		switch (e->KeyCode) {
		case Keys::U:
			TR = translate(-Wcx, -Wcy) * TR; // ������� ������ ��������� � (Wcx, Wcy) 
			TR = mirrorX() * TR; //  �������������� ������� 
			TR = translate(Wcx, Wcy) * TR; // ������� ������ ��������� ������� 
		default:
			break;
		}

		// ��������� �� �����������;
		switch (e->KeyCode) {
		case Keys::J:
			TR = translate(-Wcx, -Wcy) * TR; // ������� ������ ��������� � (Wcx, Wcy) 
			TR = mirrorY() * TR; //  ������������ ������� 
			TR = translate(Wcx, Wcy) * TR; // ������� ������ ��������� ������� 
		default:
			break;
		}
		//

		// ����������/���������� ����������� � 1.1 ���
		// ����������
		switch (e->KeyCode) {
		case Keys::Z:
			TR = translate(-Wcx, -Wcy) * TR; // ������� ������ ��������� � (Wcx, Wcy)
			TR = scale(1.1f, 1.1f) * TR;
			TR = translate(Wcx, Wcy) * TR; // ������� ������ ��������� �������
		default:
			break;
		}

		// ����������
		switch (e->KeyCode) {
		case Keys::X:
			TR = translate(-Wcx, -Wcy) * TR; // ������� ������ ��������� � (Wcx, Wcy)
			TR = scale(1.0f / 1.1f, 1.0f / 1.1f) * TR;
			TR = translate(Wcx, Wcy) * TR; // ������� ������ ��������� �������
		default:
			break;
		}

		// ������ � ���������� �� �����������
		// ����������
		switch (e->KeyCode) {
		case Keys::I:
			TR = scale(1.1f, 1.0f) * TR;	 
		default:
			break;
		}

		// ������
		switch (e->KeyCode) {
		case Keys::K:
			TR = scale(1.0f / 1.1f, 1.0f) * TR;
		default:
			break;
		}

		//

		// ������ � ���������� �� ���������
		// ����������
		switch (e->KeyCode) {
		case Keys::O:
			TR = scale(1.0f,1.1f) * TR;
		default:
			break;
		}

		// ������
		switch (e->KeyCode) {
		case Keys::L:
			TR = scale(1.0f, 1.0f / 1.1f) * TR;
		default:
			break;
		}
		//

		//

		Refresh();
	}
	private: System::Void btnOpen_Click(System::Object^ sender, System::EventArgs^ e) {

		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			 // � �������� ������� ������ ������ OK
				 // ���������� ����� ����� �� openFileDialog->FileName � fileName
				 wchar_t fileName[1024]; // ����������, � ������� ����������� �������� ��� �����
			 for (int i = 0; i < openFileDialog->FileName->Length; i++)
				 fileName[i] = openFileDialog->FileName[i];
			 fileName[openFileDialog->FileName->Length] = '\0';
			
				 // ���������� � �������� �����
				 ifstream in;
			 in.open(fileName);
			 if (in.is_open()) {
				
					 // ���� ������� ������
				 models.clear(); // ������� ��������� ������ ��������
				 // ��������� ���������� ��� ������ �� �����

				 mat3 M = mat3(1.f); // ������� ��� ��������� ��������� �������
				 mat3 initM; // ������� ��� ���������� �������������� ������� �������
				 vector<mat3> transforms; // ���� ������ ��������������
				 vector<path> figure; // ������ ������� ���������� �������

					 float thickness = 2; // ������� �� ��������� �� ��������� 2
				 float r, g, b; // ������������ �����
				 r = g = b = 0; // �������� ������������ ����� �� ��������� (������)
				 string cmd; // ������ ��� ���������� ����� �������
				 // ��������������� ������ � ������
					 string str; // ������, � ������� ��������� ������ �����
				 getline(in, str); // ��������� �� �������� ����� ������ ������
				 while (in) { // ���� ��������� ������ ������� �������
					 // ������������ ������
					 if ((str.find_first_not_of(" \t\r\n") != string::npos) && (str[0] != '#')) {
						 // ����������� ������ �� ����� � �� �����������
						 stringstream s(str); // ��������� ����� �� ������ str
						 s >> cmd;
						 if (cmd == "frame") { // ������� �����������

							 s >> VxR >> VyR; // ��������� ���������� �������� Vx � Vy

							 float Wx = ClientRectangle.Width - left - right; // ������ ��������������
							 float Wy = ClientRectangle.Height - top - bottom; // ������ ��������������
							 float aspectRect = Wx / Wy; // ����������� ������ ��������������
							 // ����������� ���������� ��� ���������� ��������� ����������� ������

							// �������� ������ ������� � ������� ���������
							 mat3 T1 = translate(-VxR / 2, -VyR / 2);
							 // ��������������� �������� �������, �������� ������ ��������
							 // ����������� ���������� ��� ���������� ��������� ����������� ������
							 float S = aspectFigR < aspectRect ? Wy / VyR : Wx / VxR;
							 mat3 S1 = scale(S, -S);
							 // ����� ����� �������� �� ������ ��������� � ������ �������
							 mat3 T2 = translate(Wx / 2 + Wcx, Wcy - Wy / 2);
							 // � initT ��������� ��� ��� �������������� (������ ������)
							 initTR = T2 * (S1 * T1);

							 TR = initTR;

						 }
						 else if (cmd == "color") { // ���� �����
							 s >> r >> g >> b; // ��������� ��� ������������ �����

						 }
						 else if (cmd == "thickness") { // ������� �����
							 s >> thickness; // ��������� �������� �������

						 }
						 else if (cmd == "path") { // ����� �����
							 vector<vec2> vertices; // ������ ����� �������
							 int N; // ���������� �����
							 s >> N;
							 string str1; // �������������� ������ ��� ������ �� �����
							 while (N > 0) { // ���� �� ��� ����� �������
								 getline(in, str1); // ��������� � str1 �� �������� ����� ��������� ������
								 // ��� ��� ���� ����������, �� �� ����� ����� ��������� �� �����
								 if ((str1.find_first_not_of(" \t\r\n") != string::npos) && (str1[0] != '#')) {
									 // ����������� ������ �� ����� � �� �����������
										// ������ � ��� ���� ���������
									 float x, y; // ���������� ��� ����������
									 stringstream s1(str1); // ��� ���� ��������� ����� �� ������ str1
									 s1 >> x >> y;
									 vertices.push_back(vec2(x, y)); // ��������� ����� � ������
									 N--; // ��������� ������� ����� ��������� ���������� �����

								 }

							 }
							 // ��� ����� �������, ���������� ������� (path) � ������ �� � ������ figure
							 figure.push_back(path(vertices, vec3(r, g, b), thickness));

						 }
						 else if (cmd == "model") { // ������ �������� ������ �������

							 float mVcx, mVcy, mVx, mVy; // ��������� ������� model
							 s >> mVcx >> mVcy >> mVx >> mVy; // ��������� �������� ����������
							 float S = mVx / mVy < 1 ? 2.f / mVy : 2.f / mVx;
							 // ����� ����� �������� �� ������ ��������� � ������ �������
								 // ����� �������� �������� ���������������
							 initM = scale(S) * translate(-mVcx, -mVcy);
							 figure.clear();

						 }
						 else if (cmd == "figure") { // ������������ ����� ������
							 models.push_back(model(figure, M * initM));

						 }
						 else if (cmd == "translate") { // �������
							 float Tx, Ty; // ��������� �������������� ��������
							 s >> Tx >> Ty; // ��������� ���������
							 M = translate(Tx, Ty) * M; // ��������� ������� � ������ ��������������

						 }
						 else if (cmd == "scale") { // ���������������
							 float S; // �������� ���������������
							 s >> S; // ��������� ��������
							 M = scale(S) * M; // ��������� ��������������� � ������ ��������������

						 }
						 else if (cmd == "rotate") { // �������
							 float theta; // ���� �������� � ��������
							 s >> theta; // ��������� ��������
							 M = rotate(-theta / 180.f * Math::PI) * M; // ��������� ������� � ������ ��������������

						 }
						 else if (cmd == "pushTransform") { // ���������� ������� � ����
							 transforms.push_back(M); // ��������� ������� � ����

						 }
						 else if (cmd == "popTransform") { // ����� � ������� �� �����
							 M = transforms.back(); // �������� ������� ������� �����
							 transforms.pop_back(); // ���������� ������� �� �����
						 }
					 }	 
						 // ��������� ��������� ������
					 // ��������� ��������� ������
						 getline(in, str);	
				}
				 Refresh();
			}
		}
	}
};
}
