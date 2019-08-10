#include "Renderer.hpp"

const std::string Renderer::TITLE = "dev";

Renderer::Renderer(sf::RenderWindow& window) 
: _window(window)
{

}

void Renderer::DrawGrid() {
    sf::Vertex hline[] = 
    {
        sf::Vertex(sf::Vector2f(0.f, static_cast<float>(HEIGHT)/3.f), sf::Color::Red),
        sf::Vertex(sf::Vector2f(WIDTH, static_cast<float>(HEIGHT)/3.f), sf::Color::Red)
    };

    sf::Vertex vline[] = 
    {
        sf::Vertex(sf::Vector2f(static_cast<float>(WIDTH)/3.f, 0.f), sf::Color::Red),
        sf::Vertex(sf::Vector2f(static_cast<float>(WIDTH)/3.f, HEIGHT), sf::Color::Red)
    };

    _window.draw(hline, 2, sf::Lines);

    hline[0].position.y += static_cast<float>(HEIGHT)/3.f;
    hline[1].position.y += static_cast<float>(HEIGHT)/3.f;
    _window.draw(hline, 2, sf::Lines);

    _window.draw(vline, 2, sf::Lines);
    vline[0].position.x += static_cast<float>(WIDTH)/3.f;
    vline[1].position.x += static_cast<float>(WIDTH)/3.f;
    _window.draw(vline, 2, sf::Lines);
}

void Renderer::Render() {
    _window.clear(sf::Color::Black);
    DrawGrid();
    _window.display();
}