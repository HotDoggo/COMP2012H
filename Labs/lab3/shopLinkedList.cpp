#include "shop.h"
#include <iostream>
using namespace std;

/**
 * A Shop implemented as linked list.
 * ShopNode is a node in the linked list, with a pointer pointing to the next node in the list. If there is no next node, it should be nullptr.
 * Do NOT modify these structs, otherwise your code may not compile with the test cases.
*/
struct ShopNode {
    FoodItem item;
    ShopNode* next;
};

struct Shop {
    ShopNode* head;
};

/**
 * Create an empty shop as a dynamic instance.
 * As you learn OOP, this is equivalent to a constructor.
*/
Shop* createShop()
{
    return new Shop{nullptr};
}

/**
 * Deallocate the shop and its content.
 * As you learn OOP, this is equivalent to a destructor.
*/
void deleteShop(Shop* shop)
{
    for (ShopNode* cur = shop->head; cur != nullptr; ) {
        ShopNode* next = cur->next;
        delete cur;
        cur = next;
    }
    delete shop;
}

/**
 * Add an item to the end of the linked list.
*/
void addItem(Shop* shop, const FoodItem &item)
{
    // TODO
}

/**
 * Return true if the item exists in the shop.
*/
bool hasItem(const Shop* shop, const FoodItem &item)
{
    // TODO
}

/**
 * Remove the provided item from the shop.
 * You can use hasItem() to check if the item exists. If it does not, simply return early.
 * Manage the item counter and linked list pointers correctly. The item order is not important.
*/
void removeItem(Shop* shop, const FoodItem &item)
{
    // TODO
}

/**
 * Sort the items in the shop array according to compareFoodItems().
 * You may use any sorting algorithm you'd like, as long as the output is correct.
 * Hint: you may either swap the items in the linked list nodes, or create a new head pointer and "move" the nodes to it in order.
*/
void sort(Shop* shop)
{
    // TODO
}

/**
 * Print the items in the shop matching the provided type.
*/
void printType(const Shop* shop, FoodType type)
{
    switch (type) {
        case SNACK: cout << "SNACKS:" << endl; break;
        case MEAL: cout << "MEALS:" << endl; break;
        case DESSERT: cout << "DESSERTS:" << endl; break;
        case DRINK: cout << "DRINKS:" << endl; break;
    }
    for (ShopNode* cur = shop->head; cur != nullptr; cur = cur->next) {
        if (cur->item.type == type) {
            cout << cur->item.name << ": " << cur->item.price << " HKD" << endl;
        }
    }
}

/**
 * Print the entire menu.
*/
void printMenu(const Shop* shop)
{
    printType(shop, SNACK); cout << endl;
    printType(shop, MEAL); cout << endl;
    printType(shop, DESSERT); cout << endl;
    printType(shop, DRINK); cout << endl;
}
