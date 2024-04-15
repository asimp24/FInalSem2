#ifndef FINALSEM2_PHONE_H
#define FINALSEM2_PHONE_H
#include "Game.h"
#include <vector>
class Phone{
public:
// Function to display the phone interface
    void displayPhoneScreen() {

        std::cout << "  _______________________________" << std::endl;
        std::cout << " / \\                             \\" << std::endl;
        std::cout << "|   |                            |" << std::endl;
        std::cout << "|   |                            |" << std::endl;
        std::cout << "|   |        Game Center         |" << std::endl;
        std::cout << "|___|____________________________|" << std::endl;
        std::cout << "|___|                            |" << std::endl;
        std::cout << "|   |   [1] War                  |" << std::endl;
        std::cout << "|___|____________________________|" << std::endl;
        std::cout << "|___|                            |" << std::endl;
        std::cout << "|   |   [2] Blackjack            |" << std::endl;
        std::cout << "|___|____________________________|" << std::endl;
        std::cout << "|___|                            |" << std::endl;
        std::cout << "|   |   [3] PigDice                 |" << std::endl;
        std::cout << "|___|____________________________|" << std::endl;
        std::cout << "|___|                            |" << std::endl;
        std::cout << "|   |   [4] Exit                  |" << std::endl;
        std::cout << "|___|____________________________|" << std::endl;
        std::cout << "\\___\\____________________________\\" << std::endl;
        std::cout << " \\________________________________\\" << std::endl;
    }

};
#endif //FINALSEM2_PHONE_H
