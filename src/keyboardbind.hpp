#pragma once

#include <SFML/Window/Keyboard.hpp>
#include "keybind.hpp"
#include "keybindmanager.hpp"

class KeyboardBind : public Keybind<KeybindManager> {
 public:
  KeyboardBind(const sf::Keyboard::Key&,
               void (KeybindManager::*const)(),
               KeybindManager&,
               const bool& keyRepeat = false);
  KeyboardBind(const sf::Keyboard::Key&,
               void (KeybindManager::*const)(),
               void (KeybindManager::*const)(),
               KeybindManager&,
               const bool& keyRepeat = false);
  virtual void update() override;

 private:
  sf::Keyboard::Key key;
};