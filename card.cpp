#include "card.h"

card::card() : rank(-1), color("none"), name(""), effect(nullptr) {}

card::card(int rank, string color, shared_ptr<CardEffect> effect)
    : rank(rank), color(color), effect(effect) {
    name = createName();
}

string card::createName() {
    //Generate the card's display name based on its rank and effect.
    if (effect) {
        return color + " " + effect->getName();
    }
    return color + " " + to_string(rank);
}

int card::get_rank() const {
    return rank;
}

void card::set_rank(int rank) {
    this->rank = rank;
    name = createName();
}

string card::get_color() const {
    return color;
}

void card::set_color(string color) {
    this->color = color;
    name = createName();
}

string card::get_name() const {
    return name;
}

void card::set_name(string name) {
    this->name = name;
}

shared_ptr<CardEffect> card::get_effect() const {
    return effect;
}

void card::set_effect(shared_ptr<CardEffect> effect) {
    this->effect = effect;
    name = createName();
}
