#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "deck.h"
#include <vector>

using namespace std;

class Game

{
private:

    vector<Player> players;

    Deck drawDeck;
    Deck playedDeck;

    int turnDirection;
    int turnIndex;
    int playerCount;
    int currentPlayer;

    void handleCardEffect(CardEffect effect);

public:

    Game();

    void setUp();
    void takeTurn();
};

#endif // GAME_H
