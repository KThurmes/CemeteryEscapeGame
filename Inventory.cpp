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

int Inventory::addItem(Item *toAdd)
{
    int successfullyAdded;
    if (nItems < maxItems)
    {
        inventoryList.push_back(toAdd);
        successfullyAdded = 1;
    }
    else
    {
        cout << "You don't have enough room in your backpack for that item! Please use something up to free up space in your backpack!" << endl;
        enterToContinue();
        successfullyAdded = 0;
    }
    return successfullyAdded;
}

void Inventory::showItems()
{

    for (auto it = inventoryList.begin(); it != inventoryList.end(); ++it)
    {
        Item *theItem = *it;
        cout << theItem->getItemName() << " " << endl;
    }
}

Item *Inventory::useItem(Item *theItem)
{
    auto p = std::find(inventoryList.begin(), inventoryList.end(), theItem);
    inventoryList.erase(p);
    return theItem;
}

Item *Inventory::useItem(int thePosition)
{
    Item *toBeReturned;
    toBeReturned = inventoryList.at(thePosition);
    removeItem(toBeReturned);
    return toBeReturned;
}

void Inventory::removeItem(Item *rmItem)
{
    auto p = std::find(inventoryList.begin(), inventoryList.end(), rmItem);
    inventoryList.erase(p);
}

int Inventory::findItem(Item *findItem)
{
    for (auto it = inventoryList.begin(); it != inventoryList.end(); ++it)
    {
        Item *theItem = *it;
        if (theItem == findItem)
        {
            int index = distance(inventoryList.begin(), it);
            return index;
        }
    }
    return maxItems;
}

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