#ifndef DECK_H
#define DECK_H

#include <vector>;
#include "card.h";

class Deck
{
private:

    // vector of pointers to card objects
    vector<card*> cards;


public:

    Deck();

    void fillDeck();
    void shuffle();
    card *drawCard();
    card *peekCard();
    void playCard(card* playedCard);
    bool isEmpty();

};

#endif // DECK_H
