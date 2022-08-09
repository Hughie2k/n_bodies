#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "keybind.hpp"
#include "planetcreator.hpp"
#include "planetsystem.hpp"
#include "viewcontroller.hpp"

class KeybindManager {
 public:
  KeybindManager(PlanetSystem&,
                 ViewController&,
                 sf::RenderWindow&,
                 PlanetCreator&);
  void update();

 private:
  PlanetSystem& planetSystem;
  ViewController& viewController;
  sf::RenderWindow& window;
  PlanetCreator& planetCreator;
  std::vector<Keybind*> keybinds;
  sf::Time time;
  sf::Clock clock;
  // Sadly, namespaces within classes are forbidden, hence the ugly prefixes
  // It's easier to keep the type of function pointer the same throughout all
  // instances of Keybind.
  Vec2f getNormalizedMousePosition();
  void ViewControllerMoveLeft();
  void ViewControllerMoveRight();
  void ViewControllerMoveUp();
  void ViewControllerMoveDown();
  void ViewControllerZoomIn();
  void ViewControllerZoomOut();
  void SelectPlanetWithMouse();
  void DeletePlanet();
  void SelectNextPlanet();
  void PlanetCreatorInitializePlanet();
  void PlanetCreatorGrowPlanet();
  void PlanetCreatorReleasePlanet();
};