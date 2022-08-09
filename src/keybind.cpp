
#pragma once

#include "keybind.hpp"


Keybind::Keybind(void (KeybindManager::*const onPress)(),
                 KeybindManager& keybindManager,
                 const bool& keyRepeat/* = false*/)
    : onPress(onPress),
      onRelease(nullptr),
      keybindManager(keybindManager),
      keyRepeat(keyRepeat),
      wasJustPressed(false) {}

Keybind::Keybind(void (KeybindManager::*const onPress)(),
        void (KeybindManager::*const onRelease)(),
        KeybindManager& keybindManager,
        const bool& keyRepeat/* = false*/)
    : onPress(onPress),
      onRelease(onRelease),
      keybindManager(keybindManager),
      keyRepeat(keyRepeat),
      wasJustPressed(false) {}

void Keybind::setKeyRepeat(const bool& newKeyRepeat) { keyRepeat = newKeyRepeat; }

/*
class Keybind {     // Putting the keyRepeat check in this base
                    // class would be beneficial
 public:
  Keybind(void (KeybindManager::*const onPress)(),
          KeybindManager& keybindManager,
          const bool& keyRepeat = false)
      : onPress(onPress),
        onRelease(nullptr),
        keybindManager(keybindManager),
        keyRepeat(keyRepeat),
        wasJustPressed(false) {}
  Keybind(void (KeybindManager::*const onPress)(),
          void (KeybindManager::*const onRelease)(),
          KeybindManager& keybindManager,
          const bool& keyRepeat = false)
      : onPress(onPress),
        onRelease(onRelease),
        keybindManager(keybindManager),
        keyRepeat(keyRepeat),
        wasJustPressed(false) {}
  virtual void update() = 0;
  void setKeyRepeat(const bool& newKeyRepeat) { keyRepeat = newKeyRepeat; }

 protected:
  void (KeybindManager::*const onPress)();
  void (KeybindManager::*const onRelease)();
  KeybindManager& keybindManager;
  bool keyRepeat;
  bool wasJustPressed;
};
*/