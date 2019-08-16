#pragma once

#include "Random.hpp"
#include "../Game.hpp"


namespace AI {

class BlockEnemy : public Random {
private:
    using Super = Random;
protected:
    sf::Vector2i FindBlockingMove(const Board& board, 
                sf::Vector2i enemyMove, Game::Cell enemySymbol); 
public:
    sf::Vector2i Play(const Board& board, sf::Vector2i enemyMove) override;
};

};