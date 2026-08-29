#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include "Card.h"
#include "Table.h"
#include "Deck.h"

// Player class storing player details and their hand
class Player {
private:
    int id;
    std::string name;
    std::string status;
    int totalPoints;
    std::vector<Card> hand;

public:
    Player(int i, std::string n);
    ~Player();

    void playCard(int index, Table& table, Deck& deck);
    void drawFromDeck(Deck& deck);
    void passTurn();
    void printHand() const;
    void addPoints(int p);

    int getId() const;
    std::string getName() const;
    int getTotalPoints() const;
    std::vector<Card>& getHand();
};

#endif // PLAYER_H
