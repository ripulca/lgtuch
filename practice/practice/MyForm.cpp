#include "MyForm.h"
#include <Windows.h>
#include <iostream>
#include <cstdlib>
using namespace System; 
using namespace System::Windows::Forms; 
[STAThread] 
void Main(array<String^>^ args) { 
	Application::EnableVisualStyles(); 
	Application::SetCompatibleTextRenderingDefault(false); 
	practice::MyForm form; 
	Application::Run(% form); }