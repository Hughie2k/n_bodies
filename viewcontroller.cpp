#include "viewcontroller.hpp"
#include "particlesystem.hpp"
#include "vector.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

ViewController::ViewController(const sf::View &view)
    : view(view), timer(),
      translationSpeed(1000.f / Vec2f(view.getSize()).size()), zoomSpeed(5.f) {}

void ViewController::update(sf::RenderWindow &window) {
  float zoomAdjust = Vec2f(view.getSize()).size();
  float dt = timer.timeDiff().count() * 1e-6f;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    view.move(-translationSpeed * dt * zoomAdjust, 0.f);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    view.move(translationSpeed * dt * zoomAdjust, 0.f);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    view.move(0.f, -translationSpeed * dt * zoomAdjust);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    view.move(0.f, translationSpeed * dt * zoomAdjust);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Hyphen)) {
    view.zoom(1.f + dt * zoomSpeed);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal)) {
    view.zoom(1.f - dt * zoomSpeed);
  }
  window.setView(view);
}