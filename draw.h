#pragma once
#include "define.h"
#include "tetromino.h"

namespace dw{
    void window(int top, int left, int width, int height, std::string title);
    void tetromino(gm::Tetromino& t, int top, int left);

}