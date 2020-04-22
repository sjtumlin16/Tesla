#include "pawn.h"

Pawn::Pawn() {
    this->name = "null";
    this->symb = '*';
    this->xCoord = -99;
    this->yCoord = -99;
    this->activated = false;
}

void Pawn::setName(string name, char symb) {
	this->name = name;
	this->symb = symb;

	return;
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

char Pawn::getSymb() {
    return symb;
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
