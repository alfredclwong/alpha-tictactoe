#include "AlphaTTT.hpp"
#include <iostream>

int main() {
    int nGames;
    std::cin >> nGames;
    AlphaTTT alphaTTT(0);
    for (int i=0; i<nGames; i++) {
        alphaTTT.play();
    }
}
