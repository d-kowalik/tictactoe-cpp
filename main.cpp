#include <SFML/Graphics.hpp>

#include "test.hpp"

constexpr int WIDTH = 640;
constexpr int HEIGHT = 480;

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), getTitle());
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}