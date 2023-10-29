#include <cstring>
#include <string>
#include "timestamp.h"

/**
 * The following function returns "the current time".
 * This is needed to ensure the program is consistent for testing.
 */
unsigned long long next_time = 1448164138;
unsigned long long time_pseudo()
{
    next_time = next_time + 60 * 60 * 24 + 12;
    return next_time;
}

/**
 * Construct the Timestamp instance.
 * Initialize all data members to 0.
 */
Timestamp::Timestamp() : hour(0), minute(0), second(0)
{
}

/**
 * Update the current time.
 *
 * You need to use time_pseudo() to get the "current" unix time and
 * assign it to unix_time. Then you need to calculate the hour,
 * minute and second based on the unix_time.
 */
void Timestamp::updateTime()
{
    unix_time = time_pseudo();
    hour = unix_time % (60 * 60 * 24) % 60;
    minute = unix_time % (60 * 60 * 24) / 60 % 60;
    second = unix_time % (60 * 60 * 24) / (60 * 60);
}

/**
 * Return the current time as a dynamic-allocated C-string.
 *
 * For example, if the time is 12:34:56, the string should be 12-34-56,
 * and if the time is 1:2:3, the string should be 01-02-03.
 *
 * Feel free to use any library functions from cstring or to write your own helper function.
 *
 * @return the string in "hh-mm-ss" format
 */
char *Timestamp::getTime() const
{
    char *temp = new char;
    sprintf(temp, "%02d-%02d-%02d", hour, minute, second);
    return temp;
}