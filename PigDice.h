#ifndef FINALSEM2_PIGDICE_H
#define FINALSEM2_PIGDICE_H
#include <iostream>
#include <cstdlib>

class Pigdice{
private:
    int score=0;
    int scoreThisTurn=0;
    int turn=0;
    bool turnOver= false;
    bool gameOver= false;
public:
    void play_game(){
        displayRules();
        while (!gameOver){
            take_turn();
        }
        std::cout << "Game over! It took you " << turn << " turns to finish!" << std::endl;
    }
    void take_turn(){
        char choice;
        turnOver=false ;
        std:: cout<< "TURN " << ++turn << std::endl;
        //ROLL OR HOLD
        while(!turnOver) {
            std:: cout << "(R)oll or (H)old: ";
            std:: cin>> choice;
            std::cout <<std::endl;
            if (choice == 'R' || choice == 'r') {
                roll();
            } else if (choice == 'H' || choice == 'h') {
                hold();
            }
        }
    }

    void roll(){
        int die;
        die= (rand() % 6)+1;
        if (die==1){
            turnOver=true;
            scoreThisTurn=0;
            std:: cout<< "Die: "<<die<< std::endl;
            std::cout << "Turn Over. No Score." << std::endl;
            std:: cout << "Score this turn " << scoreThisTurn << std::endl;
            std::  cout << "Total score " << score << std::endl << std::endl;
        }
        else{
            scoreThisTurn+=die;
            std::cout<< "Die: "<<die<< std::endl;
            std:: cout << "Score this turn " << scoreThisTurn << std::endl;
            std:: cout << "Total score " << score << std::endl << std::endl;
        }

    }

    void hold(){
        turnOver=true;
        score+=scoreThisTurn;
       scoreThisTurn=0;
        if (score>=20)
            gameOver=true;
        std::cout << "Total score " << score << std::endl << std::endl;
    }

    int displayRules() {
        std::cout << "* See how many turns it takes to reach 20 points" << std::endl <<
             "* A turn is over when you roll a 1 or you choose to hold" << std::endl <<
             "* If you roll a 1, then all points for that turn are lost" << std::endl <<
             "* If you hold, then points for the turn are added to score" << std::endl <<
             "**********************************************************" << std::endl << std::endl;
    }




};
#endif //FINALSEM2_PIGDICE_H
