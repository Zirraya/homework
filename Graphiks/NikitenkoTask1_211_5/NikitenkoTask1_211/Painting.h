#pragma once


namespace NikitenkoTask1211 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics; 
	using namespace std;


	vec3 Vc; // ���������� �������� ������ ������� ����
	vec3 V; // ������� ��������������� � ������������ �������
	vec3 Vc_work, V_work; // ������� ��������� ���������������

	mat4 T; // �������, � ������� ������������� ��� ��������������
	mat4 initT; // ������� ���������� ��������������

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
			  float Wx_work, Wy_work; // ������ � ������ ������� ������ ����� ����� �������
			  float Wx_part = 0.6, Wy_part = 0.6; // ���� Wx_work, Wy_work �� Wx, Wy ��������������
			  float Wcx_work, Wcy_work; // ���������� ������ ������� �
			  float Wz_work; // ���������� ������� ���������������
			  int numXsect = 5, numYsect = 5, numZsect = 5; // ���������� ������ ������������ ����� �� ����


	private: System::Void rectCalc() {
		maxX = ClientRectangle.Width - right; // �������� ��������� ��������� x
		maxY = ClientRectangle.Height - bottom; // �������� ��������� ��������� y
		Wcy = maxY; // ���������� ������ ������� ���� ��������������
		Wx = maxX - left; // ������ ��������������
		Wy = maxY - top; // ������ � ������ ��������������

		Wx_work = Wx_part * Wx; // ���������� ������ � ������
		Wy_work = Wy_part * Wy; // �������� ��������������
		Wcx_work = maxX - Wx_work; // ���������� ��������� ������� ������
		Wcy_work = minY + Wy_work; // ���� ������ �������� �������� ��������������
		Wz_work = Wcy - Wcy_work; // ���������� ������� ���������������

	}

	private: System::Void worldRectCalc() {
		Vc_work = normalize(T * vec4(Vc, 1.f));
		V_work = mat3(T) * V;

	}

		 private: float f(float x, float z) 
		 {
			 return x * sin(sqrtf(x * x + z * z));
		 }

		private: bool f_exists(float x, float z, float delta) 
		{
			return true;
		}




	private: System::Void Painting_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

		Graphics^ g = e->Graphics;
		g->Clear(Color::PowderBlue);

		Pen^ rectPen = gcnew Pen(Color::Black, 2);
		g->DrawRectangle(rectPen, left, top, Wx, Wy);	


		// ������������ ������������ �����
		 Pen ^ gridPen = gcnew Pen(Color::Black, 1);
		 SolidBrush ^ drawBrush = gcnew SolidBrush(Color::Black);
		 System::Drawing::Font ^ drawFont = gcnew System::Drawing::Font("Arial", 8);
		
			 // ������������ ����� �� x
			 float gridStep_x = Wx_work / numXsect; // ���������� ����� ������� ����� �� x
		 float grid_dX = V_work.x / numXsect; // ���������� ����� ������� ����� �� x � ������� �����������
		 float tick_x = Vc_work.x; // ��������, ��������������� ������ ����� �����
		 for (int i = 0; i <= numXsect; i++) { // ���� �� ���������� �����
			 float tmpXCoord_d = Wcx + i * gridStep_x; // ������ ���������� x i-� ������������ �����
			 float tmpXCoord_v = Wcx_work + i * gridStep_x; // ���������� x i-� ������������ �����
			 // i-� ������������ �����
				 g->DrawLine(gridPen, tmpXCoord_d, Wcy, tmpXCoord_v, Wcy_work);
			 // i-� ������������ �����
				 g->DrawLine(gridPen, tmpXCoord_v, Wcy_work, tmpXCoord_v, minY);
			 if (i > 0 && i < numXsect) // ���� ����� �� �������
				 // ������� ����� � ������ ����� ������������ �����
				 g->DrawString(tick_x.ToString("F4"), drawFont, drawBrush, tmpXCoord_d, Wcy);
			 tick_x += grid_dX; // ��������� ��������, ��������������� ��������� �����
			
		}
		
			 // ������������ ����� �� z
			 gridStep_x = (Wx - Wx_work) / numZsect; // ���������� ����� ������������� ������� ����� �� �����������
		 float gridStep_y = Wz_work / numZsect; // ���������� ����� ��������������� ������� ����� �� ���������
		 float grid_dZ = V_work.z / numZsect; // ���������� ����� ������� ����� �� $z$ � ������� �����������
		 float tick_z = Vc_work.z; // ��������, ��������������� ������ ����� �����
		 for (int i = 0; i <= numZsect; i++) { // ���� �� ���������� �����
			 float tmpXCoord_v = Wcx_work - i * gridStep_x; // ���������� x ������������ �����
			 float tmpYCoord_g = Wcy_work + i * gridStep_y; // ���������� y �������������� �����
			 float tmpXCoord_g = tmpXCoord_v + Wx_work; // ������ ���������� x �������������� �����
			 // i-� ������������ �����
				 g->DrawLine(gridPen, tmpXCoord_v, tmpYCoord_g, tmpXCoord_v, tmpYCoord_g - Wy_work);
			 // i-� �������������� �����
				 g->DrawLine(gridPen, tmpXCoord_v, tmpYCoord_g, tmpXCoord_g, tmpYCoord_g);
			 if (i > 0 && i < numZsect) // ���� ����� �� �������
				 // ������� ����� � ������ ����� �������������� �����
				 g->DrawString(tick_z.ToString("F4"), drawFont, drawBrush, tmpXCoord_g, tmpYCoord_g);
			 tick_z += grid_dZ; // ��������� ��������, ��������������� ��������� �����
			
		}





		// ��������� �������
		 Pen ^ pen = gcnew Pen(Color::Blue, 1);
		 float deltaX = V_work.x / Wx_work; // ��� �� x � ������� �����������
		 float deltaZ = V_work.z / Wz_work; // ��� �� z � ������� �����������
		
			
			 float deltaWcx = (Wcx_work - Wcx) / Wz_work; // ��� ��������������� �� x � ����������� ������
		
			 bool hasStart;
		
			 // ���� �� ���������������
			 float z = Vc_work.z; // ���������� z ��������������� �������� ��������������
		 // ���������� ������ ������� ���� �������� �������������� (�������������)
			 float Wcx_w = Wcx_work, Wcy_w = Wcy_work;
		 while (Wcy_w <= Wcy) { // ���� �� ��������� ��� ��������������
			 vec2 start, end; // ����� ������� � ����������� ������
			 float x, y; // ���������� ��� ��������� ����� � ������� ��
			 start.x = Wcx_w; // ��� ��������� ����� ������� ������� ������������� ���������� x
			 x = Vc_work.x; // ���������� x ��������� ����� ������� ������� � ������� �����������
			 hasStart = f_exists(x, z, deltaX);
			 if (hasStart) {
				 y = f(x, z); // ���������� y ��������� ����� � ������� �����������
				 // ��������� ��������������� �������� � ����������� ������
					 start.y = Wcy_w - (y - Vc_work.y) / V_work.y * Wy_work;
				
			}
			 float maxX = Wcx_w + Wx_work; // ������������ �������� x � ������� ��������������
			 while (start.x < maxX) {
				 vec2 end; // ����� ����� ������� � ����������� ������
				 bool hasEnd;
				 float deltaY; // ������ ����� � �������������� (���� ����� ������)
				 float red, green, blue; // ���������� ����� �������
				 end.x = start.x + 1.f; // ���������� x ���������� �� �������
				 x += deltaX; // ���������� x �������� ����� ������� � ������� �����������
				 hasEnd = f_exists(x, z, deltaX);
				 if (hasEnd) {
					 y = f(x, z); // ���������� y ��������� ����� � ������� �����������
					 // ��������� ��������������� �������� � ����������� ������
						 deltaY = (y - Vc_work.y) / V_work.y;
					 end.y = Wcy_w - deltaY * Wy_work;
					
				}
				 vec2 tmpEnd = end;
				 bool visible = hasStart && hasEnd && clip(start, end, minX, minY, maxX, maxY);
				 if (visible) { // ���� ������� �����
					 // ����� ���������, start � end - ����� ������� ����� �������
						 // ���������� ����� �������
						 if (deltaY > 1.f) deltaY = 1.f; // ����������� �������� ������ �����
					 if (deltaY < 0.f) deltaY = 0.f; // �� ������, ���� ������� ���������
					 green = 510.f * deltaY; // ��������������� ���������� ������������
					 if (deltaY < 0.5) { // ���� ����� ���� �������� ������� ���������
						 // ���������� �������� ��� ���������
							 blue = 255.f - green; // ����� ��������� �������
						 red = 0.f; // ������� ����� ����
						
					}
					 else { // ���� ����� �� ���� ��������
						 blue = 0.f; // ����� ����� ����
						 red = green - 255.f; // ��������� ������� � �������
						 green = 510.f - green; // � �������������� ������������ ������������
						
					}
					 pen->Color = Color::FromArgb(red, green, blue); // ������ ���� ����
					 // ��������� �������
						 g->DrawLine(pen, start.x, start.y, end.x, end.y); // ��������� ������� ������
					
				}
				 // �������� ����� ������������� ������� ���������� ��������� ������ ����������
					 start = tmpEnd;
				 hasStart = hasEnd;
				
			}
			 Wcy_w += 1.f; // ��������� � ���������� ��������������, �� ����� ���� �� ���� ������
			 Wcx_w -= deltaWcx; // � ����� �� ��������� ��������
			 z += deltaZ; // ��������� ��������������� �������� z ��� ���������� ��������������
			
		}


	}
	private: System::Void Painting_Resize(System::Object^ sender, System::EventArgs^ e) {
		rectCalc();
		Refresh();
	}

	private: System::Void Painting_Load(System::Object^ sender, System::EventArgs^ e) {
		initT = mat4(1.f);
		T = initT;

		Vc = vec3(-2.f, -2.f, -2.f);
		V = vec3(4.f, 4.f, 4.f);


		rectCalc();
		worldRectCalc();

	}
	private: System::Void Painting_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		float centerX = Vc_work.x + V_work.x / 2; // ���������� ������ ���������������
		float centerY = Vc_work.y + V_work.y / 2; // � ������� ������� ���������
		float centerZ = Vc_work.z + V_work.z / 2;


		float Wcx = ClientRectangle.Width / 2.f; // ���������� ������
		float Wcy = ClientRectangle.Height / 2.f; // �������� ����



		switch (e->KeyCode) {

		case Keys::Escape:
			T = initT;
			break;

		case Keys::A:
			T = translate(-V_work.x / Wx, 0.f, 0.f) * T; // ����� ������� ������ �� ����, ������
			break;

		case Keys::Z:
			T = translate(-centerX, -centerY, -centerZ) * T; // ������� ������ ��������� � �����
			T = scale(1.1, 1.1, 1.1) * T; // ��������������� ������������ ������ ���������
			T = translate(centerX, centerY, centerZ) * T; // ������� ������� ������ ���������
			break;

		}
		worldRectCalc();
		Refresh();
	}
	private: System::Void btnOpen_Click(System::Object^ sender, System::EventArgs^ e) {

		//if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		//	 // � �������� ������� ������ ������ OK
		//		 // ���������� ����� ����� �� openFileDialog->FileName � fileName
		//		 wchar_t fileName[1024]; // ����������, � ������� ����������� �������� ��� �����
		//	 for (int i = 0; i < openFileDialog->FileName->Length; i++)
		//		 fileName[i] = openFileDialog->FileName[i];
		//	 fileName[openFileDialog->FileName->Length] = '\0';
		//	
		//		 // ���������� � �������� �����
		//		 ifstream in;
		//	 in.open(fileName);
		//	 if (in.is_open()) {
		//		
		//			 // ���� ������� ������
		//		 models.clear(); // ������� ��������� ������ ��������
		//		 // ��������� ���������� ��� ������ �� �����

		//		 mat3 M = mat3(1.f); // ������� ��� ��������� ��������� �������
		//		 mat3 initM; // ������� ��� ���������� �������������� ������� �������
		//		 vector<mat3> transforms; // ���� ������ ��������������
		//		 vector<path> figure; // ������ ������� ���������� �������

		//		float thickness = 2; // ������� �� ��������� �� ��������� 2
		//		 float r, g, b; // ������������ �����
		//		 r = g = b = 0; // �������� ������������ ����� �� ��������� (������)
		//		 string cmd; // ������ ��� ���������� ����� �������
		//		 // ��������������� ������ � ������
		//			 string str; // ������, � ������� ��������� ������ �����
		//		 getline(in, str); // ��������� �� �������� ����� ������ ������
		//		 while (in) { // ���� ��������� ������ ������� �������
		//			 // ������������ ������
		//			 if ((str.find_first_not_of(" \t\r\n") != string::npos) && (str[0] != '#')) {
		//				 // ����������� ������ �� ����� � �� �����������
		//				 stringstream s(str); // ��������� ����� �� ������ str
		//				 s >> cmd;
		//				 if (cmd == "frame") { // ������� �����������

		//					 s >> Vx >> Vy; // ��������� ���������� �������� Vx � Vy

		//					 float Wx = ClientRectangle.Width - left - right; // ������ ��������������
		//					 float Wy = ClientRectangle.Height - top - bottom; // ������ ��������������
		//					 float aspectRect = Wx / Wy; // ����������� ������ ��������������
		//					 // ����������� ���������� ��� ���������� ��������� ����������� ������

		//					// �������� ������ ������� � ������� ���������
		//					 mat3 T1 = translate(-Vx / 2, -Vy / 2);
		//					 // ��������������� �������� �������, �������� ������ ��������
		//					 // ����������� ���������� ��� ���������� ��������� ����������� ������
		//					 float S = aspectFigR < aspectRect ? Wy / Vy : Wx / Vx;
		//					 mat3 S1 = scale(S, -S);
		//					 // ����� ����� �������� �� ������ ��������� � ������ �������
		//					 mat3 T2 = translate(Wx / 2 + Wcx, Wcy - Wy / 2);
		//					 // � initT ��������� ��� ��� �������������� (������ ������)
		//					 initTR = T2 * (S1 * T1);

		//					 TR = initTR;

		//				 }
		//				 else if (cmd == "color") { // ���� �����
		//					 s >> r >> g >> b; // ��������� ��� ������������ �����

		//				 }
		//				 else if (cmd == "thickness") { // ������� �����
		//					 s >> thickness; // ��������� �������� �������

		//				 }
		//				 else if (cmd == "path") { // ����� �����
		//					 vector<vec2> vertices; // ������ ����� �������
		//					 int N; // ���������� �����
		//					 s >> N;
		//					 string str1; // �������������� ������ ��� ������ �� �����
		//					 while (N > 0) { // ���� �� ��� ����� �������
		//						 getline(in, str1); // ��������� � str1 �� �������� ����� ��������� ������
		//						 // ��� ��� ���� ����������, �� �� ����� ����� ��������� �� �����
		//						 if ((str1.find_first_not_of(" \t\r\n") != string::npos) && (str1[0] != '#')) {
		//							 // ����������� ������ �� ����� � �� �����������
		//								// ������ � ��� ���� ���������
		//							 float x, y; // ���������� ��� ����������
		//							 stringstream s1(str1); // ��� ���� ��������� ����� �� ������ str1
		//							 s1 >> x >> y;
		//							 vertices.push_back(vec2(x, y)); // ��������� ����� � ������
		//							 N--; // ��������� ������� ����� ��������� ���������� �����

		//						 }

		//					 }
		//					 // ��� ����� �������, ���������� ������� (path) � ������ �� � ������ figure
		//					 figure.push_back(path(vertices, vec3(r, g, b), thickness));

		//				 }
		//				 else if (cmd == "model") { // ������ �������� ������ �������

		//					 float mVcx, mVcy, mVx, mVy; // ��������� ������� model
		//					 s >> mVcx >> mVcy >> mVx >> mVy; // ��������� �������� ����������
		//					 float S = mVx / mVy < 1 ? 2.f / mVy : 2.f / mVx;
		//					 // ����� ����� �������� �� ������ ��������� � ������ �������
		//						 // ����� �������� �������� ���������������
		//					 initM = scale(S) * translate(-mVcx, -mVcy);
		//					 figure.clear();

		//				 }
		//				 else if (cmd == "figure") { // ������������ ����� ������
		//					 models.push_back(model(figure, M * initM));

		//				 }
		//				 else if (cmd == "translate") { // �������
		//					 float Tx, Ty; // ��������� �������������� ��������
		//					 s >> Tx >> Ty; // ��������� ���������
		//					 M = translate(Tx, Ty) * M; // ��������� ������� � ������ ��������������

		//				 }
		//				 else if (cmd == "scale") { // ���������������
		//					 float S; // �������� ���������������
		//					 s >> S; // ��������� ��������
		//					 M = scale(S) * M; // ��������� ��������������� � ������ ��������������

		//				 }
		//				 else if (cmd == "rotate") { // �������
		//					 float theta; // ���� �������� � ��������
		//					 s >> theta; // ��������� ��������
		//					 M = rotate(-theta / 180.f * Math::PI) * M; // ��������� ������� � ������ ��������������

		//				 }
		//				 else if (cmd == "pushTransform") { // ���������� ������� � ����
		//					 transforms.push_back(M); // ��������� ������� � ����

		//				 }
		//				 else if (cmd == "popTransform") { // ����� � ������� �� �����
		//					 M = transforms.back(); // �������� ������� ������� �����
		//					 transforms.pop_back(); // ���������� ������� �� �����
		//				 }
		//			 }	 
		//				 // ��������� ��������� ������
		//			 // ��������� ��������� ������
		//				 getline(in, str);	
		//		}
		//		 Refresh();
		//	}
		//}
	}
};
}
