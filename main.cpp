#include <iostream>
#include <thread>
#include <chrono>
#include "terminal.h"
#include "utils.h"

using namespace std::chrono_literals;



void init() {
    tc::hideCursor();
}

void loop() {
    int i = 1;

    while (1) {
        
        tc::clearScreen();
        tc::moveTo(1,1);
        std::cout << "FPS: " << ut::fps();


        tc::moveTo(i++%20, 10); // i 在1-20行循环
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