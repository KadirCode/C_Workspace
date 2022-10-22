#ifndef __ROBOT_H__
#define __ROBOT_H__

#include <iostream>
#include <string>
#include <stdlib.h>  
#include <stdio.h>
#include <time.h>
#include <cstdlib>

class robot //Base class
{
private:   
    int hitPoint;   //health 
public:

    int strength;   //strength
    robot();    //default constructor

    int getDamageR();   //base getDamage func
    void getHit(int damage);    //get hit and lose some health points
    int health();   //returns hitPoint

};

class bulldozer : public robot  //Bulldozer class
{
public:    
    int getDamage();
};

class roomba : public robot //roomba class
{
public:
    int getDamage();
};

class humanic : public robot    //humanic class
{
public:
    int getDamageH();

};

class optimusprime : public humanic //optimusprime class
{
public:
    int getDamage();
};

class robocop : public humanic  //robocop class
{
public:
    int getDamage();
};



#endif