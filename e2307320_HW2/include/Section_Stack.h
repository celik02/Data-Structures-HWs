#ifndef SECTION_STACK_H
#define SECTION_STACK_H

#include "Student.h"


class Section_Stack
{
    public:
        Section_Stack(int capacity);
        int push_student(Student* student);

        Student* pop_student(void);

        int num_of_studentEnrolled(void);
        bool isFull(void);
        virtual ~Section_Stack();

    private:
        int sec_capacity;
        Student* student_pointer;
        int student_count;

};

#endif // SECTION_STACK_H
