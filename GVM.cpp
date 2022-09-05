#include "GVM.h"

char GVM::getBoardAtPos(const std::vector<std::vector<char>> &board, const std::vector<int> &position) {
    if (!inBounds(position[0], position[1], board)){
        std::cout << position[0] << " , " << position[1] << std::endl;
        std::cout << "Got an invalid board position! why!" << std::endl;
        exit(69);
    } else {
        return board[position[0]][position[1]];
    }
}

void GVM::setBoardAtPos(std::vector<std::vector<char>> &board, const std::vector<int> &position, char move) {
    if (!inBounds(position[0], position[1], board)){
        std::cout << "Got an invalid board position! why!" << std::endl;
        std::cout << position[0] << " , " << position[1] << std::endl;
        exit(69);
    } else {
        board[position[0]][position[1]] = move;
    }
}

bool GVM::inBounds(std::vector<int> position, const std::vector<std::vector<char>> &board) {
    return inBounds(position[0], position[1], board);
}

bool GVM::inBounds(int i, int j, const std::vector<std::vector<char>> &board) {
    return i >= 0 && j >= 0 && i < board.size() && j < board[0].size();
}

gameResults GVM::gameResult(const std::vector<std::vector<char>> &board, int turn) {
    //Check for win on row
    for (const std::vector<char>& row : board){
        char currentMove = row[0];
        int count = 0;
        int j = 0;

        while (j - count + streak <= colCount && count < streak){
            if (currentMove == blank){
                //Reset
                count = 0;
            } else {
                if (row[j] != currentMove){
                    //Mismatch, Reset
                    count = 0;
                    currentMove = row[j];
                } else {
                    //Match increase
                    count++;
                }
            }

            j++;
        }

        if (count == streak){
            return playerToResult(currentMove);
        }
    }

    //Check for win on column
    for (int j = 0; j < board[0].size(); j++){
        char currentMove = board[0][j];
        int count = 0;
        int i = 0;

        while (i - count + streak <= rowCount && count < streak){
            if (currentMove == blank){
                //Reset
                count = 0;
            } else {
                if (board[i][j] != currentMove){
                    //Mismatch, Reset
                    count = 0;
                    currentMove = board[i][j];
                } else {
                    //Match increase
                    count++;
                }
            }

            i++;
        }

        if (count == streak){
            return playerToResult(currentMove);
        }
    }

    //Check for win on diagonal, left to right
    gameResults rightDiagResult = checkDiagonal(right, board);
    if (rightDiagResult != playing){
        return rightDiagResult;
    }

    //Check for win on diagonal, right to left
    gameResults leftDiagResult = checkDiagonal(left, board);
    if (leftDiagResult != playing){
        return leftDiagResult;
    }

    if (turn == rowCount * colCount){
        return draw;
    }

    //Still Playing Then
    return playing;
}

gameResults GVM::checkDiagonal(directions direction, std::vector<std::vector<char>> board) {
    int iDirection = (direction == right) ? 1: -1;
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[i].size(); j++){
            char currentPlayer = board[i][j];
            if (currentPlayer != blank){
                int count = 0;
                while ( count < streak && GVM::inBounds(i + count, j + count * iDirection, board) &&
                        board[i + count][j + count * iDirection] == currentPlayer){
                    board[i + count][j + count * iDirection] = blank;
                    count++;
                }

                if (count == streak){
                    return playerToResult(currentPlayer);
                }
            }
        }
    }

    return playing;
}

gameResults GVM::playerToResult(char move) {
    return (move == xMove) ?  winX : winO;
}

void GVM::printBoard(const std::vector<std::vector<char>>& board){
    for (const std::vector<char>& row : board){
        for (char col : row){
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }
}