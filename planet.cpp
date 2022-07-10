#include "planet.hpp"
#include "vector.hpp"

Planet::Planet() : DrawableParticle(), mass() {}

Planet::Planet(const Vec2f &pos, const Vec2f &vel)
    : DrawableParticle(pos, vel), mass() {}

Planet::Planet(const Vec2f &pos, const Vec2f &vel, const float &mass,
               const float &radius)
    : DrawableParticle(pos, vel, radius), mass(mass) {}

Planet::operator sf::CircleShape() const {
  sf::CircleShape circle(radius);
  circle.setPosition(pos - Vec2f(radius, radius));
  return circle;
}

std::vector<Vec2f> Planet::gravityAccel(const std::vector<Planet> &planets) {
  std::vector<Vec2f> accelerations(planets.size(), Vec2f());
  for (unsigned int i = 0; i < planets.size(); ++i) {
    for (unsigned int j = 0; j < planets.size(); ++j) {
      if (planets[j] == planets[i]) {
        continue;
      }
      Vec2f diff = planets[j].pos - planets[i].pos;
      float distance = diff.size();
      accelerations[i] +=
          planets[j].mass * diff / (distance * distance * distance);
    }
  }
  return accelerations;
}