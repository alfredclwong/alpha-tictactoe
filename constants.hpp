#pragma once
#include <cstdint>

typedef uint16_t Bitboard;

const char PIECES[] = {'X', 'O', '*'};
const int N_PLAYERS = 2;

const int DIMS[] = {3, 3};
const int N_SQUARES = 9;

const Bitboard INITIAL_STATE[] = {
    0b0000000000000000,
    0b0000000000000000,
    0b0000000111111111,
    0b0000000000000000,
};

const Bitboard LINES[] = {
    0b0000000000000111,
    0b0000000000111000,
    0b0000000111000000,
    0b0000000100100100,
    0b0000000010010010,
    0b0000000001001001,
    0b0000000100010001,
    0b0000000001010100,
};
