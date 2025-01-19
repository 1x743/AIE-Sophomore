// Main.cpp : main project file.
#include "MyForm.h"

using namespace My6610110096;
[STAThreadAttribute]
int Main(array<System::String^>^ args)
{
	Application::EnableVisualStyles(); // Enabling Windows XP visual effects before any controls are created

	Application::SetCompatibleTextRenderingDefault(false);
	// Create the main window and run it
	Application::Run(gcnew MyForm());
	return 0;

}