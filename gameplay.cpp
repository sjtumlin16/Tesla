#include "gameplay.h"
#include "constants.h"

Gameplay::Gameplay() {

}
/*Function Name: playGame
 * Description: this function starts the game and initializes
 *  the board and pawns. It asks for user plays until the 
 *  game is over. At the end, it asks if the user wants to
 *  play again.
 *
 * Parameters: none
 *
 * Return Values: none, function is void, just used to run the game
 */
void Gameplay::playGame() {
    string token;

    do {
        Board theBoard;
        theBoard.initialize();
        theBoard.printBoardDark();
        while (!theBoard.gameOver()) {
            theBoard.playerMove();
        }

        cout << endl << "Play again (yes/no)" << endl;
        cin >> token;

    } while (token == "yes" || token == "Yes");
}
/*Function Name: printInstructions
 * Description: when run this function tells you everything
 *  about the game, including the goal, what is going on, and
 *  the controls for the game
 *
 * Parameters: none
 *
 * Return Values: none, function is void, used for displaying
 *  instructions for players
 */
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
    cout << "you twice, you're going to space." << endl;
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

    cout << string(SPACING_LINES, '\n');

    cout << endl << endl;
    cout << "            Welcome to Tesla!            " << endl;
    cout << endl;
    cout << "    - Try not to move in the same" << endl;
    cout << "direction for too long. If you do, there" << endl;
    cout << "is a chance that Elon could wake up. He" << endl;
    cout << "can also be woken up if you stand right" << endl;
    cout << "next to him." << endl;
    cout << "    - Hints will be displayed at the" << endl;
    cout << "bottom of the board. Some will help you" << endl;
    cout << "find the Roadster, some will let you know" << endl;
    cout << "where Elon is, and some will tell you fun" << endl;
    cout << "factoids!" << endl;
    cout << "    - Remember, be careful. Because you'd" << endl;
    cout << "rather have a Roadster than be sent to" << endl;
    cout << "space!" << endl;
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
/*Funciton Name: goodbye
 * Description: this function when run displays our goodbye message to the
 * player (in this case the grading team!)
 *
 * Parameters: none
 *
 * Return Values: none, function is void, only used for our
 *  goodbye message
 */
void Gameplay::goodbye() {
    cout << endl << "Thanks for playing, we hope you" << endl;
    cout << "had fun!" << endl;
    cout << "If you did, consider giving us 5 stars on" << endl;
    cout << "the AppStore (and a 100% on the" << endl;
    cout << "assignment)." << endl;
}
