#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int rollDice()
{
    // 6-sided dice roll.
    return (rand() % 6 ) + 1;
}

int humanTurn(int humanTotalScore)
{
    int score = 0;  //current turns score
    char cInput;    //char input for player to decide whether continue or hold.
    bool bTurnOver = false; //boolian for ending turn.

    cout << "It's your turn! Enter 'r' to roll." << endl;
    cin >> cInput;

    do
    {
        int roll = rollDice();  //dice roll
        cout << "You rolled " << roll << endl;

        if(roll == 1)   //player loses their turn and function returns 0. Which means player didn't earn any points.
        {
            cout << "You lose your turn. Enter 'c' to continue." << endl;
            cin >> cInput;
            return 0;
        }
        else
        {
            score += roll;  // if dice roll is bigger than 1, it will be added to score.
            cout << "Your score this round is: " << score << endl;
            cout << "If you hold, your total score would be: " << humanTotalScore + score << endl;
            cout << "Press 'h' to hold or 'r' to roll again." << endl;
            cin >> cInput;
            if(cInput == 'h')   //if player wants to hold their current score, function will terminate.
            {
                bTurnOver = true;
            }
        }
        
    } while (!bTurnOver);
    return score;
    
}
int computerTurn(int computerTotalScore)
{
    int score = 0;  
    bool bTurnOver = false;
    char cInput;

    cout << "It's the computer's turn!" << endl;

    do
    {
        int roll = rollDice();  //dice roll
        cout << "The computer rolled " << roll << endl;

        if(roll == 1) // computer lose all points earned from current turn.
        {
            cout << "The computer loses its turn. Enter 'c' to continue." << endl;
            cin >> cInput;
            return 0;
        }
        else
        {
            score += roll;  // dice roll is added to current turn score
            cout << "The computer's score this round is: " << score << endl;
            cout << "If the computer holds, its total score would be: " << computerTotalScore + score << endl;
            if((score >= 20) || (score + computerTotalScore >= 100))    // if computer achieved 20 score this round or exceeded 100 total score, its turn will be over. 
            {
                cout << "The computer holds. Enter 'c' to continue. " << endl;
                cin >> cInput;
                bTurnOver = true;
            }
        }
        
    } while (!bTurnOver);
    return score;
}



int main()
{
    int humanScore = 0;
    int computerScore = 0;
    bool gameOver = false;

    srand(static_cast<int>(time(NULL)));


    while(!gameOver)
    {

        humanScore += humanTurn(humanScore);    //Player will start game until they rolled 1 or they decide to hold. Returned value will be added to total score.

        if (humanScore < 100)
        {
            computerScore += computerTurn(computerScore);   // computer will start its turn and return value will be added its total score.
        }

        if (humanScore >= 100)  //human win
        {
            cout << "Congratulations, you win!" << endl;
            gameOver = true; //terminate program.
        }
        else if ( computerScore >= 100) //computer win
        {
            cout << "Sorry, the computer won." << endl;
            gameOver = true; //terminate program.
        }

    }

    return 0;
}