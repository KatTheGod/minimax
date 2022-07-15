#pragma once

#include <string>

class Agent {
  public:
    Agent();
    ~Agent();

    // Return a string that represents the move chosen by the agent
    virtual std::string getMove() { return ""; }
};