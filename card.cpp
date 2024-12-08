#include "card.h"

card::card() {
    set_rank(-1);
    set_color("none");
}
card::card(int rank, string color) {
    set_rank(rank);
    set_color(color);
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
