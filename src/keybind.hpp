#pragma once

class KeybindManager;

class Keybind {     // Putting the keyRepeat check in this base
                    // class would be beneficial
 public:
  Keybind(void (KeybindManager::*const onPress)(),
          KeybindManager& keybindManager,
          const bool& keyRepeat = false);
  Keybind(void (KeybindManager::*const onPress)(),
          void (KeybindManager::*const onRelease)(),
          KeybindManager& keybindManager,
          const bool& keyRepeat = false);
  virtual void update() = 0;
  void setKeyRepeat(const bool& newKeyRepeat);

 protected:
  void (KeybindManager::*const onPress)();
  void (KeybindManager::*const onRelease)();
  KeybindManager& keybindManager;
  bool keyRepeat;
  bool wasJustPressed;
};