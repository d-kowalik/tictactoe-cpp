#include "Game.hpp"

Game::Game() : _board{{{EMPTY, EMPTY, EMPTY}, 
                    {EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}}}, 
                    state{State::RUNNING},
                    player(Cell::X) {}

void Game::ClickOnCell(int x, int y) {
    SetCell(player, x, y);
    NextTurn();
}

void Game::NextTurn() {
    if (player == Cell::X) {
        player = Cell::O;
    } else {
        player = Cell::X;
    }
}