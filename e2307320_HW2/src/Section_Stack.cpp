// Section_Stack.cpp — array-based stack for course section enrollment.
// The initializer list ':sec_capacity(capacity)' sets sec_capacity before the constructor body runs,
// which is more efficient than assigning inside the body (avoids default-then-assign).

#include "Section_Stack.h"

Section_Stack::Section_Stack(int capacity):sec_capacity(capacity)
{
    //initialize stack counter to 0
    //create stack array for students
    student_count = 0;
    // 'new Student[capacity]' allocates an array of capacity Student objects on the heap.
    // Must be freed with 'delete[]' (not 'delete') in the destructor.
    student_pointer = new Student[capacity];
    cout<<"[INFO] Section Stack is created and student array is initialized..."<<endl;
}


int Section_Stack::push_student(Student* student)
{
    if(!isFull())
    {
        // '*student' dereferences the pointer to get the object, then assigns (copies) it
        // into the array slot. This invokes operator= defined in Student.
        student_pointer[student_count] = *student;
        student_count += 1;
    }

    else
    {
        cout<<"section is full"<<endl;
    }
    return student_count;

}

int Section_Stack::num_of_studentEnrolled()
{
    return student_count;
}


Student* Section_Stack::pop_student(void)
{
    Student* temp = new Student(9999, nullptr);
    if(student_count>0)
    {
        // '&student_pointer[student_count-1]' takes the address of the top element.
        // Decrementing student_count "removes" it logically — the slot is just ignored next time.
        temp = &student_pointer[student_count-1];
        student_count -= 1;
    }
    else{
        cout<<"There is no one in the section"<<endl;
    }
    return temp;
}


bool Section_Stack::isFull(void)
{
    if(sec_capacity>student_count)
        return false;
    else return true;
}

Section_Stack::~Section_Stack()
{
    delete [] student_pointer;
}
