#pragma once
#include "tetromino.h"

namespace gm {
    extern bool running;

    void init();
    void quit();

    void quit();
    void rotate();
    void left();
    void right();
    void down();

    extern int row, col;
    extern Tetromino cur;
    
}
