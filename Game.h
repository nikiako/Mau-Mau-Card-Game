#ifndef GAME_H
#define GAME_H
#include <vector>
#include <string>
#include "Player.h"
#include "Table.h"
#include "Deck.h"
#include "RuleEngine.h"

// Core Game loop and state management
class Game {
private:
    int scoreLimit;
    int currentPlayerIndex;
    std::string activeSuit;
    int pendingPenaltyCards;
    bool isGameOver;
    std::vector<Player> players;
    Table table;
    Deck deck;
    RuleEngine ruleEngine;

public:
    Game(const std::vector<std::string>& playerNames, int limit);
    ~Game();

    void startGame();
    void startRound();
    void nextTurn();
    void handlePlayerAction(Player& current);
    void handlePenaltyPhase(Player& current);
    void processMoveEffects(Player& p, Card& playedCard);
    void finalizeRound();
    void displayGameState();

    int getScoreLimit() const;
    void setScoreLimit(int limit);
    int getCurrentPlayerIndex() const;
    void setCurrentPlayerIndex(int index);
    std::string getActiveSuit() const;
    void setActiveSuit(std::string suit);
    int getPendingPenaltyCards() const;
    void setPendingPenaltyCards(int count);
    bool getIsGameOver() const;
    void setIsGameOver(bool status);
};

#endif // GAME_H
