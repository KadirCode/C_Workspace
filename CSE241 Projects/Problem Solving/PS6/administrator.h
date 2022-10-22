#ifndef __ADMIN_H__
#define __ADMIN_H__

#include <string>
using namespace std;

class Administrator
{
private:
    string name;
    string password;
public:
    Administrator();
    Administrator(string name, string password);
    bool Login();
    
};

#endif