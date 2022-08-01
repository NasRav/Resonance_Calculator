#include "Calculator.h"

using namespace ResonanceCalculator;

[STAThreadAttribute]
int main(array<System::String^>^ args)
{
	// Enabling Windows visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Create the main window and run it
	Application::Run(gcnew Calculator());
	return 0;
}