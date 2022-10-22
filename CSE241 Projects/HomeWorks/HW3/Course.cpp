#include <iostream>
#include <string>
#include "Student.h"
#include "Course.h"

using namespace std;

Course::Course()
{
    name = "";
    code = "";
    cStudent = NULL;
    course_Student_Count = 0;
}

Course::Course(string newName, string newCode)
{
    name = newName;
    code = newCode;
    cStudent = NULL;
    course_Student_Count = 0;
}

Course::~Course()
{
    if(cStudent != NULL)
        delete [] cStudent;
}

string Course::getName()
{
    return name;
}

void Course::setName(string newName)
{
    name = newName;
}

string Course::getCode()
{
    return code;
}

void Course::setCode(string newCode)
{
    code = newCode;
}


void Course::addStudent(const Student& newStudent)
{

    Student * new_cStudent = new Student[course_Student_Count+1];
    


    for(int i = 0; i < course_Student_Count; i++)
        new_cStudent[i] = cStudent[i];

    delete[] cStudent;

    cStudent = new_cStudent;

    new_cStudent[course_Student_Count++] = newStudent;

}

void Course::dropStudent(int dID, string dName)
{

}


bool Course::operator==(const Course& rhs) const
{
    if(code == rhs.code && name == rhs.name)
        return true;
    else
        return false;
}


Student* Course::getStudent_data()
{
    return cStudent;
}