#include "Renderer.hpp"
#include "Game.hpp"

const std::string Renderer::TITLE = "dev";

Renderer::Renderer(sf::RenderWindow& window) 
: _window(window)
{

}

void Renderer::Render(std::array<std::array<int, 3>, 3> board) {
    _window.clear(sf::Color::Black);
    DrawGrid();
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == Game::Cell::X) {
                DrawX(i, j);
            } else if (board[i][j] == Game::Cell::O) {
                DrawO(i, j);
            }
        }
    }
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
        sf::Vertex(sf::Vector2f((row*CELL_WIDTH)+80, 
                    (column * CELL_HEIGHT)+20), sf::Color::Red),
        sf::Vertex(sf::Vector2f(((row+1)*CELL_WIDTH)-80, 
                    ((column+1)*CELL_HEIGHT)-20), sf::Color::Red)
    };

    sf::Vertex line2[] = 
    {
        sf::Vertex(sf::Vector2f(((row+1)*CELL_WIDTH)-80, 
                    (column * CELL_HEIGHT)+20), sf::Color::Red),
        sf::Vertex(sf::Vector2f((row*CELL_WIDTH)+80, 
                    ((column+1)*CELL_HEIGHT)-20), sf::Color::Red)
    };

    _window.draw(line1, 2, sf::Lines);
    _window.draw(line2, 2, sf::Lines);
}

void Renderer::DrawO(int row, int column) {
    sf::CircleShape circle((CELL_HEIGHT/2)-10);
    circle.setPosition((row*CELL_WIDTH)+(CELL_WIDTH/4), (column*CELL_HEIGHT)+10);
    circle.setOutlineColor(sf::Color::Red);
    circle.setFillColor(sf::Color::Black);
    circle.setOutlineThickness(1);
    _window.draw(circle);
}