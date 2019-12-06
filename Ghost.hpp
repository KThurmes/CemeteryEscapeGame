#ifndef GHOST_HPP
#define GHOST_HPP
#include "NPC.hpp"

class Ghost : public NPC
{
private:
public:
    Ghost();
    ~Ghost();
    Space *move();
    int interact();
};
#endif