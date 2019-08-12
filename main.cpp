#include <SFML/Graphics.hpp>

#include "Renderer.hpp"
#include "Game.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(Renderer::WIDTH, Renderer::HEIGHT), 
                            Renderer::TITLE);
    
    Renderer renderer(window);
    Game game;
    game.SetCell(Game::Cell::X, 0, 0);
    game.SetCell(Game::Cell::O, 1, 2);

    while (game.state != Game::State::QUIT) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                game.state = Game::State::QUIT;
            }
        }
        renderer.Render(game.GetBoard());
    }

    window.close();

    return 0;
}