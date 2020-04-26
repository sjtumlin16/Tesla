/*
 * Project Title:
 * - Tesla
 * Description:
 *  This is a game of Tesla based on the story/brief mechanics laid
 * out in the final project assignment. The goal for the player is
 * to find Elon's Roadster. We used object oriented programming to
 * create the game using classes of pawn, board, and gameplay. the
 * purpose of each class is laid out in the supplemental document
 * we have submitted. The game includes a help feature, hints to
 * help out the player, and lots of fun! We used Git for version
 * control, so we were able to learn a bit about that too.
 *
 * Developers:
 * - Seth Tumlin - tumlinsj@mail.uc.edu
 * - Devlin Sheehan - sheehadn@mail.uc.edu
 *
 * Special Instructions:
 * - This is how we've been compiling on Windows in Command Prompt
 *      > g++ -c board.cpp
 *      > g++ -c pawn.cpp
 *      > g++ -c gameplay.cpp
 *      > g++ board.o pawn.o gameplay.o project1.cpp -o project1
 *      > project1.exe
 *
 * Developer comments:
 * Seth Tumlin:
 *  I worked on pawn and some of board as well as making the constants 
 * header and contributing to documentation. I learned a lot about the 
 * multi-file concept. I had done 3 files (with the DC Sim lab), but
 * not more than that. I was very confused how to reference the separate
 * headers, classes, etc. at first, but we eventually figured it out.
 * I also learned a lot about compilation/linking. I use Sublime Text
 * instead of Qt so I have to compile with the command-line. It took
 * me a while to figure out how to use -c and -o to create and link 
 * objects because I didn't find much from a quick Google search. I
 * enjoyed this challenge and I am very happy with our product.
 *
 * Devlin Sheehan
 *  I worked on part of Board, all of Gameplay, and some documentation.
 *
 */

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
