#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "board.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath> 
#include <limits> 

using namespace std;

class Gameplay {
  private:

  public:
    Gameplay();
    void playGame();
    void printInstructions();
    void goodbye();
};

#endif
