#pragma once

#ifndef MEMORY_CROWN_HPP
#define MEMORY_CROWN_HPP

#include "lazy_importer.hpp"

#include <string>
#include <Windows.h>
#include "TlHelp32.h"

extern "C" __declspec(dllexport) auto get_process_id(const wchar_t* name) -> DWORD;




#endif