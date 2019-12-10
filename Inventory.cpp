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
#include "Inventory.hpp"
#include "Item.hpp"
#include "enterToContinue.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
using std::cout;
using std::distance;
using std::endl;
using std::find;
using std::vector;

Inventory::Inventory()
{
    nItems = 0;
    maxItems = 5;
}

/********************************************************************* 
** Description: addItem adds an item to the inventory. Returns 1 if 
it was successful and returns 0 if there isn't enough room in the 
inventory to add another item.
********************************************************************/
int Inventory::addItem(Item *toAdd)
{
    int successfullyAdded;
    if (nItems < maxItems)
    {
        inventoryList.push_back(toAdd);
        nItems++;
        successfullyAdded = 1;
    }
    else
    {
        cout << "You don't have enough room in your backpack for that item! Please use \nsomething up to free up space in your backpack!" << endl;
        enterToContinue();
        successfullyAdded = 0;
    }
    return successfullyAdded;
}

/********************************************************************* 
** Description: showItems prints the contents of the inventory to the 
console.
********************************************************************/
void Inventory::showItems()
{
    int j = 1;
    for (auto it = inventoryList.begin(); it != inventoryList.end(); ++it)
    {
        Item *theItem = *it;
        cout << j << ". " << theItem->getItemName() << " " << endl;
        ++j;
    }
}

/********************************************************************* 
** Description: useItem removes the item pointed at by theItem 
pointer from the inventory and returns a pointer to it. Yes, it's a 
bit redundant.
********************************************************************/
Item *Inventory::useItem(Item *theItem)
{
    auto p = find(inventoryList.begin(), inventoryList.end(), theItem);
    inventoryList.erase(p);
    --nItems;
    return theItem;
}

/********************************************************************* 
** Description: useItem removes the item indicated by the index 
passed in as an argument to it. It returns a pointer to the removed 
item.
*********************************************************************/
Item *Inventory::useItem(int thePosition)
{
    Item *toBeReturned;
    toBeReturned = inventoryList.at(thePosition);
    removeItem(toBeReturned);
    --nItems;
    return toBeReturned;
}

/********************************************************************* 
** Description: removeItem is a helper function that removes the item 
pointed to by rmItem
*********************************************************************/
void Inventory::removeItem(Item *rmItem)
{
    auto p = find(inventoryList.begin(), inventoryList.end(), rmItem);
    inventoryList.erase(p);
}

/********************************************************************* 
** Description: findItem will return the index of the item that is 
pointed to by findItem. If it is not found in the inventory, then the 
method returns the maximum number of items possible in the inventory.
*********************************************************************/
int Inventory::findItem(Item *findItem)
{
    for (auto it = inventoryList.begin(); it != inventoryList.end(); ++it)
    {
        Item *theItem = *it;
        if (theItem == findItem)
        {
            //Use of "distance" adopted from https://thispointer.com/c-how-to-find-an-element-in-vector-and-get-its-index/
            //Accessed 12/1/2019
            int index = distance(inventoryList.begin(), it);
            return index;
        }
    }
    return maxItems;
}

/********************************************************************* 
** Description: findItem will return the index of the item that is 
described by searchString. If it is not found in the inventory, then 
the method returns the maximum number of items possible in the 
inventory.
*********************************************************************/
int Inventory::findItem(string searchString)
{
    string name;
    for (auto it = inventoryList.begin(); it != inventoryList.end(); ++it)
    {
        Item *theItem = *it;
        name = theItem->getItemName();
        if (name == searchString)
        {
            int index = distance(inventoryList.begin(), it);
            return index;
        }
    }
    return maxItems;
}

int Inventory::getNItems()
{
    return nItems;
}
int Inventory::getMaxItems()
{
    return maxItems;
}