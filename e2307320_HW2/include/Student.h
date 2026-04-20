// HW2 Student — demonstrates constructor overloading and operator overloading.
// Constructor overloading: multiple constructors with different parameter lists;
// the compiler selects the right one based on the arguments provided.

#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>



using namespace std;
class Student
{
    public:
        Student(int id, char* _days);
        Student(void);
        //set id and preferred days
        void setID(int _id);
        int getID(void);

        void setDays(char* _days);
        char* getDays(void);


        // Operator overloading: redefines what '=' means for Student objects.
        // Needed here because 'days' is a raw pointer — without a custom operator=,
        // the default (shallow) copy would copy the pointer address, not the data,
        // causing two objects to share the same memory (double-free bug on destruction).
        Student& operator=(const Student& rhs);

        const char* getPreferences();
        int num_of_eligible_sections(bool W, bool T, bool F); //return number of eligible sections considering section capacity
        char  most_preferred_thas_is_not_ful(bool W, bool T, bool F);
        ~Student();

    private:
        int ID;
        char* days; // heap-allocated char array; requires deep copy in operator= and destructor
};

#endif // STUDENT_H
