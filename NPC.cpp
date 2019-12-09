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

void NPC::disappear()
{
    location->setHasCharacter(false);
    location = 0;
}

void NPC::pickUpItem(Item *theItem)
{
    carriedItem = theItem;
}

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

bool NPC::dropSnack()
{
    int random = getRandomInt(1, 3);
    return (random < 2);
}