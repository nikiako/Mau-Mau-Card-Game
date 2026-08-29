#include "RuleEngine.h"
#include "Game.h"

bool RuleEngine::isValidMove(const Card& playerCard, const Card& tableCard, const std::string& activeSuit) const {
    if (playerCard.getRank() == "A") return true;
    return (playerCard.getSuit() == activeSuit || playerCard.getRank() == tableCard.getRank());
}

int RuleEngine::calculateHandPoints(const std::vector<Card>& hand) const {
    int sum = 0;
    for (const auto& c : hand) {
        sum += c.getPoints();
    }
    return sum;
}

bool RuleEngine::canPlayerWin(const Card& card) const {
    std::string r = card.getRank();
    return !(r == "7" || r == "8" || r == "9" || r == "A");
}

void RuleEngine::applySpecialEffect(const Card& card, Game& game) {
    // Special effect logic can be implemented here if needed.
}
