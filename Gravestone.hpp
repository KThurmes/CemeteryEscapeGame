#ifndef GRAVESTONE_HPP
#define GRAVESTONE_HPP
#include "Space.hpp"
class Gravestone : public Space
{
private:
    bool knockedOver;

public:
    Gravestone();
    ~Gravestone();
    void printSpaceTop();
    void printSpaceMiddle();
    void printSpaceBottom();
    void interact();
};
#endif