## Ref

[Get Started](https://learn.microsoft.com/en-us/windows/win32/learnwin32/learn-to-program-for-windows)

## content

### Get Started with Win32 and C++

| concept             | file                                        | section                                     |
| ------------------- | ------------------------------------------- | ------------------------------------------- |
| Coding Conventions  |                                             | [Coding Conventions](#coding-conventions)   |
| Strings             | [string.cpp](.\work_with_string\string.cpp) | [Working with Strings](#strings)            |
| wWinMain            |                                             | [wWinMain](#wwinmain)                       |
| windows desktop app | [main.cpp](.\windows_desktop\main.cpp)      | [windows desktop app](#windows-desktop-app) |
| COM                 | [main.cpp](.\com\main.cpp)                  | [COM](#com)                                 |

## Coding Conventions

[Coding Conventions](https://learn.microsoft.com/en-us/windows/win32/learnwin32/windows-coding-conventions)

- Component Object Model (COM) interfaces: most win32 api relay on COM, i.e. binary interface, rather than cpp class.
- `XXX_PTR` is for 32-bit app.
- `LP` and `P` prefix is old convention for pointer. avoiding them.

## Strings

[Working with Strings](https://learn.microsoft.com/en-us/windows/win32/learnwin32/working-with-strings)

- UTF-16 encoding.

```cpp
wchar_t *str = L"hello";
```

### visual studio specific encoding problem.

visual studio relay on BOM to detect encoding. if you save a file with UTF-8 without BOM, visual studio will treat it as ANSI. 

So, if code contains utf literal, save as UTF-8 with BOM.

## wWinMain

```c++
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow);
```

## windows desktop app

[Your First Windows Program](https://learn.microsoft.com/en-us/windows/win32/learnwin32/your-first-windows-program)

The simplest windows desktop app need at least two functions:
- `wWinMain`: the entry point.
- `WindowProc`: the window procedure. For callback of window message.
  - `WM_DESTROY`, `WM_PAINT` are two basic messages that need to be handled.

## COM

[Example: The Open Dialog Box](https://learn.microsoft.com/en-us/windows/win32/learnwin32/example--the-open-dialog-box)
