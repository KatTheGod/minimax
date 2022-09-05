#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <ctime>
#include <chrono>

#include "GV.h"
#include "GVM.h"
#include "Agent.h"
#include "KatTimer.h"

//Variables
static int playerNumber, turn;

//Method Definition
bool validMove(const std::vector<int>& move, const std::vector<std::vector<char>>& board);

std::vector<std::vector<char>> initialize(bool trueRandom);

int main() {
    std::vector<std::vector<char>> board = initialize(false);

    Agent smartAgent = Agent(moves[(playerNumber + 1) % 2]);

    gameResults outcome = GVM::gameResult(board, turn);
    while (outcome == playing){
        std::vector<int> move;
        char symbol = moves[turn % 2];

        std::cout << "Current Player: " << symbol << std::endl;
        GVM::printBoard(board);
        std::cout << std::endl;

        if (turn % 2 == playerNumber){
            bool turnComplete = false;

            while (!turnComplete){
                int x, y;

                std::cout << "Enter move (x y): ";

                std::cin >> x;
                std::cin >> y;

                move = std::vector<int> {x, y};

                turnComplete = validMove(move, board);

                if (!turnComplete){
                    std::cout << "Invalid Move" << std::endl;
                }
            }
        } else {
            KatTimer timer;
            move = smartAgent.getMove(board, turn);
            std::cout << "Move is " << move[0] << " , " << move[1] << std::endl;
            std::cout << "Took: " << timer.getTimeMS() << "ms" << std::endl;
        }

        turn++;
        GVM::setBoardAtPos(board, move, symbol);
        outcome = GVM::gameResult(board, turn);

    }

    GVM::printBoard(board);

    if (outcome == draw){
        std::cout << "Its a draw" << std::endl;
    }
    else if (outcome == winX){
        std::cout << "Player 1 (X) Wins" << std::endl;
    }
    else{
        std::cout << "Player 2 (O) Wins" << std::endl;
    }

    return 0;
}

//Method Implementation
std::vector<std::vector<char>> initialize(bool trueRandom){
    //Initializing Global Variables, for now we make them constant
    /*GVM::streak = 3;
    GVM::rowCount = 3;
    GVM::colCount = 3;*/

    //Initializing seed
    auto now = std::chrono::system_clock::now();
    auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);

    auto value = now_ms.time_since_epoch();
    long duration = value.count();
    //std::cout << duration << std::endl;
    std::srand(duration);

    //Initializing players
    playerNumber = (trueRandom) ? rand() % 2 : 1;
    std::cout <<  "My Move: " << moves[playerNumber] << std::endl;

    //Initializing board
    std::vector<std::vector<char>> board (GVM::rowCount, std::vector<char>(GVM::colCount, blank));

    //Initializing game variables
    turn = 0;

    return board;
}

bool validMove(const std::vector<int>& move, const std::vector<std::vector<char>>& board){
    return GVM::inBounds(move, board) && GVM::getBoardAtPos(board, move) == blank;
}