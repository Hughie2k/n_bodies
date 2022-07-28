#include "planet.hpp"
#include "SFML/Graphics/Drawable.hpp"
#include "vec2f.hpp"

void Planet::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  sf::CircleShape circle = shape;
  circle.setPosition(pos - Vec2f(shape.getRadius(), shape.getRadius()));
  target.draw(circle);
}

Vec2f Planet::accel(const std::vector<Planet>& planets) const {
  Vec2f acc;
  for (const Planet& planet : planets) {
    if (&planet == this) {
      continue;
    }
    Vec2f diff = planet.pos - pos;
    float distance = diff.size();
    acc += planet.mass * diff / (distance * distance * distance);
  }
  return acc;
}

Planet::Planet() : pos(), vel(), shape() {}

Planet::Planet(const Vec2f& pos) : pos(pos), shape() {
  shape.setOutlineColor(sf::Color::Green);
}

Planet::Planet(const Vec2f& pos, const Vec2f& vel)
    : pos(pos), vel(vel), shape() {
  shape.setOutlineColor(sf::Color::Green);
}

Planet::Planet(const Vec2f& pos, const Vec2f& vel, const float& mass)
    : pos(pos), vel(vel), mass(mass), shape() {
  shape.setOutlineColor(sf::Color::Green);
}

Planet::Planet(const Vec2f& pos,
               const Vec2f& vel,
               const float& mass,
               const float& radius)
    : pos(pos), vel(vel), mass(mass), shape(radius) {
  shape.setOutlineColor(sf::Color::Green);
}
