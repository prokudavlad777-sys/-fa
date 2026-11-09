#pragma once
#include <windows.h>
#include "SDK.h"

class Aimbot {
public:
    Aimbot(HANDLE hProcess);
    void Run(); // Главный цикл (пример)

private:
    HANDLE m_hProcess;
    DWORD m_aimKey = VK_XBUTTON2; // Боковая кнопка мыши по дефолту

    Player GetLocalPlayer();
    Player GetBestTarget(const Player& localPlayer, const Player& enemies, int count);
    void MoveMouse(float deltaX, float deltaY);
};