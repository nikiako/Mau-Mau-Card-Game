#include "Table.h"

Table::Table() : tableStatus("Active"), topCard(nullptr) {}

Table::~Table() { 
    if (topCard) delete topCard; 
}

void Table::updateStatus() { 
    // Table status logic goes here
}

std::string Table::getTableStatus() const { return tableStatus; }
void Table::setTableStatus(std::string status) { tableStatus = status; }

Card Table::getTopCard() const { 
    if (topCard) return *topCard;
    return Card("", "", 0); // Fallback if no card is present
}

void Table::setTopCard(const Card& card) {
    if (topCard) delete topCard;
    topCard = new Card(card);
}
