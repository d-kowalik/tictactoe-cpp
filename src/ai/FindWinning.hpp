#pragma once

#include "BlockEnemy.hpp"

namespace AI {

class FindWinning : public BlockEnemy {
private:
    using Super = BlockEnemy;
    sf::Vector2i _lastMove{-1, -1};

public:
    sf::Vector2i Play(const Board& board, sf::Vector2i enemyMove) override;
};

};