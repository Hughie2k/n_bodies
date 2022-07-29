#pragma once

template <class T>
class Keybind {  // Putting the keyRepeat check in this base class would be
                 // beneficial
 public:
  Keybind(void (T::*const doStuff)(),
          T& keybindManager,
          const bool& keyRepeat = false)
      : doStuff(doStuff),
        keybindManager(keybindManager),
        keyRepeat(keyRepeat),
        wasJustPressed(false) {}
  virtual void update() = 0;
  void setKeyRepeat(const bool& newKeyRepeat) { keyRepeat = newKeyRepeat; }

 protected:
  void (T::*const doStuff)();
  T& keybindManager;
  bool keyRepeat;
  bool wasJustPressed;
};