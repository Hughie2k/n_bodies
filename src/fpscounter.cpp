#include "fpscounter.hpp"
#include <SFML/Graphics.hpp>
#include <string>

FpsCounter::FpsCounter(const unsigned int& N,
                       const float& t,
                       const sf::Font& font)
    : frameTimes(), clock(), totalT(t), fps(), font(font) {
  unsigned int n = N;
  while (n--) {
    frameTimes.push(t / N);
  }
}

void FpsCounter::update() {
  float dt = clock.restart().asSeconds();
  totalT += (dt - frameTimes.front());
  frameTimes.push(dt);
  frameTimes.pop();
  fps = frameTimes.size() / totalT;
}

float FpsCounter::getFps() const {
  return fps;
}

void FpsCounter::draw(sf::RenderTarget& target, sf::RenderStates) const {
  sf::Text fpsText;
  sf::View original = target.getView();
  fpsText.setFont(font);
  fpsText.setString(std::to_string(fps));
  target.setView(target.getDefaultView());
  target.draw(fpsText);
  target.setView(original);
}
