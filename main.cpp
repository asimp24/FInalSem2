#include <iostream>
#include <string>
#include "Phone.h"
#include "Game.h"
int main(){
    Phone phone;
    Game game;
        int choice;

        do {
            phone.displayPhoneScreen();

            // Get user choice
            std::cout << "\nEnter your choice: ";
            std::cin >> choice;

            // Process user choice
            switch (choice) {
                case 1:
                    std::cout << "\nStarting War game...\n";
                    game.startGame(choice);
                    // Call function to start War game
                    break;
                case 2:
                    std::cout << "\nStarting Blackjack game...\n";
                    game.startGame(choice);
                    // Call function to start Blackjack game
                    break;
                case 3:
                    std::cout<< "\nStarting Pigdice game...\n";
                    game.startGame(choice);
                    break;
                case 4 :
                    std::cout << "\nStarting Craps game...\n";
                    break;
                case 5:
                    std::cout << "\nExiting Game Center. Goodbye!\n";
                    break;
                default:
                    std::cout << "\nInvalid choice. Please enter a valid option.\n";
                    break;
            }
        } while (choice != 5);

    return 0;
}