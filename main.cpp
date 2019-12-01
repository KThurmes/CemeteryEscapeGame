#include "Menu.hpp"
#include "GameBoard.hpp"
#include "Game.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    Game game;

    game.setPlayer(1, 7);

    game.printGameBoard();

    while (true)
    {
        game.turn();
    }

    game.deleteGame();
}