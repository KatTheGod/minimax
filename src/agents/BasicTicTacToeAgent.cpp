#include "Agent.h"

#include <string>
#include <vector>

class BasicTicTacToeAgent : public Agent {
  private:
    const char EMPTY_SPOT = '_';
    int boardSize;
    char moveShape;
    std::vector<std::vector<char>> board;

  public:
    BasicTicTacToeAgent(int boardSize, char moveShape) {
        this->boardSize = boardSize;
        this->moveShape = moveShape;
        board = std::vector<std::vector<char>>(boardSize,
                                               std::vector<char>(boardSize));
    }

    std::string getMove() override { return ""; }
};