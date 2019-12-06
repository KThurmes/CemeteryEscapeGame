#ifndef SISTER_HPP
#define SISTER_HPP
#include "NPC.hpp"

class Sister : public NPC
{

private:
    bool found;

public:
    Sister();
    ~Sister();
    Space *move();
    bool getFound();
    int interact();
};

#endif
