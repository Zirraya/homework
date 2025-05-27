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


	vec3 Vc; // координаты дальнего левого нижнего угла
	vec3 V; // размеры параллелепипеда в пространстве графика
	vec3 Vc_work, V_work; // рабочие параметры параллелепипеда

	mat4 T; // матрица, в которой накапливаются все преобразования
	mat4 initT; // матрица начального преобразования

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
			this->SuspendLayout();
			// 
			// openFileDialog
			// 
			this->openFileDialog->DefaultExt = L"txt";
			this->openFileDialog->Filter = L" (*.txt)|*.txt|Все файлы (*.*)|*.*";
			this->openFileDialog->Title = L"Открыть файл";
			// 
			// Painting
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(857, 438);
			this->DoubleBuffered = true;
			this->KeyPreview = true;
			this->Name = L"Painting";
			this->Text = L"Painting";
			this->Load += gcnew System::EventHandler(this, &Painting::Painting_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Painting::Painting_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Painting::Painting_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &Painting::Painting_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion
	 private: float left = 30, right = 100, top = 20, bottom = 50; // расстояния до границ окна
			  float minX = left, maxX; // диапазон изменения координат x
			  float minY = top, maxY; // диапазон изменения координат y
			  float Wcx = left, Wcy; // координаты левого нижнего угла прямоугольника
			  float Wx, Wy; // ширина и высота прямоугольника
			  float Wx_work, Wy_work; // ширина и высота области вывода одной линии графика
			  float Wx_part = 0.6, Wy_part = 0.6; // доля Wx_work, Wy_work от Wx, Wy соответственно
			  float Wcx_work, Wcy_work; // координаты левого нижнего у
			  float Wz_work; // количество рабочих прямоугольников
			  int numXsect = 5, numYsect = 5, numZsect = 5; // количество секций координатной сетки по осям


	private: System::Void rectCalc() {
		maxX = ClientRectangle.Width - right; // диапазон изменения координат x
		maxY = ClientRectangle.Height - bottom; // диапазон изменения координат y
		Wcy = maxY; // координаты левого нижнего угла прямоугольника
		Wx = maxX - left; // ширина прямоугольника
		Wy = maxY - top; // ширина и высота прямоугольника

		Wx_work = Wx_part * Wx; // вычисление ширины и высоты
		Wy_work = Wy_part * Wy; // рабочего прямоугольника
		Wcx_work = maxX - Wx_work; // вычисление координат нижнего левого
		Wcy_work = minY + Wy_work; // угла самого дальнего рабочего прямоугольника
		Wz_work = Wcy - Wcy_work; // количество рабочих прямоугольников

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


		// ВЫЧЕРЧИВАНИЕ КООРДИНАТНОЙ СЕТКИ
		 Pen ^ gridPen = gcnew Pen(Color::Black, 1);
		 SolidBrush ^ drawBrush = gcnew SolidBrush(Color::Black);
		 System::Drawing::Font ^ drawFont = gcnew System::Drawing::Font("Arial", 8);
		
			 // координатная сетка по x
			 float gridStep_x = Wx_work / numXsect; // расстояние между линиями сетки по x
		 float grid_dX = V_work.x / numXsect; // расстояние между линиями сетки по x в мировых координатах
		 float tick_x = Vc_work.x; // значение, соответствующее первой линии сетки
		 for (int i = 0; i <= numXsect; i++) { // цикл по количеству линий
			 float tmpXCoord_d = Wcx + i * gridStep_x; // нижняя координата x i-й диагональной линии
			 float tmpXCoord_v = Wcx_work + i * gridStep_x; // координата x i-й вертикальной линии
			 // i-я диагональная линия
				 g->DrawLine(gridPen, tmpXCoord_d, Wcy, tmpXCoord_v, Wcy_work);
			 // i-я вертикальная линия
				 g->DrawLine(gridPen, tmpXCoord_v, Wcy_work, tmpXCoord_v, minY);
			 if (i > 0 && i < numXsect) // если линия не крайняя
				 // выводим текст в нижней точке диагональной линии
				 g->DrawString(tick_x.ToString("F4"), drawFont, drawBrush, tmpXCoord_d, Wcy);
			 tick_x += grid_dX; // вычисляем значение, соответствующее следующей линии
			
		}
		
			 // координатная сетка по z
			 gridStep_x = (Wx - Wx_work) / numZsect; // расстояние между вертикальными линиями сетки по горизонтали
		 float gridStep_y = Wz_work / numZsect; // расстояние между горизонтальными линиями сетки по вертикали
		 float grid_dZ = V_work.z / numZsect; // расстояние между линиями сетки по $z$ в мировых координатах
		 float tick_z = Vc_work.z; // значение, соответствующее первой линии сетки
		 for (int i = 0; i <= numZsect; i++) { // цикл по количеству линий
			 float tmpXCoord_v = Wcx_work - i * gridStep_x; // координата x вертикальных линий
			 float tmpYCoord_g = Wcy_work + i * gridStep_y; // координата y горизонтальных линий
			 float tmpXCoord_g = tmpXCoord_v + Wx_work; // вторая координата x горизонтальных линий
			 // i-я вертикальная линия
				 g->DrawLine(gridPen, tmpXCoord_v, tmpYCoord_g, tmpXCoord_v, tmpYCoord_g - Wy_work);
			 // i-я горизонтальная линия
				 g->DrawLine(gridPen, tmpXCoord_v, tmpYCoord_g, tmpXCoord_g, tmpYCoord_g);
			 if (i > 0 && i < numZsect) // если линия не крайняя
				 // выводим текст в правой точке горизонтальной линии
				 g->DrawString(tick_z.ToString("F4"), drawFont, drawBrush, tmpXCoord_g, tmpYCoord_g);
			 tick_z += grid_dZ; // вычисляем значение, соответствующее следующей линии
			
		}

		 // КООРДИНАТНАЯ СЕТКА ПО Y
		 float gridStep_z = Wy_work / numYsect;
		 float grid_dY = V_work.y / numYsect;
		 float tick_y = Vc_work.y;
		 for (int i = 0; i <= numYsect; i++) {
			 float tmpXCoord_v = Wcx_work;
			 float tmpYCoord_v = Wcy_work - i * gridStep_z;
			 float tmpYCoord_g = tmpYCoord_v + Wz_work;
			 g->DrawLine(gridPen, tmpXCoord_v, tmpYCoord_v, minX, tmpYCoord_g);
			 g->DrawLine(gridPen, tmpXCoord_v, tmpYCoord_v, maxX, tmpYCoord_v);
			 if (i > 0 && i < numYsect)
				 g->DrawString(tick_y.ToString("F4"), drawFont, drawBrush, maxX, tmpYCoord_v);
			 tick_y += grid_dY;
		 }

		 //



		// ОТРИСОВКА ГРАФИКА
		 Pen ^ pen = gcnew Pen(Color::Blue, 1);
		 float deltaX = V_work.x / Wx_work; // шаг по x в мировых координатах
		 float deltaZ = V_work.z / Wz_work; // шаг по z в мировых координатах
		
			
			 float deltaWcx = (Wcx_work - Wcx) / Wz_work; // шаг прямоугольников по x в координатах экрана
		
			 bool hasStart;
		
			 // цикл по прямоугольникам
			 float z = Vc_work.z; // координата z соответствующая дальнему прямоугольнику
		 // координаты левого нижнего угла рабочего прямоугольника (инициализация)
			 float Wcx_w = Wcx_work, Wcy_w = Wcy_work;
		 while (Wcy_w <= Wcy) { // пока не перебрали все прямоугольники
			 vec2 start, end; // концы отрезка в координатах экрана
			 float x, y; // переменные для координат точки в мировой СК
			 start.x = Wcx_w; // для начальной точки первого отрезка устанавливаем координату x
			 x = Vc_work.x; // координата x начальной точки первого отрезка в мировых координатах
			 hasStart = f_exists(x, z, deltaX);
			 if (hasStart) {
				 y = f(x, z); // координата y начальной точки в мировых координатах
				 // вычисляем соответствующее значение в координатах экрана
					 start.y = Wcy_w - (y - Vc_work.y) / V_work.y * Wy_work;
				
			}
			 float maxX = Wcx_w + Wx_work; // максимальное значение x в рабочем прямоугольнике
			 while (start.x < maxX) {
				 vec2 end; // точка конца отрезка в координатах экрана
				 bool hasEnd;
				 float deltaY; // высота точки в прямоугольнике (доля общей высоты)
				 float red, green, blue; // компоненты цвета отрезка
				 end.x = start.x + 1.f; // координата x отличается на единицу
				 x += deltaX; // координата x конечной точки отрезка в мировых координатах
				 hasEnd = f_exists(x, z, deltaX);
				 if (hasEnd) {
					 y = f(x, z); // координата y начальной точки в мировых координатах
					 // вычисляем соответствующее значение в координатах экрана
						 deltaY = (y - Vc_work.y) / V_work.y;
					 end.y = Wcy_w - deltaY * Wy_work;
					
				}
				 vec2 tmpEnd = end;
				 bool visible = hasStart && hasEnd && clip(start, end, minX, minY, maxX, maxY);
				 if (visible) { // если отрезок видим
					 // после отсечения, start и end - концы видимой части отрезка
						 // вычичление цвета отрезка
						 if (deltaY > 1.f) deltaY = 1.f; // нормализуем значение высоты точки
					 if (deltaY < 0.f) deltaY = 0.f; // на случай, если отрезок отсекался
					 green = 510.f * deltaY; // предварительное вычисление произведения
					 if (deltaY < 0.5) { // если точка ниже середины области видимости
						 // компонента зеленого уже вычислена
							 blue = 255.f - green; // синий дополняет зеленый
						 red = 0.f; // красный равен нулю
						
					}
					 else { // если точка не ниже середины
						 blue = 0.f; // синий равен нулю
						 red = green - 255.f; // вычисляем красный и зеленый
						 green = 510.f - green; // с использованием вычисленного произведения
						
					}
					 pen->Color = Color::FromArgb(red, green, blue); // меняем цвет пера
					 // отрисовка отрезка
						 g->DrawLine(pen, start.x, start.y, end.x, end.y); // отрисовка видимых частей	
				}
				 // конечная точка неотсеченного отрезка становится начальной точкой следующего
					 start = tmpEnd;
				 hasStart = hasEnd;
			}
			 Wcy_w += 1.f; // переходим к следующему прямоугольнику, он будет ниже на один пиксел
			 Wcx_w -= deltaWcx; // и левее на некоторое значение
			 z += deltaZ; // вычисляем соответствующее значение z для очередного прямоугольника
			
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

		float centerX = Vc_work.x + V_work.x / 2; // координаты центра параллелепипеда
		float centerY = Vc_work.y + V_work.y / 2; // в мировой системе координат
		float centerZ = Vc_work.z + V_work.z / 2;


		float Wcx = ClientRectangle.Width / 2.f; // координаты центра
		float Wcy = ClientRectangle.Height / 2.f; // текущего окна



		switch (e->KeyCode) {

		case Keys::Escape:

			numXsect = 5; numYsect = 5; numZsect = 5;
			Wx_part = 0.6; Wy_part = 0.6;
			T = initT;
			break;

		case Keys::A:
			T = translate(-V_work.x / Wx, 0.f, 0.f) * T; // сдвиг графика вправо на один, пиксел
			break;

		case Keys::D:
			T = translate(V_work.x / Wx, 0.f, 0.f) * T; // сдвиг графика влево на один пиксел
			break;

		case Keys::W:
			T = translate(0.f, 0.f, V_work.x / Wx) * T; // сдвиг графика назад (от наблюдателя) на один пиксел
			break;

		case Keys::S:
			T = translate(0.f, 0.f, -V_work.x / Wx) * T; // сдвиг графика вперед (от наблюдателя) на один пиксел
			break;

		case Keys::R:
			T = translate(0.f, -V_work.y / Wy, 0.f) * T; // сдвиг графика вниз на один пиксел
			break;

		case Keys::F:
			T = translate(0.f, V_work.y / Wy, 0.f) * T; // сдвиг графика вверх на один пиксел
			break;

		case Keys::Z:
			T = translate(-centerX, -centerY, -centerZ) * T; // перенос начала координат в центр
			T = scale(1.1, 1.1, 1.1) * T; // масштабирование относительно начала координат
			T = translate(centerX, centerY, centerZ) * T; // возврат позиции начала координат
			break;

		case Keys::X: // уменьшение
			T = translate(-centerX, -centerY, -centerZ) * T; // перенос начала координат в центр
			T = scale(1. / 1.1, 1. / 1.1, 1. / 1.1) * T; // масштабирование относительно начала координат
			T = translate(centerX, centerY, centerZ) * T; // возврат позиции начала координат
			break;

		case Keys::T:
			T = translate(-centerX, -centerY, -centerZ) * T; // перенос начала координат в центр
			T = scale(1.1, 1., 1.) * T; // масштабирование относительно начала координат
			T = translate(centerX, centerY, centerZ) * T; // возврат позиции начала координат
			break;

		case Keys::G:
			T = translate(-centerX, -centerY, -centerZ) * T; // перенос начала координат в центр
			T = scale(1. / 1.1, 1., 1.) * T; // масштабирование относительно начала координат
			T = translate(centerX, centerY, centerZ) * T; // возврат позиции начала координат
			break;

		case Keys::Y:
			T = translate(-centerX, -centerY, -centerZ) * T; // перенос начала координат в центр
			T = scale(1., 1.1, 1.) * T; // масштабирование относительно начала координат
			T = translate(centerX, centerY, centerZ) * T; // возврат позиции начала координат
			break;

		case Keys::H:
			T = translate(-centerX, -centerY, -centerZ) * T; // перенос начала координат в центр
			T = scale(1., 1. / 1.1, 1.) * T; // масштабирование относительно начала координат
			T = translate(centerX, centerY, centerZ) * T; // возврат позиции начала координат
			break;

		case Keys::U:
			T = translate(-centerX, -centerY, -centerZ) * T; // перенос начала координат в центр
			T = scale(1., 1., 1.1) * T; // масштабирование относительно начала координат
			T = translate(centerX, centerY, centerZ) * T; // возврат позиции начала координат
			break;

		case Keys::J:
			T = translate(-centerX, -centerY, -centerZ) * T; // перенос начала координат в центр
			T = scale(1., 1., 1. / 1.1) * T; // масштабирование относительно начала координат
			T = translate(centerX, centerY, centerZ) * T; // возврат позиции начала координат
			break;

		case Keys::D1:
			numXsect++;
			break;

		case Keys::D2:
			if (numXsect > 2)numXsect--;
			break;

		case Keys::D3:
			numYsect++;
			break;

		case Keys::D4:
			if (numYsect > 2)numYsect--;
			break;

		case Keys::D5:
			numZsect++;
			break;

		case Keys::D6:
			if (numZsect > 2)numZsect--;
			break;

		case Keys::Q:
			if (Wx_part <= 0.9) Wx_part *= 1.1;
			break;

		case Keys::E:
			if (Wx_part >= 0.2) Wx_part /= 1.1;
			break;

		case Keys::C:
			if (Wy_part <= 0.9) Wy_part *= 1.1;
			break;

		case Keys::V:
			if (Wy_part >= 0.2) Wy_part /= 1.1;
			break;
		default:
			break;
		}
		rectCalc();
		worldRectCalc();
		Refresh();
	}
	
};
}
