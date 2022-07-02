#define SFML_STATIC
#include <cmath>
#include "vector.hpp"


Vec2f::Vec2f() : x(), y() {}
Vec2f::Vec2f(float i, float j) : x(i), y(j) {}
Vec2f::Vec2f(sf::Vector2f v) : x(v.x), y(v.y) {}

Vec2f Vec2f::operator+(const Vec2f other) const {
    return Vec2f(this->x + other.x, this->y + other.y);
}
Vec2f Vec2f::operator-() const {
    return Vec2f(-this->x, -this->y);
}
Vec2f Vec2f::operator-(const Vec2f other) const {
    return *this + -other;
}
Vec2f& Vec2f::operator+=(const Vec2f other) {
    *this = *this + other;
    return *this;
}
Vec2f& Vec2f::operator-=(const Vec2f other) {
    *this = *this - other;
    return *this;
}
Vec2f Vec2f::operator*(const float scale) const {
    return Vec2f(x * scale, y * scale);
}
Vec2f operator*(const float scale, const Vec2f vector) {
    return vector * scale;
}
Vec2f Vec2f::operator/(const float invScale) const {
    return *this * (1 / invScale);
}
bool Vec2f::operator==(const Vec2f other) const {
    return other.x == x && other.y == y;
}
bool Vec2f::operator!=(const Vec2f other) const {
    return !(*this == other);
}
Vec2f::operator sf::Vector2f() const {
    return sf::Vector2f(x, y);
}
float Vec2f::squareSize() const {
    return (x*x + y*y);
}
float Vec2f::size() const {
    return std::sqrt(squareSize());
}