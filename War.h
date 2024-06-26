#ifndef FINALSEM2_WAR_H
#define FINALSEM2_WAR_H

#include "Deck.h"
#include <iostream>


class War {
private:
    Deck deck;
    std::vector<Card> player1Hand;
    std::vector<Card> player2Hand;
    bool gameOver;

public:
    War() : gameOver(false) {} // Initialize gameOver to false

    void dealCards() {
        for (int i = 0; i < 52; i += 2) {
            player1Hand.push_back(deck.deal_card());
            player2Hand.push_back(deck.deal_card());
        }
    }

    void playRound() {
        if (gameOver) {
            return; // If the game is over, exit the function immediately.
        }

        if (player1Hand.empty() || player2Hand.empty()) {
            gameOver = true;
            return;
        }

        Card card1 = player1Hand.back();
        player1Hand.pop_back();
        Card card2 = player2Hand.back();
        player2Hand.pop_back();

        std::cout << "Player 1 plays: " << card1 << std::endl;
        std::cout << "Player 2 plays: " << card2 << std::endl;

        if (card1.get_value() > card2.get_value()) {
            std::cout << "Player 1 wins the round!" << std::endl;
            player1Hand.insert(player1Hand.begin(), card1);
            player1Hand.insert(player1Hand.begin(), card2);
        } else if (card1.get_value() < card2.get_value()) {
            std::cout << "Player 2 wins the round!" << std::endl;
            player2Hand.insert(player2Hand.begin(), card2);
            player2Hand.insert(player2Hand.begin(), card1);
        } else {
            std::cout << "WAR!" << std::endl;
            resolveWar();
        }

        if (player1Hand.empty() || player2Hand.empty()) {
            gameOver = true;
        }
        char c;
        std::cout<< "Would you like to continue?(y/n)";
       std::cin>> c;
       if (c=='n') {
           player1Hand.clear();
           player2Hand.clear();
       }
    }

    void resolveWar() {
        const int warSize = 3;
        if (player1Hand.size() < warSize || player2Hand.size() < warSize) {
            gameOver = true;
            return;
        }

        std::vector<Card> pot;
        for (int i = 0; i < warSize; ++i) {
            if (player1Hand.empty() || player2Hand.empty()) {
                gameOver = true;
                return;
            }
            pot.push_back(player1Hand.back());
            player1Hand.pop_back();
            pot.push_back(player2Hand.back());
            player2Hand.pop_back();
        }

        if (player1Hand.empty() || player2Hand.empty()) {
            gameOver = true;
            return;
        }

        Card card1 = player1Hand.back();
        Card card2 = player2Hand.back();

        std::cout << "Player 1 plays face down card." << std::endl;
        std::cout << "Player 2 plays face down card." << std::endl;

        pot.push_back(card1);
        pot.push_back(card2);

        if (card1.get_value() > card2.get_value()) {
            std::cout << "Player 1 wins the war!" << std::endl;
            player1Hand.insert(player1Hand.begin(), pot.begin(), pot.end());
        } else if (card1.get_value() < card2.get_value()) {
            std::cout << "Player 2 wins the war!" << std::endl;
            player2Hand.insert(player2Hand.begin(), pot.begin(), pot.end());
        } else {
            std::cout << "Another tie!" << std::endl;
            // Do nothing and let the current war round end without further recursion.
        }
    }

    bool isGameOver() const {
        return gameOver;
    }

    void printWinner() const {
        if (player1Hand.empty()) {
            std::cout << "Player 2 wins the game!" << std::endl;
        } else {
            std::cout << "Player 1 wins the game!" << std::endl;
        }
    }

    void startGame() {
        deck.shuffle();
        dealCards();
        while (!isGameOver()) {
            playRound();
        }
        printWinner();
    }
};

#endif //FINALSEM2_WAR_H
