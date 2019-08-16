#pragma once

#include <array>
#include <SFML/Graphics.hpp>

#include "ai/AI.hpp"

class Game {
public:
    enum State {
        RUNNING=0,
        X_WON=1,
        O_WON=2,
        TIE=3,
        QUIT=4
    };

    enum Cell {
        EMPTY=0,
        X=1,
        O=2
    };

    static State state;
    static sf::Vector2i firstCell;
    static sf::Vector2i lastCell;

private:
    std::array<std::array<int, 3>, 3> _board;
    Cell player;
    sf::Vector2i _lastMove;
    int moves = 0;
    AI::AI* _ai;

    void ClearBoard();
    void CheckWin();
    void CheckColumns();
    void CheckRows();
    void CheckDiag();
    void CheckAntiDiag();
    void ReportWin();

public:
    Game();
    ~Game();

    void ClickOnCell(int x, int y);
    void NextTurn();
    inline std::array<std::array<int, 3>, 3> GetBoard() const { return _board; }
    void SetCell(Cell cell, int x, int y);
    inline Cell GetPlayer() const { return player; }
};