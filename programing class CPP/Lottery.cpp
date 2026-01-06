#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{
    int earnings;
    double avgDailyWinnings;
    int simulations;

    srand(time(0));

    do
    {
        cout<<"how many simulations(years) would you like to run?"<<endl;
        cin>>simulations;

        if(simulations <1)
        {
            cout<<"INVALID"<<endl;
        }
        
    } while (simulations < 1);
    
    cout<<"Simulating..................... "<<endl;

    for(int i =0; i < simulations; ++i)
    {
        for(int j =0; j < 365; ++j)
        {
            if(((rand()%1000)+1) == ((rand()%1000)+1))
            {
                earnings = earnings + 400;
            }
        }
        avgDailyWinnings = (earnings / 365.0) + avgDailyWinnings;

        earnings = 0;
    }
    cout<<"the amount retained is "<<(avgDailyWinnings/simulations)<<endl;

    return 0;
}