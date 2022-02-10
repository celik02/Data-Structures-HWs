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


        // Overloading The assignment operator
        Student& operator=(const Student& rhs);

        const char* getPreferences();
        int num_of_eligible_sections(bool W, bool T, bool F); //return number of eligible sections considering section capacity
        char  most_preferred_thas_is_not_ful(bool W, bool T, bool F);
        ~Student();

    private:
        int ID;
        char* days;
};

#endif // STUDENT_H
