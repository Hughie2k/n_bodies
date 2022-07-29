#include "planetcreator.hpp"
#include "planet.hpp"
#include "vec2f.hpp"

PlanetCreator::PlanetCreator()
    : planet(), massGrowthRate(5e7f), radiusGrowthRate(4.f) {}

void PlanetCreator::initializePlanet(const Vec2f& mousePos) {
  planet.pos = mousePos;
}

void PlanetCreator::growPlanet(const sf::Time& dt) {
  planet.shape.setRadius(planet.shape.getRadius() +
                         dt.asSeconds() * radiusGrowthRate);
  planet.mass += dt.asSeconds() * massGrowthRate;
  planet.shape.setPosition(
      planet.pos - Vec2f(planet.shape.getRadius(), planet.shape.getRadius()));
}

void PlanetCreator::releasePlanet(PlanetSystem& planetSystem,
                                  const Vec2f& mousePos) {
  planet.vel = planet.pos - mousePos;
  planetSystem.addPlanet(planet);
  planet.shape.setRadius(0.f);
  planet.mass = 0.f;
}

void PlanetCreator::draw(sf::RenderTarget& target, sf::RenderStates) const {
  if (planet.shape.getRadius()) {
    target.draw(planet.shape);
  }
}