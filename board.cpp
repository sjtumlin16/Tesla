#include "board.h"
#include "constants.h"

Board::Board() {
    allPawns = {&player, &yugo, &pinto, &elon, &roadster};
    allPawns.at(0)->setName("yourself?", PLAYER);
    allPawns.at(1)->setName("the Yugo", YUGO);
    allPawns.at(2)->setName("the Pinto", PINTO);
    allPawns.at(3)->setName("Elon", ELON);
    allPawns.at(4)->setName("the Roadster", ROADSTER);

    plays = {'e', 'r', 't', 'y'};

    isGameOver = false;
    elonAwake = false;
}

bool Board::checkSpot(coords inp) {
    for (int i = 0; i < allPawns.size(); i++) {
        if ((allPawns.at(i)->getCoords().xCoord == inp.xCoord) && (allPawns.at(i)->getCoords().yCoord == inp.yCoord)) {
            return true;
        }
    }

    return false;
}

char Board::whatsThere(coords inp) {
    for (int i = 0; i < allPawns.size(); i++) {
        if ((allPawns.at(i)->getCoords().xCoord == inp.xCoord) && (allPawns.at(i)->getCoords().yCoord == inp.yCoord)) {
            return allPawns.at(i)->getSymb();
        }
    }

    return 'n';
}

bool Board::checkArea(coords inp) {
    vector<coords> area(AREA_SIZE);
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
        if (checkSpot(area.at(i))) {
            return true;
        }
    }

    return false;
}

bool Board::checkArea(coords inp, Pawn *thePawn) {
    vector<coords> area(AREA_SIZE);
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
            temp.xCoord = rand() % BOARD_COLUMNS;
            temp.yCoord = rand() % BOARD_ROWS;
        } while (checkArea(temp) || checkSpot(temp));

        allPawns.at(i)->setCoords(temp);
    }

    allPawns.at(allPawns.size() - 1)->activate();

    return true;
}

bool Board::printBoard() {
    char printChar;
    coords temp;

    for (int i = 0; i < BOARD_ROWS; i++) {
        temp.yCoord = i;
        for (int j = 0; j < BOARD_COLUMNS; j++) {
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
      << (elon.getActivatedState() ? "FUMING" : (elonAwake ? "AWOKEN" : 
      "Asleep")) << "]" << endl;

    for (int i = 0; i < BOARD_ROWS; i++) {
        temp.yCoord = i;
        for (int j = 0; j < BOARD_COLUMNS; j++) {
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

    return true;
}

bool Board::playerMove() {
    int x, y;
    coords newCoord, oldCoords;
    char inp, currPlay;
    bool cont;

    do {
        cont = true;
        cin >> inp;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        switch (inp) {
            case 'W': case 'w': 
                y = MOVE_UP;
                x = MOVE_NONE;
                currPlay = 'w';
            break;

            case 'A': case 'a': 
                y = MOVE_NONE;
                x = MOVE_LEFT;
                currPlay = 'a';
            break;

            case 'S': case 's': 
                y = MOVE_DOWN;
                x = MOVE_NONE;
                currPlay = 's';
            break;

            case 'D': case 'd': 
                y = MOVE_NONE;
                x = MOVE_RIGHT;
                currPlay = 'd';
            break;

            case 'H': case 'h':
                help();
                cont = false;
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
    hint();
    cout << endl << endl;
    trackPlays(currPlay);
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

        inp = rand() % ACTIVE_MOVE_STATES;

        switch (inp) {
            case 0: 
                y = MOVE_UP;
                x = MOVE_NONE;
            break;

            case 1: 
                y = MOVE_NONE;
                x = MOVE_LEFT;
            break;

            case 2: 
                y = MOVE_DOWN;
                x = MOVE_NONE;
            break;

            case 3: 
                y = MOVE_NONE;
                x = MOVE_RIGHT;
            break;

            case 4: case 5:
                y = thePawn->ySign(player.getCoords());
                x = MOVE_NONE;
            break;

            case 6: case 7:
                y = MOVE_NONE;
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
                if (checkArea(player.getCoords(), &elon) && !elonAwake) {
                    cout << "ELON HAS AWOKEN." << endl;
                    elonAwake = true;
                }
                activationWarning(allPawns.at(i));
            }
        }
    }

    if (elonAwake) {
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

void Board::help() {
    string inp;

    cout << "                Controls                " << endl;
    cout << "Move up:     <W>" << endl;
    cout << "Move down:   <S>" << endl;
    cout << "Move left:   <A>" << endl;
    cout << "Move right:  <D>" << endl;
    cout << "Type \"h\" for help at any time during" << endl;
    cout << "the game" << endl;
    cout << "Be sure to hit <enter> after typing your" << endl;
    cout << "play" << endl;
    cout << endl;
    cout << "If you run into the Yugo, the Pinto, or" << endl;
    cout << "you should move away immediately" << endl;
    cout << endl;
    cout << "Type \"ok\" to continue..." << endl;
    cout << endl;

    do {
        cin >> inp;
    } while (!(inp == "ok" || inp == "Ok" || inp == "OK"));
}

void Board::trackPlays(char currPlay) {
    bool same;
    int selection;

    for (int i = 0; i < (plays.size() - 1); i++) {
        plays.at(i) = plays.at(i + 1);
    }

    plays.at(plays.size() - 1) = currPlay;

    same = true;
    for (int i = 0; i < (plays.size() - 1); i++) {
        if (plays.at(i) != plays.at(i + 1)) {
            same = false;;
            break;
        }
    }

    if (same) {
        selection = rand() % ELON_WAKE_STATES;

        if (!selection && !elonAwake) {
            elonAwake = true;
            cout << "ELON HAS AWOKEN." << endl;
            cout << "He will be looking for you now" << endl;
        }
    }
}
