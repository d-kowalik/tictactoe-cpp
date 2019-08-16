#include <SFML/Graphics.hpp>

#include "Renderer.hpp"
#include "Game.hpp"

#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(Renderer::WIDTH, Renderer::HEIGHT), 
                            Renderer::TITLE);
    
    Renderer renderer(window);
    Game game;

    while (game.state != Game::State::QUIT) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                game.state = Game::State::QUIT;
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                int cellX = localPosition.x/Renderer::CELL_WIDTH;
                int cellY = localPosition.y/Renderer::CELL_HEIGHT;
                game.ClickOnCell(cellX, cellY);
            }
        }
        renderer.Render(game.GetBoard());
    }

    window.close();

    return 0;
}