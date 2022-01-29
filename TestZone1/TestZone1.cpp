#include <iostream>
#include <Windows.h>
using namespace std;

enum Colors {
    Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray,
    DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};

template<Colors txt = LightGray, Colors bg = Black>
ostream& color(ostream& text) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | txt));
    return text;
}

int main() {
    cout << color<Green, Black> << "test " << color<Red, Black> << "test2\n" << color;
    return 0;
}