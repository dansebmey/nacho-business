#include "Vec2D.h"
#include <cmath>
#include <iostream>

Vec2D::Vec2D(float x, float y) : x(x), y(y) {}

float Vec2D::magnitude() {
    return pow(x, 2) + pow(y, 2);
}

float Vec2D::sqrtMagnitude() {
    return sqrt(pow(x, 2) + pow(y, 2));
}

float Vec2D::angle() {
    return atan2(y, x) * (180 / M_PI);
}

float Vec2D::angleRad() {
    return atan2(y, x);
}

Vec2D& Vec2D::operator+(const Vec2D& rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
}

Vec2D& Vec2D::operator+=(const Vec2D& rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
}

Vec2D& Vec2D::operator-(const Vec2D& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

Vec2D& Vec2D::operator-=(const Vec2D& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

Vec2D& Vec2D::operator*(const Vec2D& rhs) {
    x *= rhs.x;
    y *= rhs.y;
    return *this;
}

Vec2D& Vec2D::operator*=(const Vec2D& rhs) {
    x *= rhs.x;
    y *= rhs.y;
    return *this;
}

Vec2D &Vec2D::operator*(const float& rhs) {
    x *= rhs;
    y *= rhs;
    return *this;
}

Vec2D &Vec2D::operator*=(const float& rhs) {
    x *= rhs;
    y *= rhs;
    return *this;
}

float Vec2D::distanceBetween(Vec2D a, Vec2D b) {
    return (a - b).sqrtMagnitude();
}

float Vec2D::dot(Vec2D b) {
    return (x * b.x) + (y * b.y);
}

float Vec2D::dot(Vec2D a, Vec2D b) {
    return (a.x * b.x) + (a.y * b.y);
}

Vec2D Vec2D::normalised() {
    return Vec2D(x / sqrtMagnitude(), y / sqrtMagnitude());
}

float Vec2D::cross(Vec2D a, Vec2D b) {
//    return Vector2()
    return 1;
}
