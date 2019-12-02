#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>
using std::string;

class Item{
    private:
        string itemName;
        string description;
    public:
        string getItemName();
        string getDescription() = 0;
        virtual ~Item();
};

#endif