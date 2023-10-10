#ifndef __SHOP_H__
#define __SHOP_H__

#include "datatype.h"

struct Shop;

Shop* createShop();
void deleteShop(Shop* shop);

void addItem(Shop* shop, const FoodItem& item);
bool hasItem(const Shop* shop, const FoodItem& item);
void removeItem(Shop* shop, const FoodItem& item);

void sort(Shop* shop);
void printType(const Shop* shop, FoodType type);
void printMenu(const Shop* shop);

#endif // __SHOP_H__