#pragma once

#include <array>

namespace AI {
class AI {
protected:
    using Board = std::array<std::array<int, 3>, 3>;
public:
    virtual void Play(const Board& board) = 0;
};
};