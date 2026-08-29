#ifndef RULEENGINE_H
#define RULEENGINE_H
#include "Card.h"
#include <vector>
#include <string>

// Forward declaration of Game to avoid circular dependency
class Game;

// RuleEngine evaluates valid moves and game rules
class RuleEngine {
public:
    bool isValidMove(const Card& playerCard, const Card& tableCard, const std::string& activeSuit) const;
    int calculateHandPoints(const std::vector<Card>& hand) const;
    bool canPlayerWin(const Card& card) const;
    void applySpecialEffect(const Card& card, Game& game); 
};

#endif // RULEENGINE_H
