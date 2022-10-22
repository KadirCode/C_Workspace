#include <iostream>
#include "humanic.h"

using namespace std;

int humanic::getDamageH()
{
    int nuke = rand() % 10 + 1;
    int damage = 0;
    if(nuke == 1)
        damage += 50;
    damage = (rand() % strength) + 1;
    return damage;
}

int optimusprime::getDamage()
{
    int damage = 2 * getDamageH();
    return damage;
}

int robocop::getDamage()
{
    int damage = getDamage();
    return damage;
}