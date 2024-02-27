#include "define.h"
#include "control.h"
#include "game.h"

namespace gm {

    char command;

    std::map<char, std::function<void()>> commandFunc{
        {KEY_Q, commandQuit},
        {KEY_W, commandRotate},
        {KEY_S, commandDown},
        {KEY_A, commandLeft},
        {KEY_D, commandRight}
    };

    char getch() {
        char c;
        struct termios old, cur; // 终端属性结构体
        tcgetattr(0, &cur); // 获取当前终端属性 存放入cur
        old = cur; // 缓存终端属性
        cfmakeraw(&cur); // control flag make raw 这是一个宏 更改cur结构体十七进入raw模式 关闭行缓冲与输入回显等
        tcsetattr(0, 0, &cur); // 应用上面一条语句 第二个参数表示什么都不执行 直接设置属性为cur结构体
        /*
        cfmakeraw 只改变结构体
        tcsetattr 可以改变结构体 不论改变与否都将结构体参数应用到终端

        tcsetattr的第二个参数
        0           不传参
        TCSANOW     Terminal Control Set Attributes Now     Apply changes immediately.
        TCSADRAIN   Terminal Control Set Attributes Drain   Apply changes after all output has been transmitted
        TCSAFLUSH   Terminal Control Set Attributes Flush   Apply changes after all output has been transmitted, and the input buffer is cleared
        */
        c = getchar();
        tcsetattr(0, 0, &old); // 复原
        return c;
    }

    // 多线程-键盘监听
    void keyEvent() {
        while (running) {
            command = getch(); // windows下有一个函数getch 相较于getchar getch不缓存(不用回车) Linix需要自己实现
            if (commandFunc.find(command) != commandFunc.end()) // 找不到返回尾迭代器
            commandFunc[command]();
        }
    }

    void startListener() {
        std::thread t(keyEvent); // 开一个线程执行keyEvent函数
        t.detach(); // 让该线程与主线程解绑
    }

    void commandQuit() {
        quit();
    }
    void commandRotate() {
        rotate();
    }
    void commandLeft() {
        left();
    }
    void commandRight() {
        right();
    }
    void commandDown() {
        down();
    }
}