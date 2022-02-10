#include "Linked_List_Schedular.h"

Linked_List_Schedular::Linked_List_Schedular(int processID_, int arrivalTime_, int runTime_, int priority_,  Linked_List_Schedular* nextNode_):
    processID(processID_), arrivalTime(arrivalTime_), runTime(runTime_), priority(priority_), nextNode(nextNode_)
{

}

void Linked_List_Schedular::InsertAfter(Linked_List_Schedular* p)
{
    p->nextNode = nextNode;
    nextNode = p;
}

Linked_List_Schedular* Linked_List_Schedular::DeleteAfter(void)
{
    Linked_List_Schedular* tempPtr = nextNode;
    if(nextNode==nullptr)
        return nullptr;
    nextNode = tempPtr->nextNode;  //set pointer to point next node of the deleted node.

    return tempPtr; //return pointer to deleteted node.
}


Linked_List_Schedular::~Linked_List_Schedular()
{
    //dtor
}
