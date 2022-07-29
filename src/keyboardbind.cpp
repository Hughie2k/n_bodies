#include "keyboardbind.hpp"
#include <SFML/Window/Keyboard.hpp>
#include "keybind.hpp"

KeyboardBind::KeyboardBind(const sf::Keyboard::Key& key,
                           void (KeybindManager::*const doStuff)(),
                           KeybindManager& keybindManager,
                           const bool& keyRepeat)
    : Keybind(doStuff, keybindManager, keyRepeat), key(key) {}

KeyboardBind::KeyboardBind(const sf::Keyboard::Key& key,
                           void (KeybindManager::*const onPress)(),
                           void (KeybindManager::*const onRelease)(),
                           KeybindManager& keybindManager,
                           const bool& keyRepeat)
    : Keybind(onPress, onRelease, keybindManager, keyRepeat), key(key) {}

void KeyboardBind::update() {
  if (sf::Keyboard::isKeyPressed(key) && (keyRepeat || !wasJustPressed) &&
      onPress) {
    (keybindManager.*onPress)();
  }
  if (!sf::Keyboard::isKeyPressed(key) && wasJustPressed && onRelease) {
    (keybindManager.*onRelease)();
  }
  wasJustPressed = sf::Keyboard::isKeyPressed(key);
}