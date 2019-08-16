#pragma once

#include <string>
#include <array>

#include <SFML/Graphics.hpp>

class Renderer 
{
public:
    static constexpr unsigned int WIDTH = 1280;
    static constexpr unsigned int HEIGHT = 720;
    static constexpr unsigned int CELL_WIDTH = WIDTH/3;
    static constexpr unsigned int CELL_HEIGHT = HEIGHT/3;
    sf::Color X_COLOR = sf::Color::Blue;
    sf::Color O_COLOR = sf::Color::Green;
    sf::Color TIE_COLOR = sf::Color::Red;
    sf::Color BACKGROUND_COLOR = sf::Color::White;
    sf::Color DEFAULT_BOARD_COLOR = sf::Color::Black;
    static const std::string TITLE;

private:
    sf::RenderWindow& _window;
public:
    Renderer(sf::RenderWindow& window);

    void Render(std::array<std::array<int, 3>, 3> board);

private:
    void DrawGrid();
    void DrawX(int row, int column);
    void DrawO(int row, int column);
    void DrawWinLine();
};