#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>
using std::string;

class Space
{
protected:
    Space *top;
    Space *right;
    Space *bottom;
    Space *left;
    bool hasCharacter;
    bool passable;
    string printSymbol;

public:
    Space();
    virtual void printSpaceTop() = 0;
    virtual void printSpaceMiddle() = 0;
    virtual void printSpaceBottom() = 0;
    virtual ~Space(){};
    void setTop(Space *);
    void setRight(Space *);
    void setBottom(Space *);
    void setLeft(Space *);
    void setHasCharacter(bool);
    void setPrintSymbol(string);
};

#endif