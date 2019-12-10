/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: Game is the main driver for the entire game. It 
keeps all the objects relating to game play together in one place.

Data members: player and sister objects, a gameboard, a list of all 
non-playable characters that appear in the game (NPCList), a list of 
all items that appear in the game (itemList), and a bool that will 
flag that the game is over.

Methods: Game has public methods to print the game board 
(printGameBoard), delete itself (deleteGame), run through one turn 
(turn), show the contents of the player's backpack 
(showBackpackContents), print a key that explains the symbols on the 
board (printBoardKey), and prints the player's health 
(printPlayerHealth).
*********************************************************************/

#include "Game.hpp"
#include "Player.hpp"
#include "GameBoard.hpp"
#include <iostream>
#include <cstdlib>
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
}

/********************************************************************* 
** Description: moveCharacter() moves a character from any Space that 
they are on and places them on the Space at the specified row and 
column on the game board.
*********************************************************************/
void Game::moveCharacter(Character *character, int row, int col)
{
    Space *theSpace = gb.getSpaceAt(row, col);
    moveCharacter(character, theSpace);
}

/********************************************************************* 
** Description: moveCharacter() moves a character from any Space that 
they are on and places them on the Space at the specified Space 
(destination) on the game board.
*********************************************************************/
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

/********************************************************************* 
** Description: printBoardGame calls a function to construct a string 
to represent the game state (buildPrintString). It prints out the 
constructed string to the terminal.
*********************************************************************/
void Game::printGameBoard()
{
    string boardVis = buildPrintString();
    cout << boardVis;
}

/********************************************************************* 
** Description: turn runs through a whole round of the game. The 
player moves first and takes any damage from running into things. 
Then the NPCs each move. Then the glares are updated in the game board.
gameOver is updated frequently throughout the method so that the game 
stops when the player runs out of health or wins the game.
*********************************************************************/
void Game::turn()
{
    Space *destination;

    if (!gameOver)
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

        if (!gameOver)
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
            //Update the spaces that are being hit by the glares of the ghosts
            setGlares();

            //Check that the player isn't in a glare space. Update health if they are.
            int glareDamage = checkGlareHit();
            player.takeDamage(glareDamage);
            gameOver = checkGameOver();

            if (!gameOver)
            {
                //Player gets hungrier
                player.takeDamage(-1);
                gameOver = checkGameOver();
            }
        }
    }

    //print screen
    printGameBoard();
}

/********************************************************************* 
** Description: checkGlareHit is a helper function that will check if 
the player has been hit with a glare during the round. It returns -1 
if the player has been hit and 0 if they haven't.
*********************************************************************/
int Game::checkGlareHit()
{
    if (player.getLocation()->getGlare())
    {
        cout << endl
             << "Yikes! The icy glare of the undead hits you like a snowball. Try to \nremain out of sight of the ghosts!" << endl
             << endl;
        enterToContinue();
        return -1;
    }
    else
    {
        return 0;
    }
}

/********************************************************************* 
** Description: setGlares is a helper function that instructs the 
gameboard to clear all its spaces of the "glare" bool using 
resetGlares. It then examines each NPC in turn and creates the glare 
beam by setting all Spaces in the glare beam to glare = true.
*********************************************************************/
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

        //Check to make sure theCharacter has a glare ray.
        if (theCharacter->getGlareRay())
        {
            Space *nextSpace;
            direction = theCharacter->getDirection();

            //construct glare ray in up direction
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
            //construct glare ray in right direction
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

            //construct glare ray in down direction
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

            //construct glare ray in left direction
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

/********************************************************************* 
** Description: interaction conducts the interaction between the 
player and an NPC. The input is a pointer to the Space where the 
player encountered an NPC.
*********************************************************************/
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
                //Interact with the character found at the location
                damage = theCharacter->interact();
            }
        }
    }

    //Update player health
    player.takeDamage(damage);
}

