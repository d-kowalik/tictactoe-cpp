#include "BlockEnemy.hpp"

#include <iostream>

#include "../Game.hpp"

namespace AI {



sf::Vector2i BlockEnemy::Play(const Board& board, sf::Vector2i enemyMove) {
    auto enemySymbol = board[enemyMove.x][enemyMove.y];
    std::vector<sf::Vector2i> possibleMoves{};

    int emptyCount = 0;
    int enemyCount = 0;
    sf::Vector2i empty{};
    for (int i = 0; i < 3; i++) {
        if (board[enemyMove.x][i] == Game::Cell::EMPTY){
          empty = {enemyMove.x, i};
          emptyCount++;  
        }  else if (board[enemyMove.x][i] == enemySymbol) {
            enemyCount++;
        }
    }
    if (emptyCount == 1 && enemyCount == 2) possibleMoves.push_back(empty);

    emptyCount = 0;
    enemyCount = 0;
    empty = {};
    for (int i = 0; i < 3; i++) {
        if (board[i][enemyMove.y] == Game::Cell::EMPTY) {
            empty = {i, enemyMove.y};
            emptyCount++;
        } else if (board[i][enemyMove.y] == enemySymbol) enemyCount++;
    }    
    if (emptyCount == 1 && enemyCount == 2) possibleMoves.push_back(empty);

    emptyCount = 0;
    enemyCount = 0;
    empty = {};
    if (enemyMove.x == enemyMove.y) {
        for (int i = 0; i < 3; i++) {
            if (board[i][i] == enemySymbol) {
                enemyCount++;
            } else if (board[i][i] == Game::Cell::EMPTY) {
                emptyCount++;
                empty = {i, i};
            }
        }
    }
    if (emptyCount == 1 && enemyCount == 2) possibleMoves.push_back(empty);

    emptyCount = 0;
    enemyCount = 0;
    empty = {};
    if (enemyMove.x + enemyMove.y == 2) {
        for (int i = 0; i < 3; i++) {
            if (board[i][2-i] == enemySymbol) {
                enemyCount++;
            } else if (board[i][2-i] == Game::Cell::EMPTY) {
                emptyCount++;
                empty = {i, 2-i};
            }
        }
    }
    if (emptyCount == 1 && enemyCount == 2) possibleMoves.push_back(empty);

    if (possibleMoves.size() == 0) {
        return Super::Play(board, enemyMove);
    }

    return possibleMoves[0];
}


};