#include "restaurant.h"

#include <iostream>
#include <iomanip>
using namespace std;

/* ===================================================
    TODO: Complete the type conversion constructor.
          Here we assume to allocate same storage of size *n_storage* for fish, potatoes and dishes.
          Try to add only one extra line of code!
    HINT: Reuse the general constuctor we define below.
   =================================================== */
Restaurant::Restaurant(int n_storage) : Restaurant(n_storage, n_storage, n_storage)
{
    // Finish constructing with printing.
    cout << "By using the conversion constructor!" << endl;
}

/* ===================================================
    TODO: Complete the general constructor
          numFish, numPotatoes, numDishes should be initialized to be 0
          maxNumFish, maxNumPotatoes, maxNumDishes should be initialized to their assigned values
   =================================================== */
Restaurant::Restaurant(int n_Fishes, int n_Potatoes, int n_Dishes) : numFish(0), numPotatoes(0), numDishes(0), maxNumFish(n_Fishes), maxNumPotatoes(n_Potatoes), maxNumDishes(n_Dishes)
{
    // TODO: Allocate memory for fishStorage, potatoStorage and dishStorage here.
    fishStorage = new Fish *[n_Fishes];
    potatoStorage = new Potato *[n_Potatoes];
    dishStorage = new Dish *[n_Dishes];
    // Finish constructing with printing.
    cout << "Restaurant is Constructed!" << endl;
}

/* ===================================================
    TODO: Complete the copy constructor
          Deep copy all data members of another restaurant
   =================================================== */
Restaurant::Restaurant(const Restaurant &other) : numFish(other.numFish), numPotatoes(other.numPotatoes), numDishes(other.numDishes), maxNumFish(other.maxNumFish), maxNumPotatoes(other.maxNumPotatoes), maxNumDishes(other.maxNumDishes), fishStorage(new Fish *[other.maxNumFish]), potatoStorage(new Potato *[other.maxNumPotatoes]), dishStorage(new Dish *[other.maxNumDishes])
{
    for (int i = 0; i < other.numFish; i++)
    {
        fishStorage[i] = new Fish(*other.fishStorage[i]);
    }
    for (int i = 0; i < other.numPotatoes; i++)
    {
        potatoStorage[i] = new Potato(*other.potatoStorage[i]);
    }
    for (int i = 0; i < other.numDishes; i++)
    {
        dishStorage[i] = new Dish(*other.dishStorage[i]);
    }
    // Finish copying with printing.
    cout << "Restaurant is Copied!" << endl;
}

/* ===================================================
    TODO: Complete the destructor
   =================================================== */
Restaurant::~Restaurant()
{
    for (int i = 0; i < numFish; i++)
    {
        delete fishStorage[i];
    }
    delete[] fishStorage;
    for (int i = 0; i < numPotatoes; i++)
    {
        delete potatoStorage[i];
    }
    delete[] potatoStorage;
    for (int i = 0; i < numDishes; i++)
    {
        delete dishStorage[i];
    }
    delete[] dishStorage;
    // Finish destructing with printing.
    cout << "Restaurant is Destructed." << endl;
}

void Restaurant::storeFish()
{
    if (numFish >= maxNumFish)
    {
        cout << "Error: Fish storage is full, store failed." << endl;
    }
    else
    {
        fishStorage[numFish++] = new Fish();
    }
}

void Restaurant::storePotato()
{
    if (numPotatoes >= maxNumPotatoes)
    {
        cout << "Error: Potato storage is full, store failed." << endl;
    }
    else
    {
        potatoStorage[numPotatoes++] = new Potato();
    }
}

void Restaurant::cookDish()
{
    if (numDishes >= maxNumDishes)
    {
        cout << "Error: Dish storage is full, cook failed." << endl;
    }
    else if (numPotatoes < 1 || numFish < 1)
    {
        cout << "Error: Not enough materials for cooking a Dish" << endl;
    }
    else
    {
        /* ===================================================
            TODO: Cook a unit of dish by using fish and potato objects.
            Since the production of fish-and-chips requires both fish and potatoes,
            it will consume one unit of fish and one unit of potato at the top of both storages for each dish.
            The ownership of the top fish and top potato is then transferred to the dish object,
            which means the Fish object and the Potato object are now pointed by the new Dish object instead.
           =================================================== */
        Fish *fish = fishStorage[--numFish];
        Potato *potato = potatoStorage[--numPotatoes];
        dishStorage[numDishes++] = new Dish(fish, potato);
    }
}

void Restaurant::serveDish()
{
    for (int i = 0; i < numDishes; i++)
    {
        delete dishStorage[i];
    }
    numDishes = 0;
}

void Restaurant::print() const
{
    cout << "----------------------" << endl;
    cout << "| Restaurant Summary |" << endl;
    cout << "----------------------" << endl;
    cout << "|" << setw(8) << "Fish" << setw(7) << "(" << numFish << "/" << maxNumFish << ") |" << endl;
    cout << "|" << setw(8) << "Potato" << setw(7) << "(" << numPotatoes << "/" << maxNumPotatoes << ") |" << endl;
    cout << "|" << setw(8) << "Dish" << setw(7) << "(" << numDishes << "/" << maxNumDishes << ") |" << endl;
    cout << "----------------------" << endl;
}
