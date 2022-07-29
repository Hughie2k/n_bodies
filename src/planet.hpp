#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "vec2f.hpp"

class Planet : public sf::Drawable {
 public:
  Vec2f pos, vel;
  float mass;
  sf::CircleShape shape;
  virtual void draw(sf::RenderTarget& target,
                    sf::RenderStates states) const override;
  Vec2f accel(const std::vector<Planet>& planets) const;
  Planet();
  Planet(const Vec2f&);
  Planet(const Vec2f&, const Vec2f&);
  Planet(const Vec2f&, const Vec2f&, const float&);
  Planet(const Vec2f&, const Vec2f&, const float&, const float&);
};