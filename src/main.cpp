#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "fpscounter.hpp"
#include "keybindmanager.hpp"
#include "planet.hpp"
#include "planetsystem.hpp"
#include "viewcontroller.hpp"
using std::cout;
#define debug(x) cout << #x << " = " << x << '\n'
#define vdebug(v)      \
  cout << #v << " = "; \
  for (auto _i : v) {  \
    cout << _i << ' '; \
  };                   \
  cout << '\n';

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Gravity");
  window.setFramerateLimit(400);

  ViewController viewController(window.getDefaultView());

  sf::Font firaCode;
  if (!firaCode.loadFromFile("/home/hugho/dev/n_body_simulation/build/bin/"
                             "Debug/FiraCode-Regular.ttf")) {
    cout << "failed to load FiraCode-Regular.ttf\n";
  }

  FpsCounter fps(50, 0.1, firaCode);

  Planet a(Vec2f(400.f, 300.f), Vec2f(), 2e8f, 10.f);
  Planet b(Vec2f(100.f, 300.f), Vec2f(0.f, 500.f), 0.f, 10.f);
  Planet c(Vec2f(200.f, 2000.f), Vec2f(600.f, 200.f), 8e8f, 10.f);
  a.shape.setFillColor(sf::Color::Red);
  std::vector<Planet> planets = {a, b};
  PlanetSystem planetSystem(planets);
  KeybindManager keybindManager(planetSystem, viewController, window);

  cout << "working\n";

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    cout << "working\n";
    window.clear(sf::Color::Blue);
    planetSystem.rk4Move();
    cout << "rk4 worked\n";
    fps.update();
    window.draw(fps);
    cout << "fps worked\n";
    keybindManager.update();
    cout << "keybind worked\n";
    viewController.update(window);
    cout << "view controller worked\n";
    window.draw(planetSystem);
    window.display();
  }
  return 0;
}
