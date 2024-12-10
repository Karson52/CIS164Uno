#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <memory>
#include "cardeffect.h"

using namespace std;

class card {
private:
    int rank;
    string color;
    string name;
    string wildColor;
    shared_ptr<CardEffect> effect; //Use polymorphism for card effects.

    string createName();

public:
    card();
    card(int rank, string color, shared_ptr<CardEffect> effect = nullptr);

    int get_rank() const;
    void set_rank(int rank);

    string get_color() const;
    void set_color(string color);

    string get_name() const;
    void set_name(string name);

    shared_ptr<CardEffect> get_effect() const;
    void set_effect(shared_ptr<CardEffect> effect);

    string get_wildColor();
    void set_wildColor(string color);

    string get_wildName();
};

#endif // CARD_H
