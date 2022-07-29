#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "keybind.hpp"
#include "planetsystem.hpp"
#include "viewcontroller.hpp"

class KeybindManager {
 public:
  KeybindManager(PlanetSystem&, ViewController&, sf::RenderWindow&);
  void update();

 private:
  PlanetSystem& planetSystem;
  ViewController& viewController;
  sf::RenderWindow& window;
  std::vector<Keybind<KeybindManager>*> keybinds;
  sf::Time time;
  sf::Clock clock;
  // Sadly, namespaces within classes are forbidden, hence the ugly prefixes
  // It's easier to keep the type of function pointer the same throughout all
  // instances of Keybind
  void ViewControllerMoveLeft();
  void ViewControllerMoveRight();
  void ViewControllerMoveUp();
  void ViewControllerMoveDown();
  void ViewControllerZoomIn();
  void ViewControllerZoomOut();
  void SelectPlanetWithMouse();
  void PlanetSystemDeletePlanet();
};