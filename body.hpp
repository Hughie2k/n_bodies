#ifndef BODY_HPP
#define BODY_HPP
#include <chrono>
#include "vector.hpp"
#include "timer.hpp"

class Body
{
private:
    Timer time;
public:
    Vec2f pos, prevPos, vel, acc, nextAcc;
    Body();
    Body(const Vec2f& p, const Vec2f& v);

    void eulerMove(); // nextAcc has to be adjusted appropriately (perhaps not at all if constant) before this is called
    void improvedEulerMove();
    void verletMove(); // TODO implement it!
    void rk2Move();
};

#endif // BODY_HPP