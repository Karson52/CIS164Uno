#ifndef PLAYER_H
#define PLAYER_H

#include "cardeffect.h"

class Player
{
public:
    Player();
    bool hasWon();
    CardEffect takeTurn();
};

#endif // PLAYER_H
