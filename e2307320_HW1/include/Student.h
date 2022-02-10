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
        const float *getHw() const;

        //setter&getter for final score
        void setFinal(float score);
        float getFinal(void);

        float overallCourseScore();
        void setWeights(int weightQ_, int weightH_, int weightF_);




        virtual ~Student();

    private:
        int ID = 9999;
        string name = "None";
        string surname = "None";
        float quiz_scores[4];
        float hw_scores[3];
        float final_score;

        int weightQ = 30;
        int weightH = 30;
        int weightF = 40;



};

#endif // STUDENT_H
