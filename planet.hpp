#ifndef PLANET_HPP
#define PLANET_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "vector.hpp"
#include "body.hpp"

class Planet: public Body
{
public:
    sf::RenderWindow& window;
    sf::Color color;
    float radius, mass;

    Planet(sf::RenderWindow&);
    Planet(const Vec2f&, sf::RenderWindow&);
    Planet(const Vec2f&, const Vec2f&, sf::RenderWindow&);
    
    explicit operator sf::CircleShape() const;
    Vec2f gravityAccel(const Planet&) const;
    Vec2f totalGravityAccel(const std::vector<Planet>&) const;
    void draw() const;
};

#endif // PLANET_HPP