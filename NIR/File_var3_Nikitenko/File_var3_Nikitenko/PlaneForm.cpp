#include "PlaneForm.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Filevar3Nikitenko::PlaneForm form;
	Application::Run(% form);

}
