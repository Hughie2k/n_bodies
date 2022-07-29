#pragma once

template <class T>  // Template because of a circular dependency issue, class T
                    // is always KeybindManager (for now)
class Keybind {     // Putting the keyRepeat check in this base
                    // class would be beneficial
 public:
  Keybind(void (T::*const onPress)(),
          T& keybindManager,
          const bool& keyRepeat = false)
      : onPress(onPress),
        onRelease(nullptr),
        keybindManager(keybindManager),
        keyRepeat(keyRepeat),
        wasJustPressed(false) {}
  Keybind(void (T::*const onPress)(),
          void (T::*const onRelease)(),
          T& keybindManager,
          const bool& keyRepeat = false)
      : onPress(onPress),
        onRelease(onRelease),
        keybindManager(keybindManager),
        keyRepeat(keyRepeat),
        wasJustPressed(false) {}
  virtual void update() = 0;
  void setKeyRepeat(const bool& newKeyRepeat) { keyRepeat = newKeyRepeat; }

 protected:
  void (T::*const onPress)();
  void (T::*const onRelease)();
  T& keybindManager;
  bool keyRepeat;
  bool wasJustPressed;
};