#ifndef BLACKJACK_GAME_H
#define BLACKJACK_GAME_H

#include <iostream>
#include "Deck.h"
#include "Hand.h"

class Blackjack {
private:
    char again;
    Deck deck;
    Hand dealer_hand;
    Hand player_hand;
public:
    Blackjack();
    Hand get_player_hand(Deck&,Hand&);
    Hand get_dealer_hand(Deck&,Hand&);
    void display_cards(Hand,std::string title);
    void display_round();
    void play_game();
};

Hand Blackjack::get_player_hand(Deck& deck,Hand& player_hand){
    char choice='h';
    while(choice !='s'){
    std::cout << "\nHit or Stand? (h/s):";
    std::cin >> choice;
        if (choice == 'h') {
        player_hand += deck.deal_card();
            display_cards(player_hand, "Your Cards:");
            if (player_hand.get_points() >= 21)
                break;
        }
        else if (choice == 's')
            break;
        else
            std::cout << "Invalid choice! Try again."<< std::endl;
    }
    return player_hand;
}
Hand Blackjack::get_dealer_hand(Deck& deck,Hand& dealer_hand){
    while(dealer_hand.get_points()<17) {
        dealer_hand += deck.deal_card();
        display_cards(dealer_hand, "\nDealer's Show Card:");
    }
    return dealer_hand;
}
void Blackjack::display_cards(Hand hand,std::string title){
    std::cout << title << std::endl;
    for (int i=0; i<hand.count(); i++)
        std::cout << hand.get_card(i).get_str()<< std::endl;
}
void Blackjack::display_round(){
    std::cout << "\nYour Points: " << player_hand.get_points() << std::endl;
    std::cout << "Dealer's Points: " << dealer_hand.get_points() << std::endl;

    if (player_hand.get_points()>21)
        std::cout << "You busted. You lose.\n";
    else if (player_hand.get_points()<21 and dealer_hand.get_points()>21)
        std::cout << "Hooray! The dealer busted. You win.\n";
    else if(player_hand.get_points()==21 and player_hand.count()==2) {
            if(dealer_hand.get_points()==21 and dealer_hand.count()==2)
                std::cout << "Darn! The dealer got Blackjack too! You push.\n";
            else
                std::cout << "Hooray! You got Blackjack! You win.\n";

    }
    else {
        if(player_hand.get_points()>dealer_hand.get_points())
            std::cout<< "You got a higher score! You win.\n";
        else if (dealer_hand.get_points()>player_hand.get_points())
            std::cout << "The dealer got a higher score. You Lose.\n";
        else
            std::cout << "You and the dealer tied. You Push.\n";
    }
}

void Blackjack::play_game(){
    char c;
    while(c!='n') {
        deck.shuffle();
        dealer_hand += deck.deal_card();
        display_cards(dealer_hand, "\nDealer's Show Card:");
        player_hand += deck.deal_card();
        player_hand += deck.deal_card();
        display_cards(player_hand, "\nYour Cards:");
        get_player_hand(deck, player_hand);
        get_dealer_hand(deck, dealer_hand);
        display_round();
        std::cout << "Continue?(y/n): ";
        std::cin >> c;
        player_hand.clear_hand();
        dealer_hand.clear_hand();
    }
}

#endif //BLACKJACK_GAME_H