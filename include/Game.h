#pragma once

class Game {
  public:
    Game();
    ~Game();

    // Perform all operations required when a new game starts
    virtual void startGame();

    // Notify agents about the move played by another agent
    virtual void broadcastMove();

    // Adjust the board configuration based on the last move played
    virtual void step();

    // Display the board
    virtual void render();
};