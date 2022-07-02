#define SFML_STATIC
#include <numeric>
#include <algorithm>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "vector.hpp"
#include "body.hpp"
#include "planet.hpp"
#define debug(x) std::cout << #x << " = " << x << '\n';


Planet::Planet(sf::RenderWindow& window):
    Body(),
    window(window),
    color(sf::Color::White),
    radius(),
    mass() {}
Planet::Planet(const Vec2f& position, sf::RenderWindow& window):
    Body(position, Vec2f()),
    window(window),
    color(sf::Color::White),
    radius(),
    mass() {}
Planet::Planet(const Vec2f& position, const Vec2f& velocity, sf::RenderWindow& window):
    Body(position, velocity),
    window(window),
    color(sf::Color::White),
    radius(),
    mass() {}

Planet::operator sf::CircleShape() const {
    sf::CircleShape circle(radius, 30);
    circle.setFillColor(color);
    circle.setPosition(pos - Vec2f(radius, radius));
    return circle;
}

Vec2f Planet::gravityAccel(const Planet& other) const {
    if (&other == this
       ||(other.pos-pos).squareSize()<4*radius*radius) {
        // No acceleration when the planets intersect
        return Vec2f();
    }
    Vec2f diff = other.pos - pos;
    float distanceSquared = diff.x * diff.x + diff.y * diff.y;
    float magnitude = other.mass / distanceSquared;
    return Vec2f(diff * magnitude / diff.size());
}

Vec2f Planet::totalGravityAccel(const std::vector<Planet>& planets) const {
    std::vector<Vec2f> accels(planets.size());
    for (unsigned i=0; i<planets.size(); ++i) {
        accels[i] = gravityAccel(planets[i]);
    }
    return std::accumulate(accels.begin(), accels.end(), Vec2f());
}

void Planet::draw() const {
    window.draw(sf::CircleShape(*this));
}