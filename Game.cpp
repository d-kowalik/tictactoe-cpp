#include "Game.hpp"

Game::Game() : _board{{{EMPTY, EMPTY, EMPTY}, 
                    {EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}}}, 
                    state{State::RUNNING},
                    player(Cell::X) {}

void Game::ClickOnCell(int x, int y) {
    if (state != State::RUNNING) return;
    SetCell(player, x, y);
    NextTurn();
}

void Game::SetCell(Cell cell, int x, int y) {
    _board[x][y] = cell;
    moves++;
    CheckWin();
}

void Game::CheckWin() {
    if (moves == 9) {
        state = State::TIE;
        return;
    }
    if (moves < 5) return;

    if ((_board[0][0] == _board[0][1] && _board[0][1] == _board[0][2])
        || (_board[1][0] == _board[1][1] && _board[1][1] == _board[1][2])
        || (_board[2][0] == _board[2][1] && _board[2][1] == _board[2][2])
        || (_board[0][0] == _board[1][0] && _board[1][0] == _board[2][0])
        || (_board[1][0] == _board[1][1] && _board[1][1] == _board [1][2])
        || (_board[2][0] == _board[2][1] && _board[2][1] == _board[2][2])
        || (_board[0][0] == _board[1][1] && _board[1][1] == _board[2][2])
        || (_board[0][2] == _board[1][1] && _board[1][1] == _board[2][0])
    ) {
        if (player == Cell::X) {
            state = State::X_WON;
        } else {
            state = State::O_WON;
        }
    }
}

void Game::NextTurn() {
    if (player == Cell::X) {
        player = Cell::O;
    } else {
        player = Cell::X;
    }
}