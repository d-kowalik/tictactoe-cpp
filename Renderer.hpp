#pragma once

#include <string>

#include <SFML/Graphics.hpp>

class Renderer 
{
public:
    static constexpr unsigned int WIDTH = 1280;
    static constexpr unsigned int HEIGHT = 720;
    static constexpr unsigned int CELL_WIDTH = WIDTH/3;
    static constexpr unsigned int CELL_HEIGHT = HEIGHT/3;
    static const std::string TITLE;

private:
    sf::RenderWindow& _window;
public:
    Renderer(sf::RenderWindow& window);

    void Render();

private:
    void DrawGrid();
    void DrawX(int row, int column);
};