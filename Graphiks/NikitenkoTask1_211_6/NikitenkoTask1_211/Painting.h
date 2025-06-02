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
	mat4 T; // матрица, в которой накапливаются все преобразования
	vec3 S, P, u; // координаты точки наблюдения
	// точки, в которую направлен вектор наблюдения
	// вектора направления вверх
	float dist; // вспомогательная переменная - расстояние между S и P
	float fovy, aspect; // угол обзора и соотношение сторон окна наблюдения
	float fovy_work, aspect_work; // рабочие переменные для fovy и aspect
	float near, far; // расстояния до окна наблюдения и до горизонта
	float n, f; // рабочие переменные для near и far
	float l, r, t, b; // рабочие вспомогательные переменные
	// для значений координат левой, правой,
	// нижней и верхней координаты в СКН

	enum projType { Ortho, Frustum, Perspective } pType; // тип трехмерной проекции

	/// <summary>
	/// Сводка для Painting
	/// </summary>
	public ref class Painting : public System::Windows::Forms::Form
	{
	public:
		Painting(void)
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
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
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
			this->openFileDialog->Filter = L" (*.txt)|*.txt|Все файлы (*.*)|*.*";
			this->openFileDialog->Title = L"Открыть файл";
			// 
			// btnOpen
			// 
			this->btnOpen->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnOpen->AutoSize = true;
			this->btnOpen->Location = System::Drawing::Point(729, 12);
			this->btnOpen->Name = L"btnOpen";
			this->btnOpen->Size = System::Drawing::Size(97, 49);
			this->btnOpen->TabIndex = 0;
			this->btnOpen->Text = L"Открыть";
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
	private: float left = 30, right = 100, top = 20, bottom = 50; // расстояния до границ окна
		   float minX = left, maxX; // диапазон изменения координат x
		   float minY = top, maxY; // диапазон изменения координат y
		   float Wcx = left, Wcy; // координаты левого нижнего угла прямоугольника
		   float Wx, Wy; // ширина и высота прямоугольника

	private: System::Void rectCalc() {
		maxX = ClientRectangle.Width - right; // диапазон изменения координат x
		maxY = ClientRectangle.Height - bottom; // диапазон изменения координат y
		Wcy = maxY; // координаты левого нижнего угла прямоугольника
		Wx = maxX - left; // ширина прямоугольника
		Wy = maxY - top; // ширина и высота прямоугольника
	}

	private: System::Void initWorkPars() { // инициализация рабочих параметров камеры
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

		mat4 proj; // матрица перехода в пространство отсечения
		switch (pType) {
		case Ortho: // прямоугольная проекция	
			proj = ortho(l, r, b, t, -n, -f);
			break;
		case Frustum: // перспективная проекция с Frustum	
			proj = frustum(l, r, b, t, n, f);
			break;
		case Perspective: // перспективная проекция с Perspective			
			proj = perspective(fovy_work, aspect_work, n, f);
			break;
		}
		// матрица кадрирования
		mat3 cdr = cadrRL(vec2(-1.f, -1.f), vec2(2.f, 2.f), vec2(Wcx, Wcy), vec2(Wx, Wy));
		mat4 C = proj * T; // матрица перехода от мировых координат в пространство отсечения
		for (int k = 0; k < models.size(); k++) { // цикл по моделям
			vector<path> figure = models[k].figure; // список ломаных очередной модели
			mat4 TM = C * models[k].modelM; // матрица общего преобразования модели
			for (int i = 0; i < figure.size(); i++) {
				path lines = figure[i]; // lines - очередная ломаная линия
				Pen^ pen = gcnew Pen(Color::FromArgb(lines.color.x, lines.color.y, lines.color.z));
				pen->Width = lines.thickness;
				// начальная точка первого отрезка в трехмерных евклидовых координатах
				vec3 start_3D = normalize(TM * vec4(lines.vertices[0], 1.0));
				// начальная точка первого отрезка в координатах экрана
				vec2 start = normalize(cdr * vec3(vec2(start_3D), 1.f));
				for (int j = 1; j < lines.vertices.size(); j++) { // цикл по конечным точкам (от единицы)
					// конечная точка отрезка в трехмерных евклидовых координатах
					vec3 end_3D = normalize(TM * vec4(lines.vertices[j], 1.0));
					// конечная точка отрезка в координатах экрана
					vec2 end = normalize(cdr * vec3(vec2(end_3D), 1.f));
					vec2 tmpEnd = end; // продублировали координаты точки для будущего использования
					if (clip(start, end, minX, minY, maxX, maxY)) { // если отрезок видим после отсечения, start и end - концы видимой части отрезка							
						g->DrawLine(pen, start.x, start.y, end.x, end.y); // отрисовка видимых частей				
					}
					start = tmpEnd; // конечная точка неотсеченного отрезка становится начальной точкой следующего								
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
				mat4 M = rotateP(0.1, vec3(1, 0, 0), vec3(0, 0, -dist)); // матрица вращения относительно точки P
				vec3 u_new = mat3(M) * vec3(0, 1, 0); // вращение направления вверх
				vec3 S_new = normalize(M * vec4(0, 0, 0, 1)); // вращение начала координат
				// переход к СКН в которой начало координат в новой точке, а направление
				// наблюдения - в точку P
				T = lookAt(S_new, vec3(0, 0, -dist), u_new) * T;
			}
			else {
				mat4 M = rotate(0.1, vec3(1, 0, 0)); // матрица вращения относительно Ox
				vec3 u_new = mat3(M) * vec3(0, 1, 0); // вращение направления вверх
				vec3 P_new = normalize(M * vec4(0, 0, -1, 1)); // вращение точки, в которую смотрит наблюдатель
				T = lookAt(vec3(0, 0, 0), P_new, u_new) * T;
			}
			break;
		}
		case Keys::G: {
			if (Control::ModifierKeys == Keys::Shift) {
				mat4 M = rotateP(-0.1, vec3(1, 0, 0), vec3(0, 0, -dist)); // матрица вращения относительно точки P
				vec3 u_new = mat3(M) * vec3(0, 1, 0); // вращение направления вверх
				vec3 S_new = normalize(M * vec4(0, 0, 0, 1)); // вращение начала координат
				// переход к СКН в которой начало координат в новой точке, а направление
				// наблюдения - в точку P
				T = lookAt(S_new, vec3(0, 0, -dist), u_new) * T;

			}
			else {
				mat4 M = rotate(-0.1, vec3(1, 0, 0)); // матрица вращения относительно Ox
				vec3 u_new = mat3(M) * vec3(0, 1, 0); // вращение направления вверх
				vec3 P_new = normalize(M * vec4(0, 0, -1, 1)); // вращение точки, в которую смотрит наблюдатель
				T = lookAt(vec3(0, 0, 0), P_new, u_new) * T;
			}
			break;
		}
		case Keys::F: {
			if (Control::ModifierKeys == Keys::Shift) {
				mat4 M = rotateP(0.1, vec3(0, 1, 0), vec3(0, 0, -dist)); // матрица вращения относительно точки P
				vec3 u_new = mat3(M) * vec3(0, 1, 0); // вращение направления вверх
				vec3 S_new = normalize(M * vec4(0, 0, 0, 1)); // вращение начала координат
				// переход к СКН в которой начало координат в новой точке, а направление
				// наблюдения - в точку P
				T = lookAt(S_new, vec3(0, 0, -dist), u_new) * T;

			}
			else {
				mat4 M = rotate(0.1, vec3(0, 1, 0)); // матрица вращения относительно Ox
				vec3 u_new = mat3(M) * vec3(0, 1, 0); // вращение направления вверх
				vec3 P_new = normalize(M * vec4(0, 0, -1, 1)); // вращение точки, в которую смотрит наблюдатель
				T = lookAt(vec3(0, 0, 0), P_new, u_new) * T;
			}
			break;
		}
		case Keys::H: {
			if (Control::ModifierKeys == Keys::Shift) {
				mat4 M = rotateP(-0.1, vec3(0, 1, 0), vec3(0, 0, -dist)); // матрица вращения относительно точки P
				vec3 u_new = mat3(M) * vec3(0, 1, 0); // вращение направления вверх
				vec3 S_new = normalize(M * vec4(0, 0, 0, 1)); // вращение начала координат
				// переход к СКН в которой начало координат в новой точке, а направление
				// наблюдения - в точку P
				T = lookAt(S_new, vec3(0, 0, -dist), u_new) * T;
			}
			else {
				mat4 M = rotate(-0.1, vec3(0, 1, 0)); // матрица вращения относительно Ox
				vec3 u_new = mat3(M) * vec3(0, 1, 0); // вращение направления вверх
				vec3 P_new = normalize(M * vec4(0, 0, -1, 1)); // вращение точки, в которую смотрит наблюдатель
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
				models.clear(); // очищаем имеющийся список рисунков
				mat4 M = mat4(1.f); // матрица для получения модельной матрицы
				mat4 initM; // матрица для начального преобразования каждого рисунка
				vector<mat4> transforms; // стек матриц преобразований
				vector<path> figure; // список ломаных очередного рисунка
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
						if (cmd == "camera") { // положение камеры
							s >> S.x >> S.y >> S.z; // координаты точки наблюдения
							s >> P.x >> P.y >> P.z; // точка, в которую направлен вектор наблюдения
							s >> u.x >> u.y >> u.z; // вектор направления вверх
							//MessageBox::Show("Test camera");
						}
						else if (cmd == "screen") { // положение окна наблюдения
							s >> fovy_work >> aspect >> near >> far; // параметры команды
							fovy = fovy_work / 180.f * Math::PI; // перевод угла из градусов в радианты
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
						else if (cmd == "clear") { // очистка
							M = mat4(1.f); // матрица для получения модельной матрицы
						}
						else if (cmd == "path") {
							vector<vec3> vertices; // список точек ломаной
							int N;
							s >> N;
							string str1;
							while (N > 0) {
								getline(in, str1);
								if ((str1.find_first_not_of("\t\r\n") != string::npos) && (str1[0] != '#')) {
									float x, y, z; // переменные для считывания
									stringstream s1(str1); // еще один строковый поток из строки str1
									s1 >> x >> y >> z;
									vertices.push_back(vec3(x, y, z)); // добавляем точку в список
									N--;
								}
							}
							//MessageBox::Show("Test path 1");
							figure.push_back(path(vertices, vec3(r, g, b), thickness));
							//MessageBox::Show("Test path 2");
						}
						else if (cmd == "model") { // начало описания нового рисунка
							float mVcx, mVcy, mVcz, mVx, mVy, mVz; // параметры команды model
							s >> mVcx >> mVcy >> mVcz >> mVx >> mVy >> mVz; // считываем значения переменных
							float S = mVx / mVy < 1 ? 2.f / mVy : 2.f / mVx;
							// сдвиг точки привязки из начала координат в нужную позицию
							// после которого проводим масштабирование
							initM = scale(S, S, S) * translate(-mVcx, -mVcy, -mVcz);
							figure.clear();
							//MessageBox::Show("Test model");
						}
						else if (cmd == "figure") { // формирование новой модели							
							models.push_back(model(figure, M * initM));
							//MessageBox::Show("Test figure");
						}
						else if (cmd == "translate") { // перенос
							float Tx, Ty, Tz; // параметры преобразования переноса
							s >> Tx >> Ty >> Tz; // считываем параметры
							M = translate(Tx, Ty, Tz) * M; // добавляем перенос к общему преобразованию	
							//MessageBox::Show("Test translate");
						}
						else if (cmd == "scale") { // масштабирование
							float S; // параметр масштабирования
							s >> S; // считываем параметр
							M = scale(S, S, S) * M; // добавляем масштабирование к общему преобразованию	
							//MessageBox::Show("Test scale");
						}
						else if (cmd == "rotate") { // поворот
							float theta; // угол поворота в градусах
							float nx, ny, nz; // координаты направляющего вектора оси вращения
							s >> theta >> nx >> ny >> nz; // считываем параметры
							// добавляем вращение к общему преобразованию
							M = rotate(theta / 180.f * Math::PI, vec3(nx, ny, nz)) * M;
							//MessageBox::Show("Test rotate");
						}
						else if (cmd == "pushTransform") { // сохранение матрицы в стек
							transforms.push_back(M); // сохраняем матрицу в стек
							//MessageBox::Show("Test pushTransform");
						}
						else if (cmd == "popTransform") { // откат к матрице из стека
							M = transforms.back(); // получаем верхний элемент стека
							transforms.pop_back(); // выкидываем матрицу из стека	
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
