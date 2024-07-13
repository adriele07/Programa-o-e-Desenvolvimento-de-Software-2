#include "menuprincipal.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Testebiblioteca;

[STAThreadAttribute]
int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MyForm());
    return 0;
}
