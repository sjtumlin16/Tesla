#include "board.h"
#include "constants.h"
/*Function Name: Board
 * Description: this function sets the names of the different
 *  pawns on the board and assigns letters to tell the difference
 *  between them
 *
 * Parameters: none
 *
 * Return Values: returns both the states of isGameOver
 *  and elonAwake as false so the game can acutally run
 */
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
/*Function Name: checkSpot
 * Description: This function allows the player to check
 *  the surroundings for other pawns
 *
 * Parameters:
 *  coords: the structure used to represent the coordinates of
 *  the playing board
 *  allPawns: The structure used to group the different entities
 *  on the playing board
 *
 * Return Value: t/f based on whether or not there is another entity next to
 *  the player
 */
bool Board::checkSpot(coords inp) {
    for (int i = 0; i < allPawns.size(); i++) {
        if ((allPawns.at(i)->getCoords().xCoord == inp.xCoord) && (allPawns.at(i)->getCoords().yCoord == inp.yCoord)) {
            return true;
        }
    }

    return false;
}
/*Function Name: whatsThere
 * Description: This function is for checking what entity is next
 *  to play player when the player checks
 *
 * Parameters:
 *  coords: the structure used to represent the coordinates of
 *  the playing board
 *  allPawns: The vector used to group the different entities
 *  on the playing board
 *
 * Return Value: This function either returns what entity the player is
 *  next to, or returns null if there is nothing there
 */
char Board::whatsThere(coords inp) {
    for (int i = 0; i < allPawns.size(); i++) {
        if ((allPawns.at(i)->getCoords().xCoord == inp.xCoord) && (allPawns.at(i)->getCoords().yCoord == inp.yCoord)) {
            return allPawns.at(i)->getSymb();
        }
    }

    return 'n';
}
/*Function Name: Board
 * Description: this function creates the board with an array
 *  called area so the game can be displayed and function
 *
 * Parameters:
 *  coords: the structure used to represent the coordinates of
 *  the playing board
 *
 * Return Values: returns the array titled area which is used
 *  for the game board
 */
vector<coords> Board::createArea(coords inp) {
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

    return area;
}
/*Function Name: checkArea
 * Description: Checks the spot next to the player if
 *  something is there
 *
 * Parameters:
 *  coords: the structure used to represent the coordinates of
 *  the playing board
 *
 * Return Values: returns t/f if something is in the spot
 *  next to the player
 */
bool Board::checkArea(coords inp) {
    vector<coords> area = createArea(inp);

    for (int i = 0; i < area.size(); i++) {
        if (checkSpot(area.at(i))) {
            return true;
        }
    }

    return false;
}
/*Function Name: checkArea
 * Description: Checks if there is another pawn in the
 *  space next to the player
 *
 * Parameters:
 *  coords: the structure used to represent the coordinates of
 *  the playing board
 *  Pawn: the class used for grouping the different types
 *  of pawns in the game.
 *
 * Return Values: returns t/f if the spot next to the player has
 *  one of the pawns
 */
bool Board::checkArea(coords inp, Pawn *thePawn) {
    vector<coords> area = createArea(inp);

    char thisChar = thePawn->getSymb();

    for (int i = 0; i < area.size(); i++) {
        if (checkSpot(area.at(i)) && (whatsThere(area.at(i)) == thisChar)) {
            return true;
        }
    }

    return false;
}
/*Function Name: offBoard
 * Description: checks if the player has reached the edge
 *  of the board for x and y direction.
 *
 * Parameters:
 *  coords: the structure used to represent the coordinates of
 *  the playing board
 *
 * Return Values: returns true if the player is at the edge of
 *  the board for both x and y values
 */
bool Board::offBoard(coords temp) {
    if (temp.xCoord > 14 || temp.xCoord < 0) {
        return true;
    }

    if (temp.yCoord > 14 || temp.yCoord < 0) {
        return true;
    }

    return false;
}
/*Function Name: initialize
 * Description: this function 'spawns' the pawns in random
 *  positions on the board
 *
 * Parameters: none
 *
 * Return Values: returns true, mainly used to just place the
 *  pawns.
 */
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
/*Function Name: printBoard
 * Description: this function prints out the board and the lines
 *  that seperate the spots the player can move
 *
 * Parameters: none
 *
 * Return Values: returns true, mainly used for printing out the board
 */
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
/*Function Name: printBoardDark
 * Description: prints out the spots that have the other pawns
 *  that the player cannot see at first, but prints them out as
 *  the player moves toward them.
 *
 * Parameters: none
 *
 * Return Values: returns true, mainly used to print out the board
 */
