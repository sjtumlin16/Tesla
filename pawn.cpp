#include "pawn.h"
#include "constants.h"
/*Function Name: Pawn
 * Description: this function created a base pawn entity
 *  that has no name, symbol, or location
 *
 * Parameters: none
 *
 * Return Values: none, just used for creating a pawn
 */
Pawn::Pawn() {
    this->name = "null";
    this->symb = '*';
    this->xCoord = NULL_COORD_X;
    this->yCoord = NULL_COORD_Y;
    this->activated = false;
}
/*Function Name: Pawn
 * Description: this function is what sets a pawn's
 *  name and symbol
 *
 * Parameters: none
 *
 * Return Values: none, function is void
 */
void Pawn::setName(string name, char symb) {
    this->name = name;
    this->symb = symb;

    return;
}
/*Function Name: setCoords
 * Description: this function sets the coords for a pawn
 *
 * Parameters:
 *  coords: the array used to represent the coordinates of
 *  the playing board
 *
 * Return Values: returns true
 */
bool Pawn::setCoords(coords temp) {
    this->xCoord = temp.xCoord;
    this->yCoord = temp.yCoord;

    return true;
}
/*Function Name: getCoords
 * Description: this function when called will
 *  retrieve the coords of a certain pawn
 *
 * Parameters: none
 *
 * Return Values: returns temp, which is the temporary
 *  coordinate values for that pawn
 */
coords Pawn::getCoords() {
    coords temp;
    temp.xCoord = this->xCoord;
    temp.yCoord = this->yCoord;

    return temp;
}
/*Function Name: getName
 * Description: this function gets the same for the pawn
 *  it is called for
 *
 * Parameters: none
 *
 * Return Values: the name of the pawn it is called for
 */
string Pawn::getName() {
    return name;
}
/*Function Name: getSymb
 * Description: gets the symbol for the pawn it is called for
 *
 * Parameters:none
 *
 * Return Values: the symbol of the pawn it is called for
 */
char Pawn::getSymb() {
    return symb;
}
/*Function Name: activate
 * Description: when this function is called it will activate a pawn
 *  if it is not so already
 *
 * Parameters: none
 *
 * Return Values: returns true
 */
bool Pawn::activate() {
    if (activated) {
        return false;
    }

    activated = true;
    
    return true;
}
/*Function Name: deactivate
 * Description: deactivates a pawn if it is not so already
 *
 * Parameters: none
 *
 * Return Values: returns true
 */
bool Pawn::deactivate() {
    if (!activated) {
        return false;
    }

    activated = false;
    
    return true;
}
/*Function Name: getActivatedState
 * Description: this function when called returns the whether
 *  or not the pawn is activated
 *
 * Parameters: none
 *
 * Return Values: it returns either t/f if the pawn is activated
 */
bool Pawn::getActivatedState() {    
    return activated;
}
/*Function Name: spotOccupied
 * Description: returns t/f depending on whether or not
 * the player is checking  a spot with a pawn in it
 *
 * Parameters:
 *  candidate: the temp values of a coord next to the player
 *  which get accesses to see if there is a pawn in them
 *
 * Return Values: it returns t/f based on the spot being occupied or not
 */
bool Pawn::spotOccupied(coords candidate) {
    return (this->xCoord == candidate.xCoord && 
        this->yCoord == candidate.yCoord);
}
/*Function Name: ySign
 * Description: checks the distance between two points, if it is negative
 *  it is returned as -1
 *
 * Parameters:
 *  ref: the temp coords being used for checking
 *
 * Return Values: -1 if the distance is negative
 */
int Pawn::ySign(coords ref) {
    int num;
    num = ref.yCoord - this->yCoord;

    if (num == 0) {
        return 0;
    }

    return num / fabs(num);
}
/*Function Name: xSign
 * Description: checks the distance between two points, if it is negative
 *  it is returned as -1
 *
 * Parameters:
 *  ref: the temp coords being used for checking
 *
 * Return Values: -1 if the distance is negative
 *
 */
int Pawn::xSign(coords ref) {
    int num;
    num = ref.xCoord - this->xCoord;

    if (num == 0) {
        return 0;
    }
    
    return num / fabs(num);
}
/*Function Name: yDiff
 * Description: checks the distance between two points and if positive returns that number
 *
 * Parameters:
 *  ref: the temp coords being used for checking
 *
 * Return Values: the distance betwen the two points
 */
int Pawn::yDiff(coords ref) {
    int num;
    num = ref.yCoord - this->yCoord;

    if (num == 0) {
        return 0;
    }

    return fabs(num);
}
/*Function Name: xDiff
 * Description: checks the distance between two points and if positive returns that number
 *
 * Parameters:
 *  ref: the temp coords being used for checking
 *
 * Return Values: the distance between the two points
 */
int Pawn::xDiff(coords ref) {
    int num;
    num = ref.xCoord - this->xCoord;

    if (num == 0) {
        return 0;
    }
    
    return fabs(num);
}
