#include <Windows.h>

#using "FriendlyRendering.dll"
#using "SharpDX.dll"
#using "SharpDX.Desktop.dll"
#using "SharpDX.Direct2D1.dll"
#using "SharpDX.DXGI.dll"

using namespace System;

extern "C" __declspec(dllexport) 
auto create_overlay_window() -> HWND
{
	auto window = FriendlyRendering::Window::CreateOverlayWindow();
	
	return static_cast<HWND>(window->Handle.ToPointer());
}

extern "C" __declspec(dllexport) 
auto get_process_id(const wchar_t* name) -> DWORD
{
	String^ process_name = gcnew String(name);

	__try
	{
		return Diagnostics::Process::GetProcessesByName(process_name)[0]->Id;
	}
	__except(1) { return NULL; }
}