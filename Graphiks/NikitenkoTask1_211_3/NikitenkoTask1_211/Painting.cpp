#include "Matrix.h"
#include "Transform.h"
#include <vector>
#include "Figure.h"
#include <fstream>
#include <sstream>
#include "Painting.h"


 using namespace System;
 using namespace System::Windows::Forms;

[STAThreadAttribute]
 void Main(array<String^> ^ args) {
	 Application::EnableVisualStyles();
	 Application::SetCompatibleTextRenderingDefault(false);
	 NikitenkoTask1211::Painting form;
	 Application::Run(% form);
	
}


