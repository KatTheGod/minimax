//
// Created by katle on 9/4/2022.
//

#include "Agent.h"

Agent::Agent(char myMove) {
    this->myMove = myMove;
    this->desiredGameResult = (this->myMove == xMove) ? winX : winO;
}

std::vector<int> Agent::getMove(const std::vector<std::vector<char>>& board, int turn) {
    std::set<State> visited;

    State startingState(board, 0, this->myMove);
    State* currentState = &startingState;


    while (currentState != nullptr){
        /*std::cout << "---------------------------------------------------------------------" << std::endl;
        std::cout << "Current state: " << currentState->move << std::endl;
        GVM::printBoard(currentState->board);
        std::cout << std::endl;*/

        currentState->updateValue();
//        std::cout << "Current state value: " << currentState->stateValue << std::endl;

        std::string nextBoard = currentState->nextMove();
        if (!nextBoard.empty()){
            char nextMove = (currentState->level % 2 == 0) ? startingState.enemyMove : startingState.move;
            State* nextState = new State(nextBoard, currentState->level + 1, nextMove);
            nextState->parent = currentState;

            if (visited.find(*nextState) == visited.end()){
                /*std::cout << "Next state" << std::endl;
                GVM::printBoard(nextState->board);
                std::cout << std::endl;*/

                visited.insert(*nextState);

                currentState->children.push_back(nextState);

                gameResults gameResult = GVM::gameResult(nextState->board, turn + nextState->level);
                if (gameResult != playing){
                    if (gameResult == winX && startingState.move == xMove ||
                        gameResult == winO && startingState.move == oMove){
                        nextState->stateValue = 1;
                    }
                    else if (gameResult == winX && startingState.move == oMove ||
                             gameResult == winO && startingState.move == xMove){
                        nextState->stateValue = -1;
                    }
                    else {
                        nextState->stateValue = 0;
                    }

                    /*std::cout << "end of game: " << nextState->stateValue << std::endl;
                    std::cout << "Wont move from current state to child" << std::endl;*/
                } else {

//                    std::cout << "Not end state, Moving to child" << std::endl;
                    currentState = nextState;
                }
            } else {
                /*std::cout << "Already visited state, going to delete" << std::endl;
                GVM::printBoard(nextState->board);
                std::cout << std::endl;*/
                delete nextState;
            }
        }
        else {
            /*std::cout << "Possible moves - current: " << currentState->possibleMoves.size() << " - " << currentState->current << std::endl;
            std::cout << "Value: " << currentState->stateValue << std::endl;
            std::cout << "back track to parent" << std::endl;
            GVM::printBoard(currentState->board);
            std::cout << std::endl;*/
            currentState = currentState->parent;
        }
    }

    currentState = &startingState;

    /*std::cout << "Agent Options" << std::endl;
    for (State* child : currentState->children){
        std::cout << "Value: " << child->stateValue << std::endl;
        GVM::printBoard(child->board);
        std::cout << std::endl;
    }*/

    //Selecting best state from children
    State* maxChild = nullptr;
    for (State* child : currentState->children){
        if (maxChild == nullptr || child->stateValue > maxChild->stateValue){
            maxChild = child;
        }
    }

    /*std::cout << std::endl << "Max Chose: " << maxChild->stateValue << std::endl;
    GVM::printBoard(maxChild->board);
    std::cout << std::endl;*/

    return Agent::findMove(*maxChild, startingState);

//    return Agent::getRandomMove(board);
}

std::vector<int> Agent::getRandomMove(std::vector<std::vector<char>> board) {
    int row, col;
    bool validMove = false;

    while (!validMove){
        row = rand() % GVM::rowCount;
        col = rand() % GVM::colCount;

        validMove = board[row][col] == blank;
    }

    return std::vector<int>{row, col};
}



std::vector<int> Agent::findMove(const State& startState, const State& endState) {
    std::vector<int> difference(2, -1);
    int count = 0;
    for (int i = 0; i < startState.board.size(); i++){
        for (int j = 0; j < startState.board[i].size(); j++){
            if (startState.board[i][j] != endState.board[i][j]){
                difference = std::vector<int>{i, j};
                count++;
            }
        }
    }

    if (count != 1){
        std::cout << "Find move was invalid!" << std::endl;
        std::cout << "Start State" << std::endl;
        GVM::printBoard(startState.board);
        std::cout << std::endl << "End State" << std::endl;
        GVM::printBoard(endState.board);
        std::cout << std::endl;
        exit(69);
    }

    return difference;
}
