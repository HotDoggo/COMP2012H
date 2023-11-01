#include "definitions.h"
#include <cstring>

/**
 * Returns true if 2 courses have the same code (subject, code, extension).
 * You don't need to compare credits.
 */
bool equalCourses(const Course &c1, const Course &c2)
{
    return (!strcmp(c1.subject, c2.subject) && c1.code == c2.code && c1.ext == c2.ext);
}

/**
 * Iterate over student's list of enrolled courses to check if "course" is already in it.
 * You can use the equalCourse function implemented above.
 * If the course is already in the list, return true.
 */
bool isCourseEnrolled(const Student &student, const Course &course)
{
    for (int i = 0; i < student.numEnrolledCourses; i++)
    {
        if (equalCourses(course, *student.enrolledCourses[i]))
            return true;
    }
    return false;
}

/**
 * Iterate over student's list of waitlisted courses to check if "course" is already in it.
 * You can use the equalCourse function implemented above.
 * If the course is already in the list, return true.
 */
bool isCourseWaitlisted(const Student &student, const Course &course)
{
    for (int i = 0; i < student.numWaitlistCourses; i++)
    {
        if (equalCourses(course, *student.waitlistCourses[i]))
            return true;
    }
    return false;
}

/**
 * Count the number of credits the student registered, including both enrolled and waitlisted.
 */
int creditsRegistered(const Student &student)
{
    int total_credits = 0;
    for (int i = 0; i < student.numEnrolledCourses; i++)
    {
        total_credits += student.enrolledCourses[i]->credits;
    }
    for (int i = 0; i < student.numWaitlistCourses; i++)
    {
        total_credits += student.waitlistCourses[i]->credits;
    }
    return total_credits;
}

/**
 * Student registers the course, which is passed via a const pointer.
 * If the above functions are implemented correctly, the student cannot register a course that is already enrolled or waitlisted,
 * or if the student would go over the credit limit.
 *
 * Implement your code in the TODO so that the student's waitlistCourse dynamic array is modified to add the provided course.
 * Manage the dynamic allocated array and numWaitListCourse correctly.
 */
void registerCourse(Student &student, Course *const course)
{
    if (isCourseEnrolled(student, *course) || isCourseWaitlisted(student, *course))
    {
        cout << "Course is already registered." << endl;
        return;
    }

    if (creditsRegistered(student) + course->credits >= MAX_CREDITS)
    { // TODO: Change condition to if the student's total credits plus the registering course would exceed MAX_CREDITS
        cout << "Cannot enroll course, overloading is not allowed." << endl;
        return;
    }

    // TODO
    if (student.waitlistCourses == nullptr)
        student.waitlistCourses = new Course *[10];
    student.waitlistCourses[student.numWaitlistCourses] = course;
    student.numWaitlistCourses++;

    cout << "Student " << student.name << " is now in the waitlist of ";
    printCourse(*course);
    cout << endl;
}

/**
 * Student enrolls a course, which is passed via a const pointer.
 * If the above functions are implemented correctly, the student cannot enroll a course that is already enrolled,
 * or if the course is not in the waitlist yet.
 *
 * Implement your code in the TODO so that the student's enrolledCourse and waitlistCourse dynamic arrays are modified:
 * - Remove course from waitlistCourse
 * - Add course to enrolledCourse
 * Manage the dynamic memory and array sizes numEnrolledCourse, numWaitListCourse correctly.
 */
void enrollCourse(Student &student, Course *const course)
{
    if (isCourseEnrolled(student, *course))
    {
        cout << "Course is already enrolled." << endl;
        return;
    }

    if (!isCourseWaitlisted(student, *course))
    {
        cout << "Course has not been registered yet." << endl;
        return;
    }

    // TODO
    if (student.enrolledCourses == nullptr)
    {
        student.enrolledCourses = new Course *[10];
    }
    for (int i = 0; i < student.numWaitlistCourses; i++)
    {
        if (equalCourses(*course, *student.waitlistCourses[i]))
        {
            for (int j = i; j < student.numWaitlistCourses - 1; j++)
            {
                student.waitlistCourses[j] = student.waitlistCourses[j + 1];
            }
            student.numWaitlistCourses--;

            student.enrolledCourses[student.numEnrolledCourses] = course;
            student.numEnrolledCourses++;
            break;
        }
    }

    cout << "Student " << student.name << " has enrolled in ";
    printCourse(*course);
    cout << endl;
}