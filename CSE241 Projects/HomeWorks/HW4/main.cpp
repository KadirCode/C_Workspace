#include <iostream>
#include <string>
#include "robot.h"

using namespace std;


int main()
{
    bulldozer bull;
    roomba room;
    optimusprime opti;
    robocop robo;


    cout << "Robocop vs Roomba" << endl;
    int robocopHit,roombaHit;
    while(robo.health() > 0 && room.health() > 0)
    {
        robocopHit = robo.getDamage();
        cout << "Robocop hits: " << robocopHit << endl;
        room.getHit(robocopHit);
        cout << "Roomba health after hit: " << room.health() << endl;

        roombaHit = room.getDamage();
        cout << "Roomba hits: " << roombaHit << endl;
        robo.getHit(roombaHit);
        cout << "Robocop healht after hit: " << robo.health() << endl;
    }
    cout << "-----------END OF GAME-------------" << endl;
    if(robo.health() > room.health())
        cout << "Robocop wins!!" << endl;
    else if(robo.health() < room.health())
        cout << "Roomba wins!!" << endl;
    else
        cout << "It is a draw!!" << endl;

    cout << "************NEXT GAME*************" << endl;

    cout << "OptimusPrime vs Bulldozer" << endl;
    int optiHit,bullHit;
    while(opti.health() > 0 && bull.health() > 0)
    {
        optiHit = opti.getDamage();
        cout << "OptimusPrime hits: " << optiHit << endl;
        bull.getHit(optiHit);
        cout << "Bulldozer health after hit: " << bull.health() << endl;

        bullHit = bull.getDamage();
        cout << "Bulldozer hits: " << bullHit << endl;
        opti.getHit(bullHit);
        cout << "OptimusPrime healht after hit: " << opti.health() << endl;
    }
    cout << "-----------END OF GAME-------------" << endl;
    if(opti.health() > bull.health())
        cout << "OptimusPrime wins!!" << endl;
    else if(opti.health() < bull.health())
        cout << "Bulldozer wins!!" << endl;
    else
        cout << "It is a draw!!" << endl;

    return 0;
}