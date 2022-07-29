#pragma once

#include <SFML/Graphics.hpp>
#include <numeric>
#include <queue>
#include "vec2f.hpp"

class FpsCounter : public sf::Drawable {
 public:
  FpsCounter(const unsigned int&,
             const float&,
             const sf::Font&);  // n is number of framtimes stored, t is how
                                // much time n frames should take (will become
                                // irrelevant once n frames have passed)
  void update();
  float getFps() const;
  virtual void draw(sf::RenderTarget&, sf::RenderStates) const override;
  Vec2f getPos() const;
  void setPos(const Vec2f&);

 private:
  std::queue<float> frameTimes;  // floats representing seconds, can't be
                                 // arsed with std::chrono
  sf::Clock clock;
  float totalT;
  float fps;
  const sf::Font& font;
  Vec2f pos;
};
