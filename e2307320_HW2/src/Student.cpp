// HW2 Student.cpp — shows deep copy via operator= and preference-based section selection.

#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(int id, char* _days)
{
    ID = id;
    days = new char[3];
    if(_days!=nullptr)
    {
        for(int i=0; i<3; i++)
        {
            days[i] = _days[i];
        }
    }

}

Student::Student()
{

}

void Student::setID(int _id)
{
    ID = _id;
}

int Student::getID()
{
    return ID;
}

void Student::setDays(char *_days)
{
    days = new char[3];
    for(int i=0; i<3; i++)
    {
        days[i] = _days[i];
    }

}


char* Student::getDays()
{

    return days;

}
// Assignment operator overloading — performs a *deep copy*.
// Default '=' would do a shallow copy: copy the 'days' pointer value, not the data it points to.
// That means both objects would point to the same memory → double-free crash on destruction.
// Deep copy: allocate fresh memory for 'days' and copy the characters over.
Student& Student::operator=(const Student& rhs)
{
    ID = rhs.ID;
    days = new char[3];          // allocate new memory, separate from rhs.days
    for(int i=0; i<3; i++)
    {
        days[i] = rhs.days[i];  // copy the actual character data
    }

    return *this; // return reference to self so chained assignment (a = b = c) works
}

const char *Student::getPreferences()
{
    return days;
}

//return #of eligible section
// Parameters W, T, F are booleans representing whether that section is FULL (true = full).
// A section is eligible if the student wants it AND it is not full.
int Student::num_of_eligible_sections(bool W, bool T, bool F)
{
    int num_of_eligible = 0;

    for(int i=0; i<3; i++)
    {
        if(days[i] == 'W' && W)        // student wants W and W is full → not eligible
            num_of_eligible++;
        else if(days[i] == 'T' && T)
            num_of_eligible++;
        else if(days[i]== 'F' &&  F)
            num_of_eligible++;
    }


    return num_of_eligible;
}

// Returns the student's highest-preference day that still has space.
// Iterates days[] in order, so earlier entries are treated as higher priority.
char Student::most_preferred_thas_is_not_ful(bool W, bool T, bool F)
{
    for(int i=0; i<3; i++)
    {
        if(days[i] == 'W' && !W)       // student wants W and W is NOT full
            return 'W';
        else if(days[i] == 'T' && !T)
            return 'T';
        else if(days[i] == 'F' && !F)
            return 'F';
    }

    //in case of error
    return 'E';
}

Student::~Student()
{
    delete [] days;
}
