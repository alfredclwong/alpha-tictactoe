#pragma once
#include <vector>
using namespace std;

const int nplayers = 2;
const char empty = '*';
const char players[] = {'X', 'O'};
const int dims[] = {3, 3};
const int nsquares = 9;

class Board {
    private:
        int turn;
        unsigned long long board[nplayers];
    public:
        Board();
        void disp();
        vector<int> moves();
        void move(int);
};
