#ifndef CARD_H
#define CARD_H
#include <string>

// Card class representing a single playing card
class Card {
private:
    std::string rank;
    std::string suit;
    int points;

public:
    Card(std::string r, std::string s, int p);
    ~Card();

    void printCard() const;
    std::string getRank() const;
    void setRank(std::string r);
    std::string getSuit() const;
    void setSuit(std::string s);
    int getPoints() const;
    void setPoints(int p);
    std::string toString() const;
};

#endif // CARD_H
