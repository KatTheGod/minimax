#ifndef MINMAX_XNO_STATE_H
#define MINMAX_XNO_STATE_H

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <utility>
#include "GVM.h"

class State {
public:

    // Variables
    int stateValue, level;

    char move, enemyMove;

    State* parent;

    std::string strBoard;

    std::vector<std::vector<char>> board;
    std::vector<State*> children;

    //Move back to private
    int current;

    std::vector<std::vector<int>> possibleMoves;

    //Methods
    State(std::string strBoard, int level, char move);
    State(std::vector<std::vector<char>> board, int level, char move);

    void updateValue();

    bool operator< (const State& state) const;

    std::string nextMove();

private:
    //Variables


    //Methods
    void boardToString();
    void stringToBoard();
    void generateMoves();
};


#endif //MINMAX_XNO_STATE_H
