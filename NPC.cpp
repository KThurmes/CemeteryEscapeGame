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
        cout << symbol << " turning clockwise" << endl;
        direction = (direction + 1) % 4;
    }
    //counter-clockwise
    else
    {
        cout << symbol << " Turning counter-clockwise" << endl;
        direction = (direction + 3) % 4;
    }
}

Space *NPC::step()
{
    //move to the next square according to which direction the character is facing.
    Space *destination;

    if (direction == 0)
    {
        //cout << symbol << " Moving up" << endl;
        destination = location->getTop();
    }
    else if (direction == 1)
    {
        //cout << symbol << " Moving right" << endl;
        destination = location->getRight();
    }
    else if (direction == 2)
    {
        //cout << symbol << " Moving down" << endl;
        destination = location->getBottom();
    }
    else
    {
        //cout << symbol << " Moving left" << endl;
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
    location->setPrintSymbol(" ");
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