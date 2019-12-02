#ifndef NPC_HPP
#define NPC_HPP
#include "Character.hpp"
#include "Item.hpp"

class NPC: public Character{
private:
    int direction;
    Item* carriedItem;
public:
    void pickUpItem(Item*);
    virtual void move() = 0;
    void turn(int);
    ~NPC(){};
    void step();
    virtual int interact() = 0;
    void disappear();
    void dropItem();
};

#endif