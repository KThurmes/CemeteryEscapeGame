/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: Gate is a child class of Space. It represents an 
impassible space that can become passible if the player has a key in 
their inventory when they interact with it.
*********************************************************************/

#ifndef GATE_HPP
#define GATE_HPP
#include "Space.hpp"
#include "Inventory.hpp"
#include <string>
using std::string;
class Gate : public Space
{
private:
public:
    Gate();
    ~Gate();
    string printSpaceTop();
    string printSpaceMiddle();
    string printSpaceBottom();
    void interact(Inventory *);
};
#endif