#include "cardeffect.h"
#include "game.h" //Include to access the Game class functionality.

void SkipEffect::activateEffect(Game& game) {
    //Skip the next player's turn by adjusting the turn index.
    game.adjustTurnIndex(1); // Skip one turn.
}

void ReverseEffect::activateEffect(Game& game) {
    // Reverse the direction of play.
    game.reverseTurnDirection();
}

void DrawTwoEffect::activateEffect(Game& game) {
    //Make the next player draw two cards.
    for (int i = 0; i < 2; i++) {
        game.drawCardForNextPlayer();
    }
}

void WildEffect::activateEffect(Game& game) {
    //Allow the player to choose a new color.
    game.setWildColor();
}

void WildDrawFour::activateEffect(Game& game) {
    // perform the wild draw four effects.
}
