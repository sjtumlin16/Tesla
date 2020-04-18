#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

struct coords {
	int xCoord;
	int yCoord;
};

class Pawn {
  private:
  	string name;
  	int xCoord;
  	int yCoord;
  	bool activated;

  public:
    Pawn(string, coords);
    bool setCoords(coords);
    coords getCoords();
    string getName();
    bool activate();
    bool deactivate();
    bool getActivatedState();
    bool spotOccupied(coords);

};

#endif
