#include <iostream>
#include <thread>
#include <chrono>
#include "terminal.h"

int main() {

    // tc::moveTo(5, 10);
    // tc::setForegroundColor(31);
    // std::cout << "HELLO";
    // tc::resetColor();
    // tc::moveTo(10,1);

    tc::hideCursor();
    int i = 1;

    while (1) {
        tc::clearScreen();
        tc::moveTo(i++, 10);
        tc::setBackgroundColor(15);
        std::cout << "  ";
        tc::resetColor();
        std::cout << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1)); // c++14后新增时间度量单位 在头文件 chrono 中
    }
    return 0;
}