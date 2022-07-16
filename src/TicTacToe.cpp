#include <iostream>
#include <string>

#include "Game.h"

class TicTacToe : public Game {
  private:
    const static int BOARD_SIZE = 3; // Board dimension
    const static char EMPTY_POSITION =
        '_'; // Used to fill starting TicTacToe board

    char board[BOARD_SIZE][BOARD_SIZE] = {};

    // Set the board to be blank
    void initializeBoard() {
        for (int row = 0; row < BOARD_SIZE; row++) {
            for (int col = 0; col < BOARD_SIZE; col++)
                board[row][col] = EMPTY_POSITION;
        }
    }

    bool isValidMove(std::string &move) {}

    void broadcastMove() override {}

    void step() override {}

    // Display the current board state
    void render() override {
        for (int row = 0; row < BOARD_SIZE; row++) {
            for (int col = 0; col < BOARD_SIZE; col++) {
                std::cout << board[row][col] << " ";
            }

            std::cout << "\n";
        }
    }

  public:
    TicTacToe() { initializeBoard(); }

    ~TicTacToe();
};