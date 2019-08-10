#include <SFML/Graphics.hpp>

#include "Renderer.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(Renderer::WIDTH, Renderer::HEIGHT), 
                            Renderer::TITLE);
    
    Renderer renderer(window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        renderer.Render();
    }

    return 0;
}