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
    vector<card*> hand;
    string handToString();
    bool checkLegality(card chosenCard, card faceUpCard);

public:

    Player();
    Player(string name);

    bool hasWon();
    CardEffect takeTurn(Deck &drawDeck, Deck &playedDeck);

    string get_name();
    void set_name(string name);

};

#endif // PLAYER_H
