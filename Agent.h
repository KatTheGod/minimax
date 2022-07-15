#pragma once

#include <string>

class Agent {
  public:
    Agent();
    ~Agent();

    virtual std::string getMove();
};