/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: Fence is a child class of Space. It is initially 
impassible, but can be rendered passible with the use of a sheet.
*********************************************************************/

#ifndef FENCE_HPP
#define FENCE_HPP
#include "Space.hpp"
#include "Inventory.hpp"
#include <string>
using std::string;
class Fence : public Space
{
private:
public:
    Fence();
    ~Fence();
    string printSpaceTop();
    string printSpaceMiddle();
    string printSpaceBottom();
    void interact(Inventory *);
};
#endif