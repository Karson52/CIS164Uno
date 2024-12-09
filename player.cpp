#include "player.h"
#include "deck.h"
#include "card.h"
#include <iostream>

Player::Player() {
    name = "No Name";
}
Player::Player(string name){
    set_name(name);
}
// this is the function we will call on the player who's turn it is. They will chose to play a card or draw.
CardEffect Player::takeTurn(Deck &drawDeck, Deck &playedDeck){
    // holds the pointer of the card that the player choses to play.
    card* cardPlayed;
    // holds a pointer to the card that the player selects from their hand
    card* cardSelsected;

    cout << "It is " << name <<"'s Turn." << endl;

    cout << "Face up card: " << playedDeck.peekCard() << endl;

    cout << "Your hand: " << handToString() << endl;

    cout << "Type 1 to play a card, 2 to draw a card";

    // TODO: take user input, validate input, and handle accordingly
    // Need to do a bunch of stuff here.. handling drawing rules and call the check legality function
    // whenever the player tries to play a card

    return cardPlayed->get_effect();
}

// TODO: write a function to validate if a card is playable or not by comparing it to the face up card.
bool Player::checkLegality(card chosenCard, card faceUpCard){

}

// A function for converting the hand into a string.
string Player::handToString(){

    string handString = "";
    // Loop over all of the cards, getting the card name and adding a space between each one.
    for(int i = 0; i < hand.size(); i ++){
        handString.append(hand[i]->get_name());
            handString.append(" ");
    }
    return handString;
}
//getters and setters
string Player::get_name(){
    return name;
}

void Player::set_name(string name){
    this->name = name;
}

