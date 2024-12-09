#ifndef CARD_H
#define CARD_H

using namespace std;
#include <iostream>

class card
{

private:
    int rank;
    string color;
    string name;

public:
    card();
    card(int rank, string color);

    int get_rank();
    void set_rank(int rank);

    string get_color();
    void set_color(string color);

    string get_name();
    void set_name(string name);


};

#endif // CARD_H
