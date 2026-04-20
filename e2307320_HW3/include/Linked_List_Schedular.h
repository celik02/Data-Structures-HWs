// SINGLY LINKED LIST node.
// Each node stores its own data and a pointer to the next node.
// The list is traversed by following nextNode pointers until nullptr.
//
// Key operations and their complexity:
//   Insertion at known position: O(1) — just pointer rewiring
//   Search for a position:       O(n) — must walk from head
//   Access by index:             O(n) — no random access like arrays
//
// Unlike an array, a linked list can grow dynamically without reallocation,
// but it uses extra memory per node for the 'nextNode' pointer.

#ifndef LINKED_LIST_SCHEDULAR_H
#define LINKED_LIST_SCHEDULAR_H


class Linked_List_Schedular
{
    public:
        Linked_List_Schedular(int processID, int arrivalTime, int runTime, int priority,  Linked_List_Schedular* nextNode_);
        // Inserts node p *after* this node by rewiring two pointers
        void InsertAfter(Linked_List_Schedular* p);
        // Removes the node after this node; returns a pointer to it (caller must delete)
        Linked_List_Schedular* DeleteAfter(void);


        virtual ~Linked_List_Schedular();
        //data part is made public for ease of coding
        int processID;
        int arrivalTime;
        int runTime;
        int priority;
        Linked_List_Schedular* nextNode; // pointer to the next node; nullptr = end of list



};

#endif // LINKED_LIST_SCHEDULAR_H
