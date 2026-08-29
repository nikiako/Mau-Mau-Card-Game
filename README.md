# Mau-Mau Card Game (Agonia / UNO Style)

## Game Description
This is a console-based multiplayer implementation of the classic shedding-type card game **Mau-Mau** (known locally as **Agonia** in Greece or similar to **UNO**). The objective of the game is to be the first player to discard all cards from your hand while strategically using special action cards to penalize, skip, or redirect turns against opponents.

---

## Key Gameplay Rules

### 1. Basic Rules
* Each player starts with 7 cards drawn from a standard 52-card deck.
* A single card is placed face-up on the table to start the discard pile.
* On their turn, a player must play a card that matches either the **Suit** (Hearts, Diamonds, Clubs, Spades) or the **Rank** (2–10, J, Q, K, A) of the card currently on top of the table.

### 2. Special Action Cards
* **7 (Draw Penalty):** Forces the next player to draw **2 cards** and lose their turn. If the next player also plays a 7, the penalty stacks (e.g., drawing 4 cards).
* **8 (Extra Turn):** The player gets to play another card immediately.
* **9 (Skip Turn):** Skips the turn of the next player in sequence.
* **Ace / A (Wildcard / Suit Selector):** Can be played on **any** suit or rank. The player who plays an Ace gets to choose and set the active suit for subsequent turns.

### 3. Winning and Restrictions
* **Special Card Ending Restriction:** A player **cannot win** or finish their hand by playing a special card (`7`, `8`, `9`, or `A`) as their final move.
* **Round Completion:** When a player successfully discards all cards in their hand, the round ends.
* **Scoring:** Opponents accumulate points based on the cards remaining in their hands. The game ends when a player reaches or exceeds the pre-defined total score limit (e.g., 100 points).

---

## Code Architecture & Class Responsibilities

* **`Card`**: Represents individual playing cards, storing rank, suit, and point value.
* **`Table`**: Tracks the face-up active card and status of the playing field.
* **`Deck`**: Manages the draw pile and discard pile, handling card shuffling and reshuffling when the draw pile empties.
* **`Player`**: Tracks individual player state, including current hand, score, and card actions.
* **`RuleEngine`**: Encapsulates game validation rules, checking valid moves, special card restrictions, and scoring calculation.
* **`Game`**: Controls the core turn loop, round management, penalty tracking, and win conditions.
* **`main.cpp`**: Initializes player configuration and starts the game loop.
