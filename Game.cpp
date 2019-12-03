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
#include "NPC.hpp"
using std::cout;
using std::endl;

Game::Game()
{
    //Put the player in their starting place.
    Player *pPlayer = &player;
    moveCharacter(pPlayer, 1, 7);

    //Set up the sister
    NPC *sis = &sister;
    moveCharacter(sis, 3, 3);
    NPCList.push_back(sis);

    //Give the sister the sheet to drop
    Sheet *sheet = new Sheet();
    itemList.push_back(sheet);
    sister.pickUpItem(sheet);

    gameOver = false;
    playerHasKey = false;
    playerHasSheet = false;
}

void Game::moveCharacter(Character *character, int row, int col)
{
    Space *theSpace = gb.getSpaceAt(row, col);
    moveCharacter(character, theSpace);
}

void Game::moveCharacter(Character *character, Space *destination)
{
    if (character->getLocation() != 0)
    {
        //Pick character up from where they were
        character->getLocation()->setHasCharacter(false);
        character->getLocation()->changeToDefaultSymbol();
    }

    //Move character to somewhere else
    destination->setPrintSymbol(character->getSymbol());
    destination->setHasCharacter(true);
    character->setLocation(destination);
}

void Game::printGameBoard()
{
    gb.printGameBoard();
}

void Game::turn()
{

    //Player makes their move
    Space *destination = player.move();

    //If there isn't a square in the direction the player wants to go...
    if (destination == 0)
    {
        cout << "Cannot go in that direction!" << endl;
        turn();
    }

    else
    {
        if (destination == player.getLocation())
        {
            //Stay where you are
        }

        //Player interacts with any characters they bumped into
        else if (destination->getHasCharacter())
        {
            interaction(destination);
        }

        //If the space isn't passable, interact with it
        else if (!destination->getPassable())
        {
            //Interact with the space
            destination->interact(player.getInventory());

            //See if game needs to spawn a ghost at destination
            if (destination->getSpawnGhost())
            {
                spawnGhost(destination);
            }
        }

        //Else, there's no one there and it's passable. Player moves.
        else
        {
            moveCharacter(&player, destination);
        }
    }

    gameOver = checkGameOver();

    if (gameOver == false)
    {
        //Pick up any items that are lying around
        Item *pickedUp = player.getLocation()->pickUpItem();

        if (pickedUp != 0)
        {
            int success = player.getInventory()->addItem(pickedUp);

            //Drop the item if there's no room in the backpack for it.
            if (success == 0)
            {
                player.getLocation()->dropItem(pickedUp);
            }
        }

        //Sister makes her move
        sister.move();

        for (auto it = NPCList.begin(); it != NPCList.end(); ++it)
        {
            NPC *theCharacter = *it;
            theCharacter->move();
        }
    }
    //print screen
    printGameBoard();
}

void Game::interaction(Space *location)
{
    //Search Character* list for which character is at the given location.
    int damage = 0;
    for (auto it = NPCList.begin(); it != NPCList.end(); ++it)
    {
        NPC *theCharacter = *it;
        if (theCharacter->getLocation() == location)
        {
            //Interact with the character at the location
            damage = theCharacter->interact();
        }
    }

    //Update player health
    player.takeDamage(damage);
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
    Space *destination = gb.getSpaceAt(row, col);
    spawnGhost(destination);
}

void Game::spawnGhost(Space *destination)
{
    Ghost *newGhost = new Ghost();
    moveCharacter(newGhost, destination);
    NPCList.push_back(newGhost);
    destination->setSpawnGhost(false);
}

void Game::deleteGame()
{
    gb.deleteGameBoard();
}

bool Game::checkGameOver()
{
    if (player.getHealth() == 0)
    {
        cout << "You have run out of health! You will now become a permanent resident of this cemetary." << endl;
        return 1;
    }

    bool escaped = player.getLocation()->getSpaceType() == "fence" || player.getLocation()->getSpaceType() == "gate";
    if (sister.getFound() && escaped)
    {
        gameOver = true;
        cout << "Congratulations! You've found your sister and now you've gotten home in time for mom's spaghetti!" << endl;
        return 1;
    }
    return 0;
}

void Game::printPlayerHealth()
{
    cout << "Player health: " << player.getHealth() << endl;
}
