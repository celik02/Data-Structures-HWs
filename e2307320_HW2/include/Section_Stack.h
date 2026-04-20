// STACK — Last In, First Out (LIFO).
// Think of a stack of plates: you can only add or remove from the top.
// Here the "top" is tracked by student_count (the index of the next free slot).
//
//   push: add to top   → student_pointer[student_count] = item; student_count++
//   pop:  remove from top → student_count--; return student_pointer[student_count]

#ifndef SECTION_STACK_H
#define SECTION_STACK_H

#include "Student.h"


class Section_Stack
{
    public:
        Section_Stack(int capacity);
        int push_student(Student* student);  // add student to the top; returns new count

        Student* pop_student(void);          // remove and return the student at the top

        int num_of_studentEnrolled(void);
        bool isFull(void);
        virtual ~Section_Stack();

    private:
        int sec_capacity;         // maximum number of students allowed
        Student* student_pointer; // heap-allocated array used as the stack storage
        int student_count;        // current number of elements (also the index of the "top + 1")

};

#endif // SECTION_STACK_H
