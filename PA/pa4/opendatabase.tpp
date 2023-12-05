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
    int index = 0;
    unsigned int key = (hashString(name) + P::offset(hashString(name), index)) % getCapacity();

    while (index < getCapacity())
    {
        if (tree.contains(key))
        {
            if (tree.getValue(key).person.name == name && !tree.getValue(key).deleted)
                return tree.getValue(key).person.phoneNumber;
        }

        key = (hashString(name) + P::offset(hashString(name), index)) % getCapacity();
    }

    return 0;
}

template <typename P>
bool OpenDatabase<P>::addPerson(const Person &person)
{
    if (getPhoneNumber(person.name))
        return false;

    int index = 0;
    unsigned int key = (person.hash() + P::offset(person.hash(), index)) % getCapacity();
    OpenDBnode new_node{person, false};
    while (index < getCapacity())
    {
        // cout << key << endl;
        if (tree.contains(key))
        {
            if (tree.getValue(key).deleted == true)
            {
                tree.getValue(key).deleted = false;
                return true;
            }
        }
        else
        {
            tree.insert(key, new_node);
            return true;
        }

        key = (person.hash() + P::offset(person.hash(), index)) % getCapacity();
    }

    return false;
}

template <typename P>
bool OpenDatabase<P>::removePerson(const Person &person)
{
    if (!getPhoneNumber(person.name))
        return false;

    int index = 0;
    unsigned int key = (person.hash() + P::offset(person.hash(), index)) % getCapacity();
    while (index < getCapacity())
    {
        if (tree.contains(key))
        {
            if (tree.getValue(key).person == person && !tree.getValue(key).deleted)
            {
                tree.getValue(key).deleted = true;
                return true;
            }
        }

        key = (person.hash() + P::offset(person.hash(), index)) % getCapacity();
    }

    return false;
}