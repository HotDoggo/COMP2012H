#ifndef DISH_H
#define DISH_H

#include "materials.h"

class Dish
{
public:
  Dish(Fish *fish, Potato *potato);     // TODO: General constructor, shallow copy the fish and potato objects.
  Dish(const Dish &other);              // TODO: Copy constructor, deep copy the fish and potato objects.
  ~Dish();                              // TODO: Destructor.

private:
  Fish *fish;
  Potato *potato;
};

#endif
