#include "dish.h"

#include <iostream>

using namespace std;

// Dish

/* ===================================================
    TODO: Complete the general constructor.
          Initialize the Dish object by shallow copying the fish and potato objects.
   =================================================== */
Dish::Dish(Fish *fish, Potato *potato)
{
    this->fish = fish;
    this->potato = potato;
    // Finish constructing with printing.
    cout << "Dish is Constructed!" << endl;
}

/* ===================================================
    TODO: Complete the copy constructor.
          Deep copy the data members of the "other" dish
    HINT: Usage of a Ternary operator:
          (condition) ? (value_if_true) : (value_if_false);
   =================================================== */
Dish::Dish(const Dish &other)
{
    fish = other.fish != nullptr ? new Fish(*other.fish) : nullptr;
    potato = other.potato != nullptr ? new Potato(*other.potato) : nullptr;
    // Finish constructing with printing.
    cout << "Dish is Copied!" << endl;
}

/* ======================================   =============
    TODO: Complete the destructor.
          Destruct all the data members
   =================================================== */
Dish::~Dish()
{
    delete fish;
    delete potato;
    // Finish constructing with printing.
    cout << "Dish is Destructed." << endl;
}
