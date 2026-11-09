#pragma once
#include "MathUtils.h" // <-- Должен быть именно этот инклуд
#include <cstdint>

namespace Offsets {
    constexpr uintptr_t GameAssembly = 0x00000000;
    constexpr uintptr_t EntityList = 0x00000000;
    constexpr uintptr_t LocalPlayer = 0x00000000;
    constexpr uintptr_t ViewMatrix = 0x00000000;
    constexpr uintptr_t Camera = 0x00000000;
}

struct Player {
    Vector3 position; // Теперь Vector3 определён
    Vector3 headPos;
    int health;
    int team;
    uintptr_t base;
};
