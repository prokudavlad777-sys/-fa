#include "Aimbot.h"
#include "Memory.h"
#include <iostream>
#include <vector>

Aimbot::Aimbot(HANDLE hProcess) : m_hProcess(hProcess) {}

Player Aimbot::GetLocalPlayer() {
    Player local{};
    // Чтение адреса локального игрока из памяти
    // uintptr_t localAddr = Memory::Read<uintptr_t>(m_hProcess, Offsets::GameAssembly + Offsets::LocalPlayer);
    // local.position = Memory::Read<Vector3>(m_hProcess, localAddr + 0x130); // Пример оффсета
    return local;
}

void Aimbot::MoveMouse(float deltaX, float deltaY) {
    INPUT input = { 0 };
    input.type = INPUT_MOUSE;
    input.mi.dx = (LONG)(deltaX);
    input.mi.dy = (LONG)(deltaY);
    input.mi.dwFlags = MOUSEEVENTF_MOVE;
    SendInput(1, &input, sizeof(INPUT));
}

void Aimbot::Run() {
    while (true) {
        if (GetAsyncKeyState(m_aimKey) & 0x8000) {
            Player local = GetLocalPlayer();
            
            // Здесь должен быть цикл по EntityList
            // Vector3 targetHead = ...;
            // Vector3 angles = CalcAngle(local.position, targetHead);
            
            // Пример плавного движения (smooth = 5.0f)
            // float deltaX = (angles.y - currentAngles.y) / 5.0f;
            // float deltaY = (angles.x - currentAngles.x) / 5.0f;
            // MoveMouse(deltaX, deltaY);
        }
        Sleep(1); // Чтобы не ебашить CPU на 100%
    }
}
