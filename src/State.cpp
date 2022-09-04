//
// Created by Kaytee on 9/4/2022.
//

#include "State.h"

State::State(std::string strBoard) {
    this->strBoard = std::move(strBoard);
    this->stringToBoard();
    this->stateValue = 0;
}

State::State(std::vector<std::vector<char>> board) {
    this->board = std::move(board);
    this->boardToString();
    this->stateValue = 0;
}

void State::stringToBoard() {
    this->board = std::vector<std::vector<char>>(3, std::vector<char>(3, State::blank));
    for (int i = 0 ; i < this->strBoard.size(); i++){
        int row = i / 3;
        int col = i % 3;

        this->board[row][col] = this->strBoard[i];
    }
}

void State::boardToString() {
    std::stringstream stringStream;

    for (const std::vector<char>& row : this->board){
        for (char letter : row){
            stringStream << letter;
        }
    }

    this->strBoard = stringStream.str();
}
