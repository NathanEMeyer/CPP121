#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int main()
{
    int randomNumb;
    int playerChoice = 101;
    int previousGuess;

    srand(time(0));
    randomNumb = (rand()%100)+1; 
    
    do
    {
        cout<<randomNumb;

        do
        {
            cout<<"Guess a number: ";
            cin>>playerChoice;
            if(playerChoice>100 || playerChoice<1)
            {
                cout<<"Invalid number"<<endl;
            }
        } while (playerChoice>100 || playerChoice<1);

        if(playerChoice<randomNumb)
        {
            cout<<"guess was too low"<<endl;
        }
        else if(playerChoice>randomNumb)
        {
            cout<<"guess was too high"<<endl;
        }
        
    } while (playerChoice != randomNumb);

    cout<<"Horray you got it"<<endl;

    return 0;
}