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
};

#endif