#include <iostream>
#include "Memory.h"
#include "Aimbot.h"

int main() {
    std::cout << "[*] RustAim v1.0 Initialized\n";
    DWORD pid = Memory::GetProcessId(L"RustClient.exe");
    if (!pid) {
        std::cout << "[-] Rust process not found.\n";
        return 1;
    }
    
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (!hProcess) {
        std::cout << "[-] Failed to open process (EAC blocking?).\n";
        return 1;
    }

    std::cout << "[+] Attached to RustClient.exe (PID: " << pid << ")\n";
    std::cout << "[*] Starting aimbot loop...\n";

    Aimbot aimbot(hProcess);
    // Тут должен быть твой цикл (поток) с логикой
    // aimbot.Run(); 

    return 0;
}
