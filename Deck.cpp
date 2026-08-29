#include "Deck.h"
#include <algorithm>
#include <random>

Deck::Deck() { 
    initializeDeck(); 
}

Deck::~Deck() {}

void Deck::initializeDeck() {
    std::string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    std::string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    int vals[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
    
    for (const std::string& s : suits) {
        for (int i = 0; i < 13; i++) {
            drawPile.push_back(Card(ranks[i], s, vals[i]));
        }
    }
}

void Deck::shuffle() {
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::shuffle(drawPile.begin(), drawPile.end(), rng);
}

Card Deck::drawCard() {
    if (drawPile.empty()) {
        reshuffleDiscard();
    }
    Card c = drawPile.back();
    drawPile.pop_back();
    return c;
}

void Deck::reshuffleDiscard() {
    drawPile = discardPile;
    discardPile.clear();
    shuffle();
}

std::vector<Card>& Deck::getDrawPile() { return drawPile; }
void Deck::setDrawPile(const std::vector<Card>& cards) { drawPile = cards; }
std::vector<Card>& Deck::getDiscardPile() { return discardPile; }
void Deck::setDiscardPile(const std::vector<Card>& cards) { discardPile = cards; }
