#include "terminal.h"
#include <iostream>

#define CSI "\x1b[" // comtrol sequence introducer

void tc::moveTo(int row, int col) {
    std::cout << CSI << row << ";" << col << "H";
}

void tc::setForegroundColor(int id) {
    std::cout << CSI << "38;5;" << id << "m";
}

void tc::setBackgroundColor(int id) {
    std::cout << CSI << "48;5;" << id << "m";
}

void tc::clearScreen() {
    std::cout << CSI << "2J";
}

void tc::resetColor() {
    std::cout << CSI << "0m";
}

void tc::showCursor() {
    std::cout << CSI << "?25h";
}

void tc::hideCursor() {
    std::cout << CSI << "?25l";
}
