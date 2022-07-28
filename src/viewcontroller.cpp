#include "viewcontroller.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include "vec2f.hpp"

namespace directions {
static Vec2f left(-1.f, 0.f);
static Vec2f right(1.f, 0.f);
static Vec2f up(0.f, -1.f);
static Vec2f down(0.f, 1.f);
}  // namespace directions

ViewController::ViewController(const sf::View& offset)
    : offset(offset),
      translationSpeed(1000.f / Vec2f(offset.getSize()).size()),
      zoomSpeed(5.f),
      lockedTo(nullptr) {}

inline Vec2f ViewController::translate(const sf::Time& dt,
                                       const Vec2f& direction) const {
  return direction * dt.asSeconds() *
         static_cast<Vec2f>(offset.getSize()).size() * translationSpeed;
}

#pragma region Move the camera
void ViewController::moveLeft(const sf::Time& dt) {
  offset.move(translate(dt, directions::left));
}

void ViewController::moveRight(const sf::Time& dt) {
  offset.move(translate(dt, directions::right));
}

void ViewController::moveUp(const sf::Time& dt) {
  offset.move(translate(dt, directions::up));
}

void ViewController::moveDown(const sf::Time& dt) {
  offset.move(translate(dt, directions::down));
}

void ViewController::zoomIn(const sf::Time& dt) {
  offset.zoom(1 - zoomSpeed * dt.asSeconds());
}

void ViewController::zoomOut(const sf::Time& dt) {
  offset.zoom(1 + zoomSpeed * dt.asSeconds());
}
#pragma endregion

const Vec2f* ViewController::getLock() const {
  return lockedTo;
}

void ViewController::setLock(const Vec2f* lock) {
  if (lock)
    offset.setCenter(0.f, 0.f);  // Centres the view on the planet to start with
  else if (lockedTo && !lock)
    offset.move(*lockedTo);  // Prevents weird jumps of the view when
                             // deselecting a planet
  lockedTo = lock;
}

void ViewController::update(sf::RenderWindow& window) {
  sf::View view(offset);
  if (lockedTo)
    view.move(*lockedTo);
  window.setView(view);
}