#include "TicTacToe.h"
#include <iostream>
#include <string>

// Set the board to be blank
void TicTacToe::initializeBoard() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++)
            board[row][col] = EMPTY_POSITION;
    }
}

bool TicTacToe::isValidMove(std::string &move) {}

void TicTacToe::broadcastMove() {}

void TicTacToe::step() {}

// Display the current board state
void TicTacToe::render() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            std::cout << board[row][col] << " ";
        }

        std::cout << "\n";
    }
}

TicTacToe::TicTacToe() { initializeBoard(); }

TicTacToe::~TicTacToe() {}