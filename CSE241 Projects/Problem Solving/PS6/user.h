#ifndef __USER_H__
#define __USER_H__

#include <string>
using namespace std;

class User
{
private:
    string name;
    string password;
public:
    User();
    User(string name, string password);
    bool Login();
    
};

#endif