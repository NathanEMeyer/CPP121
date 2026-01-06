#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));

    int rand1 = (rand()%1000)+1;
    int rand2 = (rand()%1000)+1;
    int answer;
    int sAnswer;
    bool plusMinus;
    
    if((rand()%2) == 0)
    {
        plusMinus = false;
    }
    else
    {
        plusMinus = true;
    }

    //generate rand

    if(plusMinus)
    {
        if(rand1 > rand2)
        {
            answer = rand1 + rand2;
            cout<<rand1<<"+"<<rand2<<"=";
            cin>>sAnswer;
        }
        else if(rand2 > rand1)
        {
            answer = rand2 + rand1;
            cout<<rand2<<"+"<<rand1<<"=";
            cin>>sAnswer;
        }
        else
        {
            answer = rand1 + rand2;
            cout<<rand1<<"+"<<rand2<<"=";
            cin>>sAnswer;
        }
    }
    else
    {
        if(rand1 > rand2)
        {
            answer = rand1 - rand2;
            cout<<rand1<<"-"<<rand2<<"=";
            cin>>sAnswer;
        }
         else if(rand2 > rand1)
        {
            answer = rand2 - rand1;
            cout<<rand2<<"-"<<rand1<<"=";
            cin>>sAnswer;
        }
        else
        {
            answer = rand1 - rand2;
            cout<<rand1<<"-"<<rand2<<"=";
            cin>>sAnswer;
        }
    }
    if(sAnswer == answer)
    {
        cout<<"Congrats You got it right!!!!!"<<endl;
    }
    else if(sAnswer > answer)
    {
        cout<<"Too big of an answer"<<endl;
    }
    else
    {
        cout<<"Too small of an answer"<<endl;
    }
    cout<<"Play again soon!!!";

    return 0;
}