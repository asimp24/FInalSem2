#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include <vector>
#include "Card.h"
#include <algorithm>
#include <ctime>

class Deck{
private:
    std::vector<Card> deck;
public:
    Deck();
    void shuffle();
    Card deal_card();
    int get_count();
};

int Deck::get_count(){
    return deck.size();
}


Deck::Deck() {
    std::vector<std::string> card_ranks{"2", "3", "4", "5", "6", "7", "8", "9", "10",
                                        "Jack", "Queen", "King", "Ace"};
    std::vector<int> card_values{2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
    std::vector<std::string> card_suits{"Diamonds", "Hearts", "Clubs", "Spades"};

    for (int i = 0; i < card_ranks.size(); i++) {
        Card temp;
        temp.set_rank(card_ranks[i]);
        temp.set_value(card_values[i]);
        for (int j = 0; j < card_suits.size(); j++) {
            temp.set_suit(card_suits[j]);
            deck.push_back(temp);
        }
    }

}


void Deck::shuffle(){
    srand(time(0));
    random_shuffle(deck.begin(),deck.end());
   /* for(auto card:deck)
        std::cout << card.get_str() << std::endl;*/
}

Card Deck::deal_card(){
    Card temp = deck.back();
    deck.pop_back();
    return temp;
}



#endif //BLACKJACK_DECK_H