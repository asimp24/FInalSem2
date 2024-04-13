#ifndef FINALSEM2_GAME_H
#define FINALSEM2_GAME_H
#include "War.h"
#include "BlackJack.h"
#include "PigDice.h"

class Game{

private:
    War warGame;
Blackjack blackjackGame;
Pigdice pigdiceGame;
public:
    Game();
    void start();






};
#endif //FINALSEM2_GAME_H
