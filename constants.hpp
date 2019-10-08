#pragma once
#include <cstdint>
#include <string>

typedef uint16_t Bitboard;

const std::string DATA_DIR = "data/";
const std::string MODEL_DIR = "model/";

const char PIECES[] = {'X', 'O', '*'};
const int N_PLAYERS = 2;

const int DIMS[] = {3, 3};
const int N_SQUARES = 9;

const Bitboard INITIAL_STATE[] = {
    0b000000000,
    0b000000000,
    0b111111111,
    0b000000000,
};

const Bitboard LINES[] = {
    0b000000111,
    0b000111000,
    0b111000000,
    0b100100100,
    0b010010010,
    0b001001001,
    0b100010001,
    0b001010100,
};
