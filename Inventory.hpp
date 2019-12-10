/********************************************************************* 
** Author: Katheen Thurmes
** Date: 9 Dec., 2019
** Description: Inventory is the class used to cllect and contain a 
list of items that the player is carrying in her backpack. It has a 
maximum number of items that it can hold and it keeps trak of how 
many items are currently being carried in it. It has methods for 
adding items, listing the contents of the inventory, removing items
from the list, and finding items in the list by name and by pointer.
********************************************************************/
#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include "Item.hpp"
#include <string>
#include <vector>
using std::string;
using std::vector;

class Inventory
{
private:
    vector<Item *> inventoryList;
    int nItems;
    int maxItems;

public:
    Inventory();
    int addItem(Item *);
    void showItems();
    Item *useItem(Item *);
    Item *useItem(int);
    void removeItem(Item *);
    int findItem(Item *);
    int findItem(string);
    int getNItems();
    int getMaxItems();
};

#endif