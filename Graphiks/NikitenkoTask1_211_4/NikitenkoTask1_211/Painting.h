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
	float VxR; // размер рисунка по горизонтали
	float VyR; // размер рисунка по вертикали
	float aspectFigR; // соотношение сторон рисунка

	// Матрицы, для 3 задания
	mat3 TR; // матрица, в которой накапливаются все преобразования
	mat3 initTR; // матрица начального преобразования

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
	private: bool keepAspectRatio; // значение - сохранять ли соотношение сторон рисунка?
	private: bool changeImage; // замена изображения
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
	
	private: System::Void Painting_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

		Graphics^ g = e->Graphics;
		g->Clear(Color::PowderBlue);

		Pen^ rectPen = gcnew Pen(Color::Black, 2);
		g->DrawRectangle(rectPen, left, top, Wx, Wy);

		// Перо
			 for (int k = 0; k < models.size(); k++) {
				 vector<path> figure = models[k].figure; // список ломаных очередного рисунка
				  path lines = figure[k]; // lines - очередная ломаная линия
				  mat3 TM = TR * models[k].modelM; // матрица общего преобразования рисунка
				  for (int i = 0; i < figure.size(); i++) {
					   path lines = figure[i]; // lines - очередная ломаная линия
					   Pen ^ pen = gcnew Pen(Color::FromArgb(lines.color.x, lines.color.y, lines.color.z));
					   pen->Width = lines.thickness;

				  vec2 start = normalize(TM * vec3(lines.vertices[0], 1.2)); // первая начальная точка
				  for (int j = 1; j < lines.vertices.size(); j++) { // цикл по конечным точкам (от единицы)
					  vec2 end = normalize(TM * vec3(lines.vertices[j], 1.2)); // конечная точка
					  vec2 tmpEnd = end; // продублировали координаты точки для будущего использования
					  if (clip(start, end, minX, minY, maxX, maxY)) { // если отрезок видим
						  // после отсечения, start и end - концы видимой части отрезка
						  g->DrawLine(pen, start.x, start.y, end.x, end.y); // отрисовка видимых частей  
					  }
					  start = tmpEnd; // конечная точка неотсеченного отрезка становится начальной точкой следующего
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
	
		float Wcx = ClientRectangle.Width / 2.f; // координаты центра
		float Wcy = ClientRectangle.Height / 2.f; // текущего окна

		switch (e->KeyCode) {
		case Keys::Escape:
			TR = initTR; 
			break;
		}
		//Повороты на 0.01
		// поворот изображения против часовой стрелке на 0.01 радиан относительно
		// текущего центра окна
		switch (e->KeyCode) {
		case Keys::Q:
			TR = translate(-Wcx, -Wcy) * TR; // перенос начала координат в (Wcx, Wcy)
			TR = rotate(0.01f) * TR; // поворот на 0.01 радиан относительно
			// нового центра
			TR = translate(Wcx, Wcy) * TR; // перенос начала координат обратно
			break;
		}
		// поворот изображения по часовой стрелке на 0.01 радиан относительно
		// текущего центра окна
		switch (e->KeyCode){
		case Keys::E:
			TR = translate(-Wcx, -Wcy) * TR; // перенос начала координат в (Wcx, Wcy)
			TR = rotate(-0.01f) * TR; // поворот на 0.01 радиан относительно
			// нового центра
			TR = translate(Wcx, Wcy) * TR; // перенос начала координат обратно
		default:
			break;
		}
		//

		//Повороты на 0.05
		// поворот изображения против часовой стрелке на 0.05 радиан относительно
		// текущего центра окна
		switch (e->KeyCode) {
		case Keys::Y:
			TR = translate(-Wcx, -Wcy) * TR; // перенос начала координат в (Wcx, Wcy)
			TR = rotate(0.05f) * TR; // поворот на 0.01 радиан относительно
			// нового центра
			TR = translate(Wcx, Wcy) * TR; // перенос начала координат обратно
			break;
		}
		// поворот изображения по часовой стрелке на 0.05 радиан относительно
		// текущего центра окна
		switch (e->KeyCode) {
		case Keys::R:
			TR = translate(-Wcx, -Wcy) * TR; // перенос начала координат в (Wcx, Wcy)
			TR = rotate(-0.05f) * TR; // поворот на 0.01 радиан относительно
			// нового центра
			TR = translate(Wcx, Wcy) * TR; // перенос начала координат обратно
		default:
			break;
		}
		//

		// Сдвиги изображения на 1 пиксель

		switch (e->KeyCode) {
		case Keys::W:
			TR = translate(0.f, -1.f) * TR; // сдвиг вверх на один пиксел
			break;

		}

		// сдвиг изображения соответственно вниз 1 пиксел;
		switch (e->KeyCode) {
		case Keys::S:
			TR = translate(0.f, 1.f) * TR; // сдвиг вниз на один пиксел
		default:
			break;
		}

		// сдвиг изображения соответственно влево 1 пиксел;
		switch (e->KeyCode) {
		case Keys::A:
			TR = translate(-1.f, 0.f) * TR; // сдвиг влево на один пиксел
		default:
			break;
		}

		// сдвиг изображения соответственно вправо 1 пиксел;
		switch (e->KeyCode) {
		case Keys::D:
			TR = translate(1.f, 0.f) * TR; // сдвиг вправо на один пиксел
		default:
			break;
		}
		//



		// Сдвиг изображения на 10 пикселей 
		switch (e->KeyCode) {
		case Keys::T:
			TR = translate(0.f, -10.f) * TR; // сдвиг вверх на один пиксел
			break;

		}

		// сдвиг изображения соответственно вниз 1 пиксел;
		switch (e->KeyCode) {
		case Keys::G:
			TR = translate(0.f, 10.f) * TR; // сдвиг вниз на один пиксел
		default:
			break;
		}

		// сдвиг изображения соответственно влево 1 пиксел;
		switch (e->KeyCode) {
		case Keys::F:
			TR = translate(-10.f, 0.f) * TR; // сдвиг влево на один пиксел
		default:
			break;
		}

		// сдвиг изображения соответственно вправо 1 пиксел;
		switch (e->KeyCode) {
		case Keys::H:
			TR = translate(10.f, 0.f) * TR; // сдвиг вправо на один пиксел
		default:
			break;
		}

		// Зеркальные отражения
		// отражение по вертикали;
		switch (e->KeyCode) {
		case Keys::U:
			TR = translate(-Wcx, -Wcy) * TR; // перенос начала координат в (Wcx, Wcy) 
			TR = mirrorX() * TR; //  горизонтальное зеркало 
			TR = translate(Wcx, Wcy) * TR; // перенос начала координат обратно 
		default:
			break;
		}

		// отражение по горизонтали;
		switch (e->KeyCode) {
		case Keys::J:
			TR = translate(-Wcx, -Wcy) * TR; // перенос начала координат в (Wcx, Wcy) 
			TR = mirrorY() * TR; //  вертикальное зеркало 
			TR = translate(Wcx, Wcy) * TR; // перенос начала координат обратно 
		default:
			break;
		}
		//

		// Увеличение/уменьшение изображения в 1.1 раз
		// увеличение
		switch (e->KeyCode) {
		case Keys::Z:
			TR = translate(-Wcx, -Wcy) * TR; // перенос начала координат в (Wcx, Wcy)
			TR = scale(1.1f, 1.1f) * TR;
			TR = translate(Wcx, Wcy) * TR; // перенос начала координат обратно
		default:
			break;
		}

		// уменьшение
		switch (e->KeyCode) {
		case Keys::X:
			TR = translate(-Wcx, -Wcy) * TR; // перенос начала координат в (Wcx, Wcy)
			TR = scale(1.0f / 1.1f, 1.0f / 1.1f) * TR;
			TR = translate(Wcx, Wcy) * TR; // перенос начала координат обратно
		default:
			break;
		}

		// Сжатие и растяжение по горизонтали
		// растяжение
		switch (e->KeyCode) {
		case Keys::I:
			TR = scale(1.1f, 1.0f) * TR;	 
		default:
			break;
		}

		// сжатие
		switch (e->KeyCode) {
		case Keys::K:
			TR = scale(1.0f / 1.1f, 1.0f) * TR;
		default:
			break;
		}

		//

		// Сжатие и растяжение по вертикали
		// растяжение
		switch (e->KeyCode) {
		case Keys::O:
			TR = scale(1.0f,1.1f) * TR;
		default:
			break;
		}

		// сжатие
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
			 // в файловом диалоге нажата кновка OK
				 // перезапись имени файла из openFileDialog->FileName в fileName
				 wchar_t fileName[1024]; // переменная, в которой посимвольно сохраним имя файла
			 for (int i = 0; i < openFileDialog->FileName->Length; i++)
				 fileName[i] = openFileDialog->FileName[i];
			 fileName[openFileDialog->FileName->Length] = '\0';
			
				 // объявление и открытие файла
				 ifstream in;
			 in.open(fileName);
			 if (in.is_open()) {
				
					 // файл успешно открыт
				 models.clear(); // очищаем имеющийся список рисунков
				 // временные переменные для чтения из файла

				 mat3 M = mat3(1.f); // матрица для получения модельной матрицы
				 mat3 initM; // матрица для начального преобразования каждого рисунка
				 vector<mat3> transforms; // стек матриц преобразований
				 vector<path> figure; // список ломаных очередного рисунка

					 float thickness = 2; // толщина со значением по умолчанию 2
				 float r, g, b; // составляющие цвета
				 r = g = b = 0; // значение составляющих цвета по умолчанию (черный)
				 string cmd; // строка для считывания имени команды
				 // непосредственно работа с файлом
					 string str; // строка, в которую считываем строки файла
				 getline(in, str); // считываем из входного файла первую строку
				 while (in) { // если очередная строка считана успешно
					 // обрабатываем строку
					 if ((str.find_first_not_of(" \t\r\n") != string::npos) && (str[0] != '#')) {
						 // прочитанная строка не пуста и не комментарий
						 stringstream s(str); // строковый поток из строки str
						 s >> cmd;
						 if (cmd == "frame") { // размеры изображения

							 s >> VxR >> VyR; // считываем глобальные значение Vx и Vy

							 float Wx = ClientRectangle.Width - left - right; // ширина прямоугольника
							 float Wy = ClientRectangle.Height - top - bottom; // высота прямоугольника
							 float aspectRect = Wx / Wy; // соотношение сторон прямоугольника
							 // коэффициент увеличения при сохранении исходного соотношения сторон

							// смещение центра рисунка с началом координат
							 mat3 T1 = translate(-VxR / 2, -VyR / 2);
							 // масштабирование остается прежним, меняется только привязка
							 // коэффициент увеличения при сохранении исходного соотношения сторон
							 float S = aspectFigR < aspectRect ? Wy / VyR : Wx / VxR;
							 mat3 S1 = scale(S, -S);
							 // сдвиг точки привязки из начала координат в нужную позицию
							 mat3 T2 = translate(Wx / 2 + Wcx, Wcy - Wy / 2);
							 // В initT совмещаем эти три преобразования (справа налево)
							 initTR = T2 * (S1 * T1);

							 TR = initTR;

						 }
						 else if (cmd == "color") { // цвет линии
							 s >> r >> g >> b; // считываем три составляющие цвета

						 }
						 else if (cmd == "thickness") { // толщина линии
							 s >> thickness; // считываем значение толщины

						 }
						 else if (cmd == "path") { // набор точек
							 vector<vec2> vertices; // список точек ломаной
							 int N; // количество точек
							 s >> N;
							 string str1; // дополнительная строка для чтения из файла
							 while (N > 0) { // пока не все точки считали
								 getline(in, str1); // считываем в str1 из входного файла очередную строку
								 // так как файл корректный, то на конец файла проверять не нужно
								 if ((str1.find_first_not_of(" \t\r\n") != string::npos) && (str1[0] != '#')) {
									 // прочитанная строка не пуста и не комментарий
										// значит в ней пара координат
									 float x, y; // переменные для считывания
									 stringstream s1(str1); // еще один строковый поток из строки str1
									 s1 >> x >> y;
									 vertices.push_back(vec2(x, y)); // добавляем точку в список
									 N--; // уменьшаем счетчик после успешного считывания точки

								 }

							 }
							 // все точки считаны, генерируем ломаную (path) и кладем ее в список figure
							 figure.push_back(path(vertices, vec3(r, g, b), thickness));

						 }
						 else if (cmd == "model") { // начало описания нового рисунка

							 float mVcx, mVcy, mVx, mVy; // параметры команды model
							 s >> mVcx >> mVcy >> mVx >> mVy; // считываем значения переменных
							 float S = mVx / mVy < 1 ? 2.f / mVy : 2.f / mVx;
							 // сдвиг точки привязки из начала координат в нужную позицию
								 // после которого проводим масштабирование
							 initM = scale(S) * translate(-mVcx, -mVcy);
							 figure.clear();

						 }
						 else if (cmd == "figure") { // формирование новой модели
							 models.push_back(model(figure, M * initM));

						 }
						 else if (cmd == "translate") { // перенос
							 float Tx, Ty; // параметры преобразования переноса
							 s >> Tx >> Ty; // считываем параметры
							 M = translate(Tx, Ty) * M; // добавляем перенос к общему преобразованию

						 }
						 else if (cmd == "scale") { // масштабирование
							 float S; // параметр масштабирования
							 s >> S; // считываем параметр
							 M = scale(S) * M; // добавляем масштабирование к общему преобразованию

						 }
						 else if (cmd == "rotate") { // поворот
							 float theta; // угол поворота в градусах
							 s >> theta; // считываем параметр
							 M = rotate(-theta / 180.f * Math::PI) * M; // добавляем поворот к общему преобразованию

						 }
						 else if (cmd == "pushTransform") { // сохранение матрицы в стек
							 transforms.push_back(M); // сохраняем матрицу в стек

						 }
						 else if (cmd == "popTransform") { // откат к матрице из стека
							 M = transforms.back(); // получаем верхний элемент стека
							 transforms.pop_back(); // выкидываем матрицу из стека
						 }
					 }	 
						 // считываем очередную строку
					 // считываем очередную строку
						 getline(in, str);	
				}
				 Refresh();
			}
		}
	}
};
}
