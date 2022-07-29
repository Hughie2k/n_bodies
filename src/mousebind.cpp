#include "mousebind.hpp"
#include <SFML/Window/Mouse.hpp>
#include "keybind.hpp"

MouseBind::MouseBind(const sf::Mouse::Button& button,
                     void (KeybindManager::*const doStuff)(),
                     KeybindManager& keybindManager,
                     const bool& keyRepeat)
    : button(button), Keybind(doStuff, keybindManager, keyRepeat) {}

MouseBind::MouseBind(const sf::Mouse::Button& button,
                     void (KeybindManager::*const onPress)(),
                     void (KeybindManager::*const onRelease)(),
                     KeybindManager& keybindManager,
                     const bool& keyRepeat)
    : button(button), Keybind(onPress, onRelease, keybindManager, keyRepeat) {}

void MouseBind::update() {
  if (sf::Mouse::isButtonPressed(button) && (keyRepeat || !wasJustPressed) &&
      onPress) {
    (keybindManager.*(onPress))();
  }
  if (!sf::Mouse::isButtonPressed(button) && wasJustPressed && onRelease) {
    (keybindManager.*onRelease)();
  }
  wasJustPressed = sf::Mouse::isButtonPressed(button);
}