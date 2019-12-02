#ifndef NPC_HPP
#define NPC_HPP
#include "Character.hpp"

class NPC: public Character{
private:
    int direction;
public:
    virtual void move() = 0;
    void turn(int);
    ~NPC(){};
    void step();
    virtual int interact() = 0;
    void disappear();
};

#endif