#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <SFML/Graphics.hpp>

class Vec2f
{
public:
    float x, y;

    Vec2f();
    Vec2f(const float i, const float j);
    Vec2f(const sf::Vector2f v);
    
    Vec2f operator+(const Vec2f other) const;
    Vec2f operator-() const;
    Vec2f operator-(const Vec2f other) const;
    Vec2f& operator+=(const Vec2f other);
    Vec2f& operator-=(const Vec2f other);
    Vec2f operator*(const float scale) const;
    friend Vec2f operator*(const float, const Vec2f);
    Vec2f operator/(const float invScale) const;
    bool operator==(const Vec2f other) const;
    bool operator!=(const Vec2f other) const;
    operator sf::Vector2f() const;
    float squareSize() const;
    float size() const;
};

#endif // VECTOR_HPP