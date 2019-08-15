#include "Game.hpp"

Game::State Game::state = Game::State::RUNNING;

Game::Game() {
    ClearBoard();
}

void Game::ClickOnCell(int x, int y) {
    if (state != State::RUNNING) {
        ClearBoard();
        state = State::RUNNING;
    } else {
        if (_board[x][y] != EMPTY) return;
        SetCell(player, x, y);
        NextTurn();
    }
}

void Game::ClearBoard() {
    _board =  {{{EMPTY, EMPTY, EMPTY}, 
                {EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}}};
    player = Cell::X;
    moves = 0;
}

void Game::SetCell(Cell cell, int x, int y) {
    _board[x][y] = cell;
    moves++;
    CheckWin();
}

void Game::CheckWin() {
    if (moves < 5) return;

    if ((_board[0][0] != EMPTY && _board[0][0] == _board[0][1] && _board[0][1] == _board[0][2])
        || (_board[1][0] != EMPTY && _board[1][0] == _board[1][1] && _board[1][1] == _board[1][2])
        || (_board[2][0] != EMPTY && _board[2][0] == _board[2][1] && _board[2][1] == _board[2][2])
        || (_board[0][0] != EMPTY && _board[0][0] == _board[1][0] && _board[1][0] == _board[2][0])
        || (_board[0][1] != EMPTY && _board[0][1] == _board[1][1] && _board[1][1] == _board[2][1])
        || (_board[0][2] != EMPTY && _board[0][2] == _board[1][2] && _board[1][2] == _board[2][2])
        || (_board[0][0] != EMPTY && _board[0][0] == _board[1][1] && _board[1][1] == _board[2][2])
        || (_board[0][2] != EMPTY && _board[0][2] == _board[1][1] && _board[1][1] == _board[2][0])
    ) {
        if (player == Cell::X) {
            state = State::X_WON;
        } else if (player == Cell::O) {
            state = State::O_WON;
        }
    } else if (moves == 9) {
        state = State::TIE;
    }
}

void Game::NextTurn() {
    if (player == Cell::X) {
        player = Cell::O;
    } else {
        player = Cell::X;
    }
}