#include "deck.h"
#include "card.h"
#include "cardeffect.h"
#include <algorithm>

using namespace std;
Deck::Deck() {

}

// TODO: write a function to place all of the cards into the deck
// should total to 108 cards
void Deck::fillDeck(){
    string colors[] = {"Blue","Red","Yellow", "Green"};

    for(int i = 0; i < 4; i++){
        cards.push_back(shared_ptr<card> (new card(0, colors[i])));
            for(int j = 1; j<10; j++){
                // need two of each
                cards.push_back(shared_ptr<card> (new card(j, colors[i])));
                cards.push_back(shared_ptr<card> (new card(j, colors[i])));
                }
                // create cards with effects

                // Create skip cards
                shared_ptr<CardEffect> skip = make_shared<SkipEffect>();
                cards.push_back(shared_ptr<card> (new card(10, colors[i], skip)));
                cards.push_back(shared_ptr<card> (new card(10, colors[i], skip)));

                // create reverse cards
                shared_ptr<CardEffect> reverse = make_shared<ReverseEffect>();
                cards.push_back(shared_ptr<card> (new card(11, colors[i], reverse)));
                cards.push_back(shared_ptr<card> (new card(11, colors[i], reverse)));

                // create drawTwo cards
                shared_ptr<CardEffect> drawTwo = make_shared<DrawTwoEffect>();
                cards.push_back(shared_ptr<card> (new card(12, colors[i], reverse)));
                cards.push_back(shared_ptr<card> (new card(12, colors[i], reverse)));
            }

    // shared pointer for the wild effect
    shared_ptr<CardEffect> wild = make_shared<WildEffect>();

    // shared pointer for the wild draw four effect
    shared_ptr<CardEffect> wildDrawFour = make_shared<WildDrawFour>();

    // Loop for creating the wilds/draw fours
    for(int i = 0; i<4; i++){
        cards.push_back(shared_ptr<card> (new card(13, "Wild", wild)));
        cards.push_back(shared_ptr<card> (new card(14, "Wild", wildDrawFour)));
    }
    return;
}

// A function to shuffle the cards
void Deck::shuffle(){
    random_shuffle(cards.begin(), cards.end());
    return;
}

// A function for drawing a card from the top (back) of the deck
shared_ptr<card> Deck::drawCard(){
    shared_ptr<card> drawn = cards.back();
    cards.pop_back();
    return drawn;
}

// A function for looking at the top of the deck, but not removing it
shared_ptr<card> Deck::peekCard(){
    return cards.back();
}
// A function for playing a card onto a stack of played cards.
void Deck::playCard(shared_ptr<card> playedCard){
    cards.push_back(playedCard);
    return;
}

// Lets us check if the deck is empty
bool Deck::isEmpty(){
    return cards.empty();
}
