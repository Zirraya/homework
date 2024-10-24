#include"Simple.h".
#include "MyForm.h"


using namespace System;
 using namespace System::Windows::Forms;

[STAThreadAttribute]
 void Main(array<String^> ^ args) {
	 Application::EnableVisualStyles();
	 Application::SetCompatibleTextRenderingDefault(false);
	 My12SimleNikitenko211::MyForm form;
	 Application::Run(% form);
	
}


