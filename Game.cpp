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
#include "Snack.hpp"
#include "getNumberBetween.hpp"
using std::cout;
using std::endl;
using std::string;

Game::Game()
{
    //Put the player in their starting place.
    //Player *pPlayer = &player;
    moveCharacter(&player, 1, 7);

    //Set up the sister
    moveCharacter(&sister, 3, 3);

    //Give the sister the sheet to drop
    Sheet *sheet = new Sheet();
    itemList.push_back(sheet);
    sister.pickUpItem(sheet);

    //Drop the key on the gravestone
    Key *key = new Key();
    itemList.push_back(key);
    Space *gravestoneSpace = gb.getSpaceAt(6, 8);
    gravestoneSpace->setHasKey(true);
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
    }

    //Move character to somewhere else
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
    gameOver = checkGameOver();
    Space *destination;

    if (gameOver == false)
    {
        //Player makes their move
        destination = player.move();

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
            if (!sister.getFound())
            {
                destination = sister.move();
                moveCharacter(&sister, destination);
            }

            //All the other NPCs make their moves
            for (auto it = NPCList.begin(); it != NPCList.end(); ++it)
            {
                NPC *theCharacter = *it;
                destination = theCharacter->move();
                snackDrop(theCharacter);
                moveCharacter(theCharacter, destination);
            }

            setGlares();
        }

        //Check that the player isn't in a glare space. Update health if they are.
        checkGlareHit();

        //Player gets hungrier
        player.takeDamage(-1);
    }

    //print screen
    printGameBoard();
}

void Game::checkGlareHit()
{
    if (player.getLocation()->getGlare())
    {
        cout << endl
             << "Yikes! The icy glare of the undead hits you like a snowball. Try to \nremain out of sight of the ghosts!" << endl
             << endl;
        ;

        player.takeDamage(-1);
        enterToContinue();
    }
}

void Game::setGlares()
{
    //Reset all the glares
    gb.resetGlares();

    //Redraw all the glares
    int direction;
    for (auto it = NPCList.begin(); it != NPCList.end(); ++it)
    {
        NPC *theCharacter = *it;
        //If the character has a glare, then set the spaces in the direction it is facing to have glare be "true"
        //Until the glare hits an impassible space
        if (theCharacter->getGlareRay())
        {
            Space *nextSpace;
            direction = theCharacter->getDirection();
            if (direction == 0)
            {
                nextSpace = theCharacter->getLocation()->getTop();
                while (nextSpace != 0)
                {
                    nextSpace->setGlare(true);
                    if (nextSpace->getPassable())
                    {
                        nextSpace = nextSpace->getTop();
                    }
                    else
                    {
                        nextSpace = 0;
                    }
                }
            }
            else if (direction == 1)
            {
                nextSpace = theCharacter->getLocation()->getRight();
                while (nextSpace != 0)
                {
                    nextSpace->setGlare(true);
                    if (nextSpace->getPassable())
                    {
                        nextSpace = nextSpace->getRight();
                    }
                    else
                    {
                        nextSpace = 0;
                    }
                }
            }
            else if (direction == 2)
            {
                nextSpace = theCharacter->getLocation()->getBottom();
                while (nextSpace != 0)
                {
                    nextSpace->setGlare(true);
                    if (nextSpace->getPassable())
                    {
                        nextSpace = nextSpace->getBottom();
                    }
                    else
                    {
                        nextSpace = 0;
                    }
                }
            }
            else if (direction == 3)
            {
                nextSpace = theCharacter->getLocation()->getLeft();
                while (nextSpace != 0)
                {
                    nextSpace->setGlare(true);
                    if (nextSpace->getPassable())
                    {
                        nextSpace = nextSpace->getLeft();
                    }
                    else
                    {
                        nextSpace = 0;
                    }
                }
            }
        }
    }
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
    int selection;
    cout << "Would you like to use an item?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    selection = getNumberBetween(1, 2);

    if (selection == 1)
    {
        cout << "Which item would you like to use?" << endl;
        selection = getNumberBetween(1, theBackpack->getNItems());
        Item *theItem = theBackpack->useItem(selection - 1);
        if (theItem->getItemName() == "snack")
        {
            player.takeDamage(5);
            cout << "That was a yummy snack! I feel a little better!" << endl;
            //delete theItem;
        }
        else
        {
            cout << "You can't use that here!" << endl;
            theBackpack->addItem(theItem);
        }
    }
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
    if (player.getHealth() < 1)
    {
        cout << "You have run out of health! You will now become a permanent resident \nof this cemetary." << endl;
        enterToContinue();
        return 1;
    }

    bool escaped = player.getLocation()->getSpaceType() == "fence" || player.getLocation()->getSpaceType() == "gate";
    if (sister.getFound() && escaped)
    {
        gameOver = true;
        cout << "Congratulations! You've found your sister and now you've gotten home \nin time for mom's spaghetti!" << endl;
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

    int playerRow = player.getLocation()->getRow();
    int playerCol = player.getLocation()->getCol();
    boardVis[stringPosition(playerRow, playerCol, 5)] = player.getSymbol()[0];

    if (!sister.getFound())
    {
        int sisterRow = sister.getLocation()->getRow();
        int sisterCol = sister.getLocation()->getCol();
        boardVis[stringPosition(sisterRow, sisterCol, 5)] = sister.getSymbol()[0];
    }
    int charRow;
    int charCol;

    for (auto it = NPCList.begin(); it != NPCList.end(); ++it)
    {
        NPC *theCharacter = *it;
        charRow = theCharacter->getLocation()->getRow();
        charCol = theCharacter->getLocation()->getCol();
        boardVis[stringPosition(charRow, charCol, 5)] = theCharacter->getSymbol()[0];
        if (theCharacter->getGlareRay())
        {
            //If the NPC has a direction, then print out an indicator arrow for it.
            int direction = theCharacter->getDirection();
            if (direction == 0)
            {
                boardVis[stringPosition(charRow, charCol, 2)] = '^';
            }
            else if (direction == 1)
            {
                boardVis[stringPosition(charRow, charCol, 6)] = '>';
            }
            else if (direction == 2)
            {
                boardVis[stringPosition(charRow, charCol, 8)] = 'v';
            }
            else
            {
                boardVis[stringPosition(charRow, charCol, 4)] = '<';
            }
        }
    }
    return boardVis;
}

int Game::stringPosition(int row, int col, int position)
{
    int stringPosition = 0;
    int boardCol = gb.getNCols();

    int oneRow = (5 * boardCol) + 1;
    int oneRowSpaces = oneRow * 5;

    switch (position)
    {
    case 9:
        stringPosition += 1;
    case 8:
        stringPosition += 1;
    case 7:
        stringPosition += oneRow - 2;
    case 6:
        stringPosition += 1;
    case 5:
        stringPosition += 1;
    case 4:
        stringPosition += oneRow - 2;
    case 3:
        stringPosition += 1;
    case 2:
        stringPosition += 1;
    case 1:
        stringPosition += (oneRowSpaces * row) + oneRow + (5 * col) + 1;
    }
    return stringPosition;
}

void Game::snackDrop(NPC *theSnacker)
{
    Space *dropSpace = theSnacker->getLocation();
    if (!dropSpace->hasItem() && theSnacker->dropSnack())
    {
        Snack *nibble = new Snack();
        itemList.push_back(nibble);
        dropSpace->dropItem(nibble);
    }
}
