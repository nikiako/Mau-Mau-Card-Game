#include "Card.h"
#include <iostream>

Card::Card(std::string r, std::string s, int p) : rank(r), suit(s), points(p) {}

Card::~Card() {}

void Card::printCard() const { 
    std::cout << toString() << std::endl; 
}

std::string Card::getRank() const { return rank; }
void Card::setRank(std::string r) { rank = r; }
std::string Card::getSuit() const { return suit; }
void Card::setSuit(std::string s) { suit = s; }
int Card::getPoints() const { return points; }
void Card::setPoints(int p) { points = p; }

std::string Card::toString() const { 
    return "[" + rank + " of " + suit + "]"; 
}
