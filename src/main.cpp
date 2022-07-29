#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <vector>
#include "fpscounter.hpp"
#include "keybindmanager.hpp"
#include "planet.hpp"
#include "planetcreator.hpp"
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
  cout.precision(5);
  sf::RenderWindow window(sf::VideoMode(800, 600), "Gravity");
  window.setFramerateLimit(400);

  ViewController viewController(window.getDefaultView());
  PlanetCreator planetCreator;

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
  std::vector<Planet> planets = {a, b, c};
  PlanetSystem planetSystem(planets);
  KeybindManager keybindManager(planetSystem, viewController, window,
                                planetCreator);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear(sf::Color(0x121d24ff));
    planetSystem.rk4Move();
    fps.update();
    keybindManager.update();
    viewController.update(window);
    window.draw(planetSystem);
    window.draw(planetCreator);
    window.setTitle("Gravity - " + std::to_string(fps.getFps()));
    window.display();
  }
  return 0;
}
