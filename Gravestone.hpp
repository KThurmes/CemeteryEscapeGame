/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: Gravestone is a child class of Space. It is initially 
impassible, but can be rendered passible if the player wiggles it a 
bit. However, when it is wiggled, it sets the spawnGhost flag to true 
and that can be used to trigger the spawning of a new Ghost
*********************************************************************/
#ifndef GRAVESTONE_HPP
#define GRAVESTONE_HPP
#include "Space.hpp"
#include "Inventory.hpp"
#include <string>
using std::string;
class Gravestone : public Space
{
private:
    bool cleaned;
    string engraving;

public:
    Gravestone();
    ~Gravestone();
    string printSpaceTop();
    string printSpaceMiddle();
    string printSpaceBottom();
    void interact(Inventory *);
    void setEngraving(string);
};
#endif