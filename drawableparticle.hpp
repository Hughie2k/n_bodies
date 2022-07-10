#pragma once

#include "vector.hpp"
#include <SFML/Graphics.hpp>

class DrawableParticle {
public:
  Vec2f pos, vel;
  float radius;
  DrawableParticle();
  DrawableParticle(const Vec2f &, const Vec2f &);
  DrawableParticle(const Vec2f &, const Vec2f &, const float &);
  bool operator==(const DrawableParticle &) const;
};
