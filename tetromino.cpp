#include "define.h"
#include "tetromino.h"

namespace gm {
    // IJLOSTZ
    // 1234567

    Tetromino I {
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 1, 1, 1, 1},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
        }
    };
    Tetromino J {
        {
            {2, 0, 0},
            {2, 2, 2},
            {0, 0, 0},
        }
    };
    Tetromino L {
        {
            {0, 0, 3},
            {3, 3, 3},
            {0, 0, 0},
        }
    };
    Tetromino O {
        {
            {0, 4, 4},
            {0, 4, 4},
            {0, 0, 0},
        }
    };
    Tetromino S {
        {
            {0, 5, 5},
            {5, 5, 0},
            {0, 0, 0},
        }
    };
    Tetromino T {
        {
            {0, 6, 0},
            {6, 6, 6},
            {0, 0, 0},
        }
    };
    Tetromino Z {
        {
            {7, 7, 0},
            {0, 7, 7},
            {0, 0, 0},
        }
    };

    std::map<int, Color> tetroColor {
        {1, Color::Cyan},
        {2, Color::Blue},
        {3, Color::Orange},
        {4, Color::Yellow},
        {5, Color::Green},
        {6, Color::Purple},
        {7, Color::Red},
    };

    Tetromino rotate(Tetromino& t) {
        Tetromino result(t.size(), std::vector<int>(t.size(), 0)); // t.size行 每一行是t.size列，值为0
        
        // t[i][j] = t'[j][3-1-i] 
        for (int i = 0; i < t.size(); ++i) {
            for (int j = 0; j < t[0].size(); ++j){
                if (t[i][j] > 0) // =0不用旋转
                result[j][t.size() - i - 1] = t[i][j]; 
            }
        }

        return std::move(result); // 直接返回会有复制开销 此处使用c++11后的move函数
    }

}
