#include "card.h"

card::card() {
    set_rank(-1);
    set_color("none");

}
card::card(int rank, string color) {
    set_rank(rank);
    set_color(color);
}

// A function for getting the card's name for the first time.
string card::createName(){
    // TODO: The cards will all be identified by rank. this means we will assign some value to the action cards
    // and wilds. The name shouldn't say "blue 10", but instead it should say "blue skip".
    // this name will be helpful for displaying the card hands
    string myName = "";
    return myName;
}
int card::get_rank(){
    return rank;
}

void card::set_rank(int rank){
    this->rank = rank;
}

string card::get_color(){
    return color;
}

void card::set_color(string color){
    this->color = color;
}

string card::get_name(){
    return name;
}

void card::set_name(string name){
    this->name = name;
}

CardEffect card::get_effect(){
    return effect;
}

void card::set_effect(CardEffect effect){
    this->effect = effect;
}
