#include "Board.hpp"
#include <iostream>
using namespace std;

Board::Board() {
    turn = 0;
    for (int j=0; j<nplayers; j++) {
        board[j] = 0;
    }
}

void Board::disp() {
    // debug: print bitboards
    for (int j=0; j<nplayers; j++) {
        for (int i=0; i<nsquares; i++) {
            cout << ((board[j] >> i) & 1);
        }
        cout << endl;
    }

    for (int i=0; i<nsquares; i++) {
        bool occupied = 0;
        for (int j=0; j<nplayers; j++) {
            if ((board[j] >> i) & 1) {
                cout << players[j];
                occupied = 1;
                break;
            }
        }
        if (!occupied) {
            cout << empty;
        }
        unsigned long long prod = 1;
        for (int dim : dims) {
            prod *= dim;
            if ((i+1)%prod==0) {
                cout << endl;
            }
        }
    }
}

vector<int> Board::moves() {
    vector<int> moves;
    for (int i=0; i<nsquares; i++) {
        bool occupied = 0;
        for (int j=0; j<nplayers; j++) {
            if ((board[j] >> i) & 1) {
                occupied = 1;
                break;
            }
        }
        if (!occupied) {
            moves.push_back(i);
        }
    }
    return moves;
}

void Board::move(int square) {
    cout << '(' << turn << ',' << (1<<square) << ')' << endl;
    board[turn] |= (1 << square);
    turn = (turn + 1) % nplayers;
}
