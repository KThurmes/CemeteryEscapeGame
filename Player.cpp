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

    cout << "In which direction would you like your player to move?" << endl;
    cout << "1. Up" << endl;
    cout << "2. Right" << endl;
    cout << "3. Down" << endl;
    cout << "4. Left" << endl;
    cout << "5. Don't move" << endl;
    int selection = getNumberBetween(1, 5);

    //Space *destination;
    if (selection == 1)
    {
        //check up
        return location->getTop();
    }

    else if (selection == 2)
    {
        //check right
        return location->getRight();
    }

    else if (selection == 3)
    {
        //check down
        return location->getBottom();
    }

    else if (selection == 4)
    {
        //check left
        return location->getLeft();
    }
    else
    {
        return location;
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

void Player::discoverSpaces()
{
    location->discover();
    if (location->getTop() != 0)
    {
        location->getTop()->discover();
    }
    if (location->getRight() != 0)
    {
        location->getRight()->discover();
    }
    if (location->getBottom() != 0)
    {
        location->getBottom()->discover();
    }
    if (location->getLeft() != 0)
    {
        location->getLeft()->discover();
    }
}
