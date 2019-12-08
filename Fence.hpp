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
    void changeToDefaultSymbol();
};
#endif