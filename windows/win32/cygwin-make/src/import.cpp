#include <windows.h>

// show message box
void ShowMessageBox(const char* message)
{
    MessageBoxA(NULL, message, "Message", MB_OK);
}

// main
int main()
{
    ShowMessageBox("Hello, World!");
    return 0;
}
