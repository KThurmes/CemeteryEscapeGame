#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include "Item.hpp"
#include <string>
#include <vector>
using std::string;
using std::vector;


class Inventory{
    private:
        vector<Item*> inventoryList;//###TODO: if i have time, change to list
        int nItems;
        int maxItems;

    public:
        Inventory();
        int addItem(Item*);
        void showItems();
        Item* useItem(Item*);
        Item* useItem(int);
        void removeItem(Item*);
        int findItem(Item*);
        int findItem(string);
        int getNItems();
        int getMaxItems();
};

#endif