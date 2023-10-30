#include <shobjidl.h>
#include <windows.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine,
                    int nCmdShow) {
    // initialize the COM library
    HRESULT hr =
        CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
    if (FAILED(hr)) {
        return 0;
    }

    IFileOpenDialog *pFileOpen;

    // Create the FileOpenDialog object.
    hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL,
                          IID_IFileOpenDialog,
                          reinterpret_cast<void **>(&pFileOpen));
    if (FAILED(hr)) {
        CoUninitialize();
        return 0;
    }

    // Show the Open dialog box.
    hr = pFileOpen->Show(NULL);
    if (FAILED(hr)) {
        pFileOpen->Release();
        CoUninitialize();
        return 0;
    }

    // Get the file name from the dialog box.
    IShellItem *pItem;
    hr = pFileOpen->GetResult(&pItem);
    if (SUCCEEDED(hr)) {
        PWSTR pszFilePath;
        hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);

        // Display the file name to the user.
        if (SUCCEEDED(hr)) {
            MessageBoxW(NULL, pszFilePath, L"File Path", MB_OK);
            CoTaskMemFree(pszFilePath);
        }
        pItem->Release();
    }
    pFileOpen->Release();
    CoUninitialize();

    return 0;
}