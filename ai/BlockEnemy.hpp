#pragma once

#include "Random.hpp"

namespace AI {

class BlockEnemy : public Random {
private:
    using Super = Random;
public:
    sf::Vector2i Play(const Board& board, sf::Vector2i enemyMove) override;
};

};