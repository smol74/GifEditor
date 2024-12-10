#pragma once

#include <iostream>
#include <string>

#include <windows.h>
#include <commdlg.h>
#include <shobjidl.h> // IFileDialog

namespace WinAPI {
    std::wstring get_file_path_from_explorer();
}