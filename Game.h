#ifndef FINALSEM2_GAME_H
#define FINALSEM2_GAME_H
#include "War.h"
#include "BlackJack.h"
#include "PigDice.h"
#include "Dice_Game.h"


class Game{
private:
    War warGame;
Blackjack blackjackGame;
Pigdice pigdiceGame;
Dice_Game diceGame;
public:
   void startGame(int choice) {
   if(choice==1)
       warGame.playRound();
   else if (choice==2)
       blackjackGame.play_game();
   else if (choice==3)
       pigdiceGame.play_game();
   else if (choice==4)
       diceGame.play();
   }



    };

#endif //FINALSEM2_GAME_H
