#include "Renderer.hpp"

const std::string Renderer::TITLE = "dev";

Renderer::Renderer(sf::RenderWindow& window) 
: _window(window)
{

}

void Renderer::Render() {
    _window.clear(sf::Color::Black);
    DrawGrid();
    DrawX(0, 0);
    _window.display();
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

void Renderer::DrawX(int row, int column) {
    sf::Vertex line1[] = 
    {
        sf::Vertex(sf::Vector2f((row*CELL_WIDTH)+10, 
                    (column * CELL_HEIGHT)+10), sf::Color::Red),
        sf::Vertex(sf::Vector2f(((row+1)*CELL_WIDTH)-10, 
                    ((column+1)*CELL_HEIGHT)-10), sf::Color::Red)
    };

    sf::Vertex line2[] = 
    {
        sf::Vertex(sf::Vector2f(((row+1)*CELL_WIDTH)-10, 
                    (column * CELL_HEIGHT)+10), sf::Color::Red),
        sf::Vertex(sf::Vector2f((row*CELL_WIDTH)+10, 
                    ((column+1)*CELL_HEIGHT)-10), sf::Color::Red)
    };

    _window.draw(line1, 2, sf::Lines);
    _window.draw(line2, 2, sf::Lines);
}