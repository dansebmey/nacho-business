#pragma once

class Vec2D {
    public:
        float x, y;

        Vec2D(float x, float y);

        float sqrtMagnitude();
        float angle();
        float angleRad();
        float dot(Vec2D b);
        Vec2D normalised();
        static float dot(Vec2D a, Vec2D b);
        static float cross(Vec2D a, Vec2D b);
        static float distanceBetween(Vec2D a, Vec2D b);

        Vec2D& operator+(const Vec2D& rhs);
        Vec2D& operator+=(const Vec2D& rhs);
        Vec2D& operator-(const Vec2D& rhs);
        Vec2D& operator-=(const Vec2D& rhs);
        Vec2D& operator*(const Vec2D& rhs);
        Vec2D& operator*=(const Vec2D& rhs);

        Vec2D& operator*(const float& rhs);
        Vec2D& operator*=(const float& rhs);

    private:
        float magnitude();
};