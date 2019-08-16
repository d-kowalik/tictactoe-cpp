#pragma once

#include "AI.hpp"

namespace AI {

class Random : public AI {
public:
    sf::Vector2i Play(const Board& board) override;
};

};