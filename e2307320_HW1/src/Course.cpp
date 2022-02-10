#include "Course.h"
#include <iostream>
using namespace std;

Course::Course()
{

}

int Course::getNum()
{
    return num;
}

void Course::addNewStudent(Student *student_)
{

    if(num>9){
        cout<< "Reached maximum number of students"<<endl;
    }
    students[num] = student_;

    num+=1;
    return;
}

void Course::updateWeigths(int weightQ_, int weightHW_, int weightF_)
{
    weightQ = weightQ_;
    weightHW = weightHW_;
    weightF = weightF_;

    //Updating each student's individual weights with class weight
    //so that no discrepancy occur between them.
    for(int i = 0; i<num; i++)
    {
        students[i]->setWeights(weightQ_, weightHW_, weightF_);
    }

}

//for given id pointer to that student is returned
Student *Course::getStudentInfo(int student_id)
{
    for(auto student: students)
    {
        if (student->getID() == student_id)
            return student;
    }

    //instead of initializing over and over just one initialization will be done
    static Student *empty_student = new Student;
    empty_student->setID(99999);
    return empty_student;

}

//return list of all students.
Student** Course::getStudentInfo()
{
    return students;
}

float* Course::calculateAverage()
{

    float quiz_av = 0;
    float hw_av = 0;
    float overall = 0;
    float final_all = 0;
    float* av_list = new float[4];

    for(int i = 0; i<num; i++)
    {
        quiz_av += students[i]->getQuizes()[0] + students[i]->getQuizes()[1] + students[i]->getQuizes()[2] + students[i]->getQuizes()[3];
        hw_av += students[i]->getHw()[0]  +  students[i]->getHw()[1] + students[i]->getHw()[2];
        final_all += students[i]->getFinal();

    }

    final_all /=num;
    quiz_av /= (num*4);
    hw_av /= (num*3);

    overall = (final_all*weightF + quiz_av*weightQ + hw_av*weightHW)/100;

    av_list[0] = quiz_av;
    av_list[1] = hw_av;
    av_list[2] = final_all;
    av_list[3] = overall;
    return av_list;

}
