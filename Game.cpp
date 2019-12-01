#include "Game.hpp"
#include "Player.hpp"
#include "GameBoard.hpp"
#include <iostream>
using std::cout;
using std::endl;

Game::Game()
{
}

void Game::setPlayer(int row, int col)
{

    Space *theSpace = gb.getSpaceAt(row, col);
    theSpace->setPrintSymbol(player.getSymbol());
    theSpace->setHasCharacter(true);

    player.setLocation(theSpace);
}

void Game::setCharacter(Character *character, int row, int col)
{
    Space *theSpace = gb.getSpaceAt(row, col);
    theSpace->setPrintSymbol(character->getSymbol());
    theSpace->setHasCharacter(true);
    player.setLocation(theSpace);
}

void Game::printGameBoard()
{
    gb.printGameBoard();
}

void Game::deleteGame()
{
    gb.deleteGameBoard();
}

void Game::turn()
{
    //check if game is over
    if (gameOver == true)
    {
        cout << "The game is over." << endl;
    }
    else
    {
        //user makes their move
        player.move();

        //update health

        //update foundSister

        //update gameOver

        //print screen
        printGameBoard();
    }
}
