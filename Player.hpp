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