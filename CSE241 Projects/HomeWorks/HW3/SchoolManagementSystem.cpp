#include <iostream>
#include <string>
#include <stdlib.h>
#include "Student.h"
#include "Course.h"
#include "SchoolManagementSystem.h"

using namespace std;

SchoolManagementSystem::SchoolManagementSystem()
{
    mStudent = NULL;
    mCourse = NULL;
    sCount = 0;
    cCount = 0;
}

SchoolManagementSystem::~SchoolManagementSystem()
{
    if(mStudent != NULL)
        delete [] mStudent;
    if(mCourse != NULL)
        delete [] mCourse;
}


void SchoolManagementSystem::menu()
{
    int choice = -1;

    cout << "Main_menu" << endl;
    
    while(choice != 0)
    {
        cout << "0 exit" << endl 
        << "1 student" << endl 
        << "2 course" << endl 
        << "3 list_all_students" << endl 
        << "4 list_all_courses" << endl;

        cin >> choice;

        if(choice == 1) //Student.h menu
        {
            while(choice != 0)
            {
                cout << "0 up" << endl
                << "1 add_student" << endl
                << "2 select_student" << endl;
                cin >> choice;

                if (choice == 1)    //add_student
                {
                    cin.clear();
                    cin.sync();

                    string entry;
                    getline(cin,entry);
                    Student newStudent;

                    newStudent.setName(entry.substr(0,entry.rfind(' ')));  //substr name from entry. Start from index 0 and finish at " " from end
                    newStudent.setID(stoi(entry.substr(entry.rfind(' ')+1))); //substr ID from entry. Start from rfind(" ") to the end.

                    Student * new_mStudent = new Student[sCount + 1];

                    for(int i = 0; i < sCount; i++)
                        new_mStudent[i] = mStudent[i];
                    delete[] mStudent;
                    mStudent = new_mStudent;
                    new_mStudent[sCount++] = newStudent;
                    
                }
                else if (choice == 2)   //select_student
                {
                    cin.clear();
                    cin.sync();

                    string entry;
                    getline(cin,entry);
                    string name = entry.substr(0,entry.rfind(' '));
                    int id = stoi(entry.substr(entry.rfind(' ')+1));
                    int pos = -1;

                    for(int i = 0; i < sCount; i++) //find position of selected student
                    {
                        if(mStudent[i].getName() == name && mStudent[i].getID() == id)
                            pos = i;
                    }

                    

                    while(choice != 0 && pos != -1)
                    {
                        cout << "0 up" << endl
                        << "1 delete student" << endl
                        << "3 add_selected_student_to_a_course" << endl
                        << "4 drop_selected_student_from_a_course" << endl;
                        cin >> choice;

                        Course* selected_student_courses = mStudent[pos].getCourse_data();  //get course array of selected student

                        if (choice == 1) //delete student
                        {
                            Student *result = NULL;
                            if(sCount > 1)
                                result = new Student[sCount-1];

                            for(int i = 0, j = 0; i < sCount; i++)
                            {
                                if(i != pos)
                                    result[j++] = mStudent[i];
                            }
                            sCount--;
                            delete[] mStudent;
                            mStudent = result;
                            choice = 0;
                        }
                        else if (choice == 3) //add_selected_student_to_a_course
                        {
                            int selection;
                            bool check = false;
                            Course* unassignedCourses = new Course[cCount]; //create temporary dynamic array for tracing unassigned courses(will be deleted later)
                        
                            cout << "0 up" << endl;

                            for(int i = 0,unassignedCount = 0; i < cCount; i++)
                            {
                                for(int j = 0; j < mStudent[pos].get_student_Course_count(); j++)   //loop through all the courses selected student enrolled
                                {
                                    if(selected_student_courses[j].getCode() == mCourse[i].getCode() && selected_student_courses[j].getName() == mCourse[i].getName())
                                        check = true;
                                }
                                if(!check)
                                {   
                                    cout << unassignedCount+1 << " " << mCourse[i].getCode() << " " << mCourse[i].getName() << endl;
                                    unassignedCourses[unassignedCount].setCode(mCourse[i].getCode());
                                    unassignedCourses[unassignedCount].setName(mCourse[i].getName());
                                    unassignedCount++;
                                }
                                check = false;
                            }
                    

                            cin >> selection;

                            if(selection == 0)
                                continue;

                            selection--;

                            int selectionFinal = 0;

                            while(!(unassignedCourses[selection] == mCourse[selectionFinal]))
                            {
                                selectionFinal++;
                            }

                            mStudent[pos].addCourse(mCourse[selectionFinal]);  //add course to student
                            mCourse[selectionFinal].addStudent(mStudent[pos]);  //add student to course
                            delete[] unassignedCourses;

                        }
                        else if (choice == 4) //drop_selected_student_from_a_course
                        {
                            
                            int student_cCount = mStudent[pos].get_student_Course_count();
                            cout << "0 up"<< endl;

                            for(int i = 0; i < student_cCount; i++)
                                cout << i+1 << " " << selected_student_courses[i].getCode() << " " << selected_student_courses[i].getName() << endl;
                            
                            int selection;
                            cin >> selection;

                            if(selection == 0)
                                continue;

                            selection--;

                            mStudent[pos].dropCourse(selected_student_courses[selection].getCode(),selected_student_courses[selection].getName());                           

                        }
                        
                        
                        
                    }
                    choice = -1;
                }
                
                
            }
            choice = -1;
        }
        else if (choice == 2) // Course.h menu
        {
            while (choice != 0)
            {
                cout << "0 up" << endl
                << "1 add_course" << endl
                << "2 select_course" << endl;
                cin >> choice;
                if (choice == 1)    //add_course
                {
                    cin.clear();
                    cin.sync();

                    string entry;
                    getline(cin,entry);
                    Course newCourse;

                    newCourse.setCode(entry.substr(0,entry.find(' ')));  //substr code from entry. Start from index 0 and finish at " "
                    newCourse.setName(entry.substr(entry.find(' ')+1)); //substr name from entry. Start from find(" ") to the end.

                    Course * new_mCourse = new Course[cCount + 1];

                    

                    for(int i = 0; i < cCount; i++)
                        new_mCourse[i] = mCourse[i];
                    
                    delete[] mCourse;
                    
                    mCourse = new_mCourse;
                    
                    mCourse[cCount++] = newCourse;
                    

                }
                else if (choice == 2)   //select_course
                {
                    cin.clear();
                    cin.sync();

                    string entry;
                    getline(cin,entry);
                    string code = entry.substr(0,entry.find(' '));
                    string name = entry.substr(entry.find(' ')+1);
                    int pos = -1;

                    for(int i = 0; i < cCount; i++) //find position of selected student
                    {
                        if(mCourse[i].getName() == name && mCourse[i].getCode() == code)
                            pos = i;
                    }

                    while(choice != 0)
                    {
                        cout << "0 up" << endl
                        << "1 delete_course" << endl
                        << "2 list_students_registered_to_the_selected_course" << endl;

                        int selection = 0;

                        cin >> selection;

                        if(selection == 1)//delete_course
                        {
                            Course *result = NULL;
                            if(cCount > 1)
                                result = new Course[cCount-1];

                            for(int i = 0, j = 0; i < cCount; i++)
                            {
                                if(i != pos)
                                    result[j++] = mCourse[i];
                            }
                            cCount--;
                            delete[] mCourse;
                            mCourse = result;
                            choice = 0;
                        }
                        else if (selection == 2) // list_students_registered_to_the_selected_course
                        {
                            Student* selected_Course_students = mCourse[pos].getStudent_data();

                            for(int i = 0; i < mCourse[pos].get_Course_student_count(); i++)
                            {
                                cout << selected_Course_students[i].getName() << " " << selected_Course_students[i].getID() << endl;
                            }

                            choice = 0;
                        }
                        
                    }
                    choice = -1;
                }
                else
                    continue;
                
                
            }
            choice = -1;

        }
        else if (choice == 3) //list_all_Students
        {
            for(int i = 0; i < sCount; i++)
            {
                cout << mStudent[i].getName() << " " << mStudent[i].getID() << endl;
            }
            
        }
        else if (choice == 4) //list_all_Courses
        {
            for(int i = 0; i < cCount; i++)
            {
                cout << mCourse[i].getCode() << " " << mCourse[i].getName() << endl;
            }

        }
        else    //if choice is not between 0-4 , do nothing
            continue;
    
    }
}