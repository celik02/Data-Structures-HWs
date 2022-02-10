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
        int front_, rear, count_;
        int max_size = 100;
        Student* qlist = new Student[max_size];
};

#endif // WAITINGQUEUE_H
