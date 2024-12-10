#include "winapi.h"

std::wstring WinAPI::get_file_path_from_explorer() {
    // Init COM
    if (FAILED(CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED))) {
        std::cerr << "Failed to initialize COM\n";
        return L"";
    }

    // Create an IFileDialog instance
    IFileDialog* file_dialog = nullptr;
    if (FAILED(CoCreateInstance(CLSID_FileOpenDialog, nullptr, CLSCTX_ALL, IID_PPV_ARGS(&file_dialog)))) {
        std::cerr << "Failed to create IFileDialog\n";
        CoUninitialize();
        return L"";
    }

    // Only accept GIFs or MP4s in our dialog
    COMDLG_FILTERSPEC file_types[] = {
        { L"GIF Files", L"*.gif" },
        { L"MP4 Files", L"*.mp4" }
    };
    file_dialog->SetFileTypes(ARRAYSIZE(file_types), file_types);

    // Show the dialog, nullptr means it isn't locked to a parent window
    if (FAILED(file_dialog->Show(nullptr))) {
        std::cerr << "Failed to show IFileDialog\n";
        file_dialog->Release();
        CoUninitialize();
        return L"";
    }

    // Get the selected file if there was one
    IShellItem* shell_item = nullptr;
    if (FAILED(file_dialog->GetResult(&shell_item))) {
        std::cerr << "Failed to get the selected file\n";
        file_dialog->Release();
        CoUninitialize();
        return L"";
    }

    // Get the IShellItem file path as a string
    PWSTR file_path = nullptr;
    if (FAILED(shell_item->GetDisplayName(SIGDN_FILESYSPATH, &file_path))) {
        std::cerr << "Failed to get the selected file's path\n";
        shell_item->Release();
        file_dialog->Release();
        CoUninitialize();
        return L"";
    }

    // Store the result to return as we free file_path in cleanup because its memory is managed by COM
    std::wstring r = file_path;

    // Cleanup
    CoTaskMemFree(file_path);
    shell_item->Release();
    file_dialog->Release();
    CoUninitialize();

    // Return the result
    return r;
}