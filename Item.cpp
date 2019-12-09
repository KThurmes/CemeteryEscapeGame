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