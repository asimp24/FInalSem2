#include <iostream>
#include <string>
void clearScreen(){
#ifdef _WIN32
std::system ("cls");
#else
std::system("clear");
#endif
};
// Function to display the phone interface
void displayPhoneScreen() {
    clearScreen();

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
    std::cout << "|   |   [3] Exit                 |" << std::endl;
    std::cout << "|___|____________________________|" << std::endl;
    std::cout << "\\___\\____________________________\\" << std::endl;
    std::cout << " \\________________________________\\" << std::endl;
}

int main() {
    int choice;

    do {
        displayPhoneScreen();

        // Get user choice
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        // Process user choice
        switch (choice) {
            case 1:
                std::cout << "\nStarting War game...\n";
                // Call function to start War game
                break;
            case 2:
                std::cout << "\nStarting Blackjack game...\n";
                // Call function to start Blackjack game
                break;
            case 3:
                std::cout << "\nExiting Game Center. Goodbye!\n";
                break;
            default:
                std::cout << "\nInvalid choice. Please enter a valid option.\n";
                break;
        }
    } while (choice != 3);

    return 0;
}

