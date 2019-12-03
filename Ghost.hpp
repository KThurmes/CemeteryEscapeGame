#ifndef GHOST_HPP
#define GHOST_HPP
#include "NPC.hpp"

class Ghost : public NPC
{
private:
public:
    Ghost();
    ~Ghost();
    void move();
    int interact();
};
#endif