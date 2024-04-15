#ifndef BLACKJACK_HAND_H
#define BLACKJACK_HAND_H

#include <vector>
#include "Card.h"

class Hand {
private:
    std::vector<Card> hand;
public:
    Hand();
    void clear_hand();
    void operator+=(Card);
    Card get_card(int index);
    int get_points();
    int count();
};

Hand::Hand(){

}

void Hand::clear_hand(){
    hand.clear();
}
void Hand::operator+=(Card card){
    hand.push_back(card);
}

Card Hand::get_card(int index){
    return hand.at(index);
}

int Hand::get_points(){
    int points=0, ace_count=0;

    for (auto card:hand){
        points += card.get_value();
    }

    if (points > 21){
        for (auto card:hand){
            if (card.get_rank() == "Ace")
                ace_count++;
        }
    }

    return points - (ace_count * 10);
}

int Hand::count(){
    return hand.size();
}

#endif //BLACKJACK_HAND_H