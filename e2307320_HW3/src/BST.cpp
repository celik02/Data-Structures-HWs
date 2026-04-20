// BST.cpp — constructor using member initializer list.
// The ': member(value), ...' syntax initializes members *before* the constructor body runs.
// For primitive types this is equivalent to assigning in the body, but it's the preferred style.

#include "BST.h"

BST::BST(int processID_, int arrivalTime_, int runTime_, int priority_, BST* lptr, BST* rptr):processID(processID_), arrivalTime(arrivalTime_),
        runTime(runTime_), priority(priority_), left(lptr), right(rptr){

}

BST::~BST()
{
    //dtor
}
