#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));

    //declaring veriables
    double money;
    double bet;
    int ballNumber;
    int guess;

    //creating the random number and asking how much money the player has
    ballNumber = (rand()%32)+1;
    cout<<"how much money did you bring? $";
    cin>>money;
    //checking if they have enough money to play
    if(money<= 0)
    {
        cout<<"Too little money to play.";
    }
    else
    {
        //asking how much they are betting
        cout<<"How much money are you betting? $";
        cin>>bet;
        //checking if they are betting too much money
        if(bet>money)
        {
            cout<<"You can't bet more money then you have.";
        }
        else
        {
            //removes money from their bet and the player guessing the number and the winning number printing
            money -=bet;
            cout<<"Guess what number it will be between 3-30: ";
            cin>>guess;
            cout<<"The number was "<<ballNumber<<endl;
            
            //checking how far off they were from their number and adding the money they have won
            if(guess==ballNumber)
            {
                money += (bet*2);
                cout<<"You now have $"<<money;
            }
            else if((guess+1) == ballNumber || (guess-1) == ballNumber)
            {
                money += (bet*1.5);
                cout<<"You now have $"<<money;
            }
            else if((guess+2) == ballNumber || (guess-2) == ballNumber)
            {
                money += (bet);
                cout<<"You now have $"<<money;
            }
            else
            {
                    cout<<"You now have $"<<money;
            }
        }
    }
    return 0;
}