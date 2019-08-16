#pragma once

#include <array>

#include <SFML/Graphics/Vertex.hpp>

namespace AI {
class AI {
protected:
    using Board = std::array<std::array<int, 3>, 3>;
    int _moves = 0;
public:
    virtual sf::Vector2i Play(const Board& board, sf::Vector2i enemyMove) = 0;
};
};