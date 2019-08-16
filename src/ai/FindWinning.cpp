#include "FindWinning.hpp"

namespace AI {

sf::Vector2i FindWinning::Play(const Board& board, sf::Vector2i enemyMove) {
    // Find winning move if that's not the first move
    sf::Vector2i winningMove{-1, -1};
    if (_lastMove.x != -1) {
        winningMove = Super::FindBlockingMove(board, _lastMove, static_cast<Game::Cell>(board[_lastMove.x][_lastMove.y]));
    }

    if (winningMove.x != -1) {
        return winningMove;
    }

    auto finalMove = Super::Play(board, enemyMove);
    _lastMove.x = finalMove.x;
    _lastMove.y = finalMove.y;
    return finalMove;
}


};