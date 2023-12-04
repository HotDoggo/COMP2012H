// This function is provided to print the tree for visualizing
template <typename P>
void OpenDatabase<P>::print() const
{
    tree.print();
}

// TODO: Implement OpenDatabase's member functions
template <typename P>
unsigned int OpenDatabase<P>::getPhoneNumber(const std::string &name) const
{
    unsigned int key = hashString(name) % getCapacity();

    int index = 0;
    while (index < getCapacity())
    {
        if (tree.contains(key))
        {
            if (tree.getValue(key).person.name == name && !tree.getValue(key).deleted)
                return tree.getValue(key).person.phoneNumber;
        }

        P::offset(key, index);
    }

    return 0;
}

template <typename P>
bool OpenDatabase<P>::addPerson(const Person &person)
{
    if (getPhoneNumber(person.name))
        return false;

    unsigned int key = person.hash() % getCapacity();

    int index = 0;
    while (index < getCapacity())
    {
        if (tree.contains(key))
        {
            if (tree.getValue(key).deleted)
            {
                tree.remove(key);
                tree.insert(key, new OpenDBnode{person, false});
                return true;
            }
        }
        else
        {
            tree.insert(key, new OpenDBnode{person, false});
            return true;
        }

        P::offset(key, index);
    }

    return false;
}

template <typename P>
bool OpenDatabase<P>::removePerson(const Person &person)
{
    if (!getPhoneNumber(person.name))
        return false;

    unsigned int key = person.hash() % getCapacity();

    int index = 0;
    while (index < getCapacity())
    {
        if (tree.contains(key))
        {
            if (tree.getValue(key).person == person && !tree.getValue(key).deleted)
            {
                tree.remove(key);
                tree.insert(key, new OpenDBnode{person, true});
                return true;
            }
        }

        P::offset(key, index);
    }

    return false;
}