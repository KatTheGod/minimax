#include <iostream>

#include "Game.h"

class TicTacToe : public Game {
  private:
    const int BOARD_SIZE = 3; // 3 x 3 board

  public:
    TicTacToe();
    ~TicTacToe();

    void startGame() override {}
    bool isValidMove() override {}
    void broadcastMove() override {}
    void step() override {}
    void render() override {}
    bool isGameOver() override {}
    void endGame() override {}
};