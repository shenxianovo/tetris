#pragma once
#include <string>


namespace ut {
    int fps();
    std::string UTF32To8(std::u32string str);
       inline int b2c(int block) {
        return 2*block-1;
    } // 内联函数直接放头文件
    }