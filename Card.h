#ifndef BLACKJACK_CARD_H
#define BLACKJACK_CARD_H

#include<string>
class Card{
private:
    std::string rank;
    std::string suit;
    int value;

public:
    Card();
    void set_rank(std::string);
    std::string get_rank() const;
    void set_suit(std::string);
    void set_value(int);
    int get_value() const;
    std::string get_str();
    friend std::ostream& operator<<(std::ostream &OUT,Card &card);
};


Card::Card(){
    this->rank="";
    this->value=0;
    this->suit="";
}

void Card::set_rank(std::string r){
    this->rank = r;
}
std::string Card::get_rank() const{
    return  rank;
}
void Card::set_suit(std::string s){
    this->suit = s;
}
void Card::set_value(int v){
    this->value = v;
}

int Card::get_value() const{
    return value;
}

std::string Card::get_str(){
    return rank + " of " + suit;
}

std::ostream& operator<<(std::ostream &OUT,Card &card){
    OUT << card.get_str();
    return OUT;
}

#endif //BLACKJACK_CARD_H