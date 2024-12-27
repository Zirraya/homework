
#include"CollectionNikitenko1.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Collectionvar8Nikitenko::CollectionNikitenko form;
	Application::Run(% form);

}