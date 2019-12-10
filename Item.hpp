/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: Item is a parent class of, essentially, things that 
can be picked up. Each item has a name and a description. This class
only has getter functions.
********************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>
using std::string;

class Item
{
protected:
    string itemName;
    string description;

public:
    string getItemName();
    string getDescription();
};

#endif