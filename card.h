#ifndef CARD_H
#define CARD_H

using namespace std;
#include <iostream>
#include "cardeffect.h"

class card
{

private:
    int rank;
    string color;
    string name;
    CardEffect effect;

    string createName();

public:
    card();
    card(int rank, string color);

    int get_rank();
    void set_rank(int rank);

    string get_color();
    void set_color(string color);

    string get_name();
    void set_name(string name);

    CardEffect get_effect();
    void set_effect(CardEffect effect);
};

#endif // CARD_H
