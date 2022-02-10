#include "Student.h"
#include <iostream>

using namespace std;
//Student::Student(int id=9999, string name_= "None", string surname_= "None"):ID(id), name(name_),surname(surname_)
//{
//    //ctor
//}
Student::Student()
{

}
void Student::setID(int id)
{
    ID = id;
}
int Student::getID()
{
    //cout<<ID<<endl;
    return ID;
}

void Student::setName(string name_)
{
    name = name_;
}
string Student::getName()
{
    //cout<<name<<endl;
    return name;
}

void Student::setSurname(string surname_)
{
    surname = surname_;
}

string Student::getSurname()
{
    //cout<<surname<<endl;
    return surname;
}

void Student::setQuizes(float scores[])
{
    for(int i=0; i<4; i++){
        quiz_scores[i] = scores[i];
    }
}

float* Student::getQuizes()
{
    return quiz_scores;
}

void Student::setHws(float scores[])
{
    for(int i=0; i<3; i++)
    {
        hw_scores[i] = scores[i];
    }
}

const float* Student::getHw() const
{   //hw_scores[1]= 100;
    return hw_scores;
}

void Student::setFinal(float score)
{
    final_score = score;
}

float Student::getFinal(void)
{
    return final_score;
}
float Student::overallCourseScore()
{
    float avarage = final_score*weightF/100;
    for(int i =0; i<4; i++){
        avarage += quiz_scores[i]*weightQ/400;
    }

    for(int j = 0; j<3; j++){
        avarage += hw_scores[j]*weightH/300;
    }

    return avarage;

}

//this method implemented to update each student score weights when course weights are updated.
void Student::setWeights(int weightQ_, int weightH_, int weightF_)
{
    weightF = weightF_;
    weightH = weightH_;
    weightQ = weightQ_;
}
Student::~Student()
{
    //dtor
}
