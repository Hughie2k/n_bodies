#include "keybindmanager.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "keybind.hpp"
#include "keyboardbind.hpp"
#include "mousebind.hpp"
#include "viewcontroller.hpp"
using std::cout;

KeybindManager::KeybindManager(PlanetSystem& planetSystem,
                               ViewController& view,
                               sf::RenderWindow& window)
    : planetSystem(planetSystem),
      viewController(view),
      window(window),
      time(),
      clock() {
  KeyboardBind* moveLeft =
      new KeyboardBind(sf::Keyboard::Key::Left,
                       &KeybindManager::ViewControllerMoveLeft, *this, true);
  KeyboardBind* moveRight =
      new KeyboardBind(sf::Keyboard::Key::Right,
                       &KeybindManager::ViewControllerMoveRight, *this, true);
  KeyboardBind* moveUp =
      new KeyboardBind(sf::Keyboard::Key::Up,
                       &KeybindManager::ViewControllerMoveUp, *this, true);
  KeyboardBind* moveDown =
      new KeyboardBind(sf::Keyboard::Key::Down,
                       &KeybindManager::ViewControllerMoveDown, *this, true);
  KeyboardBind* zoomOut =
      new KeyboardBind(sf::Keyboard::Key::Hyphen,
                       &KeybindManager::ViewControllerZoomOut, *this, true);
  KeyboardBind* zoomIn =
      new KeyboardBind(sf::Keyboard::Key::Equal,
                       &KeybindManager::ViewControllerZoomIn, *this, true);
  MouseBind* selectPlanet =
      new MouseBind(sf::Mouse::Button::Left,
                    &KeybindManager::SelectPlanetWithMouse, *this, false);
  KeyboardBind* deletePlanet = new KeyboardBind(
      sf::Keyboard::Key::Delete, &KeybindManager::DeletePlanet, *this, false);
  KeyboardBind* nextPlanet = new KeyboardBind(
      sf::Keyboard::Key::N, &KeybindManager::SelectNextPlanet, *this, false);
  keybinds = {moveLeft, moveRight,    moveUp,       moveDown,  zoomIn,
              zoomOut,  selectPlanet, deletePlanet, nextPlanet};
}

void KeybindManager::update() {
  time = clock.restart();
  for (Keybind<KeybindManager>* keybind : keybinds) {
    keybind->update();
  }
}

#pragma region Move / zoom the camera with the viewController
void KeybindManager::ViewControllerMoveLeft() {
  viewController.moveLeft(time);
}

void KeybindManager::ViewControllerMoveRight() {
  viewController.moveRight(time);
}

void KeybindManager::ViewControllerMoveUp() {
  viewController.moveUp(time);
}

void KeybindManager::ViewControllerMoveDown() {
  viewController.moveDown(time);
}

void KeybindManager::ViewControllerZoomIn() {
  viewController.zoomIn(time);
}

void KeybindManager::ViewControllerZoomOut() {
  viewController.zoomOut(time);
}
#pragma endregion

#pragma region Select of delete planets with the planetSystem
void KeybindManager::SelectNextPlanet() {
  viewController.setLock(planetSystem.selectNextPlanet());
}

void KeybindManager::SelectPlanetWithMouse() {
  Vec2f mousePos = static_cast<Vec2f>(
      static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
  mousePos =
      Vec2f(mousePos.x / window.getSize().x * window.getView().getSize().x,
            mousePos.y / window.getSize().y * window.getView().getSize().y) +
      window.getView().getCenter() - window.getView().getSize() / 2.f;
  viewController.setLock(planetSystem.selectPlanetWithMouse(mousePos));
}

void KeybindManager::DeletePlanet() {
  viewController.setLock(planetSystem.deletePlanet());
}
#pragma endregion