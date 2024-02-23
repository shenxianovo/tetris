#include <iostream>
#include <thread>
#include <chrono>
#include "terminal.h"
#include "utils.h"
#include "draw.h"

using namespace std::chrono_literals;



void init() {
    tc::clearScreen();
    tc::hideCursor();
    dw::window(1, 1, 9, 6, "Hold");
    dw::window(1, 10, 12, 22, "Tetris");
    dw::window(7, 1, 9, 16, "Status");
    dw::window(19, 22, 8, 4, "Info");
    dw::window(1, 22, 8, 18, "Next");
}

void loop() {
    int i = 1;

    while (1) {
        
        tc::moveTo(10,4);
        std::cout << "FPS: " << ut::fps();


        tc::moveTo(5, 5); // i 在1-20行循环
        tc::setBackgroundColor(15);
        std::cout << "  ";
        tc::resetColor();
        std::cout << std::flush;
        std::this_thread::sleep_for(100ms); // c++14后新增时间度量单位 在头文件 chrono 中
    }
}
void exit() {
    tc::showCursor();
    tc::resetColor();
}

int main() {

    init();
    loop();
    exit();
    
    return 0;
}