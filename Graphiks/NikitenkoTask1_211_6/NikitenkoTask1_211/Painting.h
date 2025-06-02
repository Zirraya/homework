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


	vector<model> models;
	mat4 T; // �������, � ������� ������������� ��� ��������������
	vec3 S, P, u; // ���������� ����� ����������
	// �����, � ������� ��������� ������ ����������
	// ������� ����������� �����
	float dist; // ��������������� ���������� - ���������� ����� S � P
	float fovy, aspect; // ���� ������ � ����������� ������ ���� ����������
	float fovy_work, aspect_work; // ������� ���������� ��� fovy � aspect
	float near, far; // ���������� �� ���� ���������� � �� ���������
	float n, f; // ������� ���������� ��� near � far
	float l, r, t, b; // ������� ��������������� ����������
	// ��� �������� ��������� �����, ������,
	// ������ � ������� ���������� � ���

	enum projType { Ortho, Frustum, Perspective } pType; // ��� ���������� ��������

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

	private: System::Void initWorkPars() { // ������������� ������� ���������� ������
		n = near;
		f = far;
		fovy_work = fovy;
		aspect_work = aspect;
		float Vy = 2 * near * tan(fovy / 2);
		float Vx = aspect * Vy;
		l = -Vx / 2;
		r = Vx / 2;
		b = -Vy / 2;
		t = Vy / 2;
		dist = length(P - S);
		T = lookAt(S, P, u);
	}
	
	private: System::Void Painting_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

		Graphics^ g = e->Graphics;
		g->Clear(Color::PowderBlue);

		Pen^ rectPen = gcnew Pen(Color::Black, 2);
		g->DrawRectangle(rectPen, left, top, Wx, Wy);

		mat4 proj; // ������� �������� � ������������ ���������
		switch (pType) {
		case Ortho: // ������������� ��������	
			proj = ortho(l, r, b, t, -n, -f);
			break;
		case Frustum: // ������������� �������� � Frustum	
			proj = frustum(l, r, b, t, n, f);
			break;
		case Perspective: // ������������� �������� � Perspective			
			proj = perspective(fovy_work, aspect_work, n, f);
			break;
		}
		// ������� ������������
		mat3 cdr = cadrRL(vec2(-1.f, -1.f), vec2(2.f, 2.f), vec2(Wcx, Wcy), vec2(Wx, Wy));
		mat4 C = proj * T; // ������� �������� �� ������� ��������� � ������������ ���������
		for (int k = 0; k < models.size(); k++) { // ���� �� �������
			vector<path> figure = models[k].figure; // ������ ������� ��������� ������
			mat4 TM = C * models[k].modelM; // ������� ������ �������������� ������
			for (int i = 0; i < figure.size(); i++) {
				path lines = figure[i]; // lines - ��������� ������� �����
				Pen^ pen = gcnew Pen(Color::FromArgb(lines.color.x, lines.color.y, lines.color.z));
				pen->Width = lines.thickness;
				// ��������� ����� ������� ������� � ���������� ���������� �����������
				vec3 start_3D = normalize(TM * vec4(lines.vertices[0], 1.0));
				// ��������� ����� ������� ������� � ����������� ������
				vec2 start = normalize(cdr * vec3(vec2(start_3D), 1.f));
				for (int j = 1; j < lines.vertices.size(); j++) { // ���� �� �������� ������ (�� �������)
					// �������� ����� ������� � ���������� ���������� �����������
					vec3 end_3D = normalize(TM * vec4(lines.vertices[j], 1.0));
					// �������� ����� ������� � ����������� ������
					vec2 end = normalize(cdr * vec3(vec2(end_3D), 1.f));
					vec2 tmpEnd = end; // �������������� ���������� ����� ��� �������� �������������
					if (clip(start, end, minX, minY, maxX, maxY)) { // ���� ������� ����� ����� ���������, start � end - ����� ������� ����� �������							
						g->DrawLine(pen, start.x, start.y, end.x, end.y); // ��������� ������� ������				
					}
					start = tmpEnd; // �������� ����� ������������� ������� ���������� ��������� ������ ����������								
				}
			}
		}		  
	}
	private: System::Void Painting_Resize(System::Object^ sender, System::EventArgs^ e) {
		rectCalc();
		Refresh();
	}

	private: System::Void Painting_Load(System::Object^ sender, System::EventArgs^ e) {
		rectCalc();
	}
	private: System::Void Painting_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	
		float Wcx = 2.f;
		float Wcy = (ClientRectangle.Height) - top - bottom / 2.f;
		switch (e->KeyCode) {
		case Keys::Escape:
			initWorkPars();
			break;
		case Keys::D3:
			pType = Perspective;
			break;
		case Keys::D2:
			pType = Frustum;
			break;
		case Keys::D1:
			pType = Ortho;
			break;
		case Keys::W:
			if (Control::ModifierKeys == Keys::Shift) {
				T = lookAt(vec3(0, 0, -0.1), vec3(0, 0, -0.2), vec3(0, 1, 0)) * T;
			}
			else {
				T = lookAt(vec3(0, 0, -1), vec3(0, 0, -2), vec3(0, 1, 0)) * T;
			}
			break;
		case Keys::S:
			if (Control::ModifierKeys == Keys::Shift) {
				T = lookAt(vec3(0, 0, 0.1), vec3(0, 0, 0), vec3(0, 1, 0)) * T;
			}
			else {
				T = lookAt(vec3(0, 0, 1), vec3(0, 0, 0), vec3(0, 1, 0)) * T;
			}
			break;
		case Keys::A:
			if (Control::ModifierKeys == Keys::Shift) {
				T = lookAt(vec3(-0.1, 0, 0), vec3(-0.1, 0, -0.1), vec3(0, 1, 0)) * T;
			}
			else {
				T = lookAt(vec3(-1, 0, 0), vec3(-1, 0, -1), vec3(0, 1, 0)) * T;
			}
			break;
		case Keys::D:
			if (Control::ModifierKeys == Keys::Shift) {
				T = lookAt(vec3(0.1, 0, 0), vec3(0.1, 0, -0.1), vec3(0, 1, 0)) * T;
			}
			else {
				T = lookAt(vec3(1, 0, 0), vec3(1, 0, -1), vec3(0, 1, 0)) * T;
			}
			break;
		case Keys::R: {
			vec3 u_new = mat3(rotate(0.1, vec3(0, 0, 1))) * vec3(0, 1, 0);
			T = lookAt(vec3(0, 0, 0), vec3(0, 0, -1), u_new) * T;
			break;
		}
		case Keys::Y: {
			vec3 u_new = mat3(rotate(-0.1, vec3(0, 0, 1))) * vec3(0, 1, 0);
			T = lookAt(vec3(0, 0, 0), vec3(0, 0, -1), u_new) * T;
			break;
		}
		case Keys::T: {
			if (Control::ModifierKeys == Keys::Shift) {
				mat4 M = rotateP(0.1, vec3(1, 0, 0), vec3(0, 0, -dist)); // ������� �������� ������������ ����� P
				vec3 u_new = mat3(M) * vec3(0, 1, 0); // �������� ����������� �����
				vec3 S_new = normalize(M * vec4(0, 0, 0, 1)); // �������� ������ ���������
				// ������� � ��� � ������� ������ ��������� � ����� �����, � �����������
				// ���������� - � ����� P
				T = lookAt(S_new, vec3(0, 0, -dist), u_new) * T;
			}
			else {
				mat4 M = rotate(0.1, vec3(1, 0, 0)); // ������� �������� ������������ Ox
				vec3 u_new = mat3(M) * vec3(0, 1, 0); // �������� ����������� �����
				vec3 P_new = normalize(M * vec4(0, 0, -1, 1)); // �������� �����, � ������� ������� �����������
				T = lookAt(vec3(0, 0, 0), P_new, u_new) * T;
			}
			break;
		}
		case Keys::G: {
			if (Control::ModifierKeys == Keys::Shift) {
				mat4 M = rotateP(-0.1, vec3(1, 0, 0), vec3(0, 0, -dist)); // ������� �������� ������������ ����� P
				vec3 u_new = mat3(M) * vec3(0, 1, 0); // �������� ����������� �����
				vec3 S_new = normalize(M * vec4(0, 0, 0, 1)); // �������� ������ ���������
				// ������� � ��� � ������� ������ ��������� � ����� �����, � �����������
				// ���������� - � ����� P
				T = lookAt(S_new, vec3(0, 0, -dist), u_new) * T;

			}
			else {
				mat4 M = rotate(-0.1, vec3(1, 0, 0)); // ������� �������� ������������ Ox
				vec3 u_new = mat3(M) * vec3(0, 1, 0); // �������� ����������� �����
				vec3 P_new = normalize(M * vec4(0, 0, -1, 1)); // �������� �����, � ������� ������� �����������
				T = lookAt(vec3(0, 0, 0), P_new, u_new) * T;
			}
			break;
		}
		case Keys::F: {
			if (Control::ModifierKeys == Keys::Shift) {
				mat4 M = rotateP(0.1, vec3(0, 1, 0), vec3(0, 0, -dist)); // ������� �������� ������������ ����� P
				vec3 u_new = mat3(M) * vec3(0, 1, 0); // �������� ����������� �����
				vec3 S_new = normalize(M * vec4(0, 0, 0, 1)); // �������� ������ ���������
				// ������� � ��� � ������� ������ ��������� � ����� �����, � �����������
				// ���������� - � ����� P
				T = lookAt(S_new, vec3(0, 0, -dist), u_new) * T;

			}
			else {
				mat4 M = rotate(0.1, vec3(0, 1, 0)); // ������� �������� ������������ Ox
				vec3 u_new = mat3(M) * vec3(0, 1, 0); // �������� ����������� �����
				vec3 P_new = normalize(M * vec4(0, 0, -1, 1)); // �������� �����, � ������� ������� �����������
				T = lookAt(vec3(0, 0, 0), P_new, u_new) * T;
			}
			break;
		}
		case Keys::H: {
			if (Control::ModifierKeys == Keys::Shift) {
				mat4 M = rotateP(-0.1, vec3(0, 1, 0), vec3(0, 0, -dist)); // ������� �������� ������������ ����� P
				vec3 u_new = mat3(M) * vec3(0, 1, 0); // �������� ����������� �����
				vec3 S_new = normalize(M * vec4(0, 0, 0, 1)); // �������� ������ ���������
				// ������� � ��� � ������� ������ ��������� � ����� �����, � �����������
				// ���������� - � ����� P
				T = lookAt(S_new, vec3(0, 0, -dist), u_new) * T;
			}
			else {
				mat4 M = rotate(-0.1, vec3(0, 1, 0)); // ������� �������� ������������ Ox
				vec3 u_new = mat3(M) * vec3(0, 1, 0); // �������� ����������� �����
				vec3 P_new = normalize(M * vec4(0, 0, -1, 1)); // �������� �����, � ������� ������� �����������
				T = lookAt(vec3(0, 0, 0), P_new, u_new) * T;
			}
			break;
		}
		case Keys::K:
			if (Control::ModifierKeys == Keys::Shift) {
				b--;
			}
			else {
				b++;
			}
			break;
		case Keys::L:
			if (Control::ModifierKeys == Keys::Shift) {
				r--;
			}
			else {
				r++;
			}
			break;
		case Keys::U:
			if (Control::ModifierKeys == Keys::Shift) {
				if (n >= 0.3) {
					n = n - 0.2;
				}
			}
			else {
				if (n <= f - 0.3) {
					n = n + 0.2;
				}
			}
			break;
		case Keys::O:
			if (Control::ModifierKeys == Keys::Shift) {
				if (f >= n + 0.3) {
					f = f - 0.2;
				}
			}
			else {
				f = f + 0.2;
			}
			break;
		case Keys::B:
			if (Control::ModifierKeys == Keys::Shift) {
				if (dist >= 0.3) {
					dist = dist - 0.2;
				}
			}
			else {
				dist = dist + 0.2;
			}
			break;
		case Keys::Z:
			if (Control::ModifierKeys == Keys::Shift) {
				if (fovy_work >= 0.4) {
					fovy_work = fovy_work - 0.1;
				}
			}
			else {
				if (fovy_work <= 2.9) {
					fovy_work = fovy_work + 0.1;
				}
			}
			break;
		case Keys::X:
			if (Control::ModifierKeys == Keys::Shift) {
				if (aspect_work >= 0.06) {
					aspect_work = aspect_work - 0.05;
				}
			}
			else {
				aspect_work = aspect_work + 0.05;
			}
			break;
		case Keys::I: {
			if (Control::ModifierKeys == Keys::Shift) {
				t -= 1;
			}
			else {
				t += 1;
			}
			break;
		}
		case Keys::J: {
			if (Control::ModifierKeys == Keys::Shift) {
				l += 1;
			}
			else {
				l -= 1;
			}
			break;
		}
		}
		Refresh();
	}

		private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
		}

	private: System::Void btnOpen_Click(System::Object^ sender, System::EventArgs^ e) {

		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			wchar_t fileName[1024];
			for (int i = 0; i < openFileDialog->FileName->Length; i++)
				fileName[i] = openFileDialog->FileName[i];
			fileName[openFileDialog->FileName->Length] = '\0';
			ifstream in;
			in.open(fileName);
			if (in.is_open()) {
				models.clear(); // ������� ��������� ������ ��������
				mat4 M = mat4(1.f); // ������� ��� ��������� ��������� �������
				mat4 initM; // ������� ��� ���������� �������������� ������� �������
				vector<mat4> transforms; // ���� ������ ��������������
				vector<path> figure; // ������ ������� ���������� �������
				float thickness = 2;
				float r, g, b;
				r = g = b = 0;
				string cmd;
				string str;
				getline(in, str);
				while (in) {
					if ((str.find_first_not_of("\t\r\n") != string::npos) && (str[0] != '#')) {
						stringstream s(str);
						s >> cmd;
						if (cmd == "camera") { // ��������� ������
							s >> S.x >> S.y >> S.z; // ���������� ����� ����������
							s >> P.x >> P.y >> P.z; // �����, � ������� ��������� ������ ����������
							s >> u.x >> u.y >> u.z; // ������ ����������� �����
							//MessageBox::Show("Test camera");
						}
						else if (cmd == "screen") { // ��������� ���� ����������
							s >> fovy_work >> aspect >> near >> far; // ��������� �������
							fovy = fovy_work / 180.f * Math::PI; // ������� ���� �� �������� � ��������
							//MessageBox::Show("Test screen");
						}
						else if (cmd == "color") {
							s >> r >> g >> b;
							//MessageBox::Show("Test color");
						}
						else if (cmd == "thickness") {
							s >> thickness;
							//MessageBox::Show("Test thickness");
						}
						else if (cmd == "clear") { // �������
							M = mat4(1.f); // ������� ��� ��������� ��������� �������
						}
						else if (cmd == "path") {
							vector<vec3> vertices; // ������ ����� �������
							int N;
							s >> N;
							string str1;
							while (N > 0) {
								getline(in, str1);
								if ((str1.find_first_not_of("\t\r\n") != string::npos) && (str1[0] != '#')) {
									float x, y, z; // ���������� ��� ����������
									stringstream s1(str1); // ��� ���� ��������� ����� �� ������ str1
									s1 >> x >> y >> z;
									vertices.push_back(vec3(x, y, z)); // ��������� ����� � ������
									N--;
								}
							}
							//MessageBox::Show("Test path 1");
							figure.push_back(path(vertices, vec3(r, g, b), thickness));
							//MessageBox::Show("Test path 2");
						}
						else if (cmd == "model") { // ������ �������� ������ �������
							float mVcx, mVcy, mVcz, mVx, mVy, mVz; // ��������� ������� model
							s >> mVcx >> mVcy >> mVcz >> mVx >> mVy >> mVz; // ��������� �������� ����������
							float S = mVx / mVy < 1 ? 2.f / mVy : 2.f / mVx;
							// ����� ����� �������� �� ������ ��������� � ������ �������
							// ����� �������� �������� ���������������
							initM = scale(S, S, S) * translate(-mVcx, -mVcy, -mVcz);
							figure.clear();
							//MessageBox::Show("Test model");
						}
						else if (cmd == "figure") { // ������������ ����� ������							
							models.push_back(model(figure, M * initM));
							//MessageBox::Show("Test figure");
						}
						else if (cmd == "translate") { // �������
							float Tx, Ty, Tz; // ��������� �������������� ��������
							s >> Tx >> Ty >> Tz; // ��������� ���������
							M = translate(Tx, Ty, Tz) * M; // ��������� ������� � ������ ��������������	
							//MessageBox::Show("Test translate");
						}
						else if (cmd == "scale") { // ���������������
							float S; // �������� ���������������
							s >> S; // ��������� ��������
							M = scale(S, S, S) * M; // ��������� ��������������� � ������ ��������������	
							//MessageBox::Show("Test scale");
						}
						else if (cmd == "rotate") { // �������
							float theta; // ���� �������� � ��������
							float nx, ny, nz; // ���������� ������������� ������� ��� ��������
							s >> theta >> nx >> ny >> nz; // ��������� ���������
							// ��������� �������� � ������ ��������������
							M = rotate(theta / 180.f * Math::PI, vec3(nx, ny, nz)) * M;
							//MessageBox::Show("Test rotate");
						}
						else if (cmd == "pushTransform") { // ���������� ������� � ����
							transforms.push_back(M); // ��������� ������� � ����
							//MessageBox::Show("Test pushTransform");
						}
						else if (cmd == "popTransform") { // ����� � ������� �� �����
							M = transforms.back(); // �������� ������� ������� �����
							transforms.pop_back(); // ���������� ������� �� �����	
							//MessageBox::Show("Test popTransform");
						}
					}
					getline(in, str);
				}
				initWorkPars();
				Refresh();
			}
		}
	}
};
}
