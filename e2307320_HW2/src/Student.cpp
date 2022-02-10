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
//asignment operator overloading. To avoid problems with pointers and memories.
Student& Student::operator=(const Student& rhs)
{
    ID = rhs.ID;
    days = new char[3];
    for(int i=0; i<3; i++)
    {
        days[i] = rhs.days[i];
    }

    return *this;
}

const char *Student::getPreferences()
{
    return days;
}

//return #of eligible section
int Student::num_of_eligible_sections(bool W, bool T, bool F)
{
    int num_of_eligible = 0;

    for(int i=0; i<3; i++)
    {
        if(days[i] == 'W' && W)
            num_of_eligible++;
        else if(days[i] == 'T' && T)
            num_of_eligible++;
        else if(days[i]== 'F' &&  F)
            num_of_eligible++;
    }


    return num_of_eligible;
}

char Student::most_preferred_thas_is_not_ful(bool W, bool T, bool F)
{
    for(int i=0; i<3; i++)
    {
        if(days[i] == 'W' && !W)
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
