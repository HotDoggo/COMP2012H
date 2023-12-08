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
    while (index <= getCapacity())
    {
        // cout << key << endl;
        if (tree.contains(key))
        {
            // cout << tree.getValue(key).person << ": " << tree.getValue(key).deleted << endl;
            if (tree.getValue(key).person.name == name && !tree.getValue(key).deleted)
            {
                // cout << "found" << endl;
                return tree.getValue(key).person.phoneNumber;
            }
        }

        key = (hashString(name) + P::offset(hashString(name), index)) % getCapacity();
    }

    // cout << "not found" << endl;
    return 0;
}

template <typename P>
bool OpenDatabase<P>::addPerson(const Person &person)
{
    if (getPhoneNumber(person.name))
    {
        // cout << "found" << endl;
        return false;
    }

    int index = 0;
    unsigned int key = (person.hash() + P::offset(person.hash(), index)) % getCapacity();
    while (index <= getCapacity())
    {
        // cout << key << endl;
        if (tree.contains(key))
        {
            // cout << tree.getValue(key).person << ": " << tree.getValue(key).deleted << endl;
            if (tree.getValue(key).deleted == true)
            {
                tree.getValue(key).person = person;
                tree.getValue(key).deleted = false;
                return true;
            }
        }
        else
        {
            OpenDBnode new_node{person, false};
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
    {
        // cout << "not found" << endl;
        return false;
    }

    int index = 0;
    unsigned int key = (person.hash() + P::offset(person.hash(), index)) % getCapacity();
    while (index <= getCapacity())
    {
        // cout << key << endl;
        // cout << index << endl;
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