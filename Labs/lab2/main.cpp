#include "functions.h"

int main()
{
    Student adam = {(char *)"Adam", 0, nullptr, 0, nullptr};
    Student eve = {(char *)"Eve", 0, nullptr, 0, nullptr};

    Course courseList[] = {
        {(char *)"COMP", 1021, '\0', 3},
        {(char *)"COMP", 2011, '\0', 3},
        {(char *)"COMP", 2012, 'H', 5},
        {(char *)"MATH", 1012, '\0', 4},
        {(char *)"MATH", 2011, '\0', 3},
        {(char *)"PHYS", 1112, '\0', 4},
        {(char *)"HUMA", 1000, 'A', 4},
        {(char *)"SOSC", 1960, '\0', 3},
        {(char *)"COMP", 4981, 'H', 6},
        {(char *)"COMP", 1029, 'V', 1},
    };

    registerCourse(adam, &courseList[0]);
    registerCourse(adam, &courseList[2]);
    registerCourse(adam, &courseList[5]);
    registerCourse(adam, &courseList[6]);
    registerCourse(adam, &courseList[0]);
    registerCourse(adam, &courseList[8]);
    enrollCourse(adam, &courseList[0]);
    enrollCourse(adam, &courseList[3]);
    enrollCourse(adam, &courseList[2]);
    enrollCourse(adam, &courseList[2]);

    printStudent(adam);

    cout << endl;

    registerCourse(eve, &courseList[0]);
    registerCourse(eve, &courseList[1]);
    registerCourse(eve, &courseList[3]);
    registerCourse(eve, &courseList[4]);
    enrollCourse(eve, &courseList[0]);
    enrollCourse(eve, &courseList[3]);
    registerCourse(eve, &courseList[7]);
    enrollCourse(eve, &courseList[7]);
    enrollCourse(eve, &courseList[4]);
    registerCourse(eve, &courseList[9]);

    printStudent(eve);

    delete[] adam.enrolledCourses;
    delete[] adam.waitlistCourses;
    delete[] eve.enrolledCourses;
    delete[] eve.waitlistCourses;
}