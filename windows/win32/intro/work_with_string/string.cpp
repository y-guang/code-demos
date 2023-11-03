#include <iostream>
#include <Windows.h>

void message_box_ansi(const char* message)
{
    MessageBoxA(NULL, message, "Message", MB_OK);
}

void message_box_utf(const wchar_t* message)
{
    MessageBoxW(NULL, message, L"Message", MB_OK);
}

int main()
{
    // message_box_ansi("Hello, World!");
    message_box_utf(L"你好, 世界!"); // if no BOM signiture, this one could fail.
    message_box_utf(L"\u4f60\u597d, \u4e16\u754c!"); // but this one can always work.
    return 0;
}