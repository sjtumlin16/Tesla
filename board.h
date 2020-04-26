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
    bool elonAwake;
    bool isGameOver;
    vector<char> plays;

    bool activeMove(Pawn*);
    void updatePawns();
    void activationWarning(Pawn*);
    void help();
    void trackPlays(char);
    bool checkSpot(coords);
    char whatsThere(coords);
    bool checkArea(coords);
    bool checkArea(coords, Pawn*);
    bool offBoard(coords);
    void hint();
    vector<coords> createArea(coords);

  public:
    Board();
    bool initialize();
    bool printBoard();
    bool printBoardDark();
    bool gameOver();
    void gameOver(Pawn*);
    bool playerMove();
};

#endif
