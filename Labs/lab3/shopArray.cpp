#include "shop.h"
#include <iostream>
using namespace std;

/**
 * A Shop implemented as dynamic-length array.
 * Do NOT modify this struct, otherwise your code may not compile with the test cases.
 */
struct Shop
{
    FoodItem *items;
    int numItems;
};

/**
 * Create an empty shop as a dynamic instance.
 * As you learn OOP, this is equivalent to a constructor.
 */
Shop *createShop()
{
    return new Shop{nullptr, 0};
}

/**
 * Deallocate the shop and its content.
 * As you learn OOP, this is equivalent to a destructor.
 */
void deleteShop(Shop *shop)
{
    delete[] shop->items;
    delete shop;
}

/**
 * Add an item to the end of the dynamic array.
 */
void addItem(Shop *shop, const FoodItem &item)
{
    FoodItem *newItems = new FoodItem[shop->numItems + 1];
    for (int i = 0; i < shop->numItems; ++i)
    {
        newItems[i] = shop->items[i];
    }
    newItems[shop->numItems++] = item;
    delete[] shop->items;
    shop->items = newItems;
}

/**
 * Return true if the item exists in the shop.
 */
bool hasItem(const Shop *shop, const FoodItem &item)
{
    for (int i = 0; i < shop->numItems; ++i)
    {
        if (compareFoodItems(shop->items[i], item) == 0)
        {
            return true;
        }
    }
    return false;
}

/**
 * Remove the provided item from the shop.
 * You can use hasItem() to check if the item exists. If it does not, simply return early.
 * Manage the item counter and array size, as well as perform copying correctly. The item order is not important.
 */
void removeItem(Shop *shop, const FoodItem &item)
{
    if (!hasItem(shop, item))
    {
        return;
    }

    Shop *temp = createShop();
    for (int i = 0; i < shop->numItems; i++)
    {
        if (compareFoodItems(shop->items[i], item))
        {
            addItem(temp, shop->items[i]);
        }
    }
    delete[] shop->items;
    shop->items = temp->items;
    shop->numItems--;
    delete temp;
}

/**
 * Sort the items in the shop array according to compareFoodItems().
 * You may use any sorting algorithm you'd like, as long as the output is correct.
 */
void sort(Shop *shop)
{
    for (int i = 0; i < shop->numItems - 1; i++)
    {
        for (int j = 0; j < shop->numItems - i - 1; j++)
        {
            if (compareFoodItems(shop->items[j], shop->items[j + 1]) > 0)
            {
                FoodItem temp = shop->items[j];
                shop->items[j] = shop->items[j + 1];
                shop->items[j + 1] = temp;
            }
        }
    }
}

/**
 * Print the items in the shop matching the provided type.
 */
void printType(const Shop *shop, FoodType type)
{
    switch (type)
    {
    case SNACK:
        cout << "SNACKS:" << endl;
        break;
    case MEAL:
        cout << "MEALS:" << endl;
        break;
    case DESSERT:
        cout << "DESSERTS:" << endl;
        break;
    case DRINK:
        cout << "DRINKS:" << endl;
        break;
    }
    for (int i = 0; i < shop->numItems; ++i)
    {
        if (shop->items[i].type == type)
        {
            cout << shop->items[i].name << ": " << shop->items[i].price << " HKD" << endl;
        }
    }
}

/**
 * Print the entire menu.
 */
void printMenu(const Shop *shop)
{
    printType(shop, SNACK);
    cout << endl;
    printType(shop, MEAL);
    cout << endl;
    printType(shop, DESSERT);
    cout << endl;
    printType(shop, DRINK);
    cout << endl;
}
