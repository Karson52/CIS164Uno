#include "game.h"
#include "player.h"
#include "cardeffect.h"

using namespace std;

Game::Game() {
    // Variables for controlling which player's turn it is.
    // after turnIndex%playerCount we will know who's turn it should be
    // index itself is arbitrary, start at 10k to avoid the -mod bug
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

    deal();
}

void Game::takeTurn(){
    shared_ptr<CardEffect> effect;

    // figure out who's turn it is.
    currentPlayer = turnIndex%playerCount;

    // player.takeTurn() will perform the player's turn actions and return any required card effects.
    effect = players[currentPlayer]->takeTurn(drawDeck, playedDeck);

    // handle any card effects we need to
    //handleCardEffect(effect);
    effect->activateEffect(this);

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

void Game::deal() {
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < maxPlayers; j++){
            players[j]->draw(drawDeck.drawCard());
        }
    }
}
void Game::addPlayer(shared_ptr<Player> player) {
    players.push_back(player);
}

// getters and setters
int Game::get_turnIndex(){
    return turnIndex;
}
void Game::set_turnIndex(int index){
    this->turnIndex = index;
}

int Game::get_turnDirection(){
    return turnDirection;
}

void Game::set_turnDirection(int direction){
    this->turnDirection = direction;
}

