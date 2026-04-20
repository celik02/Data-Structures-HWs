// WaitingQueue.cpp — circular buffer queue implementation.
// The initializer list sets front_, rear, and count_ before the constructor body runs.

#include "WaitingQueue.h"

WaitingQueue::WaitingQueue():front_(0), rear(0), count_(0)
{

}

//queue test methods
int WaitingQueue::Qlenght(void) const
{
    return count_;
}

int WaitingQueue::Qempty(void) const
{
    return (count_ == 0);
}

int WaitingQueue::Qfull(void) const
{
    return (max_size == count_);
}

//Queue modification operations
void WaitingQueue::Qinsert(const Student * item)
{
    if (Qfull())
    {
        cerr<<"Queue overflow"<<endl;
        exit(1);
    }

    count_++;
    qlist[rear] = *item;
    // Modulo wraps rear back to 0 when it reaches max_size — this is what makes it circular.
    // Without this, rear would go out of bounds even though the front of the array is free.
    rear = (rear +1)%max_size;

    return;
}

Student* WaitingQueue::Qdelete(void)
{
    Student* temp;
    if (Qempty())
    {
        cerr<<"Deleting from an empty Queue"<<endl;
        exit(1);
    }

    temp = &qlist[front_];
    count_--;
    front_ = (front_ +1)%max_size; // advance front_ with wrap-around (same circular trick)
    return temp;
}

Student WaitingQueue::Qfront(void) const
{
    return qlist[front_];
}

//WaitingQueue::~WaitingQueue()
//{
//    delete [] qlist;
//}


