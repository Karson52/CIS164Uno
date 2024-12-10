#ifndef DECK_H
#define DECK_H

#include <vector>
#include "card.h"

class Deck
{
private:

    // vector of pointers to card objects
    vector<shared_ptr<card>> cards;


public:

    Deck();

    void fillDeck();
    void shuffle();
    shared_ptr<card> drawCard();
    shared_ptr<card> peekCard();
    void playCard(shared_ptr<card> playedCard);
    bool isEmpty();

};

#endif // DECK_H
