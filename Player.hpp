#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Character.hpp"
#include "Inventory.hpp"
#include "Item.hpp"

class Player : public Character
{
private:
    Inventory inv;
    //int health;

public:
    Player();
    ~Player();
    Space* move();
    //void takeDamage(int);
    Inventory* getInventory();
    void pickUpItem(Item*);

};

#endif