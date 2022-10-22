#include <iostream>
#include <string>
#include "administrator.h"
#include "security.h"
using namespace std;

Administrator::Administrator()
{
    name = "";
    password = "";
}

Administrator::Administrator(string username, string pass)
{
    name = username;
    password = pass;
}

bool Administrator::Login()
{
    int result;

    result = Security::validate(name,password);
    if (result == 2)
    {
        return true;
    }
    return false;
    
}