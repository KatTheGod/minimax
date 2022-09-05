#ifndef MINMAX_XNO_GVM_H
#define MINMAX_XNO_GVM_H

#include <vector>
#include <iostream>
#include "GV.h"

class GVM {
public:
    //Variables

    //Global Variables
    static const int rowCount = 3;
    static const int colCount = 3;
    static const int streak = 3;

    static void printBoard(const std::vector<std::vector<char>>& board);
    static void setBoardAtPos(std::vector<std::vector<char>>& board, const std::vector<int>& position, char move);

    static bool inBounds(int i, int j, const std::vector<std::vector<char>>& board);
    static bool inBounds(std::vector<int> position, const std::vector<std::vector<char>>& board);

    static char getBoardAtPos(const std::vector<std::vector<char>>& board, const std::vector<int>& position);

    static gameResults playerToResult(char move);
    static gameResults gameResult(const std::vector<std::vector<char>>& board, int turn);
    static gameResults checkDiagonal(directions direction, std::vector<std::vector<char>> board);
};


#endif //MINMAX_XNO_GVM_H
