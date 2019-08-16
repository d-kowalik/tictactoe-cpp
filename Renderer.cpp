#include "Renderer.hpp"
#include "Game.hpp"

const std::string Renderer::TITLE = "dev";

Renderer::Renderer(sf::RenderWindow& window) 
: _window(window)
{

}

void Renderer::Render(std::array<std::array<int, 3>, 3> board) {
    _window.clear(BACKGROUND_COLOR);
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
    if (Game::state != Game::State::RUNNING) {
        DrawWinLine();
    }
    _window.display();
}

void Renderer::DrawWinLine() {
    sf::Vertex line[] = 
    {
        sf::Vertex(sf::Vector2f(
            Game::firstCell.x * CELL_WIDTH + (CELL_WIDTH/2), 
            Game::firstCell.y * CELL_HEIGHT + (CELL_HEIGHT/2)), X_COLOR),
        sf::Vertex(sf::Vector2f(
            Game::lastCell.x * CELL_WIDTH + (CELL_WIDTH/2), 
            Game::lastCell.y * CELL_HEIGHT + (CELL_HEIGHT/2)), O_COLOR)
    };
    _window.draw(line, 2, sf::Lines);
}

void Renderer::DrawGrid() {
    sf::Color boardColor = DEFAULT_BOARD_COLOR;
    switch (Game::state) {
        case Game::State::O_WON:
            boardColor = O_COLOR;
            break;
        case Game::State::X_WON:
            boardColor = X_COLOR;
            break;
        case Game::State::TIE:
            boardColor = TIE_COLOR;
            break;
        default: {}
    }

    sf::Vertex hline[] = 
    {
        sf::Vertex(sf::Vector2f(0.f, CELL_HEIGHT), boardColor),
        sf::Vertex(sf::Vector2f(WIDTH, CELL_HEIGHT), boardColor)
    };

    sf::Vertex vline[] = 
    {
        sf::Vertex(sf::Vector2f(CELL_WIDTH ,0.f), boardColor),
        sf::Vertex(sf::Vector2f(CELL_WIDTH, HEIGHT), boardColor)
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
    sf::Color xcolor = X_COLOR;
    switch (Game::state) {
        case Game::State::O_WON:
            xcolor = O_COLOR;
            break;
        case Game::State::TIE:
            xcolor = TIE_COLOR;
            break;
        default: {}
    }

    sf::Vertex line1[] = 
    {
        sf::Vertex(sf::Vector2f((row*CELL_WIDTH)+80, 
                    (column * CELL_HEIGHT)+20), xcolor),
        sf::Vertex(sf::Vector2f(((row+1)*CELL_WIDTH)-80, 
                    ((column+1)*CELL_HEIGHT)-20), xcolor)
    };

    sf::Vertex line2[] = 
    {
        sf::Vertex(sf::Vector2f(((row+1)*CELL_WIDTH)-80, 
                    (column * CELL_HEIGHT)+20), xcolor),
        sf::Vertex(sf::Vector2f((row*CELL_WIDTH)+80, 
                    ((column+1)*CELL_HEIGHT)-20), xcolor)
    };

    _window.draw(line1, 2, sf::Lines);
    _window.draw(line2, 2, sf::Lines);
}

void Renderer::DrawO(int row, int column) {
    sf::Color ocolor = O_COLOR;
    switch (Game::state) {
        case Game::State::X_WON:
            ocolor = X_COLOR;
            break;
        case Game::State::TIE:
            ocolor = TIE_COLOR;
            break;
        default: {}
    }
    sf::CircleShape circle((CELL_HEIGHT/2)-10);
    circle.setPosition((row*CELL_WIDTH)+(CELL_WIDTH/4), (column*CELL_HEIGHT)+10);
    circle.setOutlineColor(ocolor);
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineThickness(1);
    _window.draw(circle);
}