#ifndef UNICODE
#define UNICODE  // ensure using unicode version of micros and funcs.
#endif

#include <windows.h>

// every Windows desktop application must also have a window-procedure function
// it handles messages sent to the window.
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR pCmdLine, int nCmdShow) {
    const wchar_t CLASS_NAME[] = L"sample windows class";

    WNDCLASS wc = {};

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;  // register the handler to the current instance.
    wc.lpszClassName = CLASS_NAME;  // the name of the class.

    RegisterClass(&wc);  // register the class.

    // create the windows
    HWND hwnd = CreateWindowEx(0,            // style
                               CLASS_NAME,   // specify windows class
                               L"桌面程序",  // windows title
                               WS_OVERLAPPEDWINDOW,
                               // positions and size
                               CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                               CW_USEDEFAULT,
                               NULL,       // parent window
                               NULL,       // menu
                               hInstance,  // instance handle
                               NULL        // additional application data
    );

    if (hwnd == NULL) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // Run message loop.

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(
            &msg);  // translate virtual-key messages into character messages.
        DispatchMessage(&msg);  // dispatch message to the window procedure.
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam,
                            LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_PAINT: {
            // re-paint the windows. if comment out this case, the windows will
            // not be re-painted. e.g. re-size the windows.
            PAINTSTRUCT ps;
            HDC         hdc = BeginPaint(hwnd, &ps);
            FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
            EndPaint(hwnd, &ps);
        }
            return 0;
        default:
            break;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}