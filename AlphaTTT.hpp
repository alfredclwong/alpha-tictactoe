#pragma once
#include <vector>

class AlphaTTT {
private:
    int gameIndex;
public:
    AlphaTTT(int);
    AlphaTTT(int, int);

    void play();
};
