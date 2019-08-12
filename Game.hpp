#include <array>

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

    State state;

private:
    std::array<std::array<int, 3>, 3> _board;

public:
    Game();

    inline std::array<std::array<int, 3>, 3> GetBoard() const { return _board; }
    inline void SetCell(Cell cell, int x, int y) { _board[x][y] = cell; }
};