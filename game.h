#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "deck.h"
#include <vector>

using namespace std;

class Game

{
private:

    vector<shared_ptr<Player>> players;

    Deck drawDeck;
    Deck playedDeck;

    int turnDirection;
    int turnIndex;
    int playerCount;
    int currentPlayer;
    int maxPlayers;

    bool gameWon;

    void handleCardEffect(CardEffect* effect);
    void deal();

public:

    Game();


    void setUp();
    void takeTurn();
    void play();
    void addPlayer(shared_ptr<Player> player);
    // getters and setters
    int get_turnIndex();
    void set_turnIndex(int index);

    int get_turnDirection();
    void set_turnDirection(int direction);

    void nextPlayerDraw();

    void getWildChoice();
};

#endif // GAME_H
