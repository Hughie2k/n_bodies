#include "fpscounter.hpp"
#include "vector.hpp"
#include <SFML/Graphics.hpp>
#include <string>

FpsCounter::FpsCounter(const unsigned int &N, const float &t,
                       const sf::Font &font)
    : frameTimes(), timer(), totalT(t), fps(), font(font) {
  unsigned int n = N;
  while (n--) {
    frameTimes.push(t / N);
  }
}

void FpsCounter::update() {
  float dt = timer.timeDiff().count() * 1e-6;
  totalT += (dt - frameTimes.front());
  frameTimes.push(dt);
  frameTimes.pop();
  fps = frameTimes.size() / totalT;
}

float FpsCounter::getFps() const { return fps; }

void FpsCounter::draw(const Vec2f &pos, sf::RenderWindow &window) const {
  sf::Text fpsText;
  fpsText.setFont(font);
  fpsText.setString(std::to_string(fps));
  window.setView(window.getDefaultView());
  window.draw(fpsText);
}