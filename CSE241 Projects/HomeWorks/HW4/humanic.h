#ifndef __HUMANIC_H__
#define __HUMANIC_H__

#include <iostream>
#include <string>
#include <cstdlib>
#include "robot.h"

using namespace std;


class humanic : public robot
{
public:
    int getDamageH();

};

class optimusprime : public humanic
{
public:
    int getDamage();
};

class robocop : public humanic
{
public:
    int getDamage();
};

#endif
