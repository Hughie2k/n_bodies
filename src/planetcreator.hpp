#pragma once

#include "SFML/Graphics.hpp"
#include "planet.hpp"
#include "planetsystem.hpp"
#include "vec2f.hpp"

class PlanetCreator : public sf::Drawable {
 public:
  PlanetCreator();
  void initializePlanet(const Vec2f&);
  void growPlanet(const sf::Time&);
  void releasePlanet(PlanetSystem&, const Vec2f&);
  virtual void draw(sf::RenderTarget&, sf::RenderStates) const override;

 private:
  Planet planet;
  float massGrowthRate;    // Units (arbitrary) per second
  float radiusGrowthRate;  // Units (px) per second
  bool planetIsGrowing;
};