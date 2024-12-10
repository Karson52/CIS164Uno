#include "cardeffect.h"
#include "game.h" //Include to access the Game class functionality.

void SkipEffect::activateEffect(Game* game) {
    //Skip the next player's turn by adjusting the turn index.
    int turnIndex = game->get_turnIndex();
    int turnDirection = game->get_turnDirection();
    // do the math to skip one player
    game->set_turnIndex(turnIndex+turnDirection);
}

void ReverseEffect::activateEffect(Game* game) {
    // Reverse the direction of play.
    int direction = game->get_turnDirection();
    // multiply by -1 to reverse play
    game->set_turnDirection(direction * -1);
}

void DrawTwoEffect::activateEffect(Game* game) {
    //Make the next player draw two cards.
    for (int i = 0; i < 2; i++) {
        game->nextPlayerDraw();
    }
}

void WildEffect::activateEffect(Game* game) {
    game->getWildChoice();


}

void WildDrawFour::activateEffect(Game* game) {
    // perform the wild draw four effects.
    for (int i = 0; i< 4; i++){
        game->nextPlayerDraw();
    }
    game->getWildChoice();
}
