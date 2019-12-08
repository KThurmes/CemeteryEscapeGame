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
#include <string>
#include "enterToContinue.hpp"
using std::cout;
using std::endl;
using std::string;

Game::Game()
{
    //Put the player in their starting place.
    Player *pPlayer = &player;
    moveCharacter(pPlayer, 1, 7);

    //Set up the sister
    moveCharacter(&sister, 3, 3);

    //Give the sister the sheet to drop
    Sheet *sheet = new Sheet();
    itemList.push_back(sheet);
    sister.pickUpItem(sheet);

    //Drop the key on the gravestone
    Key *key = new Key();
    itemList.push_back(key);
    //Horrible coding, but the gravestone already has the hasKey flag set.
    Space *gravestoneSpace = gb.getSpaceAt(6, 8);
    gravestoneSpace->dropItem(key);

    //Create starter Ghosts
    Ghost *newGhost1 = new Ghost();
    Ghost *newGhost2 = new Ghost();
    moveCharacter(newGhost1, 1, 1);
    moveCharacter(newGhost2, 3, 10);
    NPCList.push_back(newGhost1);
    NPCList.push_back(newGhost2);

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
    string boardVis = buildPrintString();
    cout << boardVis;
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
            player.discoverSpaces();
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
        if (!sister.getFound())
        {
            destination = sister.move();
            moveCharacter(&sister, destination);
        }

        for (auto it = NPCList.begin(); it != NPCList.end(); ++it)
        {
            NPC *theCharacter = *it;
            destination = theCharacter->move();
            moveCharacter(theCharacter, destination);
        }
    }
    //print screen
    printGameBoard();
}

void Game::interaction(Space *location)
{
    //Search Character* list for which character is at the given location.
    int damage = 0;
    //Check to see if it's the sister
    if (sister.getLocation() == location)
    {
        damage = sister.interact();
    }
    //If not, see what other character is there.
    else
    {
        for (auto it = NPCList.begin(); it != NPCList.end(); ++it)
        {
            NPC *theCharacter = *it;
            if (theCharacter->getLocation() == location)
            {
                //Interact with the character at the location
                damage = theCharacter->interact();
            }
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
    for (auto it = NPCList.begin(); it != NPCList.end(); ++it)
    {
        NPC *theCharacter = *it;
        delete theCharacter;
    }

    for (auto it = itemList.begin(); it != itemList.end(); ++it)
    {
        Item *theItem = *it;
        delete theItem;
    }

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
        enterToContinue();
        return 1;
    }
    return 0;
}

void Game::printPlayerHealth()
{
    cout << "Player health: " << player.getHealth() << endl;
}

string Game::buildPrintString()
{
    string boardVis = gb.printGameBoard();
    return boardVis;
}