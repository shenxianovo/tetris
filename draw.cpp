#include "define.h"
#include "draw.h"
#include "terminal.h"
#include "utils.h"

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
    const std::u32string style1 = U" ┌┐└┘│─";
    const std::u32string style2 = U" ┏┓┗┛┃━";
    const std::u32string style3 = U" ╔╗╚╝║═";
    const std::u32string style4 = U" ╭╮╰╯│─";

    const std::u32string currentStyle = style4;



    // 1 10 12 22
    void window(int top, int left, int width, int height, std::string title) {
        for (int r = 0; r < height; ++r) {
            tc::moveTo(top + r, ut::b2c(left));
            for (int c = 0; c < width; ++c) {
                // 第一行
                if (r == 0) {
                    if (c == 0) {std::cout << ut::UTF32To8({currentStyle[0], currentStyle[1]});} // 第一列 {}表示创建临时对象
                    else if (c == width - 1) {std::cout << ut::UTF32To8({currentStyle[2]});} // 最后一列
                    else {std::cout << ut::UTF32To8({currentStyle[6], currentStyle[6]});} // 其他
                }
                // 最后一行
                else if (r == height - 1) {
                    if (c == 0) {std::cout << ut::UTF32To8({currentStyle[0], currentStyle[3]});} // 第一列
                    else if (c == width - 1) {std::cout << ut::UTF32To8({currentStyle[4]});} // 最后一列
                    else {std::cout << ut::UTF32To8({currentStyle[6], currentStyle[6]});} // 其他
                } 
                // 中间
                else {
                    if (c == 0) {std::cout << ut::UTF32To8({currentStyle[0], currentStyle[5]});} // 第一列
                    else if (c == width - 1) {std::cout << ut::UTF32To8({currentStyle[5]});} // 最后一列
                    else {std::cout << "  ";} // 其他
                }
            }
        }
        tc::moveTo(top, ut::b2c(left) + (width*2-title.length()) / 2);
        std::cout << title;
    }
}