#include "planetcreator.hpp"
#include "planet.hpp"
#include "vec2f.hpp"

PlanetCreator::PlanetCreator()
    : planet(),
      massGrowthRate(1e7f),
      radiusGrowthRate(4.f),
      planetIsGrowing(false) {
  planet.shape.setOutlineColor(sf::Color::Green);
  planet.shape.setFillColor(
      sf::Color(0x100 * (rand() % 0xAAAAAA) + 0x555555FF));
}

void PlanetCreator::initializePlanet(const Vec2f& mousePos) {
  std::srand(static_cast<unsigned>(mousePos.x));
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
  planet.shape.setFillColor(
      sf::Color(0x100 * (rand() % 0xAAAAAA) + 0x555555FF));
}

void PlanetCreator::draw(sf::RenderTarget& target, sf::RenderStates) const {
  if (planet.shape.getRadius()) {
    target.draw(planet.shape);
  }
}