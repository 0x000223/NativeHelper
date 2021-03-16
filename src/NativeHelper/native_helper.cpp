#include "include.hpp"

using namespace System;

extern "C" __declspec(dllexport)
auto create_overlay(const wchar_t* text_name) -> HWND
{
	String^ text = gcnew String(text_name);
	
	auto window_handle = static_cast<HWND>(WindowRelated::Window::GetOverlayWindow(text));

	MARGINS margins
	{
		margins.cxLeftWidth	= -1,
		margins.cxRightWidth 	= -1,
		margins.cyBottomHeight 	= -1,
		margins.cyTopHeight 	= -1,
	};

	DwmExtendFrameIntoClientArea(window_handle, &margins);

	SetLayeredWindowAttributes(window_handle, NULL, 255, LWA_ALPHA);

	return window_handle;
}

extern "C" __declspec(dllexport)
auto create_managed_window(int width, int height, int posX, int posY, const wchar_t* text_name) -> HWND
{
	String^ text = gcnew String(text_name);
	
	return static_cast<HWND>(WindowRelated::Window::CreateManagedWindow(width, height, posX, posY, text));
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
