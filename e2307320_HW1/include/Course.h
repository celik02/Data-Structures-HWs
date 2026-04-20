// Course uses *composition*: it owns an array of Student pointers.
// "Has-a" relationships (a Course has Students) are modeled this way in OOP,
// as opposed to inheritance which models "is-a" relationships.

#ifndef COURSE_H
#define COURSE_H

#include "Student.h"


class Course
{
    public:
        Course(void);
        int getNum(void);
        // Takes ownership of a heap-allocated Student (pointer is stored, not a copy)
        void addNewStudent(Student *student_);
        // Propagates new weights to both the Course and every enrolled Student
        void updateWeigths(int weightQ_, int weightHW_, int weightF_);

        // Function overloading — same name, different parameter signatures.
        // The compiler picks the correct version based on the argument type at the call site.
        Student *getStudentInfo(int student_id);  // look up by ID → one pointer
        Student **getStudentInfo();               // no args → the whole pointer array

        // Returns a heap-allocated float[4]; caller is responsible for delete[]
        float* calculateAverage(void);

    private:
        // Array of *pointers* — each element stores an address of a Student on the heap.
        // Student* students[10] is 10 slots of addresses; actual objects live elsewhere.
        Student *students[10];
        int num = 0;
        // Course-level weights are the authoritative source; Student weights mirror these.
        int weightQ = 30;
        int weightHW = 30;
        int weightF = 40;
};

#endif // COURSE_H
