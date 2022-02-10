#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <stdlib.h>

#include "Student.h"
#include "Section_Stack.h"
#include "WaitingQueue.h"

using namespace std;

//since ID is in char, in order to parse line and convert id given in char array to integer
//this function is implemented
int get_student_id(char* text)
{
    char *index = strstr(text, ",");
    int i = 0;
    string id;
    while(index != &text[i])
    {
        id.push_back(text[i]);
        i++;
    }

    stringstream data(id);
    int id_;
    data>>id_;
    return id_;
}

//this function does the same job with the previous one for class capacity.
int get_class_cap(char *text)
{
    int cap;
    string str;

    int i = 2;
    while(text[i] != '\0')
    {
        str.push_back(text[i]);

        i++;
        if(i>10)
        {
            cout<<"[ERROR]"<<endl;
        }
    }

    stringstream data(str);
    data>>cap;
    return cap;
}

//this function get rids of commas given in the txt file
//and returns pointer to new char array.
char* get_student_days(char* text)
{
    char *index = strstr(text, ",");
    int i=0;
    string days;
    while(index[i] != '\0')
    {
        if(index[i] != ',')
            days.push_back(index[i]);

        i++;

        if(i>10)
        {
            cout<<"[ERROR]"<<endl;
        }
    }

    stringstream data(days + '\0');
    char* ar = new char[5];
    data>>ar;
    return ar;
}

//check for student if he has only one choice
//assign him/her to the corresponding section if capacity is enough
bool assing_student_if_one_choice(Student* stud, Section_Stack* W, Section_Stack* T, Section_Stack* F)
{
    char* days;

    bool assigned = false;

    days = stud->getDays();

    int i=0;
    while(days[i] != '\0')
    {
        i++;
    }

    if(i==1)
    {
        if(days[0] == 'W' && W->isFull() !=true)
        {
            W->push_student(stud);
            assigned = true;

        }
        else if(days[0]=='T' && T->isFull() != true)
        {
            T->push_student(stud);
            assigned = true;

        }
        else if(days[0] == 'F' && F->isFull() != true)
        {
            F->push_student(stud);
            assigned = true;

        }
        else
            cout<<"[ERROR] student is not assign to any section"<<endl;

    }

    return assigned;

}


//When new student that is read from the txt file assigned to any class, this function is invoked. So that
//it checks each student and if any of them has one option assigns them otherwise pushes student to the end of the queue.
//relative order of students are protected.
bool assign_from_waiting_queue(WaitingQueue* item, Section_Stack* W, Section_Stack* T, Section_Stack* F )
{
    bool no_body_assigned = true;
    int counter = 0;
    int queue_len = item->Qlenght();
    while(queue_len > 0)
    {
        Student *temp = item->Qdelete();
        char option;

        if(temp->num_of_eligible_sections(W->isFull(), T->isFull(),F->isFull()) == 1)
        {
            cout<<"This student has only one option: "<<temp->getDays()<<endl;
            cout<<"W"<<W->isFull()<<" T:"<<T->isFull()<<" F:"<<F->isFull()<<endl;
            option = temp->most_preferred_thas_is_not_ful(W->isFull(), T->isFull(),F->isFull());
            if(option == 'W')
                {
                    W->push_student(temp);
                    cout<<"Student assigned to:"<<option<<endl;
                    no_body_assigned = false;
                }
            else if(option == 'T')
            {
                T->push_student(temp);
                cout<<"Student assigned to:"<<option<<endl;
                no_body_assigned = false;
            }
            else if(option == 'F')
            {
                F->push_student(temp);
                cout<<"Student assigned to:"<<option<<endl;
                no_body_assigned = false;
            }
            else
                {
                    cout<<"Student is not assigned to any section!!!"<<endl;
                    no_body_assigned = true;
                }

        }
        else
        {
            item->Qinsert(temp);
            cout<<"NUM of eligible sections:"<<temp->num_of_eligible_sections(W->isFull(), T->isFull(),F->isFull())<<endl;
             no_body_assigned = true;
        }

        queue_len--;
        if(!no_body_assigned)
            counter++;
    }

    return (counter==0);
}


//students with more than 2 or 0 option are in the queue. According to their order in the queue they are assigned to one of the sections
//If no section is avaliable the student/s will stay in the waiting queue until capacities are increased :)
void assign_remaining_in_the_queue(WaitingQueue* item, Section_Stack* W, Section_Stack* T, Section_Stack* F)
{
    int queue_len = item->Qlenght();
    char option;
    while(queue_len>0)
    {
        Student* temp = item->Qdelete();
        option = temp->most_preferred_thas_is_not_ful(W->isFull(), T->isFull(),F->isFull());
        if(option == 'W')
                {
                    W->push_student(temp);
                    cout<<"Student assigned to:"<<option<<endl;
                }
            else if(option == 'T')
            {
                T->push_student(temp);
                cout<<"Student assigned to:"<<option<<endl;
            }
            else if(option == 'F')
            {
                F->push_student(temp);
                cout<<"Student assigned to:"<<option<<endl;
            }
            else
              {
                  cout<<"Student is not assigned to any section!!!"<<temp->getID()<<endl;

                  item->Qinsert(temp);

              }

        queue_len--;
    }


}


