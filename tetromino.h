#pragma once
#include "define.h"
#include "color.h"

namespace gm {
    // I[5][5] JOSTZ[3][3]
    using Tetromino = std::vector<std::vector<int>>; // 类型别名 类似于typedef
    extern Tetromino I;
    extern Tetromino J;
    extern Tetromino L;
    extern Tetromino O;
    extern Tetromino S;
    extern Tetromino T;
    extern Tetromino Z;

    extern std::map<int,Color> tetroColor;

    Tetromino rotate(Tetromino& t);
    
}
