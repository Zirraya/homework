#include"RecurFunc.h"
#include "RecurFunc3.h"

using namespace System;
 using namespace System::Windows::Forms;

[STAThreadAttribute]
 void Main(array<String^> ^ args) {
	 Application::EnableVisualStyles();
	 Application::SetCompatibleTextRenderingDefault(false);
	 RecurFunc3Nikitenko211::RecurFunc3 form;
	 Application::Run(% form);
	
}


