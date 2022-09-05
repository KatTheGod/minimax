#ifndef MINMAX_XNO_AGENT_H
#define MINMAX_XNO_AGENT_H

#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <set>
#include <stack>

#include "State.h"
#include "GVM.h"

class Agent {

public:
    //Variables
    char myMove;

    //Methods
    Agent(char myMove);

    std::vector<int> getMove(const std::vector<std::vector<char>>& board, int turn);

private:
    //Variables

    gameResults desiredGameResult;

    //Methods
    static std::vector<int> getRandomMove(std::vector<std::vector<char>> board);
    static std::vector<int> findMove(const State& startState, const State& endState);
};


#endif //MINMAX_XNO_AGENT_H
