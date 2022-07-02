#define SFML_STATIC
#include <chrono>
#include <ratio>
#include <iostream>
#include "body.hpp"
#include "vector.hpp"
#include "timer.hpp"
#define debug(x) std::cout << #x << " = " << x << '\n';

Body::Body():
    time(),
    pos(),
    vel(),
    acc(),  
    nextAcc() {} // Set all to 0

Body::Body(const Vec2f& p, const Vec2f& v):
    time(),
    pos(p),
    vel(v * 1e-6f), // 1e6f so that velocity is in px/s, not px/μs
    acc(),
    nextAcc() {} // Set all to 0

void Body::eulerMove() { // nextAcc has to be adjusted appropriately (perhaps not at all if constant) before this is called
    long dt = time.timeDiff().count();
    pos += dt * ((vel += dt * nextAcc) + dt * nextAcc); // This works perfectly when jerk is 0, otherwise not so perfectly :(
    acc = nextAcc;
}

void Body::improvedEulerMove() {
    long dt = time.timeDiff().count();
    Vec2f nextVel = vel + 0.5f * dt * (acc + nextAcc); // Like a trapezium vs rectangle
    pos += 0.5f * dt * (vel + nextVel);
    vel = nextVel;
    acc = nextAcc;
}

void Body::rk2Move() {
    long dt = time.timeDiff().count();
    
}