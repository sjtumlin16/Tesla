#include "board.h"

Board::Board() {
	allPawns = {&player, &yugo, &pinto, &elon, &roadster};
	allPawns.at(0)->setName("yourself?", 'O');
	allPawns.at(1)->setName("the Yugo", 'Y');
	allPawns.at(2)->setName("the Pinto", 'P');
	allPawns.at(3)->setName("Elon", 'E');
	allPawns.at(4)->setName("the Roadster", 'R');

	isGameOver = false;
}

bool Board::checkSpot(coords inp) {
	//cout << "here: " << inp.xCoord << " " << inp.yCoord << endl;
	for (int i = 0; i < allPawns.size(); i++) {
		//cout << player.getCoords().xCoord << endl;
		//cout << "val: " << allPawns.at(i)->getCoords().xCoord << " " << allPawns.at(i)->getCoords().yCoord << endl;
		if ((allPawns.at(i)->getCoords().xCoord == inp.xCoord) && (allPawns.at(i)->getCoords().yCoord == inp.yCoord)) {
			return true;
		}
	}

	return false;
}

char Board::whatsThere(coords inp) {
	//cout << "here: " << inp.xCoord << " " << inp.yCoord << endl;
	for (int i = 0; i < allPawns.size(); i++) {
		//cout << player.getCoords().xCoord << endl;
		//cout << "val: " << allPawns.at(i)->getCoords().xCoord << " " << allPawns.at(i)->getCoords().yCoord << endl;
		if ((allPawns.at(i)->getCoords().xCoord == inp.xCoord) && (allPawns.at(i)->getCoords().yCoord == inp.yCoord)) {
			return allPawns.at(i)->getSymb();
		}
	}

	return 'n';
}

bool Board::checkArea(coords inp) {
	vector<coords> area(8);
	area.at(0).xCoord = inp.xCoord - 1;
	area.at(0).yCoord = inp.yCoord - 1;
	area.at(1).xCoord = inp.xCoord;
	area.at(1).yCoord = inp.yCoord - 1;
	area.at(2).xCoord = inp.xCoord + 1;
	area.at(2).yCoord = inp.yCoord - 1;
	area.at(3).xCoord = inp.xCoord - 1;
	area.at(3).yCoord = inp.yCoord;
	area.at(4).xCoord = inp.xCoord + 1;
	area.at(4).yCoord = inp.yCoord;
	area.at(5).xCoord = inp.xCoord - 1;
	area.at(5).yCoord = inp.yCoord + 1;
	area.at(6).xCoord = inp.xCoord;
	area.at(6).yCoord = inp.yCoord + 1;
	area.at(7).xCoord = inp.xCoord + 1;
	area.at(7).yCoord = inp.yCoord + 1;

	for (int i = 0; i < area.size(); i++) {
		//cout << area.at(i).xCoord << " " << area.at(i).yCoord << " " << (allPawns.at(1)->getCoords().xCoord == area.at(i).xCoord) << endl;
		if (checkSpot(area.at(i))) {
			return true;
		}
	}

	return false;
}

bool Board::checkArea(coords inp, Pawn *thePawn) {
	vector<coords> area(8);
	area.at(0).xCoord = inp.xCoord - 1;
	area.at(0).yCoord = inp.yCoord - 1;
	area.at(1).xCoord = inp.xCoord;
	area.at(1).yCoord = inp.yCoord - 1;
	area.at(2).xCoord = inp.xCoord + 1;
	area.at(2).yCoord = inp.yCoord - 1;
	area.at(3).xCoord = inp.xCoord - 1;
	area.at(3).yCoord = inp.yCoord;
	area.at(4).xCoord = inp.xCoord + 1;
	area.at(4).yCoord = inp.yCoord;
	area.at(5).xCoord = inp.xCoord - 1;
	area.at(5).yCoord = inp.yCoord + 1;
	area.at(6).xCoord = inp.xCoord;
	area.at(6).yCoord = inp.yCoord + 1;
	area.at(7).xCoord = inp.xCoord + 1;
	area.at(7).yCoord = inp.yCoord + 1;

	char thisChar = thePawn->getSymb();

	for (int i = 0; i < area.size(); i++) {
		//cout << area.at(i).xCoord << " " << area.at(i).yCoord << " " << (allPawns.at(1)->getCoords().xCoord == area.at(i).xCoord) << endl;
		if (checkSpot(area.at(i)) && (whatsThere(area.at(i)) == thisChar)) {
			return true;
		}
	}

	return false;
}

bool Board::offBoard(coords temp) {
	if (temp.xCoord > 14 || temp.xCoord < 0) {
		return true;
	}

	if (temp.yCoord > 14 || temp.yCoord < 0) {
		return true;
	}

	return false;
}

bool Board::initialize() {
	for (int i = 0; i < allPawns.size(); i++) {
		coords temp;

		do {
			temp.xCoord = rand() % 15;
			temp.yCoord = rand() % 15;
		} while (checkArea(temp) || checkSpot(temp));

		// cout << "setting " << allPawns.at(i)->getSymb() << " " << temp.xCoord << " " << temp.yCoord << endl;

		allPawns.at(i)->setCoords(temp);
	}

	allPawns.at(allPawns.size() - 1)->activate();

	return true;
}

