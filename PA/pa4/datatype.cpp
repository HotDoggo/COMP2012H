#include "datatype.h"

unsigned int hashString(std::string str) {
	int sum = 0;
	for (unsigned int i = 0; i < str.length(); ++i)
		sum = sum + static_cast<int>(str[i]);
	return sum % HASH_MODULO; 
}

std::ostream& operator<<(std::ostream& os, const Person& person)
{
    os << person.name;
    return os;
}

bool Directory::addPerson(const Person& person)
{
    return database->addPerson(person);
}

bool Directory::removePerson(const Person& person)
{
    return database->removePerson(person);
}

unsigned int Directory::getPhoneNumber(const std::string& name) const
{
    return database->getPhoneNumber(name);
}

void Directory::print() const
{
    database->print();
}
