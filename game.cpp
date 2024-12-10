#include "game.h"
#include "player.h"
#include "cardeffect.h"

using namespace std;

Game::Game() {
    // Variables for controlling which player's turn it is.
    // after turnIndex%playerCount we will know who's turn it should be
    turnIndex = 0;
    /*
     *  If counter clockwise play(due to a reverse card), we will have -1 turn direction.
     *  turnIndex += turnDirection will adjust turnIndex properly so that the correct player
     *  takes the next turn.
     */
    turnDirection = 1;
    // not sure yet if we want this variable here, or if it can be within the scope of takeTurn.
    currentPlayer = 0;
    maxPlayers = 4;
    gameWon = false;

    // This is the deck players will be drawing card from.
    drawDeck = Deck();

    // This is the deck players will be playing cards onto.
    playedDeck = Deck();

}

void Game::setUp(){

    // fill and shuffle the draw deck.
    drawDeck.fillDeck();
    drawDeck.shuffle();

    // flip a card from the draw deck to the played deck to be the initial face up card.
    playedDeck.playCard(drawDeck.drawCard());
}

void Game::takeTurn(){

    // figure out who's turn it is.
    currentPlayer = turnIndex%playerCount;

    // player.takeTurn() will perform the player's turn actions and return any required card effects.
    effect = players[currentPlayer]->takeTurn();

    // handle any card effects we need to
    handleCardEffect(effect);

    if(players[currentPlayer]->hasWon()){
        // do something to end the game
    }

    // adjust the turnIndex
    turnIndex += turnDirection;

}
void Game::play()
{
    // Set up the game by preparing decks and players.
    setUp();
    gameWon = false;

    // Main game loop.
    while (!gameWon)
    {
        takeTurn();

        // Check if the draw deck is empty and needs to be repfilled.
        if (drawDeck.isEmpty()) {
            drawDeck.fillDeck();
        }
    }
}
void Game::addPlayer(Player* player) {
    players.push_back(player);
}
// TODO: handle any card effects we might get back from player.takeTurn();
void handleCardEffect(CardEffect effect){
    // Uno reverse should multiply turn direction by -1.
    // draw four and draw two cause next player to draw cards.
    // skip should perform turnIndex+=turnDirection an extra time
    // wild should ask player to select the new color/suit
}
