/********************************************************************* 
** Author: Katheen Thurmes
** Date: 27 Oct., 2019
** Description: The Exhibit class represents an exhibit at the zoo. 
Each exhibit contains only one type of animal (Tiger, Penguin, 
Turtle, etc). An exhibit contains an int to represent the number of 
animals in the exhibit, an int to represent the capacity of the 
array, and an array of pointers to animals.
*********************************************************************/

#include "Exhibit.hpp"
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Turtle.hpp"
#include "Penguin.hpp"
#include <iostream>

using std::cout;
using std::endl;

/*********************************************************************
Description: The Exhibit constructor creates an empty array of default 
animals of size 10.
*/
Exhibit::Exhibit()
{
    nAnimals = 0;
    arraySize = 10;
    exhib = new Animal *[arraySize];
}
/*********************************************************************
Description: resizeArray creates a new array with double the capacity 
of the old array. It deletes the dynamically allocated memory in the 
old array and copies all the animals in it
*/
void Exhibit::resizeArray()
{

    int newSize = arraySize * 2;

    //Create new array with double capacity
    Animal **newExhib = new Animal *[newSize];

    //Copy all animals into it
    for (int i = 0; i < nAnimals; i++)
    {
        newExhib[i] = exhib[i];
    }

    //Delete the array exhib used to point to
    delete[] exhib;

    //Reassign exhib pointer to point to new array
    exhib = newExhib;
    arraySize = newSize;
}

/*********************************************************************
Description: animalDies takes the index of an animal that has died. It 
deletes the dynamically allocated memory for the dead animal and 
redirects that pointer to point to the Animal object that was in the 
last place in the array. It also decrements the number of anials in 
the Exhibit.
*/
void Exhibit::animalDies(int index)
{

    //Overwrite dead animal by copying last animal in array into the space of the one that died
    if (nAnimals > 1)
    {
        delete exhib[index];
        exhib[index] = exhib[nAnimals - 1];
    }

    //Don't resize

    //Decrement number of animals
    nAnimals--;
}

/*********************************************************************
Description: animalDies does not take any parameters. It chooses an 
animal at random from the array of animals in the Exhibit and calls 
on animalDies(int) to kill it.
*/
void Exhibit::animalDies()
{
    srand(time(NULL));
    int nRand = (rand() % nAnimals);
    animalDies(nRand);
}

/*********************************************************************
Description: acquireAnimal takes a pointer to an animal as an 
argument and inserts the new animal into the exhibit in the last 
location in the array. It resizes the array if necessary to fit the 
new animal in.
*/
void Exhibit::acquireAnimal(Animal *newGuy)
{
    //Check to make sure another animal will fit
    if (nAnimals == arraySize)
    {
        resizeArray();
    }

    //Copy the new animal into nAnimals index of array.
    exhib[nAnimals] = newGuy;
    nAnimals++;
}

/*********************************************************************
Description: viewExhibit prints out a list of the animals in the 
Exhibit and their stats.
*/
void Exhibit::viewExhibit()
{

    cout << nAnimals << " animals in Exhibit.\n";
    cout << "Array of size " << arraySize << endl;
    ;
    Animal *steve;
    //Print each animal
    for (int i = 0; i < nAnimals; i++)
    {
        steve = exhib[i];
        cout << "Animal " << i + 1 << ":" << endl;
        cout << "Age: " << steve->getAge() << endl;
    }
}

/*********************************************************************
Description: freeTheAnimals deallocates memory from the Exhibit array.
*/
void Exhibit::freeTheAnimals()
{
    for (int i = 0; i < nAnimals; i++)
    {
        delete exhib[i];
    }
    delete[] exhib;
}

/*********************************************************************
Description: animalsAge iterates through each animal in the exhibit 
and increases their age by 1 day.
*/
void Exhibit::animalsAge()
{
    for (int i = 0; i < nAnimals; i++)
    {
        exhib[i]->ageOneDay();
    }
}

/*********************************************************************
Description: animalFoodCost returns the total food cost to feed all 
animals in the exhibit.
*/
double Exhibit::animalFoodCost()
{
    double runningTotal = 0;
    //Iterate through each animal in exhibit
    for (int i = 0; i < nAnimals; i++)
    {
        runningTotal += exhib[i]->getFoodCost();
    }
    return runningTotal;
}

/*********************************************************************
Description: animalPayoff returns the total payoff that the zoo gets 
each day due to each of the animals in the Exhibit
*/
double Exhibit::animalPayoff()
{
    double runningTotal = 0;
    //Iterate through each animal in exhibit
    for (int i = 0; i < nAnimals; i++)
    {
        runningTotal += exhib[i]->getPayoff();
    }
    return runningTotal;
}

/*********************************************************************
Description: hayAdulto returns the number of adult animals in the 
exhibit.
*/
int Exhibit::hayAdulto()
{
    int adult = 0;
    //Iterate through each animal in exhibit
    for (int i = 0; i < nAnimals; i++)
    {
        if (exhib[i]->isAdult())
        {
            adult++;
        }
    }
    return adult;
}

/*********************************************************************
Description: getnAnimals returns the number of animals in the exhibit
*/
int Exhibit::getnAnimals()
{
    return nAnimals;
}

/*********************************************************************
Description: getAnimal returns a pointer to the animal in index index 
in the exhibit
*/
Animal *Exhibit::getAnimal(int index)
{
    return exhib[index];
}