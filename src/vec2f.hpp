#pragma once

#include <SFML/Graphics.hpp>
class Vec2f {
public:
  float x, y;

  Vec2f();
  Vec2f(const float &, const float &);
  Vec2f(sf::Vector2f);
  operator sf::Vector2f() const;

  Vec2f operator+(const Vec2f &) const;
  Vec2f operator-() const;
  Vec2f operator-(const Vec2f &) const;
  Vec2f &operator+=(const Vec2f &);
  Vec2f &operator-=(const Vec2f &);
  Vec2f operator*(const float &) const;
  friend Vec2f operator*(const float &, const Vec2f &);
  Vec2f operator/(const float &) const;
  bool operator==(const Vec2f &) const;
  bool operator!=(const Vec2f &) const;
  float squareSize() const;
  float size() const;
};
