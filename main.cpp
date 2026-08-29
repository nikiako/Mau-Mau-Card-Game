#include "Game.h"
#include <vector>
#include <string>

int main() {
    // Initialize the game with two players and a score limit of 100
    std::vector<std::string> names = {"Player1", "Player2"};
    Game game(names, 100);
    game.startGame();
    
    return 0;
}
