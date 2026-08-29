#include "Game.h"
#include <iostream>

Game::Game(const std::vector<std::string>& playerNames, int limit) 
    : scoreLimit(limit), currentPlayerIndex(0), pendingPenaltyCards(0), isGameOver(false) {
    for(size_t i = 0; i < playerNames.size(); i++) {
        players.push_back(Player(i, playerNames[i]));
    }
}

Game::~Game() {}

void Game::startGame() {
    deck.shuffle();
    startRound();
    while(!isGameOver) {
        displayGameState();
        handlePlayerAction(players[currentPlayerIndex]);
    }
}

void Game::startRound() {
    for(auto& p : players) {
        p.getHand().clear();
        for(int i = 0; i < 7; i++) p.drawFromDeck(deck);
    }
    Card first = deck.drawCard();
    table.setTopCard(first);
    activeSuit = first.getSuit();
}

void Game::nextTurn() { 
    currentPlayerIndex = (currentPlayerIndex + 1) % players.size(); 
}

void Game::handlePlayerAction(Player& current) {
    if (pendingPenaltyCards > 0) {
        handlePenaltyPhase(current);
        return;
    }

    std::cout << "Choose card index (1-" << current.getHand().size() << ") or 0 to draw/pass: ";
    int choice; 
    std::cin >> choice;

    if (choice > 0 && choice <= static_cast<int>(current.getHand().size())) {
        Card& selected = current.getHand()[choice - 1];
        if (ruleEngine.isValidMove(selected, table.getTopCard(), activeSuit)) {
            if (current.getHand().size() == 1 && !ruleEngine.canPlayerWin(selected)) {
                std::cout << "Cannot finish with a special card!\n";
                return;
            }
            processMoveEffects(current, selected);
            current.playCard(choice - 1, table, deck);
            if (current.getHand().empty()) finalizeRound();
        } else {
            std::cout << "Invalid Move!\n";
        }
    } else {
        current.drawFromDeck(deck);
        nextTurn();
    }
}

void Game::handlePenaltyPhase(Player& current) {
    std::cout << current.getName() << " MUST play a 7 or draw " << pendingPenaltyCards << " cards. Index (0 to draw): ";
    int choice; 
    std::cin >> choice;
    
    if (choice > 0 && choice <= static_cast<int>(current.getHand().size())) {
        Card& c = current.getHand()[choice - 1];
        if (c.getRank() == "7") {
            processMoveEffects(current, c);
            current.playCard(choice - 1, table, deck);
            return;
        }
    }
    
    for(int i = 0; i < pendingPenaltyCards; i++) {
        current.drawFromDeck(deck);
    }
    pendingPenaltyCards = 0;
    nextTurn();
}

void Game::processMoveEffects(Player& p, Card& playedCard) {
    std::string rank = playedCard.getRank();
    activeSuit = playedCard.getSuit();

    if (rank == "7") {
        pendingPenaltyCards += 2;
        nextTurn();
    } else if (rank == "8") {
        std::cout << p.getName() << " plays again!\n";
    } else if (rank == "9") {
        std::cout << "Next player skipped!\n";
        nextTurn(); 
        nextTurn();
    } else if (rank == "A") {
        std::cout << "New suit (Hearts, Diamonds, Clubs, Spades): ";
        std::cin >> activeSuit;
        nextTurn();
    } else {
        nextTurn();
    }
}

void Game::finalizeRound() {
    std::cout << "\n--- Round Over! ---\n";
    for(auto& p : players) {
        p.addPoints(ruleEngine.calculateHandPoints(p.getHand()));
        if(p.getTotalPoints() >= scoreLimit) isGameOver = true;
    }
    if(!isGameOver) startRound();
}

void Game::displayGameState() {
    std::cout << "\nTable: " << table.getTopCard().toString() << " | Active Suit: " << activeSuit << std::endl;
    players[currentPlayerIndex].printHand();
}

int Game::getScoreLimit() const { return scoreLimit; }
void Game::setScoreLimit(int limit) { scoreLimit = limit; }
int Game::getCurrentPlayerIndex() const { return currentPlayerIndex; }
void Game::setCurrentPlayerIndex(int index) { currentPlayerIndex = index; }
std::string Game::getActiveSuit() const { return activeSuit; }
void Game::setActiveSuit(std::string suit) { activeSuit = suit; }
int Game::getPendingPenaltyCards() const { return pendingPenaltyCards; }
void Game::setPendingPenaltyCards(int count) { pendingPenaltyCards = count; }
bool Game::getIsGameOver() const { return isGameOver; }
void Game::setIsGameOver(bool status) { isGameOver = status; }
