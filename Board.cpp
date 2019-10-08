#include "Board.hpp"
#include <vector>
#include <iostream>

Board::Board() {
    for (int i=0; i<N_PLAYERS+2; ++i) {
        board[i] = INITIAL_STATE[i];
    }
}

Board::Board(const Board *_board) {
    for (int i=0; i<N_PLAYERS+2; ++i) {
        board[i] = _board->board[i];
    }
}

std::vector<int> Board::getMoves() {
    std::vector<int> moves;
    for (int j=0; j<N_SQUARES; ++j) {
        if ((board[2] >> j) & 1) {
            moves.push_back(j);
        }
    }
    return moves;
}

void Board::move(int square) {
    bool turn = board[3] | 0;
    board[turn] |= 1 << square;
    board[2] &= ~(1 << square);
    board[3] = ~board[3];
    //std::cout << '(' << turn << ',' << square << ')' << std::endl;

    // update state
    for (Bitboard line : LINES) {
        if ((board[turn] & line) == line) {
            state = turn + 1;
            return;
        }
    }
    if (board[2] == 0) {
        state = 3;
    }
}

void Board::disp() {
    /*
    // debug: print moves
    std::vector<int> moves = getMoves();
    for (int move : moves) {
        std::cout << move << ' ';
    }
    std::cout << std::endl;

    // debug: print bitboards
    for (int i=0; i<N_PLAYERS+2; ++i) {
        for (int j=0; j<N_SQUARES; ++j) {
            std::cout << ((board[i] >> j) & 1);
        }
        std::cout << std::endl;
    }
    */

    // print board
    for (int j=0; j<N_SQUARES; ++j) {
        for (int i=0; i<N_PLAYERS+1; ++i) {
            if ((board[i] >> j) & 1) {
                std::cout << PIECES[i];
                break;
            }
        }

        int prod = 1;
        for (int dim : DIMS) {
            prod *= dim;
            if ((j + 1) % prod == 0) {
                std::cout << std::endl;
            }
        }
    }
}
