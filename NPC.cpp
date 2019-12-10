/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: NPC is a child class of Character that is not 
controlled by the user. It has a bool that determines whether the 
NPC has a death glare, it has a direction that it is facing, and it 
can carry an item.
It has getter and setter methods, but also methods to turn, to take 
a step, to disappear, to drop the item they are carrying, to 
determine whether they'll drop a snack or not, and to pick up an 
item. They also have virtual functions for moving and for 
interacting with a player.
********************************************************************/
#include "NPC.hpp"
#include <iostream>
#include "Space.hpp"
#include "Item.hpp"
#include "getRandomInt.hpp"
using std::cout;
using std::endl;

NPC::NPC()
{
    direction = getRandomInt(0, 3);
    carriedItem = 0;
}

/********************************************************************* 
** Description: turn turns the NPC 90 degrees either clockwise or 
counter-clockwise. 0 is clockwise, 1 is counter-clockwise.
********************************************************************/
void NPC::turn(int directionToTurn)
{
    //0 is clockwise rotation, 1 is counter-clockwise
    if (directionToTurn == 0)
    {
        direction = (direction + 1) % 4;
    }
    //counter-clockwise
    else
    {
        direction = (direction + 3) % 4;
    }
}

/********************************************************************* 
** Description: step returns the next space in the direction that 
the NPC is facing.
********************************************************************/
Space *NPC::step()
{
    //move to the next square according to which direction the character is facing.
    Space *destination;

    if (direction == 0)
    {
        destination = location->getTop();
    }
    else if (direction == 1)
    {
        destination = location->getRight();
    }
    else if (direction == 2)
    {
        destination = location->getBottom();
    }
    else
    {
        destination = location->getLeft();
    }

    //Make sure there isn't anything in the way
    if (destination != 0)
    {
        if (!destination->getHasCharacter())
        {
            if (destination->getPassable())
            {
                return destination;
            }
            else
            {
                turn(0);
                return location;
            }
        }
        else
        {
            turn(0);
            return location;
        }
    }
    else
    {
        turn(0);
        return location;
    }
}

/********************************************************************* 
** Description: disappear removes the NPC from the board.
********************************************************************/
void NPC::disappear()
{
    location->setHasCharacter(false);
    location = 0;
}

/********************************************************************* 
** Description: pickUpItem essentially is a setter function for the 
carriedItem member
********************************************************************/
void NPC::pickUpItem(Item *theItem)
{
    carriedItem = theItem;
}

/********************************************************************* 
** Description: dropItem has the NPC drop their carriedItem onto the 
Space that they have set as their location.
********************************************************************/
void NPC::dropItem()
{
    Item *theItem = carriedItem;
    carriedItem = 0;
    location->dropItem(theItem);
}

bool NPC::getGlareRay()
{
    return glareRay;
}

int NPC::getDirection()
{
    return direction;
}

/********************************************************************* 
** Description: dropSnack returns a random number that will be used 
to determine whether the NPC has dropped a snack on the floor or not.
********************************************************************/
bool NPC::dropSnack()
{
    int random = getRandomInt(1, 3);
    return (random < 2);
}