#include "fpscounter.hpp"
#include "particlesystem.hpp"
#include "planet.hpp"
#include "vector.hpp"
#include "viewcontroller.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using std::cout;
#define debug(x) cout << #x << " = " << x << '\n'
#define vdebug(v)                                                              \
  cout << #v << " = ";                                                         \
  for (auto _i : v) {                                                          \
    cout << _i << ' ';                                                         \
  };                                                                           \
  cout << '\n';

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Gravity");
  window.setFramerateLimit(600);
  ViewController viewController(window.getDefaultView());
  sf::Font firaCode;
  if (!firaCode.loadFromFile("FiraCode-Regular.ttf")) {
    cout << "failed to load FiraCode-Regular.ttf\n";
  }

  FpsCounter fps(50, 0.1, firaCode);

  Planet a(Vec2f(400.f, 300.f), Vec2f(), 800e6f, 10.f);
  Planet b(Vec2f(200.f, 300.f), Vec2f(0.f, 2000.f), 0.f, 10.f);
  Planet c(Vec2f(200.f, 2000.f), Vec2f(222.f, 20.f), 1e7f, 10.f);
  std::vector<Planet> planets = {a, b, c};
  ParticleSystem<Planet> planetSystem(Planet::gravityAccel, planets);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear();
    viewController.update(window);
    planetSystem.rk4Move();
    planetSystem.draw(window);
    fps.update();
    fps.draw(Vec2f(0.f, 0.f), window);
    window.display();
  }
  return 0;
}
