#include "define.h"
#include "utils.h"

namespace ut{
    int fps() {
        static auto start = std::chrono::steady_clock::now(); // c++20 稳定计时器 加static是为了不被重复初始化
        // 初始化：类型 类型名 = 值；赋值：类型名 = 值。static是只能初始化一次，之后的初始化无效
        auto end = start;
        static int frameCount = 0;
        static int fps = 0;

        end = std::chrono::steady_clock::now();
        frameCount++;
        if (end - start > 1s) {
            fps = frameCount;
            frameCount = 0;
            start = end;
        }

        return fps;
    }

    std::string UTF32To8(std::u32string str) {
        static std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> convert; // 只要一个convert
        return convert.to_bytes(str);
    }


}