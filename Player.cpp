/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: Player is the child class of Character that is 
controlled by the user. The player inherits from Character, but also 
has additional data members and functions.
Data members include an inventory to keep track of the Items the 
player is carrying and the player's health.
Member functions include functions to determine if the player is 
carrying some key items (hasSheet and hasKey), and a takeDamage 
function in addition to the getters, setters, and inherited functions.
*********************************************************************/
#include "Player.hpp"
#include <iostream>
#include "getNumberBetween.hpp"
using std::cout;
using std::endl;

Player::Player()
{
    location = 0;
    symbol = 'x';
    health = 30;
}

Player::~Player()
{
}

/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: Player's move function gets input from the user. Like 
all of the Character move functions, it returns a pointer to the 
player's destination Space.
*********************************************************************/
Space *Player::move()
{

    cout << "In which direction would you like your player to move?" << endl;
    cout << "1. Up" << endl;
    cout << "2. Right" << endl;
    cout << "3. Down" << endl;
    cout << "4. Left" << endl;
    cout << "5. Don't move" << endl;
    int selection = getNumberBetween(1, 5);

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

/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: getInventory returns the player's inventory.
*********************************************************************/
Inventory *Player::getInventory()
{
    Inventory *pInv = &inv;
    return pInv;
}

/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: pickUpItem picks up an item and puts it in the
player's inventory.
*********************************************************************/
void Player::pickUpItem(Item *toBePickedUp)
{
    int success = inv.addItem(toBePickedUp);
    if (success == 0)
    {
        location->dropItem(toBePickedUp);
    }
}

/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: hasSheet searchs through the palyer's inventory and 
returns true if the player has the sheet.
*********************************************************************/
bool Player::hasSheet()
{
    return (inv.findItem("sheet") < inv.getMaxItems());
}

/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: hasKey searches through the player's inventory and 
returns true if the player has the key.
*********************************************************************/
bool Player::hasKey()
{
    return (inv.findItem("key") < inv.getMaxItems());
}

/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: takeDamage takes a damage amount and adds it to the 
player's health. Damage should be inputted as a negative number and 
healing should be positive.
*********************************************************************/
void Player::takeDamage(int damage)
{
    health += damage;
}

int Player::getHealth()
{
    return health;
}
