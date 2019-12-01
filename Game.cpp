#include "Game.hpp"
#include "Player.hpp"
#include "GameBoard.hpp"

Game::Game()
{
    //gb = new GameBoard();
    //gb->setCharacter(0, 0, &player);
}

void Game::setPlayer(int row, int col)
{
    Space *theSpace = gb.getSpaceAt(row, col);
    theSpace->setPrintSymbol(player.getSymbol());
    theSpace->setHasCharacter(true);
    player.setLocation(theSpace);
}

void Game::printGameBoard()
{
    gb.printGameBoard();
}

void Game::deleteGame()
{
    //delete characters

    //delete game board
    gb.deleteGameBoard();
    //delete gb;

    //delete player
    //delete[] player;
}