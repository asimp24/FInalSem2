#ifndef FINALSEM2_DICE_GAME_H
#define FINALSEM2_DICE_GAME_H
#include <cstdlib>
#include <iostream>
#include <ctime>


class Dice_Game{
private:
    int die1;
    int die2;
    int rollDice;

public:
    Dice_Game(){
        srand(time(nullptr));

    }
    int roll(){
        die1 = rand()%6 +1;
        die2 = rand()%6 +1;
        return die1+die2;
    }

    void play(){
        std::cout << "Welcome to the dice game Craps" << std::endl << std::endl;
        char repeat = 'y';

        while (repeat != 'n'){
            rollDice=roll();
            char l;
            std::cout << "You rolled " << rollDice << std::endl;
            std::cout<< "Enter any letter to continue: ";
            std:: cin >> l;
            if(rollDice == 7 || rollDice == 11){
                std::cout << "You win!" << std::endl;
            }else if (rollDice == 2 || rollDice == 3 || rollDice == 12){
                std::cout << "You lose!" << std::endl;
            }else{
                int sum2;
                char y;
                while(sum2 != rollDice ){
                    sum2 = roll();
                    std::cout << "You rolled " << sum2 << std::endl;
                    if (sum2==7)
                        break;
                    std::cout<< "Enter any letter to continue: ";
                    std:: cin >> y;
                }
                if(sum2 == rollDice){
                    std::cout << "Winner! " << std::endl;
                    break;
                }else if (sum2==7){
                    std::cout << "You lose!" << std::endl;
                    break;
                }
            }
            std::cout << "Play again?(y/n)";
            std::cin >> repeat;
        }
        std::cout << "Thank you for playing!";
    }
};

#endif //FINALSEM2_DICE_GAME_H
