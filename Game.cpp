#include "Game.hpp"

#include "ai/Random.hpp"

Game::State Game::state = Game::State::RUNNING;
sf::Vector2i Game::firstCell = sf::Vector2i{};
sf::Vector2i Game::lastCell = sf::Vector2i{};

Game::Game() {
    ClearBoard();
}

Game::~Game() {
    if (_ai != nullptr) delete _ai;
}

void Game::ClearBoard() {
    _board =  {{{EMPTY, EMPTY, EMPTY}, 
                {EMPTY, EMPTY, EMPTY}, 
                {EMPTY, EMPTY, EMPTY}}};
    _player = Cell::X;
    _moves = 0;
    _ai = new AI::Random();
}

void Game::NextTurn() {
    if (_player == Cell::X) {
        _player = Cell::O;
    } else {
        _player = Cell::X;
    }
}

void Game::ClickOnCell(int x, int y) {
    if (state != State::RUNNING) {
        ClearBoard();
        state = State::RUNNING;
    } else {
        if (_board[x][y] != EMPTY) return;
        SetCell(_player, x, y);
        NextTurn();
    }
}

void Game::SetCell(Cell cell, int x, int y) {
    _board[x][y] = cell;
    _moves++;
    _lastMove.x = x;
    _lastMove.y = y;

    CheckWin();
}

void Game::CheckWin() {
    if (_moves < 5) return;

    CheckColumns();
    CheckRows();
    CheckDiag();
    CheckAntiDiag();
}

void Game::CheckColumns() {
    for (int i = 0; i < 3; i++)
        if (_board[_lastMove.x][i] != _player) return;

    Game::firstCell.x = _lastMove.x;
    Game::firstCell.y = 0;
    Game::lastCell.x = _lastMove.x;
    Game::lastCell.y = 2;
    ReportWin();
}

void Game::CheckRows() {
    for (int i = 0; i < 3; i++)
        if (_board[i][_lastMove.y] != _player) return;
    
    Game::firstCell.x = 0;
    Game::firstCell.y = _lastMove.y;
    Game::lastCell.x = 2;
    Game::lastCell.y = _lastMove.y;
    ReportWin();
}

void Game::CheckDiag() {
    if (_lastMove.x == _lastMove.y) {
        for (int i = 0; i < 3; i++) 
            if (_board[i][i] != _player) return;

        Game::firstCell.x = 0;
        Game::firstCell.y = 0;
        Game::lastCell.x = 2;
        Game::lastCell.y = 2;
        ReportWin();
    }
}

void Game::CheckAntiDiag() {
    if (_lastMove.x + _lastMove.y == 2) {
        for (int i = 0; i < 3; i++)
            if (_board[i][2-i] != _player) return; 

        Game::firstCell.x = 2;
        Game::firstCell.y = 0;
        Game::lastCell.x = 0;
        Game::lastCell.y = 2;
        ReportWin();
    }
}

void Game::ReportWin() {
    if (_player == Game::Cell::O) {
        state = Game::State::O_WON;
    } else {
        state = Game::State::X_WON;
    }
}