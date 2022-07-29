#include "planetcreator.hpp"
#include "planet.hpp"
#include "vec2f.hpp"

PlanetCreator::PlanetCreator()
    : planet(),
      massGrowthRate(1e7f),
      radiusGrowthRate(4.f),
      planetIsGrowing(false) {
  planet.shape.setOutlineColor(sf::Color::Green);
}

void PlanetCreator::initializePlanet(const Vec2f& mousePos) {
  planet.pos = mousePos;
  planetIsGrowing = true;
}

void PlanetCreator::growPlanet(const sf::Time& dt) {
  if (!planetIsGrowing) {
    return;
  }
  planet.shape.setRadius(planet.shape.getRadius() +
                         dt.asSeconds() * radiusGrowthRate);
  planet.mass += dt.asSeconds() * massGrowthRate;
  planet.shape.setPosition(
      planet.pos - Vec2f(planet.shape.getRadius(), planet.shape.getRadius()));
}

void PlanetCreator::releasePlanet(PlanetSystem& planetSystem,
                                  const Vec2f& mousePos) {
  if (!planetIsGrowing) {
    return;
  }
  planet.vel = (planet.pos - mousePos) * 2.f;
  planetSystem.addPlanet(planet);
  planet.shape.setRadius(0.f);
  planet.mass = 0.f;
  planetIsGrowing = false;
}

void PlanetCreator::draw(sf::RenderTarget& target, sf::RenderStates) const {
  if (planet.shape.getRadius()) {
    target.draw(planet.shape);
  }
}