#include <iostream>
#include <string>
#include "Student.h"
#include "Course.h"

using namespace std;

Student::Student()  //default constructor
{
    name = "";
    ID = 0;
    sCourse = NULL;
    student_Course_count = 0;
}

Student::Student(string newName, int newID) //constructor with parameters
{
    name = newName;
    ID = newID;
    sCourse = NULL;
    student_Course_count = 0;
}


Student::~Student() //deconstructor
{
    if(sCourse != NULL)
    {
        delete [] sCourse;       
    }
}

string Student::getName()   //return student name
{
    return name;
}

void Student::setName(string newName)   //set student name
{
    name = newName;
}

int Student::getID()    //return student ID
{
    return ID;
}

void Student::setID(int newID)  //set student ID
{
    ID = newID;
}

Student& Student::operator=(const Student& rhs) //operator overload for assignment operator
{
    if(sCourse != NULL) //id course dynamic array is not empty, delete it
    {
        delete[] sCourse;
    }
    //assign new informations to *this
    ID = rhs.ID;
    name = rhs.name;
    student_Course_count = rhs.student_Course_count;

    sCourse = new Course[student_Course_count];
    for(int i = 0; i < student_Course_count; i++)
    {
        sCourse[i] = rhs.sCourse[i];
    }
    return *this;
    
}

Course* Student::getCourse_data()   //return course dynamic array of student
{
    return sCourse;
}

void Student::addCourse(const Course& newCourse)    //add course to students course dynamic array
{
    Course * new_sCourse = new Course[student_Course_count+1];

    for(int i = 0; i < student_Course_count; i++)
        new_sCourse[i] = sCourse[i];

    delete[] sCourse;

    sCourse = new_sCourse;

    new_sCourse[student_Course_count++] = newCourse;

}

int Student::get_student_Course_count()
{
        return student_Course_count;
}

void Student::set_student_Course_count(int newCount)
{
    student_Course_count = newCount;
}

void Student::dropCourse(string dCode,string dName) //drop selected course from students course dynamic array
{
    Course * new_sCourse = new Course[student_Course_count-1];
    for(int i = 0; i < student_Course_count; i++)
    {
        if(sCourse[i].getCode() != dCode && sCourse[i].getName() != dName)
            new_sCourse[i] = sCourse[i];
    }
    delete [] sCourse;
    sCourse = new_sCourse;
    student_Course_count--;
}

