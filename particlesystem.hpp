#pragma once

#include "drawableparticle.hpp"
#include "planet.hpp"
#include "timer.hpp"
#include "vector.hpp"
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <type_traits>
#include <vector>

template <class T>
concept DerivedFromDrawableParticle =
    std::is_base_of<DrawableParticle, T>::value;

template <class T>
requires DerivedFromDrawableParticle<T>
class ParticleSystem {
private:
  Timer timer;
  std::vector<Vec2f> (*accelCalc)(const std::vector<T> &);
  std::vector<T> particles;
  // sf::RenderWindow &window;

public:
  ParticleSystem(std::vector<Vec2f> (*accelCalc)(const std::vector<T> &))
      : timer(), accelCalc(), particles() {}

  ParticleSystem(std::vector<Vec2f> (*accelCalc)(const std::vector<T> &),
                 const std::vector<T> &particles)
      : timer(), accelCalc(accelCalc), particles(particles) {}

  void eulerMove() {
    float dt = timer.timeDiff().count() * 1e-6f;
    std::vector<Vec2f> accelerations = accelCalc(particles);
    for (unsigned int i = 0; i < particles.size(); ++i) {
      particles[i].pos +=
          dt * particles[i].vel + 0.5f * dt * dt * accelerations[i];
      particles[i].vel += dt * accelerations[i];
    }
  }

  void rk4Move() {
    float dt = timer.timeDiff().count() * 1e-6f;
    std::vector<Vec2f> k1 = accelCalc(particles);
    std::vector<T> nextParticles = particles;
    for (unsigned int i = 0; i < nextParticles.size(); ++i) {
      nextParticles[i].pos +=
          0.5f * dt * nextParticles[i].vel + 0.25f * dt * dt * k1[i];
      nextParticles[i].vel += 0.5f * dt * k1[i];
    }
    std::vector<Vec2f> k2 = accelCalc(nextParticles);
    for (unsigned int i = 0; i < nextParticles.size(); ++i) {
      nextParticles[i].pos = particles[i].pos +
                             0.5f * dt * nextParticles[i].vel +
                             0.25f * dt * dt * k2[i];
      nextParticles[i].vel = particles[i].vel + 0.5f * dt * k2[i];
    }
    std::vector<Vec2f> k3 = accelCalc(nextParticles);
    for (unsigned int i = 0; i < nextParticles.size(); ++i) {
      nextParticles[i].pos =
          particles[i].pos + dt * nextParticles[i].vel + 0.5f * dt * dt * k3[i];
      nextParticles[i].vel = particles[i].vel + dt * k3[i];
    }
    std::vector<Vec2f> k4 = accelCalc(nextParticles);
    for (unsigned int i = 0; i < nextParticles.size(); ++i) {
      Vec2f accel = 0.16667f * (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i]);
      particles[i].pos += dt * particles[i].vel + 0.5f * dt * dt * accel;
      particles[i].vel += dt * accel;
    }
  }

  void pushParticle(const T &particle) { particles.push_back(particle); }

  bool eraseParticle(const T &particle) {
    auto pos = std::find(particles.begin(), particles.end(), particle);
    if (pos == particles.end()) {
      return false;
    }
    particles.erase(pos);
    return true;
  }

  void draw(sf::RenderWindow &window) const {
    for (T particle : particles) {
      sf::CircleShape circle = sf::CircleShape(particle);
      window.draw(circle);
    }
  }
};