#include "Game.hpp"
#include "Player.hpp"
#include "GameBoard.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::endl;

Game::Game()
{
    srand(time(NULL));
    setPlayer(1,7);
    setSister(3,3);
}

void Game::setSister(int row, int col){
    Space *theSpace = gb.getSpaceAt(row, col);
    theSpace->setPrintSymbol(sister.getSymbol());
    theSpace->setHasCharacter(true);

    sister.setLocation(theSpace);
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
        Space* charSpace = player.move();
        if(charSpace != 0){
            interaction(charSpace);
        }

        //Check if sister has been found
        if (!sister.getFound()){
            //sister makes her move
            sister.move();
        }
 
        //Delete sister if found

        
        //update health

        //update foundSister

        //update gameOver

        //print screen
        printGameBoard();
    }
}

void Game::interaction (Space* location){
    //###TODO change when multiple characters are introduced. Search Character* list for which character is at the given location.
    int damage = sister.interact();
    //player.takeDamage(damage);
}
