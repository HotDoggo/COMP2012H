#include <iostream>
using namespace std;

const int MAX_CREDITS = 18;

struct Course {
    char* subject;
    int code;
    char ext;
    int credits;
};

struct Student {
    char* name;

    int numEnrolledCourses;
    Course** enrolledCourses;
    int numWaitlistCourses;
    Course** waitlistCourses;
};

void printCourse(const Course& course) {
    cout << course.subject << course.code;
    if (course.ext)
        cout << course.ext;
}

void printStudent(const Student& student) {
    cout << "Student name: " << student.name << endl;
    cout << "Enrolled courses: " << endl;
    for (int i=0; i<student.numEnrolledCourses; ++i) {
        printCourse(*student.enrolledCourses[i]);
        cout << endl;
    }
    cout << "Waitlisting courses: " << endl;
    for (int i=0; i<student.numWaitlistCourses; ++i) {
        printCourse(*student.waitlistCourses[i]);
        cout << endl;
    }
}