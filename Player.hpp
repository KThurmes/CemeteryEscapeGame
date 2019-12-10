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
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Character.hpp"
#include "Inventory.hpp"
#include "Item.hpp"

class Player : public Character
{
private:
    Inventory inv;
    int health;

public:
    Player();
    ~Player();
    Space *move();
    Inventory *getInventory();
    bool hasSheet();
    bool hasKey();
    void pickUpItem(Item *);
    int interact();
    void takeDamage(int);
    int getHealth();
};

#endif