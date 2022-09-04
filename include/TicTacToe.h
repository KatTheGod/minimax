#pragma once
#include "Game.h"
#include <string>

class TicTacToe : public Game {
public:
    TicTacToe();
    ~TicTacToe();

private:
    const static int BOARD_SIZE = 3; // Board dimension
    const static char EMPTY_POSITION =
        '_'; // Used to fill starting TicTacToe board

    char board[BOARD_SIZE][BOARD_SIZE] = {};
    void initializeBoard();
    bool isValidMove(std::string &move);
    void broadcastMove() override;
    void step() override;
    void render() override;
};