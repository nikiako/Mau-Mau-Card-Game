#include "Player.h"
#include <iostream>

Player::Player(int i, std::string n) : id(i), name(n), status("Active"), totalPoints(0) {}

Player::~Player() {}

void Player::playCard(int index, Table& table, Deck& deck) {
    Card c = hand[index];
    hand.erase(hand.begin() + index);
    deck.getDiscardPile().push_back(table.getTopCard());
    table.setTopCard(c);
}

void Player::drawFromDeck(Deck& deck) { 
    hand.push_back(deck.drawCard()); 
}

void Player::passTurn() { 
    std::cout << name << " passes.
"; 
}

void Player::printHand() const {
    for (size_t i = 0; i < hand.size(); i++) {
        std::cout << i + 1 << "." << hand[i].toString() << " ";
    }
    std::cout << std::endl;
}

void Player::addPoints(int p) { totalPoints += p; }

int Player::getId() const { return id; }
std::string Player::getName() const { return name; }
int Player::getTotalPoints() const { return totalPoints; }
std::vector<Card>& Player::getHand() { return hand; }
