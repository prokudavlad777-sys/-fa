#pragma once
#include <cmath>
#include <algorithm>

struct Vector3 {
    float x, y, z;
    Vector3 operator-(const Vector3& v) const { return { x - v.x, y - v.y, z - v.z }; }
    Vector3 operator+(const Vector3& v) const { return { x + v.x, y + v.y, z + v.z }; }
    float Length() const { return std::sqrt(x * x + y * y + z * z); }
};

struct Vector2 {
    float x, y;
};

inline float Dot(const Vector3& a, const Vector3& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline Vector3 CalcAngle(const Vector3& src, const Vector3& dst) {
    Vector3 delta = src - dst;
    float hyp = std::sqrt(delta.x * delta.x + delta.y * delta.y);
    Vector3 angles;
    angles.x = std::atan2(delta.z, hyp) * 57.295779513082f;
    angles.y = std::atan2(delta.y, delta.x) * 57.295779513082f;
    angles.z = 0.0f;
    if (angles.x < 0.0f) angles.x += 360.0f;
    if (angles.y < 0.0f) angles.y += 360.0f;
    return angles;
}

inline bool WorldToScreen(const Vector3& pos, Vector2& screen, float matrix[16], int windowWidth, int windowHeight) {
    screen.x = matrix[0] * pos.x + matrix[1] * pos.y + matrix[2] * pos.z + matrix[3];
    screen.y = matrix[4] * pos.x + matrix[5] * pos.y + matrix[6] * pos.z + matrix[7];
    float w = matrix[12] * pos.x + matrix[13] * pos.y + matrix[14] * pos.z + matrix[15];

    if (w < 0.01f) return false;

    float inv_w = 1.0f / w;
    screen.x *= inv_w;
    screen.y *= inv_w;

    float x = windowWidth / 2.0f;
    float y = windowHeight / 2.0f;

    x += 0.5f * screen.x * windowWidth + 0.5f;
    y -= 0.5f * screen.y * windowHeight + 0.5f;

    screen.x = x;
    screen.y = y;
    return true;
}
