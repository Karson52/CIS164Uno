#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include "cardeffect.h"
#include "deck.h"
#include <vector>

class Player
{
private:

    string name;
    vector<shared_ptr<card>> hand;
    string handToString();
    bool checkLegality(shared_ptr<card> chosenCard, shared_ptr<card> faceUpCard);

public:

    Player();
    Player(string name);

    bool hasWon();
    shared_ptr<CardEffect> takeTurn(shared_ptr<Deck> drawDeck, shared_ptr<Deck> playedDeck);

    string get_name();
    void set_name(string name);

    void draw(shared_ptr<card> card);

};

#endif // PLAYER_H
