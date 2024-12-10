#include <QCoreApplication>
#include "game.h"
#include "player.h"
#include "deck.h"
#include "card.h"
#include "cardeffect.h"
#include <iostream>
using namespace std;

int main()
{
    Game game;

    // Set up test players (replace with user input?)
    vector<string> unoPlayers = {"Player 1", "Player 2", "Player 3", "Player 4"};

    for (size_t i = 0; i < unoPlayers.size(); ++i)
    {
        shared_ptr<Player> newPlayer (new Player(unoPlayers[i]));
        game.addPlayer(newPlayer); // Adds the new player to the game's vector.
    }
    // Run the game.
    cout << "Starting the game!" << endl;
    game.play();

    cout << "Game over!" << endl;
    return 0;
}
