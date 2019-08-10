#include <SFML/Graphics.hpp>

#include "test.hpp"

constexpr unsigned int WIDTH = 2560/3;
constexpr unsigned int HEIGHT = 1440;

void render(sf::RenderWindow& window) {
    sf::Vertex hline[] = 
    {
        sf::Vertex(sf::Vector2f(0.f, static_cast<float>(HEIGHT)/3.f), sf::Color::Red),
        sf::Vertex(sf::Vector2f(WIDTH, static_cast<float>(HEIGHT)/3.f), sf::Color::Red)
    };
    window.draw(hline, 2, sf::Lines);

    hline[0].position.y += static_cast<float>(HEIGHT)/3.f;
    hline[1].position.y += static_cast<float>(HEIGHT)/3.f;
    window.draw(hline, 2, sf::Lines);


    sf::Vertex vline[] = 
    {
        sf::Vertex(sf::Vector2f(static_cast<float>(WIDTH)/3.f, 0.f), sf::Color::Red),
        sf::Vertex(sf::Vector2f(static_cast<float>(WIDTH)/3.f, HEIGHT), sf::Color::Red)
    };
    window.draw(vline, 2, sf::Lines);

    vline[0].position.x += static_cast<float>(WIDTH)/3.f;
    vline[1].position.x += static_cast<float>(WIDTH)/3.f;
    window.draw(vline, 2, sf::Lines);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), getTitle());
    

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::White);
        render(window);
        window.display();
    }

    return 0;
}