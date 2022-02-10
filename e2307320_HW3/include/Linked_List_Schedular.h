#ifndef LINKED_LIST_SCHEDULAR_H
#define LINKED_LIST_SCHEDULAR_H


class Linked_List_Schedular
{
    public:
        Linked_List_Schedular(int processID, int arrivalTime, int runTime, int priority,  Linked_List_Schedular* nextNode_);
        void InsertAfter(Linked_List_Schedular* p);
        Linked_List_Schedular* DeleteAfter(void);


        virtual ~Linked_List_Schedular();
        //data part is made public for ease of coding
        int processID;
        int arrivalTime;
        int runTime;
        int priority;
        Linked_List_Schedular* nextNode;



};

#endif // LINKED_LIST_SCHEDULAR_H
