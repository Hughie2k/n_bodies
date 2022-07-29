#pragma once

#include <SFML/Graphics.hpp>
#include "vec2f.hpp"

class ViewController {
 public:
  ViewController();
  ViewController(const sf::View&);
  void update(sf::RenderWindow&);
  void setLock(const Vec2f*);
  const Vec2f* getLock() const;
  void moveLeft(const sf::Time&);
  void moveRight(const sf::Time&);
  void moveUp(const sf::Time&);
  void moveDown(const sf::Time&);
  void zoomIn(const sf::Time&);
  void zoomOut(const sf::Time&);

 private:
  sf::View offset;
  float translationSpeed;  // pixels per second
  float zoomSpeed;
  const Vec2f*
      lockedTo;  // Can lock to some point, e.g. the position of a planet
  Vec2f translate(const sf::Time&, const Vec2f&) const;
};