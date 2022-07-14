#pragma once

class Game {
  public:
    Game();
    ~Game();

    // Perform all operations required when a new game starts
    virtual void startGame();

    // Check if the move from the last agent was valid
    virtual bool isValidMove();

    // Notify agents about the move played by another agent
    virtual void broadcastMove();

    // Adjust the board configuration based on the last move played
    virtual void step();

    // Display the board
    virtual void render();

    // Check if the game is over
    virtual bool isGameOver();

    // Notify agents that the game has been ended
    virtual void endGame();
};