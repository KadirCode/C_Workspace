#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

const int NUM_DUELS = 10000;

void Aaron_shoots(bool aaron, bool& bob, bool& charlie);
void Bob_shoots(bool& aaron, bool bob, bool& charlie);
void Charlie_shoots(bool& aaron, bool& bob, bool charlie);


void Aaron_shoots(bool aaron, bool& bob, bool& charlie)
{
    int shot;

    //if Aaron is dead, do nothing
    if (aaron == false) return;

    //Aaron's shot
    shot = rand() %3;   // 1/3 chance of hitting target

    //hit if shot is 0
    if(shot==0) {
        // Would shoot
        if(charlie) charlie = false;

        else if (bob)
        {
            bob = false;
        }
        return;
    }
}

void Bob_shoots(bool & aaron, bool bob, bool& charlie)
{
    int shot;

    //if bob is dead, do nothing
    if(bob == false) return;

    // Bob's shot
    shot = rand() %2;

    //Hit is shot is 0

    if(shot == 0)
    {
        if(charlie) charlie = false;
        else if (aaron) aaron = false;
        
    }
    return;
}

void Charlie_shoots(bool& aaron, bool& bob, bool charlie)
{
    //if charlie is dead, do nothing
    if(charlie == false) return; 


    //charlie never misses   
    if (bob) bob = false;
    else if (aaron) aaron = false;
    return;
}

int main()
{
    //Variables
    bool aaronAlive, bobAlive, charlieAlive;
    int aaronWins = 0, bobWins = 0, charlieWins = 0;
    
    srand(time(NULL));

    //play 10000 duels
    for(int i = 0; i < NUM_DUELS; i++)
    {
        // Simulate single duel here
        aaronAlive = true;
        bobAlive = true;
        charlieAlive = true;


        //continue duel
        do
        {
            Aaron_shoots(aaronAlive,bobAlive,charlieAlive);
            Bob_shoots(aaronAlive,bobAlive,charlieAlive);
            Charlie_shoots(aaronAlive,bobAlive,charlieAlive);

        } while (aaronAlive + bobAlive + charlieAlive > 1);
        
        if (aaronAlive) aaronWins++;
        if (bobAlive) bobWins++;
        if (charlieAlive) charlieWins++;

    }

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);


    //Output probability of winning
    cout << "Aaron won " << aaronWins << "/10000 duels or " << (static_cast<double> (aaronWins) / NUM_DUELS) *100 << "%" << endl;
    cout << "Bob won " << bobWins << "/10000 duels or " << (static_cast<double> (bobWins) / NUM_DUELS) *100 << "%" << endl;
    cout << "Charlie won " << charlieWins << "/10000 duels or " << (static_cast<double> (charlieWins) / NUM_DUELS) *100 << "%" << endl;
}