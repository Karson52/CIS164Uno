#include "deck.h"
#include "card.h"

Deck::Deck() {

}

// TODO: write a function to place all of the cards into the deck
void Deck::fillDeck(){
    return;
}

//TODO: make a function for suffling the deck of cards
void Deck::shuffle(){
    return;
}

// A function for drawing a card from the top (back) of the deck
card Deck::drawCard(){
    card drawn = cards.back();
    cards.pop_back();
    return drawn;
}

// A function for looking at the top of the deck, but not removing it
card Deck::peekCard(){
    return cards.back();
}
// A function for playing a card onto a stack of played cards.
void Deck::playCard(card playedCard){
    cards.push_back(playedCard);
    return;
}

// Lets us check if the deck is empty
bool Deck::isEmpty(){
    return cards.empty();
}
