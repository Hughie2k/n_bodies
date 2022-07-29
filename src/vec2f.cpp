#include "vec2f.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>

Vec2f::Vec2f() : x(), y() {}
Vec2f::Vec2f(const float& i, const float& j) : x(i), y(j) {}
Vec2f::Vec2f(sf::Vector2f vector) : Vec2f(vector.x, vector.y) {}
Vec2f::operator sf::Vector2f() const {
  return sf::Vector2f(x, y);
}

Vec2f Vec2f::operator+(const Vec2f& other) const {
  return Vec2f(x + other.x, y + other.y);
}
Vec2f Vec2f::operator-() const {
  return Vec2f(-x, -y);
}
Vec2f Vec2f::operator-(const Vec2f& other) const {
  return *this + -other;
}
Vec2f& Vec2f::operator+=(const Vec2f& other) {
  *this = *this + other;
  return *this;
}
Vec2f& Vec2f::operator-=(const Vec2f& other) {
  *this = *this - other;
  return *this;
}
Vec2f Vec2f::operator*(const float& scale) const {
  return Vec2f(x * scale, y * scale);
}
Vec2f operator*(const float& scale, const Vec2f& vector) {
  return vector * scale;
}
Vec2f Vec2f::operator/(const float& invScale) const {
  return *this * (1 / invScale);
}
bool Vec2f::operator==(const Vec2f& other) const {
  return other.x == x && other.y == y;
}
bool Vec2f::operator!=(const Vec2f& other) const {
  return !(*this == other);
}
float Vec2f::squareSize() const {
  return (x * x + y * y);
}
float Vec2f::size() const {
  return std::sqrt(squareSize());
}