#ifndef BOARD_H
#define BOARD_H

#include "pawn.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath> 
#include <limits> 

using namespace std;

class Board {
  private:
    vector<Pawn*> allPawns;
    Pawn player;
    Pawn yugo;
    Pawn pinto;
    Pawn roadster;
    Pawn elon;
    bool isGameOver;

  public:
    Board();
    bool checkSpot(coords);
    char whatsThere(coords);
    bool checkArea(coords);
    bool checkArea(coords, Pawn*);
    bool offBoard(coords);
    bool initialize();
    bool printBoard();
    bool printBoardDark();
    bool playerMove();
    bool activeMove(Pawn*);
    void updatePawns();
    void activationWarning(Pawn*);
    bool gameOver();
    void gameOver(Pawn*);
};

#endif
