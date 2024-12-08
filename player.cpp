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

    cout << "It is " << name << "'s turn." << endl;
    cout << "Face up card: " << faceUpCard->get_name() << endl;

    cout << "Your hand: " << handToString() << endl;

int choice;
    do {
        cout << "Type 1 to play a card, or 2 to draw a card: ";
        cin >> choice;

        if (choice == 1) {
            int cardIndex;
            cout << "Select the card index to play (starting from 0): ";
            cin >> cardIndex;

            if (cardIndex >= 0 && cardIndex < hand.size()) {
                card* chosenCard = hand[cardIndex];

                if (checkLegality(*chosenCard, *faceUpCard)) {
                    cardPlayed = chosenCard;
                    hand.erase(hand.begin() + cardIndex); //Remove the card from hand.
                    playedDeck.playCard(cardPlayed);      //Place the card on the played deck.
                    cout << "You played: " << cardPlayed->get_name() << endl;
                    break;
                } else {
                    cout << "That card cannot be played on the current face-up card." << endl;
                }
            } else {
                cout << "Invalid card index. Try again." << endl;
            }
        } else if (choice == 2) {
            card* drawnCard = drawDeck.drawCard();
            hand.push_back(drawnCard);  //Add the drawn card to the player's hand.
            cout << "You drew a card: " << drawnCard->get_name() << endl;
            //TODO maybe remove this line? turn shouldnt end after drawing
            break;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
    } while (true);
    return cardPlayed->get_effect() : CardEffect(); //No effect if no card is played.
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

