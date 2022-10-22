#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    cout << "You have entered " << argc << " arguments:" << "\n";
  
    if(argv[1][1] == 'r')   // Normal mode
    {
        
    }
    else if(argv[1][1] == 'u')  //debug mode
    {
        int secretNum = int(argv[2]);
        //check if secretNum has unique nums
    }

    return 0;
}