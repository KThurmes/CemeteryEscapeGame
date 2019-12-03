#include "Player.hpp"
#include <iostream>
#include "getNumberBetween.hpp"
using std::cout;
using std::endl;

Player::Player()
{
    location = 0;
    symbol = 'x';
    health = 5;
}

Player::~Player()
{
}

Space *Player::move()
{
    cout << "In which direction would you like your player to go?" << endl;
    cout << "0: Up" << endl;
    cout << "1: Right" << endl;
    cout << "2: Down" << endl;
    cout << "3: Left" << endl;
    cout << "4: Don't move" << endl;

    int selection = getNumberBetween(0, 4);

    Space *destination;

    if (selection == 0)
    {
        //check up
        destination = location->getTop();
    }

    else if (selection == 1)
    {
        //check right
        destination = location->getRight();
    }

    else if (selection == 2)
    {
        //check down
        destination = location->getBottom();
    }

    else if (selection == 3)
    {
        //check left
        destination = location->getLeft();
    }
    else
    {
        return location;
    }

    if (destination != 0)
    {
        Inventory *inventory = &inv;
        //Make sure the space is passable
        if (!destination->getPassable())
        {
            destination->interact(inventory);
            return 0;
        }
        //If there's a character there already, don't move.
        else if (destination->getHasCharacter())
        {
            cout << "There's another character there!" << endl;
            return destination;
        }
        else
        {
            setLocation(destination);
            return 0;
        }
    }
    else
    {
        cout << "Cannot go in that direction!" << endl;
        return move();
    }
}

Inventory *Player::getInventory()
{
    Inventory *pInv = &inv;
    return pInv;
}

void Player::pickUpItem(Item *toBePickedUp)
{
    int success = inv.addItem(toBePickedUp);
    if (success == 0)
    {
        location->dropItem(toBePickedUp);
    }
}

bool Player::hasSheet()
{
    return (inv.findItem("sheet") < inv.getMaxItems());
}

bool Player::hasKey()
{
    return (inv.findItem("key") < inv.getMaxItems());
}

void Player::takeDamage(int damage)
{
    health += damage;
}

int Player::getHealth()
{
    return health;
}

bool Player::getPastFence()
{
    return pastFence;
}

void Player::setPastFence(bool past)
{
    pastFence = past;
}