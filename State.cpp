//
// Created by Kaytee on 9/4/2022.
//

#include "State.h"

State::State(std::string strBoard, int level, char move) {
    this->strBoard = std::move(strBoard);
    this->stringToBoard();
    this->stateValue = 0;
    this->level = level;
    this->parent = nullptr;
    this->move = move;
    this->enemyMove = (this->move == xMove) ? oMove : xMove;
    this->generateMoves();
}

State::State(std::vector<std::vector<char>> board, int level, char move) {
    this->board = std::move(board);
    this->boardToString();
    this->stateValue = 0;
    this->level = level;
    this->parent = nullptr;
    this->move = move;
    this->enemyMove = (this->move == xMove) ? oMove : xMove;
    this->generateMoves();
}

void State::stringToBoard() {
    this->board = std::vector<std::vector<char>>(GVM::rowCount, std::vector<char>(GVM::colCount, blank));
    for (int i = 0 ; i < this->strBoard.size(); i++){
        int row = i / GVM::rowCount;
        int col = i % GVM::colCount;

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

bool State::operator< (const State &state) const {
    return this->strBoard < state.strBoard;
}

std::string State::nextMove() {
    if (this->current < this->possibleMoves.size()){
        std::vector<int> possibleMove = this->possibleMoves[this->current];
        int index = possibleMove[0] * GVM::rowCount + possibleMove[1];

        std::string newBoard = this->strBoard;
        newBoard[index] = this->move;

        this->current++;

        return newBoard;
    } else {
        return "";
    }
}

void State::generateMoves() {
    for (int i = 0; i < GVM::rowCount; i++){
        for (int j = 0; j < GVM::colCount; j++){
            if (this->board[i][j] == blank){
                this->possibleMoves.push_back(std::vector<int>{i, j});
            }
        }
    }
    this->current = 0;
}

void State::updateValue() {
    if (!this->children.empty()){
//        std::cout << "Has kids will update" << std::endl;
        std::stringstream stringStream;

        if (this->level % 2 == 0){
            int maxValue = -1;

            for (State* child : this->children){
                maxValue = std::max(child->stateValue, maxValue);
                stringStream << child->stateValue << " , ";
            }

            /*std::cout << "options " << stringStream.str() << std::endl;
            std::cout << "Maximize: " << maxValue << std::endl;*/
            this->stateValue = maxValue;
        }
        else {
            int minValue = 1;

            for (State* child : this->children){
                minValue = std::min(child->stateValue, minValue);
                stringStream << child->stateValue << " , ";
            }

            /*std::cout << "options " << stringStream.str() << std::endl;
            std::cout << "Minimize: " << minValue << std::endl;*/
            this->stateValue = minValue;
        }
    }
    /*else {
        std::cout << "No kids, no update" << std::endl;
    }*/
}
