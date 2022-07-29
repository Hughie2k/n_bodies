#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "planet.hpp"
#include "viewcontroller.hpp"

class PlanetSystem : public sf::Drawable {
 public:
  PlanetSystem();
  PlanetSystem(const std::vector<Planet>&);

  void eulerMove();
  void rk4Move();
  std::vector<Vec2f> accelCalc(const std::vector<Planet>&) const;
  virtual void draw(sf::RenderTarget&, sf::RenderStates) const override;
  // void updateIO(sf::RenderWindow&);
  Vec2f* selectPlanet(const size_t&);
  Vec2f* selectNextPlanet();
  Vec2f* selectPreviousPlanet();
  Vec2f* selectPlanetWithMouse(const Vec2f&);
  Vec2f* deleteSelectedPlanet();
  void addPlanet(const Planet&);

 private:
  std::vector<Planet> planets;
  sf::Clock clock;
  std::vector<Planet>::iterator selected;
};