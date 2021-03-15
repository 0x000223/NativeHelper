#ifndef NATIVE_HELPER_CRT_HPP
#define NATIVE_HELPER_CRT_HPP

#include <Windows.h>

extern "C" __declspec(dllexport) auto create_overlay() -> HWND;

extern "C" __declspec(dllexport) auto get_process_id(const wchar_t* name) -> DWORD;

#endif