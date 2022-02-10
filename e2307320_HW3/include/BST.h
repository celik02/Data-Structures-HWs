#ifndef BST_H
#define BST_H


class BST
{   //binary search tree class.
    public:
        BST(int processID_, int arrivalTime_, int runTime_, int priority_, BST* lptr, BST* rptr);
        BST* left;
        BST* right;
        int processID, arrivalTime, runTime, priority;
        virtual ~BST();

    private:
};

#endif // BST_H
