#ifndef NPC_HPP
#define NPC_HPP
#include "Character.hpp"

class NPC: public Character{
private:
    int direction;
public:
    void turn(int);
    virtual void move()=0;
    ~NPC(){};
    void step();
};

#endif