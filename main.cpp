#define SFML_STATIC
#include <vector>
#include <algorithm>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "vector.hpp"
#include "planet.hpp"
#define debug(x) std::cout << #x << " = " << x << '\n';

void drawPlanets(std::vector<Planet>& planets) { 
    for (Planet& planet: planets) {
        planet.draw();
        planet.improvedEulerMove();
        planet.nextAcc = planet.totalGravityAccel(planets);
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    window.setFramerateLimit(60);
    Planet a(Vec2f(375.f, 300.f), Vec2f(0.f, 100.f), window);
    a.radius = 10.f;
    Planet b(Vec2f(400.f, 300.f), Vec2f(), window);
    b.radius = 10.f;
    std::vector<Planet> planets = {a, b};
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        drawPlanets(planets);
        window.display();
    }
    std::cout<< "END\n";
    planets[0].eulerMove();
    return 0;
}