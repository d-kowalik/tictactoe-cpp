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
                {EMPTY, EMPTY, EMPTY}, 
                {EMPTY, EMPTY, EMPTY}}};
    player = Cell::X;
    moves = 0;
}

void Game::SetCell(Cell cell, int x, int y) {
    _board[x][y] = cell;
    moves++;
    _lastMove.x = x;
    _lastMove.y = y;

    CheckWin();
}

void Game::ReportWin() {
    if (player == Game::Cell::O) {
        state = Game::State::O_WON;
    } else {
        state = Game::State::X_WON;
    }
}

void Game::CheckColumns() {
    for (int i = 0; i < 3; i++)
        if (_board[_lastMove.x][i] != player) return;

     ReportWin();
}

void Game::CheckRows() {
    for (int i = 0; i < 3; i++)
        if (_board[i][_lastMove.y] != player) return;
    
    ReportWin();
}

void Game::CheckDiag() {
    if (_lastMove.x == _lastMove.y) {
        for (int i = 0; i < 3; i++) 
            if (_board[i][i] != player) return;
        ReportWin();
    }
}

void Game::CheckAntiDiag() {
    if (_lastMove.x + _lastMove.y == 2) {
        for (int i = 0; i < 3; i++)
            if (_board[i][2-i] != player) return; 
        ReportWin();
    }
}

void Game::CheckWin() {
    if (moves < 5) return;

    CheckColumns();
    CheckRows();
    CheckDiag();
    CheckAntiDiag();
}

void Game::NextTurn() {
    if (player == Cell::X) {
        player = Cell::O;
    } else {
        player = Cell::X;
    }
}