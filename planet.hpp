#pragma once

#include "drawableparticle.hpp"
#include "vector.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class Planet : public DrawableParticle {

public:
  float mass;
  Planet();
  Planet(const Vec2f &, const Vec2f &);
  Planet(const Vec2f &, const Vec2f &, const float &, const float &);
  operator sf::CircleShape() const;
  static std::vector<Vec2f> gravityAccel(const std::vector<Planet> &planets);
};
