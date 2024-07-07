// In this programme, we will do the following:
// 1. Create a class Deck which represents a deck of cards (advice: use a vector to store the cards).
// 2. Implement the following methods:
//     a. void shuffle() - Shuffles the deck of cards.
//     b. void deal() - Deals a card from the deck.
//     c. void reset() - Resets the deck of cards.
//     d. void print() - Prints the deck of cards at any point.
// 3. Create a class Dealer which represents a dealer in a card game.
// 4. Implement the following methods:
//     a. void shuffleDeck(Deck &deck) - Shuffles the deck of cards.
//     b. void dealCard(Deck &deck) - Deals a card from the deck.
//     c. void resetDeck(Deck &deck) - Resets the deck of cards.
//     d. void printDeck(Deck &deck) - Prints the deck of cards at any point.
// 5. Create a class Player which represents a player in a card game.
// 6. Have the following data members:
//     a. string name - Name of the player.
//     b. Deck hand - Hand of the player.
// 7. Implement the following methods:
//     a. void printHand() - Prints the hand of the player.
//     b. void dealCard(Deck &deck) - Deals a card from the deck to the player.
//     c. void resetHand() - Resets the hand of the player.
//     d. void printHand() - Prints the hand of the player.
//     e. void scoreHand() - Scores the hand of the player (A: 1, J: 11, Q: 12, K: 13).
// 8. Create a class Game which represents a card game.
// 9. Have the following data members:
//     a. Deck deck - Deck of cards.
//     b. Dealer dealer - Dealer of the game.
//     c. vector<Player> players - Players of the game.
// 10. Implement the following methods:
//     a. void startGame() - Starts the game.
//     b. void endGame() - Ends the game.
//     c. void printPlayers() - Prints the players of the game.
//     d. void printDeck() - Prints the deck of cards.
//     e. void printDealer() - Prints the dealer of the game.
// endGame() should print the scores of all the players, and the player with the highest score should be declared the winner.

#include <iostream>
#include <vector>

using namespace std;

class Deck {
    public: vector<pair<int, int>> cards; // First int is the value of the card, and the second int is the suite of the card.
    // Diamond: 0, Heart: 1, Club: 2, Spade: 3.
    // A: 1, J: 11, Q: 12, K: 13.

    Deck() {
        // Initialize the deck of cards.
        for (int i = 1; i <= 13; i++) {
            for (int j = 0; j < 4; j++) {
                cards.push_back({i, j});
            }
        }
    }

public:
    void shuffle() {
        // Shuffle the deck of cards.

        // Choose a random card and swap it with the current card, a random number of times.
        int randomTimes = rand() % (cards.size() * 5);
        for (int i = 0; i < randomTimes; i++) {
            int randomCard = rand() % cards.size();
            swap(cards[i], cards[randomCard]);
        }
    }

    void deal() {
        // Deal a card from the deck.
        
        // Remove the first card from the deck and return it.
        pair<int, int> card = cards[0];
        cout << "Dealt card: ";
        if (card.first == 1) {
            cout << "A";
        } else if (card.first == 11) {
            cout << "J";
        } else if (card.first == 12) {
            cout << "Q";
        } else if (card.first == 13) {
            cout << "K";
        } else {
            cout << card.first;
        }

        cout << " of ";

        if (card.second == 0) {
            cout << "Diamonds";
        } else if (card.second == 1) {
            cout << "Hearts";
        } else if (card.second == 2) {
            cout << "Clubs";
        } else if (card.second == 3) {
            cout << "Spades";
        }

        cout << endl;

        cards.erase(cards.begin());
    }

    void reset() {
        // Reset the deck of cards.

        // Clear the deck of cards and reinitialize it.
        cards.clear();
        for (int i = 1; i <= 13; i++) {
            for (int j = 0; j < 4; j++) {
                cards.push_back({i, j});
            }
        }
    }

