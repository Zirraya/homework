#include "TableValue.h"
#include "FuncForMassiv.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	TableValue2Nikitenko211::TableValue form;
	Application::Run(% form);

}



