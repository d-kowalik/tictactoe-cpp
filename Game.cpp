#include "Game.hpp"

Game::Game() : _board{{{EMPTY, EMPTY, EMPTY}, 
                    {EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}}} {
    state = Game::State::RUNNING;
}