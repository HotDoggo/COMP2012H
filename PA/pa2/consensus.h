// https://rich01.com/what-is-crypto-pos-0/
// For simplicity, we assume that there is a node that specifically select the block.
#ifndef __CONSENSUS_H__
#define __CONSENSUS_H__

#include <iostream>
#include "math.h"
#include "user.h"

const int MAX_USERS = 10;
const int MAX_PROB_POOL_SIZE = MAX_USERS * MAX_DAYS;

class UserPool {
    private:
        User poolManager;
        User* users[MAX_USERS];
        unsigned int numUsers;
        User* userProbPool[MAX_PROB_POOL_SIZE];
        unsigned int poolSize;

        // Private function to be implemented
        void updateProbPool();
    
    public:
        UserPool();
        ~UserPool();

        // Provided accessor function
        unsigned int getNumUsers() const { return numUsers; }
        User* getUser(unsigned int index) const { return index < numUsers ? users[index] : nullptr; }
        User* getManager() { return &poolManager; }
        
        // To be implemented
        User* getValidator();
        void addUser(User* user);
};
#endif //__CONSENSUS_H__