#pragma once
#include "Math.h"
#include <cstdint>

// Оффсеты меняются каждый патч. Обновляй вручную.
namespace Offsets {
    constexpr uintptr_t GameAssembly = 0x00000000; // Base address (example)
    constexpr uintptr_t EntityList = 0x00000000; // GameAssembly + offset
    constexpr uintptr_t LocalPlayer = 0x00000000;
    constexpr uintptr_t ViewMatrix = 0x00000000;
    constexpr uintptr_t Camera = 0x00000000;
}

// Упрощенная структура игрока (для примера)
struct Player {
    Vector3 position; // World position
    Vector3 headPos;  // Head bone pos
    int health;
    int team;
    uintptr_t base;
};
