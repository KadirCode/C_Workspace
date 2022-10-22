#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include <cstdlib>
#include "robot.h"

using namespace std;

robot::robot()  //default stats
{
    strength = 10;
    hitPoint = 100;
}

int robot::getDamageR() // default damage func
{
    Sleep(1000);
    srand(time(0));
    int damage = (rand() % strength) +1;
    return damage;
}

int roomba::getDamage() //roomba attacks twice
{
    int damage = getDamageR() + getDamageR();
    return damage;    
}

void robot::getHit(int damage)  //get hit and lose some health
{
    hitPoint -= damage;
}

int robot::health()
{
    return hitPoint;
}

int humanic::getDamageH()   //humanic robot attacks have a chance of attacking with a nuke
{
    Sleep(1000);
    srand(time(0));
    int nuke = rand() % 10 + 1;
    int damage = 0;
    if(nuke == 1)
        damage += 50;
    damage = (rand() % strength) + 1;
    return damage;
}

int optimusprime::getDamage()   //optimus prime attacks are doubled
{
    int damage = 2 * getDamageH();
    return damage;
}

int robocop::getDamage()
{
    int damage = getDamageH();
    return damage;
}

int bulldozer::getDamage()
{
    int damage = getDamageR();
    return damage;
}