#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <vector>

// Deck class representing a collection of cards
class Deck {
private:
    std::vector<Card> drawPile;
    std::vector<Card> discardPile;

public:
    Deck();
    ~Deck();

    void initializeDeck();
    void shuffle();
    Card drawCard();
    void reshuffleDiscard();
    
    std::vector<Card>& getDrawPile();
    void setDrawPile(const std::vector<Card>& cards);
    std::vector<Card>& getDiscardPile();
    void setDiscardPile(const std::vector<Card>& cards);
};

#endif // DECK_H
