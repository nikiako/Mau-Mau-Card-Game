#ifndef TABLE_H
#define TABLE_H
#include "Card.h"
#include <string>

// Table class representing the playing surface
class Table {
private:
    std::string tableStatus;
    Card* topCard; // Pointer used to manage the top card

public:
    Table();
    ~Table();

    void updateStatus();
    std::string getTableStatus() const;
    void setTableStatus(std::string status);
    Card getTopCard() const;
    void setTopCard(const Card& card);
};

#endif // TABLE_H
