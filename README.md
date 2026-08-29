# Card Game Implementation

This project contains a refactored version of the original C++ card game, broken down into modular files for better structure, maintainability, and compilation.

## Project Structure
Each class now resides in its own pair of `.h` (header) and `.cpp` (source) files.
- `main.cpp` - The entry point to start the game.
- `Game.h` / `Game.cpp` - Controls the flow of the game, turn mechanics, and rounds.
- `Card.h` / `Card.cpp` - Represents a single playing card.
- `Deck.h` / `Deck.cpp` - Manages the draw pile and discard pile.
- `Player.h` / `Player.cpp` - Represents a player, holding their cards and score.
- `Table.h` / `Table.cpp` - Represents the playing field.
- `RuleEngine.h` / `RuleEngine.cpp` - Controls validation of moves and effects.

## Improvements Made
- **File Modularity:** Classes are separated into standard C++ headers and implementation files to prevent clutter and allow easier debugging.
- **Removed `using namespace std;`:** Replaced global namespace declarations with explicit `std::` to adhere to best C++ practices and prevent symbol collision.
- **Comments Added:** English comments clarify logic inside headers and source files.
- **Circular Dependencies Addressed:** Implemented forward declarations in `RuleEngine.h` to effectively support references to the `Game` class.
- **Enhanced Safety:** Fallbacks provided (e.g. `getTopCard()` returning an empty card if the table is empty).

## How to Compile & Run
To compile the project from your terminal/command line, assuming you have `g++` installed, run:

```bash
g++ *.cpp -o cardgame
```

Then execute the output file:
- On Linux/macOS: `./cardgame`
- On Windows: `cardgame.exe`
