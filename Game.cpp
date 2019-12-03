#include "Game.hpp"
#include "Player.hpp"
#include "GameBoard.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Key.hpp"
#include "Sheet.hpp"
#include <list>
#include "Ghost.hpp"
using std::cout;
using std::endl;

Game::Game()
{
    srand(time(NULL));
    setPlayer(1, 7);
    setSister(3, 3);
    Sheet *sheet = new Sheet();
    //Key *key = new Key();
    sister.pickUpItem(sheet);
}

void Game::setSister(int row, int col)
{
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
        //Player makes their move
        Space *charSpace = player.move();

        //Player interacts with any characters they bumped into
        if (charSpace != 0)
        {
            interaction(charSpace);
        }

        //Pick up any items that are lying around
        Item *pickedUp = player.getLocation()->pickUpItem();
        if (pickedUp != 0)
        {
            int success = player.getInventory()->addItem(pickedUp);
            if (success == 0)
            {
                player.getLocation()->dropItem(pickedUp);
            }
        }

        //Check if sister has been found
        if (!sister.getFound())
        {
            //sister makes her move
            sister.move();
        }

        //update health

        //update foundSister

        //update gameOver

        //print screen
        printGameBoard();
    }
}

void Game::interaction(Space *location)
{
    //###TODO change when multiple characters are introduced.
    //Search Character* list for which character is at the given location.

    //int damage = sister.interact();
    sister.interact();
    //player.takeDamage(damage);
}

void Game::showBackpackContents()
{
    Inventory *theBackpack = player.getInventory();
    cout << "Here is a list of items you have in your backpack:\n";
    theBackpack->showItems();
}

void Game::printBoardKey()
{
    gb.printKey();
}

void Game::spawnGhost(int row, int col)
{
    Ghost *newGhost = new Ghost();
    setCharacter(newGhost, row, col);
    charList.push_back(newGhost);
}