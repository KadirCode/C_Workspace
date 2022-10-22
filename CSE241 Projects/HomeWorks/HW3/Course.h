#ifndef __COURSE_H__
#define __COURSE_H__

#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

class Student;

class Course
{
private:
    string name;    
    string code;
    Student* cStudent;
    int course_Student_Count;

public:
    Course();
    Course(string newName, string newCode);
    ~Course();

    void addStudent(const Student &newStudent);
    void dropStudent(int dID, string dName);

    int get_Course_student_count(){return course_Student_Count;}

    Student* getStudent_data();

    bool operator==(const Course&rhs) const;    //comparison operator overload

    string getName();
    void setName(string newName);

    string getCode();
    void setCode(string newCode);



};



#endif
