#pragma once

#include <SFML/Window/Mouse.hpp>
#include "keybind.hpp"
#include "keybindmanager.hpp"

class MouseBind : public Keybind<KeybindManager> {
 public:
  MouseBind(const sf::Mouse::Button&,
            void (KeybindManager::*const)(),
            KeybindManager&,
            const bool& keyRepeat = false);
  MouseBind(const sf::Mouse::Button&,
            void (KeybindManager::*const)(),
            void (KeybindManager::*const)(),
            KeybindManager&,
            const bool& keyRepeat = false);
  virtual void update() override;

 private:
  sf::Mouse::Button button;
};
