#include <iostream>
#include <fstream>
#include "Linked_List_Schedular.h"
#include "BST.h"
using namespace std;

/*My Opinion on performance

    Overall BST is better since sum of insertion and search is smaller compared to linked list.
    In terms of insertion BST's performance is clearly better than linked list
    In terms of search, linked list seems like a little bit better however, difference is not much. Their search count is relatively close to each other
    compared to insertion count.
    When number of processes increases, linked list insertion increases dramatically. Big O complexity of linked list insertion is higher than BST insertion.
    Complexity of search in linked list is O(n). For BST is slightly higher than O(n).
*/
class Node
{   //this class is to just read data from file and store in an array.
    public:
    Node(int processID, int arrivalTime, int runTime, int priority):processID(processID), arrivalTime(arrivalTime), runTime(runTime), priority(priority){};
    Node(){};
    int processID, arrivalTime, runTime, priority;

};

//to create new linked list nodes dynamically
Linked_List_Schedular* GetNode(Node& item, Linked_List_Schedular* nextPtr = nullptr)
{   // this function creates new linked list nodes on heap memory and returns a pointer to them.
    Linked_List_Schedular* newNode;
    newNode = new Linked_List_Schedular(item.processID, item.arrivalTime, item.runTime, item.priority, nextPtr);
    if(newNode==nullptr)
    {
        cerr<<"Memory Allocation Failed"<<endl;
        exit(1);
    }

    return newNode;
}

//create tree nodes dynamically
BST* getTreeNode(Node  &item, BST* lptr=nullptr, BST* rptr=nullptr)
{
    //creates tree nodes on heap and returns a pointers to that node
    BST* temp;
    temp = new BST(item.processID, item.arrivalTime, item.runTime, item.priority, lptr, rptr);
    if(temp==nullptr)
    {
        cerr<<"Memory allocation failure"<<endl;
        exit(1);
    }
    return temp;
}


//for linked list insertion function
//to make code more robust, I used function overloading. For linked list and BST I use same function name.
//how RQ initialized determines which function to be used.
void InsertIntoRQ(Node& tempProcess, Linked_List_Schedular** linked_list_head, int* insertion_count)
{
        //in this function processes are inserted into linked list wrt to their priority order.
        //also counter is used to count number of insertion. Nothing is returned.
        Linked_List_Schedular* temp = *linked_list_head;
        Linked_List_Schedular* temp_prev;
        while(temp!= nullptr)
        {
            if(tempProcess.priority < temp->priority)
            {
                if(temp==*linked_list_head)
                {
                    temp = GetNode(tempProcess, temp);
                    *linked_list_head = temp;
                    (*insertion_count)++;
                    return;
                }
                else{
                        temp_prev->InsertAfter(GetNode(tempProcess, temp));
                        (*insertion_count)++;
                        return;
                }
            }
            else
            {
                (*insertion_count)++;
                temp_prev = temp;
                temp = temp->nextNode;

                if(temp==nullptr)
                {
                       temp_prev->InsertAfter(GetNode(tempProcess));
                       (*insertion_count)++;
                       return;
                }
            }
        }
    if(*linked_list_head == nullptr)
        *linked_list_head = GetNode(tempProcess);
    (*insertion_count)++;
}

//for tree function overloading
void InsertIntoRQ(Node &tempProcess, BST** head, int* insertion_count)
{
        //this function gets processes and inserts them into binary search tree wrt to their priority order.
        //counter counts the number of insertion
        //nothing is returned.
        BST* temp = *head;
        BST* tempPrev = *head;
        bool left_way = true;
        while(temp!=nullptr)
        {
            if(temp->priority > tempProcess.priority)
                {
                    tempPrev = temp;
                    temp = temp->left;
                    (*insertion_count)++;
                    left_way = true;

                }
            else if(temp->priority < tempProcess.priority)
                {
                    tempPrev = temp;
                    temp = temp->right;
                    (*insertion_count)++;
                    left_way = false;
                }
        }

         if((*head) == nullptr)
        {
            *head = getTreeNode(tempProcess);

            return;

        }
        (*insertion_count)++;
        if(left_way)
            tempPrev->left = getTreeNode(tempProcess);
        else
            tempPrev->right = getTreeNode(tempProcess);

}

//linked list traversal
Node* GetHighPriorityRQ(Linked_List_Schedular** head, int* traversel_count)
{
    //returns node with the highest priority in the linked list
    //and deletes it from the linked list
    Node* tempNode = new Node((*head)->processID, (*head)->arrivalTime, (*head)->runTime, (*head)->priority);
    Linked_List_Schedular* tempLinked = *head;
    (*head) = (*head)->nextNode;

    if(tempLinked != nullptr)
        delete tempLinked;
    (*traversel_count)++;
    return tempNode;
}

//BST traversel
Node* GetHighPriorityRQ(BST** head, int* counter)
{
    //returns node with the highest priority in the BST
    //and deletes it from the BST
    BST* temp = *head;
    BST* tempPrev = *head;
    (*counter)++;
    while(temp->left!=nullptr)
    {
        tempPrev = temp;
        temp = temp->left;
        (*counter)++;
    }
    tempPrev->left = temp->right;
    if(temp == tempPrev)
    {
        *head = temp->right;
    }

    Node* tempNode = new Node(temp->processID, temp->arrivalTime, temp->runTime, temp->priority);
    return tempNode;

}


int main()
{
    /* reading processes from file */
    ifstream processesFile; /* input file stream */
    processesFile.open ("processes100.txt");
    int numProcesses; /* number of processes */
    processesFile >> numProcesses; /* read from file */
    Node process[numProcesses]; /* create Node array */
    int processID, arrivalTime, runTime, priority;
    for(int i=0; i<numProcesses; ++i){
        /* read 4 integers from file */
        processesFile >> processID >> arrivalTime >> runTime >> priority;
        /* construct i'th element of the array */
        process[i] = Node(processID, arrivalTime, runTime, priority);
    }
    processesFile.close();
    /* end of reading from file */

    int *insertion_count = new int(0);
    int* traversal_count = new int(0);
    int time = 0;
    bool  CPUBusy = false;
    Node* currentProcess = new Node(-1, -1, -1, -1);
    int processIndex = 0;
    //for Linked list
//    Linked_List_Schedular* RQ = nullptr;
//    for tree uncomment below
    BST* RQ = nullptr;
    while(processIndex < numProcesses || CPUBusy == true || RQ != nullptr)
    {
        //implementation of process schedular
        if(processIndex < numProcesses)
        {
            if(process[processIndex].arrivalTime == time)
            {
                //insert into RQ
                InsertIntoRQ(process[processIndex], &RQ, insertion_count);
                processIndex++;
            }
        }

        if(CPUBusy == true)
            currentProcess->runTime--;

        if(currentProcess->runTime == 0)
        {
            cout<<"Process ID of Finished:"<<currentProcess->processID<<endl;
            CPUBusy = false;
        }

        if(CPUBusy == false && RQ != nullptr)
        {
            //currentProcess = highes  highest priority process in RQ and delete it.
            currentProcess = GetHighPriorityRQ(&RQ, traversal_count);
            CPUBusy = true;
        }


        time++;
    }
    cout<<"Insertion Count "<<*insertion_count<<endl;
    cout<<"Traversel Count "<<*traversal_count<<endl;
    return 0;
}
