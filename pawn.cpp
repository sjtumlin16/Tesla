#include "pawn.h"

Pawn::Pawn(string name, coords temp) {
    this->name = name;
    this->xCoord = temp.xCoord;
    this->yCoord = temp.yCoord;
    this->activated = false;
}

bool Pawn::setCoords(coords temp) {
	this->xCoord = temp.xCoord;
	this->yCoord = temp.yCoord;

	return true;
}

coords Pawn::getCoords() {
	coords temp;
	temp.xCoord = this->xCoord;
	temp.yCoord = this->yCoord;

    return temp;
}

string Pawn::getName() {
    return name;
}

bool Pawn::activate() {
	if (activated) {
		return false;
	}

	activated = true;
	
    return true;
}

bool Pawn::deactivate() {
	if (!activated) {
		return false;
	}

	activated = false;
	
    return true;
}

bool Pawn::getActivatedState() {	
    return activated;
}

bool Pawn::spotOccupied(coords candidate) {
    return (this->xCoord == candidate.xCoord && 
    	this->yCoord == candidate.yCoord);
}
