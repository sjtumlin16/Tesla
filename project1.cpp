// Seth Tumlin & Devlin Sheehan

#include "pawn.h"
#include "board.h"
#include "gameplay.h"

int main() {
    srand (time(NULL));
    Gameplay game;

    game.printInstructions();
    game.playGame();
    game.goodbye();

    return 0;
}
