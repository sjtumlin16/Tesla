#include "gameplay.h"

Gameplay::Gameplay() {
    theBoard.initialize();
}

void Gameplay::playGame() {
    theBoard.printBoardDark();
    while (!theBoard.gameOver()) {
        theBoard.playerMove();
    }
}

void Gameplay::printInstructions() {
    string inp;

    cout << endl << endl;
    cout << "            Welcome to Tesla!            " << endl;
    cout << endl;
    cout << "    It's the night before Elon Musk's " << endl;
    cout << "Roadster is going to be launched into" << endl;
    cout << "space. Your job is to find the Roadster" << endl;
    cout << "and save it." << endl;
    cout << "    There is also a Ford Pinto and a Yugo" << endl;
    cout << "hidden in the room. If you touch one of" << endl;
    cout << "these cars more than once, you're going" << endl;
    cout << "to space with the Roadster." << endl;
    cout << "    Additionally, Elon himself is asleep" << endl;
    cout << "somewhere in the room. If you wake him," << endl;
    cout << "he'll start looking for you. If he finds" << endl;
    cout << "you, you're going to space." << endl;
    cout << endl;
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