    void print() {
        // Print the deck of cards.

        // Loop through the cards and print the value and suite of each in order, in a readable format.
        for (int i = 0; i < cards.size(); i++) {
            if (cards[i].first == 1) {
                cout << "A";
            } else if (cards[i].first == 11) {
                cout << "J";
            } else if (cards[i].first == 12) {
                cout << "Q";
            } else if (cards[i].first == 13) {
                cout << "K";
            } else {
                cout << cards[i].first;
            }

            cout << " of ";

            if (cards[i].second == 0) {
                cout << "Diamonds";
            } else if (cards[i].second == 1) {
                cout << "Hearts";
            } else if (cards[i].second == 2) {
                cout << "Clubs";
            } else if (cards[i].second == 3) {
                cout << "Spades";
            }

            cout << endl;
        }
    }
};

class Dealer {
public:
    void shuffleDeck(Deck &deck) {
        // Shuffle the deck of cards.
        deck.shuffle();
    }

    void dealCard(Deck &deck) {
        // Deal a card from the deck.
        deck.deal();
    }

    void resetDeck(Deck &deck) {
        // Reset the deck of cards.
        deck.reset();
    }

    void printDeck(Deck &deck) {
        // Print the deck of cards.
        deck.print();
    }
};

class Player {
public:
    string name;
    Deck hand;

public:
    void printHand() {
        // Print the hand of the player.
        cout << "Hand of " << name << ":" << endl;
        hand.print();
    }

    void dealCard(Deck &deck) {
        // Deal a card from the deck to the player.
        hand.deal();
    }

    void resetHand() {
        // Reset the hand of the player.
        hand.reset();
    }

    void scoreHand() {
        // Score the hand of the player (A: 1, J: 11, Q: 12, K: 13).
        // Loop through the cards in the hand and score them accordingly.
        int score = 0;
        for (int i = 0; i < hand.cards.size(); i++) {
            if (hand.cards[i].first == 1) {
                score += 1;
            } else if (hand.cards[i].first == 11) {
                score += 11;
            } else if (hand.cards[i].first == 12) {
                score += 12;
            } else if (hand.cards[i].first == 13) {
                score += 13;
            } else {
                score += hand.cards[i].first;
            }
        }
        cout << "Score of " << name << ": " << score << endl;
    }
};

class Game {
    Deck deck;
    Dealer dealer;
    vector<Player> players;

public:
    void startGame() {
        // Start the game.
        // Shuffle the deck of cards.
        dealer.shuffleDeck(deck);

        // Deal 5 cards to each player.
        for (int i = 0; i < players.size(); i++) {
            for (int j = 0; j < 5; j++) {
                players[i].dealCard(deck);
            }
        }
    }

    void endGame() {
        // End the game.
        // Print the scores of all the players.
        for (int i = 0; i < players.size(); i++) {
            players[i].scoreHand();
        }

        // Declare the player with the highest score as the winner.
        int maxScore = 0;
        string winner;
        for (int i = 0; i < players.size(); i++) {
            int score = 0;
            for (int j = 0; j < players[i].hand.cards.size(); j++) {
                if (players[i].hand.cards[j].first == 1) {
                    score += 1;
                } else if (players[i].hand.cards[j].first == 11) {
                    score += 11;
                } else if (players[i].hand.cards[j].first == 12) {
                    score += 12;
                } else if (players[i].hand.cards[j].first == 13) {
                    score += 13;
                } else {
                    score += players[i].hand.cards[j].first;
                }
            }
            if (score > maxScore) {
                maxScore = score;
                winner = players[i].name;
            }
        }

        cout << "Winner: " << winner << endl;
    }

    void printPlayers() {
        // Print the players of the game.
        cout << "Players:" << endl;
        for (int i = 0; i < players.size(); i++) {
            cout << players[i].name << endl;
        }
    }

    void printDeck() {
        // Print the deck of cards.
        deck.print();
    }

    void printDealer() {
        // Print the dealer of the game.
        cout << "Dealer:" << endl;
        dealer.printDeck(deck);
    }
};