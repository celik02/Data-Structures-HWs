// Linked_List_Schedular.cpp — pointer-manipulation operations for a singly linked list.

#include "Linked_List_Schedular.h"

Linked_List_Schedular::Linked_List_Schedular(int processID_, int arrivalTime_, int runTime_, int priority_,  Linked_List_Schedular* nextNode_):
    processID(processID_), arrivalTime(arrivalTime_), runTime(runTime_), priority(priority_), nextNode(nextNode_)
{

}

// InsertAfter inserts node 'p' immediately after 'this'.
// Order of pointer assignments matters — do NOT swap the two lines:
//   1. p->nextNode = nextNode   →  p now points to what comes after 'this'
//   2. nextNode    = p          →  'this' now points to p
// If you did step 2 first, nextNode (the original successor) would be lost.
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
