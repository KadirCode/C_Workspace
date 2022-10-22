#ifndef __SCHOOLMANAGEMENTSYSTEM_H__
#define __SCHOOLMANAGEMENTSYSTEM_H__

#include <iostream>
#include <string>
#include "Student.h"
#include "Course.h"

using namespace std;

class SchoolManagementSystem
{   
private:
    Course* mCourse;
    int cCount;

    Student* mStudent;
    int sCount;
    
public:
    SchoolManagementSystem();
    ~SchoolManagementSystem();



    void menu();
};




#endif