#pragma once
#include <windows.h>
#include <TlHelp32.h>
#include <string>

class Memory {
public:
    static DWORD GetProcessId(const std::wstring& processName) {
        PROCESSENTRY32W entry;
        entry.dwSize = sizeof(entry);
        HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        if (Process32FirstW(snapshot, &entry)) {
            do {
                if (processName == entry.szExeFile) {
                    CloseHandle(snapshot);
                    return entry.th32ProcessID;
                }
            } while (Process32NextW(snapshot, &entry));
        }
        CloseHandle(snapshot);
        return 0;
    }

    template <typename T>
    static T Read(HANDLE hProcess, uintptr_t address) {
        T buffer{};
        ReadProcessMemory(hProcess, reinterpret_cast<LPCVOID>(address), &buffer, sizeof(T), nullptr);
        return buffer;
    }
};
