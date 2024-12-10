#ifndef CARDEFFECT_H
#define CARDEFFECT_H

#include <string>

using namespace std;

class Game; //Forward declaration for the Game class.

class CardEffect {
public:
    virtual ~CardEffect() = default;

    //Pure virtual function to activate the card's effect.
    virtual void activateEffect(Game* game) = 0;

    //Virtual function to get the effect's name.
    virtual string getName() const = 0;
};

class SkipEffect : public CardEffect {
public:
    void activateEffect(Game* game) override;
    string getName() const override { return "Skip"; }
};

class ReverseEffect : public CardEffect {
public:
    void activateEffect(Game* game) override;
    string getName() const override { return "Reverse"; }
};

class DrawTwoEffect : public CardEffect {
public:
    void activateEffect(Game* game) override;
    string getName() const override { return "Draw Two"; }
};

class WildEffect : public CardEffect {
public:
    void activateEffect(Game* game) override;
    string getName() const override { return "Wild"; }
};

class WildDrawFour : public CardEffect {
public:
    void activateEffect(Game* game) override;
    string getName() const override { return "Wild Draw Four"; }
};

#endif // CARDEFFECT_H
