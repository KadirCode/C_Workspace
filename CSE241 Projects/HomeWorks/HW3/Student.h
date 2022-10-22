#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <iostream>
#include <string>
#include "Course.h"

using namespace std;

class Course;

class Student
{
private:
    string name;
    int ID;
    Course* sCourse;
    int student_Course_count;
public:
    Student();
    Student(string name, int id);
    ~Student();

    Student& operator=(const Student& rhs); //assignment operator overload

    int get_student_Course_count(); //returns enrolled course count of the student
    void set_student_Course_count(int newCount);    // set enrolled course count of the student

    Course* getCourse_data();   //returns course dynamic array pointer of the student

    void addCourse(const Course &newCourse);    //add course to dynamic array
    void dropCourse(string dCode,string dName); //drop course from dynamic array

    string getName();   //returns student's name
    void setName(string newName);//set name

    int getID();    //return id
    void setID(int newID);  //set id


};



#endif