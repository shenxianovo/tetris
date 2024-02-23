#pragma once
// terminal control
// “函数不需要访问类的实例成员，并且是通用的函数，那么将它们封装在命名空间中是一种更合适的选择”
namespace tc{
    void moveTo(int row, int col);
    void setForegroundColor(int id);
    void setBackgroundColor(int id);
    void clearScreen();
    void resetColor();
    void showCursor();
    void hideCursor();
}