#include "BST.h"

BST::BST(int processID_, int arrivalTime_, int runTime_, int priority_, BST* lptr, BST* rptr):processID(processID_), arrivalTime(arrivalTime_),
        runTime(runTime_), priority(priority_), left(lptr), right(rptr){

}

BST::~BST()
{
    //dtor
}
