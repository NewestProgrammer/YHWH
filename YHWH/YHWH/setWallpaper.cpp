#include <iostream>
#include <Shlobj.h>
#include <ShObjIdl.h>
#include <ShObjIdl_core.h>
#include <atlbase.h>
#include "setWallpaper.h"

int setWallpaper(void) {
	::CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);

	CComPtr<IDesktopWallpaper> pWallPaper;
	//���� �뵵���� �𸣁���
	HRESULT hr = pWallPaper.CoCreateInstance(CLSID_DesktopWallpaper);
	if (FAILED(hr)) {
		return 1;
	}
	//hr�� �� ����� �𸣰���
	hr = pWallPaper->Enable(TRUE);
	pWallPaper->SetWallpaper(NULL,L"C:\\jesus.bmp");

	return 0;
}