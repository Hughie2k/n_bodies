#include "drawableparticle.hpp"
#include <SFML/Graphics.hpp>

DrawableParticle::DrawableParticle() : pos(), vel(), radius() {}

DrawableParticle::DrawableParticle(const Vec2f &pos, const Vec2f &vel)
    : pos(pos), vel(vel), radius() {}

DrawableParticle::DrawableParticle(const Vec2f &pos, const Vec2f &vel,
                                   const float &radius)
    : pos(pos), vel(vel), radius(radius) {}

bool DrawableParticle::operator==(const DrawableParticle &other) const {
  return &other == this;
}
