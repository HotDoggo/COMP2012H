#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "materials.h"
#include "dish.h"

class Restaurant
{
public:
  Restaurant(int n_storage);                                      // TODO: Type conversion constructor
  Restaurant(int n_Fishes, int n_Potatoes, int n_Dishes);         // TODO: General constructor.
  Restaurant(const Restaurant &other);                            // TODO: Copy constructor.
  ~Restaurant();                                                  // TODO: Destructor.

  void storeFish();     // TODO: Store a new unit of fish by allocating a Fish object.
  void storePotato();   // TODO: Store a new unit of potato by allocating a Potato object.
  void cookDish();      // TODO: Cook a new unit of fish-and-chips dish by allocating a Dish object,
  	  	  	  	  	    // Since the production of fish-and-chips requires both fish and potatoes,
  	  	  	  	  	    // it will consume one unit of fish and one unit of potato at the top of both storages for each dish.
  	  	  	  	  	    // The ownership of the top fish and top potato is then transferred to the dish object,
  	  	  	  	  	    // which means the Fish object and the Potato object are now pointed by the new Dish object instead.
  
  void serveDish();     // TODO: Serve all dishes in storage by deleting each of the Dish objects in dishStorage

  void print() const;   // print the Restaurant summary

private:
  Fish **fishStorage;
  Potato **potatoStorage;
  Dish **dishStorage;

  int numFish;        // Current number of fish.
  int numPotatoes;      // Current number of potatoes.
  int numDishes;        // Current number of dishes.

  int maxNumFish;     // Maximum number of fish.
  int maxNumPotatoes;   // Maximum number of potatoes.
  int maxNumDishes;     // Maximum number of dishes.
};

#endif
