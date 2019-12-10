/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: Ghost is a child class of Character and NPC. They 
have a deathly glare and they make the people who run into them very 
hungry and cold.
********************************************************************/
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