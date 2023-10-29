## Ref

[Get Started](https://learn.microsoft.com/en-us/windows/win32/learnwin32/learn-to-program-for-windows)

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