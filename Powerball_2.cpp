#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

void randomBalls(int balls[])
{
    bool isRandom = false;

    for(int i =0; i < 5; ++i)
    {
        balls[i] = (rand()%69)+1;
    }

    while(!isRandom)
    {
        isRandom =true;

        for(int i =0; i<5; ++i)
        {
            for(int j = 0; j<5; ++j)
            {
                if(balls[i] == balls[j] && i != j)
                {
                    isRandom =false;
                    balls[i] = (rand()%69)+1;
                }
            }
        }
    }

}

int main()
{
    const int MAX_BALLS =5;

    int whiteBallsPlayer[MAX_BALLS];

    int whiteBallsRandom[MAX_BALLS];

    int interations = 100000;
    int perLifeTime = 9672;
    double winningsTotal =0.0;
    int checker=0;
    int redBallP =0;
    int redBallR =0;

    srand(time(0));

    cout<<"Simulating";

    for(int i =0; i < interations; ++i)
    {
        for(int f =0; f < perLifeTime; ++f)
        {
            randomBalls(whiteBallsPlayer);
            randomBalls(whiteBallsRandom);
            redBallP = (rand()%26)+1;
            redBallR = (rand()%26)+1;

            for(int i=0; i<MAX_BALLS; ++i)
            {
                for(int j=0; j<MAX_BALLS; ++j)
                {
                    if(whiteBallsPlayer[i] == whiteBallsRandom[j])
                    {
                        ++checker;
                    }
                }
            }

            if(checker == 5 && redBallP == redBallR)
            {
                winningsTotal += 210000000;
            }
            else if(checker == 5)
            {
                winningsTotal += 1000000;
            }
            else if(checker == 4 && redBallP == redBallR)
            {
                winningsTotal += 50000;
            }
            else if(checker == 4)
            {
                winningsTotal += 100;
            }
            else if(checker == 3 && redBallP == redBallR)
            {
                winningsTotal += 100;
            }
            else if(checker == 3)
            {
                winningsTotal += 7;
            }
            else if(checker == 2 && redBallP == redBallR)
            {
                winningsTotal += 7;
            }
            else if(checker <= 1 && redBallP == redBallR)
            {
                winningsTotal += 4;
            }

            checker =0;
        }

        if(i %10000 == 0)
        {
            cout<<".";
            cout.flush();
        }
    }

    cout<<endl<<"You on average would make $"<<(winningsTotal/(interations*perLifeTime));

    return 0;
}