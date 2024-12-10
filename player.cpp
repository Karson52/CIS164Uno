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
//this is the function we will call on the player who's turn it is. They will chose to play a card or draw.
shared_ptr<CardEffect> Player::takeTurn(Deck &drawDeck, Deck &playedDeck) {
    //Holds the pointer of the card that the player chooses to play.
    card* cardPlayed = nullptr;

    cout << "It is " << name << "'s turn." << endl;

    int choice;
    do {
        cout << "Face up card: " << playedDeck.peekCard()->get_name() << endl;
        cout << "Your hand: " << handToString() << endl;
        cout << "Type 1 to play a card, or 2 to draw a card: ";
        cin >> choice;

        if (choice == 1) {
            int cardIndex;
            cout << "Select the card index to play (starting from 0): ";
            cin >> cardIndex;

            if (cardIndex >= 0 && cardIndex < hand.size()) {
                card* chosenCard = hand[cardIndex];

                if (checkLegality(*chosenCard, *playedDeck.peekCard())) {
                    cardPlayed = chosenCard;
                    hand.erase(hand.begin() + cardIndex); //Remove the card from hand.
                    playedDeck.playCard(cardPlayed);      //Place the card on the played deck.
                    cout << "You played: " << cardPlayed->get_name() << endl;
                    break;  //End turn after successfully playing a card.
                } else {
                    cout << "That card cannot be played on the current face-up card." << endl;
                }
            } else {
                cout << "Invalid card index. Try again." << endl;
            }
        } else if (choice == 2) {
            card* drawnCard = drawDeck.drawCard();
            hand.push_back(drawnCard);  // Add the drawn card to the player's hand.
            cout << "You drew a card: " << drawnCard->get_name() << endl;
            //Continue the turn after drawing a card (no break here).
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
    } while (true);

    //Return the effect of the played card, or no effect if none was played.
    //return cardPlayed ? cardPlayed->get_effect() : CardEffect();
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
// return true if the player's hand is empty.
bool Player::hasWon(){
    if(hand.empty()){
        return true;
    }
    return false;
}
// player draws the card into their hand
void Player::draw(card* card){
    hand.push_back(card);
}

//getters and setters
string Player::get_name(){
    return name;
}

void Player::set_name(string name){
    this->name = name;
}