int main()
{

    ifstream input_txt;
    input_txt.open("preferences.txt");

    ofstream outputtxt;
    outputtxt.open("results.txt");

    Section_Stack* W, *T, *F;
    char output[10]; //to get the lines from txt file
    bool is_assigned;
    bool no_body_assigned=true;

    WaitingQueue waiting_queue;

    // read the preferences.txt file
    // create section stacks
    if(input_txt.is_open())
    {
        //for the first section
        input_txt>>output;
        cout<<"section W:"<<output[2]<<endl;
        if(output[0] == 'W')
            W = new Section_Stack(get_class_cap(output));
        else if(output[0] == 'T')
            T = new Section_Stack(get_class_cap(output));
        else if(output[0] == 'F')
            F = new Section_Stack(get_class_cap(output));
        else
        {   cout<<"[ERROR] class stack is not created"<<endl;
            exit(1);
        }

        //for the second section
        input_txt>>output;
        cout<<"section T:"<<output[2]<<endl;
        if(output[0] == 'W')
            W = new Section_Stack(get_class_cap(output));
        else if(output[0] == 'T')
            T = new Section_Stack(get_class_cap(output));
        else if(output[0] == 'F')
            F = new Section_Stack(get_class_cap(output));
        else
        {   cout<<"[ERROR] class stack is not created"<<endl;
            exit(1);
        }
        //for the third section
        input_txt>>output;
        cout<<"section F:"<<output[2]<<endl;
        if(output[0] == 'W')
            W = new Section_Stack(get_class_cap(output));
        else if(output[0] == 'T')
            T = new Section_Stack(get_class_cap(output));
        else if(output[0] == 'F')
            F = new Section_Stack(get_class_cap(output));
        else
        {   cout<<"[ERROR] class stack is not created"<<endl;
            exit(1);
        }


        // create the students objects assign to a section if single preference otherwise add to
        // waiting queue

        // !input_txt.eof() when used that expression it read last line twice
        // so I changed it.
        while(input_txt>>output)
        {
            int student_id = get_student_id(output);
            char* days = get_student_days(output);
            Student* temp = new Student(student_id, days);



            //if student has one choice assigned it. If section capacity does not allow
            //add it to the queue
            is_assigned = assing_student_if_one_choice(temp, W, T, F);
            if(!is_assigned)
            {
              waiting_queue.Qinsert(temp);
            }
            else//if new student is assigned check all students from the waiting queue
            {
                while(!no_body_assigned)
                {
                    //no_body_assigned flag is used to keep track of if anybody is assigned from queue
                    //so that we can reconsider remaining student from the queue.
                    no_body_assigned = assign_from_waiting_queue(&waiting_queue, W, T, F);
                }

                no_body_assigned = false;
            }


            cout<<output<<endl;
        }
    }

        assign_remaining_in_the_queue(&waiting_queue, W, T, F);

        //write students ids to the section they are assigned.
        int counter = W->num_of_studentEnrolled();
        outputtxt << "Wednesday:\n";
        for(int i=0; i<counter; i++)
        {
            Student* temp = W->pop_student();
            outputtxt << temp->getID() <<endl;
        }

        counter = T->num_of_studentEnrolled();
        outputtxt << "\nThursday:\n";
        for(int i=0; i<counter; i++)
        {
            Student* temp = T->pop_student();
            outputtxt << temp->getID() <<endl;
        }

        counter = F->num_of_studentEnrolled();
        outputtxt <<"\nFriday:\n";
        for(int i=0; i<counter; i++)
        {
            Student* temp = F->pop_student();
            outputtxt << temp->getID() <<endl;
        }


        //if still there are students not assigned to any section write ids
        //under unassigned
        outputtxt <<"\nUnassigned:\n";
        if(!waiting_queue.Qempty())
        {
            while(!(waiting_queue.Qempty()))
            {
                Student *temp = waiting_queue.Qdelete();
                cout<<"Num of eligible section:---"<<temp->num_of_eligible_sections(W->isFull(), T->isFull(), F->isFull())<<endl;
                cout<<"ID:"<<temp->getID()<<endl;
                outputtxt << temp->getID() <<endl;
            }
        }
        else//if queue is empty
        {
            outputtxt<<"-"<<endl;
        }

    cout << "Hello world!" << endl;

    return 0;
}
