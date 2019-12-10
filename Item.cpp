/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: Item is a parent class of, essentially, things that 
can be picked up. Each item has a name and a description. This class
only has getter functions.
********************************************************************/
#include "Item.hpp"
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

string Item::getItemName()
{
    return itemName;
}

string Item::getDescription()
{
    return description;
}