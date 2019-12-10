/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: Sister is a child class of Character and NPC. The 
sister inherits from Character, but also has an additional data member
and function.
The additional data member is the found boolean which is a flag for 
sister having been found. The additional member function is simply a 
getter for found.
*********************************************************************/
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
