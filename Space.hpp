#ifndef SPACE_HPP
#define SPACE_HPP

class Space
{
private:
    Space *top;
    Space *right;
    Space *bottom;
    Space *left;

public:
    Space();
    //virtual void printSpace() = 0;
    virtual void printSpaceTop() = 0;
    virtual void printSpaceMiddle() = 0;
    virtual void printSpaceBottom() = 0;
};

#endif