bool Board::printBoard() {
	char printChar;
	coords temp;

	for (int i = 0; i < 15; i++) {
		temp.yCoord = i;
		for (int j = 0; j < 15; j++) {
			temp.xCoord = j;
			if (checkSpot(temp)) {
				printChar = whatsThere(temp);
			}
			else {
				printChar = '.';
			}

			cout << printChar << " ";
		}
		cout << endl;
	}

	return true;
}

bool Board::printBoardDark() {
	char printChar;
	coords temp;

	cout << string(100, '\n');

	cout << " Y: [/" << (yugo.getActivatedState() ? " " : "/") << "] P: [/" 
	  << (pinto.getActivatedState() ? " " : "/") << "] E: [" 
	  << (elon.getActivatedState() ? "AWOKEN" : "Asleep") << "]" << endl;

	for (int i = 0; i < 15; i++) {
		temp.yCoord = i;
		for (int j = 0; j < 15; j++) {
			temp.xCoord = j;
			if (checkSpot(temp) && (whatsThere(temp) == 'O')) {
				printChar = whatsThere(temp);
			}
			else if (checkArea(temp, &player)) {
				if (checkSpot(temp)) {
					printChar = whatsThere(temp);
				}
				else {
					printChar = '.';
				}
			}
			else {
				printChar = '/';
			}

			cout << printChar << " ";
		}
		cout << endl;
	}

	cout << endl << endl;

	return true;
}

bool Board::playerMove() {
	int x, y;
	coords newCoord, oldCoords;
	char inp;
	bool cont;

	do {
		cont = true;
		cin >> inp;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');

		switch (inp) {
			case 'W': case 'w': 
				y = -1;
				x = 0;
			break;

			case 'A': case 'a': 
				y = 0;
				x = -1;
			break;

			case 'S': case 's': 
				y = 1;
				x = 0;
			break;

			case 'D': case 'd': 
				y = 0;
				x = 1;
			break;

			default:
				cont = false;
		}

		oldCoords = player.getCoords();

		newCoord.xCoord = oldCoords.xCoord + x;
		newCoord.yCoord = oldCoords.yCoord + y;

		if (checkSpot(newCoord)) {
			cont = false;
		}

		if (offBoard(newCoord)) {
			cont = false;
		}

		if (!cont) {
			printBoardDark();
		}

	} while(!cont);

	player.setCoords(newCoord);
	printBoardDark();
	updatePawns();

	return true;
}

bool Board::activeMove(Pawn *thePawn) {
	int x, y;
	coords newCoord, oldCoords;
	int inp;
	bool cont;

	do {
		cont = true;

		inp = rand() % 6;

		switch (inp) {
			case 0: 
				y = -1;
				x = 0;
			break;

			case 1: 
				y = 0;
				x = -1;
			break;

			case 2: 
				y = 1;
				x = 0;
			break;

			case 3: 
				y = 0;
				x = 1;
			break;

			case 4:
				y = thePawn->ySign(player.getCoords());
				x = 0;
			break;

			case 5:
				y = 0;
				x = thePawn->xSign(player.getCoords());
			break;

			default:
				cont = false;
		}

		oldCoords = thePawn->getCoords();

		newCoord.xCoord = oldCoords.xCoord + x;
		newCoord.yCoord = oldCoords.yCoord + y;

		if (checkSpot(newCoord)) {
			cont = false;
		}

		if (offBoard(newCoord)) {
			cont = false;
		}

		if (checkArea(newCoord, &player)) {
			cont = false;
		}

	} while(!cont);

	thePawn->setCoords(newCoord);

	return true;
}

void Board::updatePawns() {
	for (int i = 1; i < allPawns.size(); i++) {
		if (checkArea(allPawns.at(i)->getCoords(), &player)) {
			if (!(allPawns.at(i)->activate())) {
				gameOver(allPawns.at(i));
			}
			else {
				activationWarning(allPawns.at(i));
			}
		}
	}

	if (elon.getActivatedState()) {
		activeMove(&elon);
	}

	return;
}

void Board::activationWarning(Pawn *thePawn) {
	cout << "You ran into " << thePawn->getName() << "!" << endl;
	cout << "One more time and you're going to be on the rocket!" << endl;
	if (thePawn->getSymb() == 'E') {
		cout << "Now he will be looking for you. Be careful." << endl;
	}

	cout << endl;

	return;
}

bool Board::gameOver() {
	return isGameOver;
}

void Board::gameOver(Pawn *thePawn) {
	if (thePawn->getSymb() == 'E') {
		cout << "Welp, Elon got you. Good luck in space." << endl;
	}
	else if (thePawn->getSymb() == 'R') {
		cout << "Congrats, you saved the Roadster!" << endl;
	}
	else {
		cout << "Wrong car. I told you to be careful..." << endl;
	}

	isGameOver = true;

	return;
}
