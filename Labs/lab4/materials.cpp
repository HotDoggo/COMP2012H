#include "materials.h"

#include <iostream>

using namespace std;

// Fish

Fish::Fish()
{
    cout << "Fish is Constructed!" << endl;
}

Fish::Fish(const Fish &other)
{
    cout << "Fish is Copied!" << endl;
}

Fish::~Fish()
{
    cout << "Fish is Destructed." << endl;
}

// Potato

Potato::Potato()
{
    cout << "Potato is Constructed!" << endl;
}

Potato::Potato(const Potato &other)
{
    cout << "Potato is Copied!" << endl;
}

Potato::~Potato()
{
    cout << "Potato is Destructed." << endl;
}
