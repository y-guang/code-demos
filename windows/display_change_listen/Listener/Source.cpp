#include <Windows.h>
#include <iostream>

// Forward declaration of the Window Procedure
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{
    // Register a dummy window class
    const wchar_t* CLASS_NAME = L"DummyClass";
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(nullptr);
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create a dummy window
    HWND hwnd = CreateWindowEx(
        0,                           // Optional window styles.
        CLASS_NAME,                  // Window class
        L"Monitor Change Listener",  // Window text
        WS_OVERLAPPEDWINDOW,         // Window style

        // Size and position
        0, 0, 0, 0,

        nullptr,       // Parent window    
        nullptr,       // Menu
        wc.hInstance,  // Instance handle
        nullptr        // Additional application data
    );

    if (hwnd == nullptr)
    {
        return 0;
    }

    // Main message loop
    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DISPLAYCHANGE:
    {
        MessageBox(hwnd, L"Display change detected", L"Notification", MB_OK | MB_ICONINFORMATION);
        break;
    }

    case WM_DESTROY:
    {
        PostQuitMessage(0);
        break;
    }

    default:
    {
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    }
    return 0;
}