#pragma once

namespace NikitenkoTask1211 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
			this->SuspendLayout();
			// 
			// Painting
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(920, 483);
			this->DoubleBuffered = true;
			this->Name = L"Painting";
			this->Text = L"Painting";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Painting::Painting_Paint);
			this->Resize += gcnew System::EventHandler(this, &Painting::Painting_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion
	
	private: System::Void Painting_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

		Graphics^ g = e->Graphics;
		g->Clear(Color::Aquamarine);

		// Перо
		Pen^ redPen = gcnew Pen(Color::Red);
		redPen->Width = 6;
		g->DrawLine(redPen, 0, 0, this->ClientRectangle.Width, this->ClientRectangle.Height);

		Pen^ bluePen = gcnew Pen(Color::Blue, 10);
		g->DrawLine(bluePen, 90, 50, ClientRectangle.Width, 80);


		// Дополнение для проекта
		Pen^ greenPen = gcnew Pen(Color::Green, 5);

		g->DrawLine(greenPen, 0, this->ClientRectangle.Height / 3, this->ClientRectangle.Width / 3 * 2, 0);

		g->DrawLine(greenPen, this->ClientRectangle.Width / 3 * 2, 0, this->ClientRectangle.Width, this->ClientRectangle.Height / 3 * 2);
		g->DrawLine(greenPen, this->ClientRectangle.Width, this->ClientRectangle.Height / 3 * 2, this->ClientRectangle.Width / 3, this->ClientRectangle.Height);
		g->DrawLine(greenPen, this->ClientRectangle.Width / 3, this->ClientRectangle.Height, 0, this->ClientRectangle.Height / 3);
		//

		// Кисть испоьлзуется для вывода текста
		SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);
		System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 10);
		g->DrawString("Harpie", drawFont, drawBrush, 40, 100);
		//
		
		
		//// Контрольный вопрос №9
		//Pen^ whitePen = gcnew Pen(Color::White, 10);
		//g->DrawLine(whitePen, 90, 50, this->ClientRectanglethis->ClientRectangle.Width, 200);
		////


	}

	private: System::Void Painting_Resize(System::Object^ sender, System::EventArgs^ e) {
		Refresh();
	}

	};
}
