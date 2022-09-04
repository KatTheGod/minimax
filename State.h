#ifndef MINMAX_XNO_STATE_H
#define MINMAX_XNO_STATE_H

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <utility>

class State {
public:

    // Variables
    int stateValue;

    std::string strBoard;

    std::vector<std::vector<char>> board;

    static const char blank = ' ';

    //Methods
    State(std::string strBoard);
    State(std::vector<std::vector<char>> board);

private:
    //Methods
    void boardToString();
    void stringToBoard();
};


#endif //MINMAX_XNO_STATE_H
