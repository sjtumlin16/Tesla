#ifndef PAWN_H
#define PAWN_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath> 
#include <limits> 

using namespace std;

struct coords {
	int xCoord;
	int yCoord;
};

class Pawn {
  private:
  	string name;
    char symb;
  	int xCoord;
  	int yCoord;
  	bool activated;

  public:
    Pawn();
    void setName(string, char);
    bool setCoords(coords);
    coords getCoords();
    string getName();
    char getSymb();
    bool activate();
    bool deactivate();
    bool getActivatedState();
    bool spotOccupied(coords);
    int ySign(coords);
    int xSign(coords);

};

#endif
