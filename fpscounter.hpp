#pragma once

#include "timer.hpp"
#include "vector.hpp"
#include <SFML/Graphics.hpp>
#include <numeric>
#include <queue>

class FpsCounter {
private:
  std::queue<float> frameTimes; // floats representing seconds, can't be arsed
                                // with std::chrono
  Timer timer;
  float totalT;
  float fps;
  const sf::Font &font;

public:
  FpsCounter(const unsigned int &, const float &,
             const sf::Font &); // n is number of framtimes stored, t is how
                                // much time n frames should take (will become
                                // irrelevant once n frames have passed)
  void update();
  float getFps() const;
  void draw(const Vec2f &, sf::RenderWindow &) const;
};