bool Board::printBoardDark() {
    char printChar;
    coords temp;

    cout << string(SPACING_LINES, '\n');

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
/*Function Name: playerMove
 * Description: this function is used to allow the player to move,
 *  it also checks if the player is off the board or not, and updates
 *  the other pawns to move every time the player moves.
 *
 * Parameters: none
 *
 * Return Values: returns true, used mainly for tracking movement in
 *  the game as it progresses
 */
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
/*Function Name: activeMove
 * Description: this function generates random directions for
 *  the other pawns to move, while their state is set to active,
 *  with special cases to help them move towards the player
 *
 * Parameters:
 *  Pawn: the structure used for grouping the different types
 *  of pawns in the game.
 *
 * Return Value: returns true, mainly used for updating the
 *  movement for the pawns
 */
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
/*Function Name: updatePawns
 * Description: checks the pawn's locations compared to the player's
 *  to see if the player is in close enough range to activate the pawns
 *  and allow them to start moving.
 *
 * Parameters: none
 *
 * Return Values: returns true, mainly used for activating pawns if player is
 *  in proximity
 */
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
/*Function Name: activationWarning
 * Description: Tells the player if they moved into a sleeping pawn,
 *  and if it's elon he will be activated and now look for the player
 *
 * Parameters:
 *  Pawn: the structure used for grouping the different types
 *  of pawns in the game.
 *
 * Return Values: function is void and returns nothing, mainly used
 *  for interactions with the pawns
 */
void Board::activationWarning(Pawn *thePawn) {
    cout << "You ran into " << thePawn->getName() << "!" << endl;
    cout << "One more time and you're going to be on the rocket!" << endl;
    if (thePawn->getSymb() == 'E') {
        cout << "Now he will be looking for you. Be careful." << endl;
    }

    cout << endl;

    return;
}
/*Function Name: gameOver
 * Description: if function is run, the game will be over :(
 *
 * Parameters: none
 *
 * Return Value: it returns isGameOver which is what ends the game
 */
bool Board::gameOver() {
    return isGameOver;
}
/*Function Name: gameOver
 * Description: This function has the different types of game outcomes
 *  when the game is over, either you go to space :(, you save the roadster,
 *  or you got the wrong car, then the game officially ends.
 *
 * Parameters:
 *  Pawn: the structure used for grouping the different types
 *  of pawns in the game.
 *
 * Return Values: returns isGameOver = true which tells the program the game is over
 */
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
/*Function Name: help
 * Description: the function when run, displays tips for playing the game,
 *  including controls and gameplay tips for winning.
 *
 * Parameters: none
 *
 * Return Values: none since function is void, just used for help menu
 */
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
/*Function Name: trackPlays
 * Description: this function tracks the amount of times the
 *  player has played the game, and adds a chance for elon to
 *  be awake at the start of the game the more times the game is
 *  played.
 *
 * Parameters:
 *  currPlay: used to track the amount of times the game has been played
 *
 * Return Values: function is void so it does not return anything, just
 *  used to track the number of plays
 */
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
/*Function Name: hint
 * Description: this function gives hints to the player as the
 *  player moves throughout the play area, like whether or not
 *  the roadster or Elon is close
 *
 * Parameters: none
 *
 * Return Values: none, just used for giving hints to the player
 */
void Board::hint() {
    int hintType, xRange, yRange;

    if (elonAwake) {
        hintType = rand() % ELON_HINT_STATES;
    }
    else {
        hintType = rand() % (ELON_HINT_STATES - 1) + 1;
    }
    
    if (!hintType) {
        xRange = elon.xDiff(player.getCoords());
        yRange = elon.yDiff(player.getCoords());

        if ((xRange == CLOSE_PAWN && yRange < CLOSE_PAWN) ||
            (yRange == CLOSE_PAWN && xRange < CLOSE_PAWN)) {
            cout << "ELON IS RIGHT NEXT TO YOU!\n" << endl;
        }
        else if (xRange < MEDIUM_PAWN && yRange < MEDIUM_PAWN) {
            cout << "Elon is within striking \ndistance!" << endl;
        }
        else if (xRange < FAR_PAWN && yRange < FAR_PAWN) {
            cout << "Elon is hot on your tracks.\n" << endl;
        }
        else {
            cout << "No need to worry about Elon \nat the moment." << endl;
        }
    }
    else if (hintType < ROADSTER_HINT_THRESHOLD) {
        xRange = roadster.xDiff(player.getCoords());
        yRange = roadster.yDiff(player.getCoords());

        if ((xRange == CLOSE_PAWN && yRange < CLOSE_PAWN) ||
            (yRange == CLOSE_PAWN && xRange < CLOSE_PAWN)) {
            cout << "YOU'RE ALMOST TO THE ROADSTER!\n" << endl;
        }
        else if (xRange < FAR_PAWN && yRange < FAR_PAWN) {
            cout << "You can probably smell the \nRoadster from here." << endl;
        }
        else {
            cout << "Try looking somewhere else.\n" << endl;
        }

    }
    else {
        if (hintType == ENCOURAGEMENT_HINT) {
            cout << "Keep up the effort!\n" << endl;
        }
        else if (hintType == INTERESTING_FACT) {
            cout << "The Roadster can achieve \nspeeds up to 250 mph!" << endl;
        }
        else {
            cout << "The 2020 Roadster is expected \nto cost $200,000!" << endl;
        }
    }
}
