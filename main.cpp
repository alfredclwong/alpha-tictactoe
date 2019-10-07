#include "Board.hpp"
#include <vector>
#include <iostream>

int main() {
    Board b;
    b.disp();
    for (int i=0; i<9; ++i) {
        std::vector<int> moves = b.getMoves();
        b.move(moves[0]);
        b.disp();
        if (b.state != 0) {
            if (b.state == 3) {
                std::cout << "Draw" << std::endl;
            } else {
                std::cout << "Winner: " << PIECES[b.state - 1] << std::endl;
            }
            break;
        }
    }
}
