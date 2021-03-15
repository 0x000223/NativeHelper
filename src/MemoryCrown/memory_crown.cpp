#include "memory_crown.hpp"

auto get_process_id(const wchar_t* name) -> DWORD
{
	auto* snapshot = LI_FN(CreateToolhelp32Snapshot)(TH32CS_SNAPPROCESS, NULL);

	if(snapshot == INVALID_HANDLE_VALUE)
	{
		return NULL;
	}

	PROCESSENTRY32 pe { pe.dwSize = sizeof(PROCESSENTRY32) };

	if(!LI_FN(Process32FirstW)(snapshot, &pe))
	{
		LI_FN(CloseHandle)(snapshot);
		
		return NULL;
	}

	do
	{
		if(!wcscmp(pe.szExeFile, name))
		{
			LI_FN(CloseHandle)(snapshot);
			
			return pe.th32ProcessID;
		}
		
	} while(LI_FN(Process32NextW)(snapshot, &pe));

	LI_FN(CloseHandle)(snapshot);

	return NULL;
}