/********************************************************************* 
** Description: showBackpackContents displays the contents of the 
backpack and allows the player to select an item for use.
*********************************************************************/
void Game::showBackpackContents()
{
    Inventory *theBackpack = player.getInventory();
    cout << "Here is a list of items you have in your backpack:\n";
    theBackpack->showItems();
    int selection;
    if (theBackpack->getNItems() > 0)
    {
        cout << "Would you like to use an item?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        selection = getNumberBetween(1, 2);

        if (selection == 1)
        {
            cout << "Which item would you like to use (input a number)?" << endl;
            selection = getNumberBetween(1, theBackpack->getNItems());
            Item *theItem = theBackpack->useItem(selection - 1);

            //At this point, snack is really the only item that the player can elect to use.
            if (theItem->getItemName() == "snack")
            {
                player.takeDamage(5);
                cout << "That was a yummy snack! I feel a little better!" << endl;
                //don't delete the item. It exists in the itemList and will be deleted at the end.
            }
            else
            {
                cout << "You can't use that here!" << endl;
                //Put the item back
                theBackpack->addItem(theItem);
            }
        }
    }
    else
    {
        cout << endl
             << "There's nothing in your backpack! Look around for \"#\" symbols for \nthings to pick up!" << endl
             << endl;
    }
}

/********************************************************************* 
** Description: printBoardKey instructs the gameboard to print its key
*********************************************************************/
void Game::printBoardKey()
{
    gb.printKey();
}

/********************************************************************* 
** Description: spawnGhost creates a new instance of a ghost in the 
game. It adds it to the NPCList and places it in the specified Space.
*********************************************************************/
void Game::spawnGhost(int row, int col)
{
    Space *destination = gb.getSpaceAt(row, col);
    spawnGhost(destination);
}

/********************************************************************* 
** Description: spawnGhost creates a new instance of a ghost in the 
game. It adds it to the NPCList and places it in the specified Space.
*********************************************************************/
void Game::spawnGhost(Space *destination)
{
    Ghost *newGhost = new Ghost();
    moveCharacter(newGhost, destination);
    NPCList.push_back(newGhost);
    destination->setSpawnGhost(false);
}

/********************************************************************* 
** Description: deleteGame frees the memory allocated for the game 
and all its components.
*********************************************************************/
void Game::deleteGame()
{
    //Delete all the NPCs
    for (auto it = NPCList.begin(); it != NPCList.end(); ++it)
    {
        NPC *theCharacter = *it;
        delete theCharacter;
    }

    //Deete all the items
    for (auto it = itemList.begin(); it != itemList.end(); ++it)
    {
        Item *theItem = *it;
        delete theItem;
    }

    //Delete all the spaces
    gb.deleteGameBoard();
}

/********************************************************************* 
** Description: checkGameOver returns true if the game is over The 
game is over when the player has found their sister and escaped the 
graveyard or when the player has lost all health.
*********************************************************************/
bool Game::checkGameOver()
{
    //Oops you died
    if (player.getHealth() < 1)
    {
        cout << "You have run out of health! You will now become a permanent resident \nof this cemetary." << endl;
        enterToContinue();
        return 1;
    }
    //Player has won
    bool escaped = player.getLocation()->getSpaceType() == "fence" || player.getLocation()->getSpaceType() == "gate";
    if (sister.getFound() && escaped)
    {
        gameOver = true;
        cout << "Congratulations! You've found your sister and now you've gotten home \nin time for dinner!" << endl;
        enterToContinue();
        return 1;
    }

    return 0;
}

/********************************************************************* 
** Description: printPlayerHealth will print the player's health to 
the console.
*********************************************************************/
void Game::printPlayerHealth()
{
    cout << "Player health: " << player.getHealth() << endl;
}

/********************************************************************* 
** Description: buildPrintString builds and returns a string that 
represents the current game state.
*********************************************************************/
string Game::buildPrintString()
{
    //Get the board visualization without any of the Characters or items on it from the Gameboard
    string boardVis = gb.printGameBoard();

    //Place the player on the map
    int playerRow = player.getLocation()->getRow();
    int playerCol = player.getLocation()->getCol();
    boardVis[stringPosition(playerRow, playerCol, 5)] = player.getSymbol()[0];

    //Place the sister on the map
    if (!sister.getFound())
    {
        int sisterRow = sister.getLocation()->getRow();
        int sisterCol = sister.getLocation()->getCol();
        boardVis[stringPosition(sisterRow, sisterCol, 5)] = sister.getSymbol()[0];
    }

    //Place each of the NPCs on the map
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

/********************************************************************* 
** Description: stringPosition returns the index in the string of a 
specific part of a specific Space. The space is represented by row, 
column, and the space is broken into nine parts, representing the nine 
spaces in the 3x3 square. position represents the space within the 
space and the spaces are numbered as seen below.
1 2 3
4 5 6
7 8 9
*********************************************************************/
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

/********************************************************************* 
** Description: NPCs drop snacks as they go, and this helper function 
helps determine if and when they drop.
*********************************************************************/
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
