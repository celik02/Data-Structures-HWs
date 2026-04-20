// HW1 — OOP basics: encapsulation bundles private data with the public methods that
// operate on it. External code accesses data only through getters/setters.

#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;

class Student
{
    public:
        // Initialize Student instances with id, name and surname
//        Student(int id, string name_, string surname_);
        Student();
        void setID(int id);
        int getID(void);

        //setter & getter for name surname
        void setName(string name_);
        string getName(void);
        void setSurname(string surname_);
        string getSurname(void) ;

        //setter and getter for quiz scores
        void setQuizes(float score[]);
        float *getQuizes(void);

        //setter&getter for hw scores
        void setHws(float score[]);
        // trailing 'const' on the method = doesn't modify the object
        // 'const float*' = caller cannot modify the returned array elements
        const float *getHw() const;

        //setter&getter for final score
        void setFinal(float score);
        float getFinal(void);

        // Weighted average: quiz*weightQ/100 + hw*weightH/100 + final*weightF/100
        float overallCourseScore();
        // Called by Course when class-wide weights change to keep student weights in sync
        void setWeights(int weightQ_, int weightH_, int weightF_);

        // 'virtual' destructor is needed when a class may be subclassed —
        // without it, deleting via a base-class pointer skips the derived destructor.
        virtual ~Student();

    private:
        // Default member initialization (C++11): used when the default constructor runs
        int ID = 9999;
        string name = "None";
        string surname = "None";
        // Fixed-size arrays on the stack — size must be a compile-time constant
        float quiz_scores[4];
        float hw_scores[3];
        float final_score;

        // Weights stored per-student so overallCourseScore() is self-contained.
        // They mirror the Course-level weights; setWeights() keeps them synchronized.
        int weightQ = 30;
        int weightH = 30;
        int weightF = 40;



};

#endif // STUDENT_H
