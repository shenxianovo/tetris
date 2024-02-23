#include <iostream>
#include "draw.h"
#include "terminal.h"

// unicode box
/*
 	0	1	2	3	4	5	6	7	8	9	A	B	C	D	E	F
U+250x	─	━	│	┃	┄	┅	┆	┇	┈	┉	┊	┋	┌	┍	┎	┏
U+251x	┐	┑	┒	┓	└	┕	┖	┗	┘	┙	┚	┛	├	┝	┞	┟
U+252x	┠	┡	┢	┣	┤	┥	┦	┧	┨	┩	┪	┫	┬	┭	┮	┯
U+253x	┰	┱	┲	┳	┴	┵	┶	┷	┸	┹	┺	┻	┼	┽	┾	┿
U+254x	╀	╁	╂	╃	╄	╅	╆	╇	╈	╉	╊	╋	╌	╍	╎	╏
U+255x	═	║	╒	╓	╔	╕	╖	╗	╘	╙	╚	╛	╜	╝	╞	╟
U+256x	╠	╡	╢	╣	╤	╥	╦	╧	╨	╩	╪	╫	╬	╭	╮	╯
U+257x	╰	╱	╲	╳	╴	╵	╶	╷	╸	╹	╺	╻	╼	╽	╾	╿
*/
namespace dw {
    inline int block2Col(int block) {
        return 2*block-1;
    }

    // 1 10 12 22
    void window(int top, int left, int width, int height, std::string title) {
        for (int r = 0; r < height; ++r) {
            tc::moveTo(top + r,block2Col(left));
            for (int c = 0; c < width; ++c) {
                // 第一行
                if (r == 0) {
                    if (c == 0) {std::cout << " ┌";} // 第一列
                    else if (c == width - 1) {std::cout << "┐ ";} // 最后一列
                    else {std::cout << "──";} // 其他
                }
                // 最后一行
                else if (r == height - 1) {
                    if (c == 0) {std::cout << " └";} // 第一列
                    else if (c == width - 1) {std::cout << "┘ ";} // 最后一列
                    else {std::cout << "──";} // 其他
                } 
                // 中间
                else {
                    if (c == 0) {std::cout << " │";} // 第一列
                    else if (c == width - 1) {std::cout << "│ ";} // 最后一列
                    else {std::cout << "  ";} // 其他
                }
            }
        }
        tc::moveTo(top, block2Col(left) + (width*2-title.length()) / 2);
        std::cout << title;
    }
}