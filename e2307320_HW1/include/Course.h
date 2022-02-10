#ifndef COURSE_H
#define COURSE_H

#include "Student.h"


class Course
{
    public:
        Course(void);
        int getNum(void);
        void addNewStudent(Student *student_);
        void updateWeigths(int weightQ_, int weightHW_, int weightF_);
        Student *getStudentInfo(int student_id);
        Student **getStudentInfo();
        float* calculateAverage(void);

    private:
        Student *students[10];
        int num = 0;
        int weightQ = 30;
        int weightHW = 30;
        int weightF = 40;
};

#endif // COURSE_H
