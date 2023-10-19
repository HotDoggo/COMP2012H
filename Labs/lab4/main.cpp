#include <iostream>

#include "restaurant.h"

using namespace std;

int main()
{
    cout << "1. Open the restaurant!" << endl;
    Restaurant restaurant(5);
    restaurant.print();

    cout << "\n2. Try to cook a dish with only two units of fish. No chips no happiness, failed." << endl;
    restaurant.storeFish();
    restaurant.storeFish();
    restaurant.print();
    restaurant.cookDish();

    cout << "\n3. Make a dish with both fish and potatoes. Hmmm I like that, succeed." << endl;
    restaurant.storePotato();
    restaurant.print();
    restaurant.cookDish();
    restaurant.print();

    cout << "\n4. Store new fish and potato seperately." << endl;
    restaurant.storeFish();
    restaurant.storePotato();
    restaurant.print();

    cout << "\n5. Make plans about dinner time! Clone the restaurant, make a dish and then destroy the cloned restaurant." << endl;
    {
        Restaurant clonedrestaurant = restaurant;
        clonedrestaurant.print();
        clonedrestaurant.cookDish();
        clonedrestaurant.print();
    } // "clonedrestaurant" is destructed once the program runs out of this scope.

    cout << "\n6. Dinner time! Make a dish and then serve all the stored dishes." << endl;
    cout << "(State of the original restaurant)" << endl;
    restaurant.print();
    restaurant.cookDish();
    restaurant.print();
    restaurant.serveDish();

    cout << "\n7. End of the busy day! Destroy the original restaurant." << endl;
    cout << "(State of the restaurant just before destruction)" << endl;
    restaurant.print();


    return 0;
} // "restaurant" is destructed once the program runs out of this scope.
