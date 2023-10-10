#include <iostream>
using namespace std;

#include "shop.h"

int main() {
    Shop* shop = createShop();

    addItem(shop, FoodItem{"French Fries", SNACK, 10});
    addItem(shop, FoodItem{"Mashed Potatoes", SNACK, 15});
    addItem(shop, FoodItem{"Biscuits", SNACK, 5});

    addItem(shop, FoodItem{"BBQ Rice", MEAL, 25});
    addItem(shop, FoodItem{"Vegetable Ramen", MEAL, 40});
    addItem(shop, FoodItem{"10-inch Pizza", MEAL, 72});
    addItem(shop, FoodItem{"Teppanyaki Rice", MEAL, 55});

    addItem(shop, FoodItem{"Ice Cream Cone", DESSERT, 5});
    addItem(shop, FoodItem{"Watermelon", DESSERT, 15});
    addItem(shop, FoodItem{"Cheesecake", DESSERT, 15});

    addItem(shop, FoodItem{"Hot Chocolate", DRINK, 10});
    addItem(shop, FoodItem{"Pepsi", DRINK, 5});
    addItem(shop, FoodItem{"Coca-Cola", DRINK, 5});
    addItem(shop, FoodItem{"Iced Coffee", DRINK, 15});

    cout << "The shop is currently selling:" << endl;
    printMenu(shop);

    sort(shop);
    cout << "The shop has re-ordered the items:" << endl;
    printMenu(shop);

    removeItem(shop, FoodItem{"Mashed Potatoes", SNACK, 15});
    removeItem(shop, FoodItem{"Hot Chocolate", DRINK, 10});
    removeItem(shop, FoodItem{"Library Book", SNACK, 20});
    addItem(shop, FoodItem{"Soft Bun", SNACK, 8});
    addItem(shop, FoodItem{"Tiramisu", DESSERT, 25});
    addItem(shop, FoodItem{"Omelette Rice", MEAL, 33});

    sort(shop);
    cout << "The shop has re-stocked:" << endl;
    printMenu(shop);

    deleteShop(shop);
}