#include "Menu.hpp"
#include "GameBoard.hpp"
#include "Game.hpp"

int main()
{
    Game game;
    game.setPlayer(0, 0);
    game.printGameBoard();
    game.deleteGame();
}