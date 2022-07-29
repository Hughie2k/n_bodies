#include "keyboardbind.hpp"
#include <SFML/Window/Keyboard.hpp>
#include "keybind.hpp"

KeyboardBind::KeyboardBind(const sf::Keyboard::Key& key,
                           void (KeybindManager::*const doStuff)(),
                           KeybindManager& keybindManager,
                           const bool& keyRepeat)
    : key(key), Keybind(doStuff, keybindManager, keyRepeat) {}

void KeyboardBind::update() {
  if (sf::Keyboard::isKeyPressed(key) && (keyRepeat || !wasJustPressed)) {
    (keybindManager.*(doStuff))();
  }
  wasJustPressed = sf::Keyboard::isKeyPressed(key);
}