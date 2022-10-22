#include <iostream>
#include <string>
#include "security.h"

using namespace std;

int Security::validate(string username, string password)
{
    if ((username == "mustafa") && (password == "musti")) return 1;
    if ((username == "ahmet") && (password == "amed")) return 1;
    return 0;
}

