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
    vector<pair<int, int>> cards; // First int is the value of the card, and the second int is the suite of the card.
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
        int val = (rand() % 52);
        cout << "Your card: " << cards[val].first << " "<< cards[val].second << endl;
        
    }

    void reset() {
        // Reset the deck of cards.
        for (int i = 1; i <= 13; i++) {
            for (int j = 0; j < 4; j++) {
                cards.push_back({i, j});
            }
        }
        //Do I need to call the constructor for this?


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
        int randomTimes = rand() % (cards.size() * 5);
        for (int i = 0; i < randomTimes; i++) {
            int randomCard = rand() % cards.size();
            swap(cards[i], cards[randomCard]);
        }

    }
    void dealCard(Deck &deck){
        for (int i = 0; i < 5; i++) {
            
        }
    }
    void resetDeck(Deck &deck){
        
    }
    void printDeck(Deck &deck){

    }
};
class Player : Deck {
    string name;
    Deck hand;
public:
    void printHand() {

        
    }
    void dealCard(Deck &deck){
        
    }
    void resetHand() {
        
    }
    void printHand() {
        
    }
    void scoreHand(){
        
    }
};
class Game{
    Deck deck;
    Dealer dealer;
    vector<Player> player;
public:
    void startGame() {
        
    }
    void endGame(){
        
    }
    void printPlayers() {
        
    }
    void printDeck() {
        
    }
    void printDealer() {
        
    }
// endGame()
};
