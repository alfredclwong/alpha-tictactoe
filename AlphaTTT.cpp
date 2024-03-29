#include "AlphaTTT.hpp"
#include "Board.hpp"
#include "constants.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <unistd.h> // chdir
#include <sys/stat.h> // stat

unsigned long long getGameIndex() {
    unsigned long long gameIndex = 0;
    chdir(DATA_DIR.c_str());
    struct stat buffer;
    while (true) {
        if (stat(std::to_string(gameIndex).c_str(), &buffer)) {
            break;
        }
        ++gameIndex;
    }
    chdir("../");
    return gameIndex;
}

int pickMove(std::vector<int> moves) {
    return moves[0];
}

AlphaTTT::AlphaTTT(int model) : AlphaTTT::AlphaTTT(model, model) {}

AlphaTTT::AlphaTTT(int model1, int model2) {
    gameIndex = getGameIndex();
}

void AlphaTTT::play() {
    Board game[N_SQUARES];
    Board board;
    for (int i=0; i<N_SQUARES; ++i) {
        std::vector<int> moves = board.getMoves();
        int move = pickMove(moves);
        board.move(move);
        game[i] = board;
        if (board.state != 0) {
            break;
        }
    }

    // write game to file
    //std::cout << DATA_DIR << gameIndex << std::endl;
    //std::ofstream file;
    //file.open(DATA_DIR + std::to_string(gameIndex++));
    std::cout << board.state - 1;// << std::endl;
    for (int i=0; i<N_SQUARES; ++i) {
        for (int j=0; j<N_PLAYERS+2; ++j) {
            for (int k=N_SQUARES-1; k>=0; --k) {
                std::cout << ((game[i].board[j] >> k) & 1);
            }
            //std::cout << std::endl;
        }
        //game[i].disp();
        if (game[i].state != 0) {
            //break;
        }
    }
    //file.close();
}
