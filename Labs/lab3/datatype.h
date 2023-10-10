#ifndef __DATATYPES_H__
#define __DATATYPES_H__

#include <cstring>

enum FoodType { SNACK, MEAL, DESSERT, DRINK };

struct FoodItem {
    const char* name;
    FoodType type;
    int price;
};

int compareFoodItems(const FoodItem& item1, const FoodItem& item2);

#endif // __DATATYPES_H__