#include "mousebind.hpp"
#include <SFML/Window/Mouse.hpp>
#include "keybind.hpp"

MouseBind::MouseBind(const sf::Mouse::Button& button,
                     void (KeybindManager::*const doStuff)(),
                     KeybindManager& keybindManager,
                     const bool& keyRepeat)
    : button(button), Keybind(doStuff, keybindManager, keyRepeat) {}

void MouseBind::update() {
  if (sf::Mouse::isButtonPressed(button) && (keyRepeat || !wasJustPressed)) {
    (keybindManager.*(doStuff))();
  }
  wasJustPressed = sf::Mouse::isButtonPressed(button);
}