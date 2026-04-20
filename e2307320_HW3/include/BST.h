// BINARY SEARCH TREE (BST) node.
// A BST organizes nodes so that for any node N:
//   - every node in the LEFT subtree has a smaller key
//   - every node in the RIGHT subtree has a larger key
//
// This ordering property makes search O(log n) on average (balanced tree),
// because each comparison eliminates half of the remaining nodes.
// Worst case is O(n) when the tree degenerates into a sorted linked list
// (e.g., inserting already-sorted data without rebalancing).
//
// In this HW, priority is the key: lower priority value → go left (higher urgency).

#ifndef BST_H
#define BST_H


class BST
{   //binary search tree class.
    public:
        BST(int processID_, int arrivalTime_, int runTime_, int priority_, BST* lptr, BST* rptr);
        BST* left;   // pointer to the left child (lower priority)
        BST* right;  // pointer to the right child (higher priority)
        int processID, arrivalTime, runTime, priority;
        virtual ~BST();

    private:
};

#endif // BST_H
