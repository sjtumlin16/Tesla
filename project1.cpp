#include "pawn.h"
#include "board.h"
#include "gameplay.h"

/*bool checkSpots(coords spot) {
	for (int i = 0; i < allPawns.size(); i++) {
		cout << allPawns.at(i)->getName() << " " << 
			allPawns.at(i)->getCoords().xCoord << endl;
	}	

	return false;
}*/

int main() {
	coords user2;
	coords user;
	user.xCoord = -98;
	user.yCoord = -97;
	user2.xCoord = 2;
	user2.yCoord = 3;

	/*Pawn car("hey", user2);

	user2 = car.getCoords();

	cout << user2.xCoord << " " << user2.yCoord << endl;

	car.setCoords(user);
	user2 = car.getCoords();

	cout << user2.xCoord << " " << user2.yCoord << endl;*/

/*	Pawn player("yourself?", user);
	Pawn yugo("the Yugo", user);
	Pawn pinto("the Pinto", user);
	Pawn roadster("the Roadster", user2);
	Pawn elon("Elon", user);

	vector<Pawn*> allPawns = {&player, &yugo, &pinto, &roadster, &elon};

	for (int i = 0; i < allPawns.size(); i++) {
		cout << allPawns.at(i)->getName() << " " << 
			allPawns.at(i)->getCoords().xCoord << endl;
	}*/
	srand (time(NULL));

	Gameplay game;

	game.playGame();

	return 0;
}