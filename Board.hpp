#pragma once
#include "constants.hpp"
#include <vector>

class Board {
public:
    // board[0] Xs
    // board[1] Os
    // board[2] empty
    // board[3] turn
    Bitboard board[N_PLAYERS + 2];

    // 0        not game over
    // 1        player 1 win
    // 2        player 2 win
    // 3        draw
    int state = 0;

    Board();
    Board(const Board*);
 
    std::pair<bool, bool> getWinner();
    std::vector<int> getMoves();
    void move(int);
    void disp();
};
