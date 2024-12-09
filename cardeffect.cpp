#include "cardeffect.h"

// This class should be inherited by all of the card effect classes. we will have a class for each effect
// which has a function as it's member called activateEffect that gets called by the game class when the
// object gets returned to it after the player's turn. that function will perform the card's effect.
// Might be best to just pass the game object into this function by reference and then use game's getters and
// setters within the activateEffect function.

CardEffect::CardEffect() {}
