#pragma once

#include "timer.hpp"
#include "vector.hpp"
#include <SFML/Graphics.hpp>

class ViewController {
private:
  sf::View view;
  Timer timer;
  float translationSpeed; // pixels per second
  float zoomSpeed;
  bool locked;

public:
  ViewController(const sf::View &);
  void update(sf::RenderWindow &);
};
