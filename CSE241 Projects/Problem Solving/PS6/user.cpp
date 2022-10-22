#include <iostream>
#include <string>
#include "user.h"
#include "security.h"
using namespace std;

User::User()
{
    name = "";
    password = "";
}

User::User(string username, string pass)
{
    name = username;
    password = pass;
}

bool User::Login()
{
    int result;

    result = Security::validate(name,password);
    if((result == 2) || (result == 1))
        return true;
    return false;
}