#include "Random.hpp"

#include <vector>
#include <algorithm>
#include <random>

#include <SFML/Graphics/Vertex.hpp>

#include "../Game.hpp"

namespace AI {

sf::Vector2i Random::Play(const Board& board, sf::Vector2i enemyMove) {
    std::vector<sf::Vector2i> possibleMoves{};
    for (int x = 0; x < board.size(); x++) {
        for (int y = 0; y < board.size(); y++) {
            if (board[x][y] == Game::Cell::EMPTY) {
                possibleMoves.push_back({x, y});
            }
        }
    } 

    std::vector<sf::Vector2i> sample;
    std::sample(possibleMoves.begin(), possibleMoves.end(), std::back_inserter(sample), 1, std::mt19937{std::random_device{}()});
    return sample[0];
}

};