/********************************************************************* 
** Author: Katheen Thurmes
** Date: 27 Oct., 2019
** Description: The Exhibit class represents an exhibit at the zoo. 
Each exhibit contains only one type of animal (Tiger, Penguin, 
Turtle, etc). An exhibit contains an int to represent the number of 
animals in the exhibit, an int to represent the capacity of the 
array, and an array of pointers to animals.
*********************************************************************/

#ifndef EXHIBIT_HPP
#define EXHIBIT_HPP

#include "Animal.hpp"
#include "Tiger.hpp"
#include "Turtle.hpp"
#include "Penguin.hpp"

class Exhibit
{
private:
    int nAnimals;
    int arraySize;
    Animal **exhib;
    void resizeArray();

public:
    Exhibit();
    void animalDies(int index);
    void animalDies();
    void acquireAnimal(Animal *);
    void viewExhibit();
    void freeTheAnimals();
    void animalsAge();
    double animalFoodCost();
    double animalPayoff();
    int hayAdulto();
    int getnAnimals();
    void animalBirth();
    Animal *getAnimal(int);
};

#endif