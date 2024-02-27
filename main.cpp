#include "define.h"
#include "terminal.h"
#include "utils.h"
#include "draw.h"
#include "control.h"
#include "game.h"

using namespace std::chrono_literals;


void init() {
    tc::hideCursor();
    gm::startListener();
    gm::init();
}

void loop() {
    int i = 0;

    while (gm::running) {
        tc::clearScreen();
        dw::window(1, 1, 9, 6, "Hold");
        dw::window(1, 10, 12, 22, "Tetris");
        dw::window(7, 1, 9, 16, "Status");
        dw::window(19, 22, 8, 4, "Info");
        dw::window(1, 22, 8, 18, "Next");

        tc::moveTo(10,4);
        std::cout << "FPS: " << ut::fps();

        tc::moveTo(gm::row, ut::b2c(gm::col));
        
        dw::tetromino(gm::cur, gm::row, gm::col);
        tc::resetColor();

        std::cout << std::flush;
        std::this_thread::sleep_for(18ms); // c++14后新增时间度量单位 在头文件 chrono 中
    }
}

void exit() {
    tc::showCursor();
    tc::resetColor();
    tc::clearScreen();
    tc::moveTo(1,1);
    tc::setForegroundColor(9);
    std::cout << "GOODBYE !\n";

}

int main() {

    init();
    loop();
    exit();
    
    return 0;
}