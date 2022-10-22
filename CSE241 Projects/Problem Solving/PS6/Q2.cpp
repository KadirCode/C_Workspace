#include <iostream>
#include <string>
#include "user.h"
#include "administrator.h"
using namespace std;

int main()
{
    User user1("mustafa","musti"), user2("mehmet","memed"), user3("ahmet","amed");
    Administrator admin1("mustafa","musti"), admin2("suleyman","sulo"),admin3("furkan","furki");

    cout << "Result of login: " << endl;
    cout << "User login for mustafa: " << user1.Login() << endl;
    cout << "User login for mehmet: " << user2.Login() << endl;
    cout << "User login for ahmet: " << user3.Login() << endl;
    cout << "User login for mustafa: " << user1.Login() << endl;
    cout << "User login for suleyman: " << user2.Login() << endl;
    cout << "User login for furkan: " << user3.Login() << endl;


    return 0;
}