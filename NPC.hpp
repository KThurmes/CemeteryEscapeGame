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
#ifndef NPC_HPP
#define NPC_HPP
#include "Character.hpp"
#include "Item.hpp"

class NPC : public Character
{
protected:
    int direction;
    Item *carriedItem;
    bool glareRay;

public:
    NPC();
    void pickUpItem(Item *);
    virtual Space *move() = 0;
    void turn(int);
    ~NPC(){};
    Space *step();
    virtual int interact() = 0;
    void disappear();
    void dropItem();
    bool getGlareRay();
    int getDirection();
    bool dropSnack();
};

#endif