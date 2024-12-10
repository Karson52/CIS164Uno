#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "deck.h"
#include <vector>

using namespace std;

class Game

{
private:

    vector<Player*> players;

    Deck drawDeck;
    Deck playedDeck;

    int turnDirection;
    int turnIndex;
    int playerCount;
    int currentPlayer;
    int maxPlayers;

    bool gameWon;

    void handleCardEffect(CardEffect effect);

public:

    Game();

    void setUp();
    void takeTurn();
    void play();

    void addPlayer(Player* player);
};

#endif // GAME_H
