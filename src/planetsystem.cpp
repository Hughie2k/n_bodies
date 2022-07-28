#include "planetsystem.hpp"
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <functional>
#include <iostream>
#include "vec2f.hpp"
#include "viewcontroller.hpp"

std::vector<Vec2f> PlanetSystem::accelCalc(
    const std::vector<Planet>& planets) const {
  size_t n = planets.size();
  std::vector<Vec2f> accels(n);
  for (size_t i = 0; i < n; ++i) {
    accels[i] = planets[i].accel(planets);
  }
  return accels;
}

void PlanetSystem::draw(sf::RenderTarget& target,
                        sf::RenderStates states) const {
  for (const Planet& planet : planets) {
    target.draw(planet);
  }
}

void PlanetSystem::eulerMove() {
  float dt = clock.restart().asSeconds();
  std::vector<Vec2f> accelerations = accelCalc(planets);
  for (size_t i = 0; i < planets.size(); ++i) {
    planets[i].pos += dt * planets[i].vel + 0.5f * dt * dt * accelerations[i];
    planets[i].vel += dt * accelerations[i];
  }
}

void PlanetSystem::rk4Move() {
  float dt = clock.restart().asSeconds();
  std::vector<Vec2f> k1 = accelCalc(planets);
  std::vector<Planet> nextPlanets =
      planets;  // Need to calculate next batch of accelerations
  /* A brief synopsis of the following code:
  Use the last calculated batch of accelerations (kn) to adjust the position
  and velocities of the nextPlanets, repeat until k4, use a weighted average of
  each k as the final acceleration to move the planets */
  for (size_t i = 0; i < nextPlanets.size(); ++i) {
    nextPlanets[i].pos +=
        0.5f * dt * nextPlanets[i].vel + 0.25f * dt * dt * k1[i];
    nextPlanets[i].vel += 0.5f * dt * k1[i];
  }
  std::vector<Vec2f> k2 = accelCalc(nextPlanets);
  for (size_t i = 0; i < nextPlanets.size(); ++i) {
    nextPlanets[i].pos = planets[i].pos + 0.5f * dt * nextPlanets[i].vel +
                         0.25f * dt * dt * k2[i];
    nextPlanets[i].vel = planets[i].vel + 0.5f * dt * k2[i];
  }
  std::vector<Vec2f> k3 = accelCalc(nextPlanets);
  for (size_t i = 0; i < nextPlanets.size(); ++i) {
    nextPlanets[i].pos =
        planets[i].pos + dt * nextPlanets[i].vel + 0.5f * dt * dt * k3[i];
    nextPlanets[i].vel = planets[i].vel + dt * k3[i];
  }
  std::vector<Vec2f> k4 = accelCalc(nextPlanets);
  for (unsigned int i = 0; i < nextPlanets.size(); ++i) {
    Vec2f accel = 0.16667f * (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i]);
    planets[i].pos += dt * planets[i].vel + 0.5f * dt * dt * accel;
    planets[i].vel += dt * accel;
  }
}

Vec2f* PlanetSystem::selectPlanet(const size_t& i) {
  if (selected != planets.end()) {
    selected->shape.setOutlineThickness(0.f);
  }
  if (selected - planets.begin() == i) {
    selected = planets.end();
    return nullptr;
  }
  selected = planets.begin() + i;
  selected->shape.setOutlineThickness(2.f);
  return &selected->pos;
}

Vec2f* PlanetSystem::selectNextPlanet() {
  return selectPlanet(selected == planets.end()
                          ? 0
                          : (selected - planets.begin() + 1) % planets.size());
}

Vec2f* PlanetSystem::selectPlanetWithMouse(const Vec2f& mousePos) {
  for (size_t i = 0; i < planets.size(); ++i) {
    const Planet& planet = planets[i];
    if ((mousePos - planet.pos).squareSize() <
        planet.shape.getRadius() * planet.shape.getRadius()) {
      return selectPlanet(i);
    }
  }
  return selected == planets.end() ? nullptr : &selected->pos;
}

Vec2f* PlanetSystem::deletePlanet() {
  if (selected != planets.end()) {
    planets.erase(selected);
    selected = planets.end();
  }
  return nullptr;
}

/*
void PlanetSystem::updateIO(sf::RenderWindow& window) {
  viewController.update(window);
  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
    std::cout << "mouse down\n";
    Vec2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
    Vec2f relativePos =
        Vec2f(mousePos.x / window.getSize().x * window.getView().getSize().x,
              mousePos.y / window.getSize().y * window.getView().getSize().y) +
        window.getView().getCenter() - window.getView().getSize() / 2.f;
    std::cout << "MOUSE: " << relativePos.x << ", " << relativePos.y << '\n';
    for (int i = 0; i < planets.size(); ++i) {
      std::cout << "PLANET #" << i << ": " << planets[i].pos.x << ", "
                << planets[i].pos.y << '\n';
      if ((planets[i].pos - relativePos).squareSize() <=
          planets[i].shape.getRadius() * planets[i].shape.getRadius()) {
        std::cout << "clicked\n";
        planets[i].shape.setOutlineThickness(2.f);
        if (selected != planets.end()) {
          selected->shape.setOutlineThickness(0.f);
        }
        if (selected == planets.begin() + i) {
          selected = planets.end();
          viewController.setLock(nullptr);
        } else {
          selected = planets.begin() + i;
          viewController.setLock(&selected->pos);
        }
      }
    }
  }
  if (selected != planets.end() &&
      sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)) {
    planets.erase(selected);
    selected = planets.end();
  }
}
*/

PlanetSystem::PlanetSystem() : planets(), clock(), selected(planets.end()) {}
PlanetSystem::PlanetSystem(const std::vector<Planet>& _planets)
    : planets(_planets), clock(), selected(planets.end()) {}