#include "Board.hpp"

int main() {
    Board b;
    b.disp();
    for (int i=0; i<9; i++) {
        b.move(b.moves()[0]);
        b.disp();
    }
}
