#include "Menu.hpp"
#include "GameBoard.hpp"
#include "Game.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    Game game;

    game.setPlayer(1, 1);

    game.printGameBoard();

    game.turn();
    game.deleteGame();
}