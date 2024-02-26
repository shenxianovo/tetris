#pragma once

namespace gm {
    extern char command;

    char getch();
    void keyEvent();
    void startListener();

    // 键盘命令函数
    void commandQuit();
    void commandRotate();
    void commandLeft();
    void commandRight();
    void commandDown();


}