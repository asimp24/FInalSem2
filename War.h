#ifndef FINALSEM2_WAR_H
#define FINALSEM2_WAR_H
#include "Deck.h"

class War {
private:
    Deck deck;
    std::vector<Card> player1Hand;
    std::vector<Card> player2Hand;
    bool gameOver;

public:
    War();
    void dealCards();
    void playRound();
    void resolveWar();
    bool isGameOver() const;
    void printWinner() const;
};

#endif //FINALSEM2_WAR_H
