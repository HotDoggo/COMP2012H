#include <cstring>
#include "consensus.h"

/**
 * Construct the class UserPool.
 *
 * Initialize poolManager with the name "Pool", e = 19, d = 115, N = 2279.
 * The arrays need to be initialized to be all nullptr.
 * Set numUsers and poolSize to 0.
 */
UserPool::UserPool() : poolManager("Pool", 19, 115, 2279), users{nullptr}, userProbPool{nullptr}, numUsers(0), poolSize(0)
{
}

/**
 * Destory the class UserPool.
 *
 * Delete every element in the users array. As userProbPool only contains pointers to existing users,
 * it does not need to be deleted.
 */
UserPool::~UserPool()
{
    for (int i = 0; i < numUsers; i++)
    {
        delete users[i];
    }
}

/**
 * Add a user to the pool at index numUsers. Checking if there is space left is optional
 * since main.cpp already checks if numUsers < MAX_USERS, as long as
 * you manage that variable correctly.
 */
void UserPool::addUser(User *user)
{
    users[numUsers++] = user;
}

/**
 * Get the validator based on some naive random methods.
 *
 * First, use updateProbPool() to set the userProbPool. Then use randomPA2()
 * to generate a random number between 0 and poolSize (exclusive).
 * Use that random number as index into the userProbPool array to choose the validator, then reset his days at stake.
 * Then update the stake days of all other users. Finally, return the validator.
 */
User *UserPool::getValidator()
{
    updateProbPool();
    int random_number = randomPA2(0, poolSize);
    userProbPool[random_number]->resetDays();

    for (int i = 0; i < numUsers; i++)
        users[i]->updateDays();

    return userProbPool[random_number];
}

/**
 * Update the userProbPool to prepare for the validator selection.
 *
 * At first set the poolSize to 0. Then for each user, add the name
 * of the user to the userProbPool for getDays() times. Remember to
 * update the poolSize.
 */
void UserPool::updateProbPool()
{
    poolSize = 0;
    for (int i = 0; i < numUsers; i++)
    {
        for (int j = 0; j < users[i]->getDays(); j++)
        {
            userProbPool[poolSize++] = users[i];
        }
    }
}
