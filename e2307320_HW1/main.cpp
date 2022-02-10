#include <iostream>
#include "Student.h"
#include "Course.h"


using namespace std;

//declare globally so that each function can reach it without argument passing
Course ee441;




Student* addNewStudent(int ID_, string name_, string surname_)
{   // this function creates new student object in heap and returns pointer to it.
    float hws[3] = {0, 0, 0};
    float quiz[4] = {0, 0 , 0 , 0};
    Student *student = new Student;
    student->setID(ID_);
    student->setName(name_);
    student->setSurname(surname_);
    student->setFinal(0);
    student->setHws(hws);
    student->setQuizes(quiz);
    //ID_list.push_back(ID_);

    return student;
}

void showStudent(int ID_)
{
    Student* student_ =  ee441.getStudentInfo(ID_);
    cout<<student_->getID()<<" "<< student_->getName()<< " " << student_->getSurname() << " "<< student_->getQuizes()[0] << " "<< student_->getQuizes()[1];
    cout << " " << student_->getQuizes()[2] << " " << student_->getQuizes()[3] << " " << student_->getHw()[0] << " ";
    cout << student_->getHw()[1] << " " << student_->getHw()[2] << " " << student_->getFinal()<<endl;
    cout<<endl;

}

//changes student scores for given ID
void changeStudentScores(int ID, float *quiz_scores, float* hw_scores, float final_score)
{
    Student* student = ee441.getStudentInfo(ID);
    student->setFinal(final_score);
    student->setHws(hw_scores);
    student->setQuizes(quiz_scores);
}

//update weights for course and each student enrolled to that course
void changeWeights(int weightQ, int weightHW, int weightF)
{
    ee441.updateWeigths(weightQ,  weightHW,  weightF);
}

void showAverage()
{
    float * av_list = ee441.calculateAverage();
    float quiz_av = av_list[0];
    float hw_av = av_list[1];
    float final_av = av_list[2];
    float overall = av_list[3];

    cout<<"Quizzes Average: " << quiz_av<<endl;
    cout<<"Homeworks Average: " << hw_av <<endl;
    cout<< "Final-Average: " << final_av <<endl;
    cout<< "Overall Average: " << overall <<endl;
    cout<<endl;
    delete av_list;

}

void showAbove(float threshold)
{
    int num_of_student = ee441.getNum();
    float overall_score;
    Student* student_ptr;
    //iterate through each student to see if their average is above threshold
    Student **student_list = ee441.getStudentInfo();
    for(int i=0; i<num_of_student; i++)
    {
        student_ptr = student_list[i];
        overall_score = student_ptr->overallCourseScore();
        if(threshold<overall_score)
        {
            cout<< student_ptr->getID() << " " << student_ptr->getName() << " " << student_ptr->getSurname() << " Avg:" << overall_score<<endl;
        }
    }

}

void showBelow(float threshold)
{
    int num_of_student = ee441.getNum();
    float overall_score;
    Student* student_ptr;
    //iterate through each student to see if their average is below threshold
    Student **student_list = ee441.getStudentInfo();
    for(int i=0; i<num_of_student; i++)
    {
        student_ptr = student_list[i];
        overall_score = student_ptr->overallCourseScore();
        if(threshold>overall_score)
        {
            cout<< student_ptr->getID() << " " << student_ptr->getName() << " " << student_ptr->getSurname() << " Avg:" << overall_score<<endl;
        }
    }

}



int main()
{

    cout<<"EE441 Classroom Interface"<<endl;
    bool cont = true;
    int option;
    float ID;
    string name, surname;
    float quizes[4];
    float hw[3];
    float final_score;
    float threshold;
    int WEIGTHQ = 30;
    int WEIGTHHW = 30;
    int WEIGHTF = 40;


    while(cont)
    {
        cin.clear();
        cout<<"1) Add a student"<< endl;
        cout<<"2) Search student by ID"<<endl;
        cout<<"3) Change student's score"<<endl;
        cout<<"4) Update weights" <<endl;
        cout<<"5) Show class average"<<endl;
        cout<<"6) Show students with overall score above a threshold"<<endl;
        cout<<"7) Show students with overall score below a threshold"<<endl;
        cout<<"8) Exit"<<endl;
        cout<<"Enter your option: ";
        cin>>option;

        if(option == 8)
            cont = false;
        else if(option == 1)
        { // add student
            int num = ee441.getNum();
            //check if max number of student is reached
            if(num>9)
            {
                cout<<"MAX number of student reached. No more student can be added"<<endl;
                continue;
            }
            cout<<"Enter student's ID, name, surname and scores(Q1, Q2, Q3, Q4, HW1, HW2, HW3, Final)"<<endl;
            //to check for invalid ID or entering something invalid
            try
            {
                 cin>>ID>>name>>surname>>quizes[0]>>quizes[1]>>quizes[2]>>quizes[3]>>hw[0]>>hw[1]>>hw[2]>>final_score;
                 if(int(ID)!= ID || ID<0)
                    throw "invalidID";

            }
            catch(...)
            {
                cout<<"Please enter positive integers for ID and  positive floats for grades"<<endl;
                cout<<endl;
                continue;
            }

            //check if grade is negative
            if(quizes[0]<0 || quizes[1] <0 || quizes[2] <0 || quizes[3] <0 || hw[0]<0 || hw[1]<0 || hw[2]<0 || final_score<0)
            {
                cout<<"Negative grade is not permitted. Please try again"<<endl;
                cout<<endl;
                continue;
            }

            ee441.addNewStudent(addNewStudent(ID, name, surname));
            changeStudentScores(ID, quizes, hw, final_score);
            cout<<endl;
        }
        else if(option == 2)
        {   // search student by id
            cout<<"Enter student ID"<<endl;
            cin>>ID;
            bool id_exist = false;
            int num = ee441.getNum();
            //get pointer to pointer list of students
            Student **student_list = ee441.getStudentInfo();
            for(int i = 0 ; i<num; i++)
            {
                Student *student_ptr = student_list[i];
                if(student_ptr->getID() == ID)
                {
                    id_exist = true;
                    break;

                }
            }

            if(!id_exist)
                cout<<"ID does not exist"<<endl;
            else
                showStudent(ID);
        }
        else if(option == 3)
        {   //updpate student's scores
            cout<<"Enter Student ID and exam scores(4 quiz, 3 homeworks, 1 final)"<<endl;
            cin>>ID>>quizes[0]>>quizes[1]>>quizes[2]>>quizes[3]>>hw[0]>>hw[1]>>hw[2]>>final_score;
            changeStudentScores(ID, quizes, hw, final_score);
            cout<<endl;
        }
        else if(option == 4)
        {   // update weights
            cout<<"Enter quiz weight, homework weight and final weight as integers between 0 and 100"<<endl;
            cin>>WEIGTHQ>>WEIGTHHW>>WEIGHTF;
            changeWeights(WEIGTHQ, WEIGTHHW,WEIGHTF);
        }
        else if(option == 5)
        {   // show class average
            showAverage();
            cout<<endl;

        }
        else if(option == 6)
        {   //show above threshold
            cout<<"Enter Threshold: ";
            cin>>threshold;

            showAbove(threshold);
        }
        else if(option==7)
        {   //show below threshold
            cout<<"Enter threshold: ";
            cin>>threshold;
            showBelow(threshold);
        }

    }

    return 0;
}
