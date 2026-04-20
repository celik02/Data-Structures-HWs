// QUEUE — First In, First Out (FIFO).
// Think of a line at a checkout: new arrivals join the back, served from the front.
//
// This is a *circular buffer* implementation backed by a fixed-size array.
// Instead of shifting all elements on every dequeue, we use two index pointers
// (front_ and rear) that wrap around with modulo arithmetic:
//
//   Qinsert: qlist[rear] = item;  rear = (rear + 1) % max_size;
//   Qdelete: temp = qlist[front_]; front_ = (front_ + 1) % max_size;
//
// The wrap-around means the array is reused without copying, making both
// operations O(1) instead of O(n).

#ifndef WAITINGQUEUE_H
#define WAITINGQUEUE_H

#include "Student.h"

class WaitingQueue
{
    public:
        WaitingQueue(void);

        //Queue modification operations
        void Qinsert(const Student *item);
        Student* Qdelete(void);
        void ClearQueue(void);

        //Queue access
        Student Qfront(void) const;

        //Queue info methods
        int Qlenght(void) const;
        int Qempty(void) const;
        int Qfull(void) const;

//        ~WaitingQueue();

    private:
        int front_, rear, count_; // front_ = dequeue index, rear = next enqueue index
        int max_size = 100;
        Student* qlist = new Student[max_size]; // heap array used as circular buffer
};

#endif // WAITINGQUEUE_H
