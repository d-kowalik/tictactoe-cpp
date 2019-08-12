#include "Renderer.hpp"

const std::string Renderer::TITLE = "dev";

Renderer::Renderer(sf::RenderWindow& window) 
: _window(window)
{

}

void Renderer::DrawGrid() {
    sf::Vertex hline[] = 
    {
        sf::Vertex(sf::Vector2f(0.f, CELL_HEIGHT), sf::Color::Red),
        sf::Vertex(sf::Vector2f(WIDTH, CELL_HEIGHT), sf::Color::Red)
    };

    sf::Vertex vline[] = 
    {
        sf::Vertex(sf::Vector2f(CELL_WIDTH ,0.f), sf::Color::Red),
        sf::Vertex(sf::Vector2f(CELL_WIDTH, HEIGHT), sf::Color::Red)
    };

    _window.draw(hline, 2, sf::Lines);

    hline[0].position.y += CELL_HEIGHT;
    hline[1].position.y += CELL_HEIGHT;
    _window.draw(hline, 2, sf::Lines);

    _window.draw(vline, 2, sf::Lines);
    vline[0].position.x += CELL_WIDTH;
    vline[1].position.x += CELL_WIDTH;
    _window.draw(vline, 2, sf::Lines);
}

void Renderer::Render() {
    _window.clear(sf::Color::Black);
    DrawGrid();
    _window.display();
}