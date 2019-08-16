#pragma once

#include <array>
#include <SFML/Graphics.hpp>

namespace AI { class AI; };
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
    Cell _player;
    sf::Vector2i _lastMove;
    sf::Vector2i _lastPlayerMove;
    int _moves = 0;
    AI::AI* _ai;
    bool _playerFirst = false;

    void ClearBoard();
    void NextTurn();
    void SetCell(Cell cell, int x, int y);

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
    inline std::array<std::array<int, 3>, 3> GetBoard() const { return _board; }
    inline Cell GetPlayer() const { return _player; }
};