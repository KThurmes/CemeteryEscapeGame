#ifndef FENCE_HPP
#define FENCE_HPP
#include "Space.hpp"
#include "Inventory.hpp"
class Fence : public Space
{
private:
public:
    Fence();
    ~Fence();
    void printSpaceTop();
    void printSpaceMiddle();
    void printSpaceBottom();
    void interact(Inventory *);
};
#endif