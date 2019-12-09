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