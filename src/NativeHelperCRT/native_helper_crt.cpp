#include <Windows.h>


__declspec(dllexport) auto create_overlay() -> HWND
{
	auto window = FriendlyRendering::Window::CreateOverlayWindow();
	
	return static_cast<HWND>(window->Handle.ToPointer());
}

__declspec(dllexport) auto get_process_id(const wchar_t* name) -> DWORD
{
	System::String^ process_name = gcnew System::String(name);

	__try
	{
		return System::Diagnostics::Process::GetProcessesByName(process_name)[0]->Id;
	}
	__except(1) { return NULL; }
}