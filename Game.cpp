#include <iostream>
#include "Game.h"

Game::Game() {}

void Game::start() {
    std::cout << "Welcome to the War game!" << std::endl;
    warGame.dealCards();

    while (!warGame.isGameOver()) {
        warGame.playRound();
    }

    warGame.printWinner();
}

