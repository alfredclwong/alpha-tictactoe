#pragma once
#include <vector>

class AlphaTTT {
private:
    int gameIndex;
    int pickMove(std::vector<int>);
public:
    AlphaTTT(int);
    AlphaTTT(int, int);

    void play();
};
